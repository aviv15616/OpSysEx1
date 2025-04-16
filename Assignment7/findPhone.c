#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "logger.h"

/**
 * @brief Main function for the findPhone program.
 * 
 * This program searches for a name in "phonebook.txt" and processes the result
 * using a pipeline of Unix commands: cat → grep → sed → sed → awk.
 * Each stage is connected via pipes, and processes are logged using logger.h.
 * 
 * Usage: ./findPhone "Name To Search"
 */
int main(int argc, char *argv[]) {
    // Clear previous log file (start fresh)
    fclose(fopen("findPhone.log", "w"));

    // Ensure the user provided a name to search for
    if (argc < 2) {
        fprintf(stderr, "Usage: %s \"Name to search\"\n", argv[0]);
        exit(1);
    }

    // Declare pipes for connecting the processes:
    // pipe1: cat → grep
    // pipe2: grep → sed (spaces)
    // pipe3: sed (spaces) → sed (commas)
    // pipe4: sed (commas) → awk
    int pipe1[2], pipe2[2], pipe3[2], pipe4[2];
    if (pipe(pipe1) == -1) { perror("pipe1"); exit(1); }
    if (pipe(pipe2) == -1) { perror("pipe2"); exit(1); }
    if (pipe(pipe3) == -1) { perror("pipe3"); exit(1); }
    if (pipe(pipe4) == -1) { perror("pipe4"); exit(1); }

    pid_t pid;

    // Process 1: Run `cat phonebook.txt`
    pid = fork();
    if (pid < 0) { perror("fork cat"); exit(1); }
    if (pid == 0) {
        log_process("cat phonebook.txt", getpid());
        dup2(pipe1[1], STDOUT_FILENO); // Output → pipe1
        // Close all pipe ends
        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);
        close(pipe3[0]); close(pipe3[1]);
        close(pipe4[0]); close(pipe4[1]);
        // Execute cat
        char *cat_args[] = { "cat", "phonebook.txt", NULL };
        execve("/bin/cat", cat_args, NULL);
        log_execve_failure("cat", getpid());
        perror("execve cat");
        exit(1);
    }

    // Process 2: Run `grep <search_term>`
    pid = fork();
    if (pid < 0) { perror("fork grep"); exit(1); }
    if (pid == 0) {
        log_process("grep", getpid());
        dup2(pipe1[0], STDIN_FILENO);  // Input ← pipe1
        dup2(pipe2[1], STDOUT_FILENO); // Output → pipe2
        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);
        close(pipe3[0]); close(pipe3[1]);
        close(pipe4[0]); close(pipe4[1]);
        char *grep_args[] = { "grep", argv[1], NULL };
        execve("/bin/grep", grep_args, NULL);
        log_execve_failure("grep", getpid());
        perror("execve grep");
        exit(1);
    }

    // Process 3: Run `sed 's/ /#/g'`
    pid = fork();
    if (pid < 0) { perror("fork sed spaces"); exit(1); }
    if (pid == 0) {
        log_process("sed s/ /#", getpid());
        dup2(pipe2[0], STDIN_FILENO);  // Input ← pipe2
        dup2(pipe3[1], STDOUT_FILENO); // Output → pipe3
        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);
        close(pipe3[0]); close(pipe3[1]);
        close(pipe4[0]); close(pipe4[1]);
        char *sed_space_args[] = { "sed", "s/ /#/g", NULL };
        execve("/bin/sed", sed_space_args, NULL);
        log_execve_failure("sed space", getpid());
        perror("execve sed spaces");
        exit(1);
    }

    // Process 4: Run `sed 's/,/ /'`
    pid = fork();
    if (pid < 0) { perror("fork sed comma"); exit(1); }
    if (pid == 0) {
        log_process("sed s/,/ /", getpid());
        dup2(pipe3[0], STDIN_FILENO);  // Input ← pipe3
        dup2(pipe4[1], STDOUT_FILENO); // Output → pipe4
        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);
        close(pipe3[0]); close(pipe3[1]);
        close(pipe4[0]); close(pipe4[1]);
        char *sed_comma_args[] = { "sed", "s/,/ /", NULL };
        execve("/bin/sed", sed_comma_args, NULL);
        log_execve_failure("sed comma", getpid());
        perror("execve sed comma");
        exit(1);
    }

    // Process 5: Run `awk '{print $2}'`
    pid = fork();
    if (pid < 0) { perror("fork awk"); exit(1); }
    if (pid == 0) {
        log_process("awk {print $2}", getpid());
        dup2(pipe4[0], STDIN_FILENO); // Input ← pipe4
        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);
        close(pipe3[0]); close(pipe3[1]);
        close(pipe4[0]); close(pipe4[1]);
        char *awk_args[] = { "awk", "{print $2}", NULL };
        execve("/usr/bin/awk", awk_args, NULL);
        log_execve_failure("awk", getpid());
        perror("execve awk");
        exit(1);
    }

    // Parent process: close all pipe ends
    close(pipe1[0]); close(pipe1[1]);
    close(pipe2[0]); close(pipe2[1]);
    close(pipe3[0]); close(pipe3[1]);
    close(pipe4[0]); close(pipe4[1]);

    // Wait for all child processes to complete
    log_parent_wait();
    int status;
    pid_t wpid;
    int count = 0;
    while ((wpid = wait(&status)) > 0) {
        log_child_exit(wpid);
        count++;
    }

    log_parent_end(count);
    return 0;
}
