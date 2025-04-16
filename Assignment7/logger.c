/**
 * @file logger.c
 * @brief Implements logging functions for process events in the findPhone program.
 *
 * Each function writes log entries to "findPhone.log", including:
 * - When a process starts a new stage
 * - When execve fails
 * - When the parent process starts waiting
 * - When a child process terminates
 * - When the parent finishes waiting
 *
 * All log entries include a timestamp (HH:MM:SS) for easier debugging and tracking.
 */

 #include "logger.h"
 #include <stdio.h>
 #include <time.h>
 
 /**
  * @brief Logs the start of a process stage.
  *
  * @param stage Description of the stage (e.g. "grep", "awk", etc.)
  * @param pid   Process ID of the current process.
  */
 void log_process(const char *stage, pid_t pid) {
	 FILE *log = fopen("findPhone.log", "a");
	 if (!log) return;
 
	 time_t now = time(NULL);
	 struct tm *t = localtime(&now);
	 fprintf(log, "[%02d:%02d:%02d] PID %d started stage: %s\n",
			 t->tm_hour, t->tm_min, t->tm_sec, pid, stage);
 
	 fclose(log);
 }
 
 /**
  * @brief Logs a failure to execute a stage using execve.
  *
  * @param stage Name of the stage that failed.
  * @param pid   Process ID of the failing process.
  */
 void log_execve_failure(const char *stage, pid_t pid) {
	 FILE *log = fopen("findPhone.log", "a");
	 if (!log) return;
 
	 time_t now = time(NULL);
	 struct tm *t = localtime(&now);
	 fprintf(log, "[%02d:%02d:%02d] [ERROR] PID %d failed to execve: %s\n",
			 t->tm_hour, t->tm_min, t->tm_sec, pid, stage);
 
	 fclose(log);
 }
 
 /**
  * @brief Logs when the parent process begins waiting for child processes.
  */
 void log_parent_wait() {
	 FILE *log = fopen("findPhone.log", "a");
	 if (!log) return;
 
	 time_t now = time(NULL);
	 struct tm *t = localtime(&now);
	 fprintf(log, "[%02d:%02d:%02d] Parent is now waiting for children to terminate...\n",
			 t->tm_hour, t->tm_min, t->tm_sec);
 
	 fclose(log);
 }
 
 /**
  * @brief Logs when a child process exits.
  *
  * @param pid PID of the child process that has terminated.
  */
 void log_child_exit(pid_t pid) {
	 FILE *log = fopen("findPhone.log", "a");
	 if (!log) return;
 
	 time_t now = time(NULL);
	 struct tm *t = localtime(&now);
	 fprintf(log, "[%02d:%02d:%02d] Child with PID %d exited.\n",
			 t->tm_hour, t->tm_min, t->tm_sec, pid);
 
	 fclose(log);
 }
 
 /**
  * @brief Logs when the parent process has finished waiting and how many children exited.
  *
  * @param count The number of children that have terminated.
  */
 void log_parent_end(int count) {
	 FILE *log = fopen("findPhone.log", "a");
	 if (!log) return;
 
	 time_t now = time(NULL);
	 struct tm *t = localtime(&now);
	 fprintf(log, "[%02d:%02d:%02d] Parent process finished. Total children exited: %d\n",
			 t->tm_hour, t->tm_min, t->tm_sec, count);
 
	 fclose(log);
 }
 