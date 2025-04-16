/**
 * @file logger.h
 * @brief Function declarations for logging process events in the findPhone program.
 *
 * This header defines utility functions for writing log messages to a log file (findPhone.log),
 * including timestamps and process information.
 */

 #ifndef LOGGER_H
 #define LOGGER_H
 
 #include <sys/types.h>  // for pid_t
 
 /**
  * @brief Logs the start of a process stage (e.g. grep, sed).
  *
  * @param stage A string describing the current stage (e.g., "grep", "awk", etc.)
  * @param pid   The process ID of the current process.
  */
 void log_process(const char *stage, pid_t pid);
 
 /**
  * @brief Logs an error if execve fails in a child process.
  *
  * @param stage Name of the failed command or stage.
  * @param pid   The process ID that attempted to execute the command.
  */
 void log_execve_failure(const char *stage, pid_t pid);
 
 /**
  * @brief Logs that the parent process has begun waiting for its children to finish.
  */
 void log_parent_wait();
 
 /**
  * @brief Logs when a child process has terminated.
  *
  * @param pid The PID of the child process that exited.
  */
 void log_child_exit(pid_t pid);
 
 /**
  * @brief Logs when the parent has finished waiting and how many child processes exited.
  *
  * @param count The total number of child processes that have exited.
  */
 void log_parent_end(int count);
 
 #endif // LOGGER_H
 