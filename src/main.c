
#define _GNU_SOURCE
#define _XOPEN_SOURCE 600

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

#include <unistd.h>

#include <fcntl.h>
#include <signal.h>
#include <syslog.h>

#include <sys/stat.h>

#define BD_NO_UMASK0 010

#define DEFAULT_LOG_FILENAME "ork-output.log"
#define DEFAULT_CONFIGURATION_FILENAME "ork.conf"

static const char* log_filename = DEFAULT_LOG_FILENAME;
static const char* configuration_filename = DEFAULT_CONFIGURATION_FILENAME;

static void signal_handler_kill(int signal) {
	syslog(LOG_DEBUG, "I HAVE BEEN SLAIN :(\n");
}

int main(int argc, char *argv[])
{
	// Start orchestration server
	syslog(LOG_DEBUG, "Initializing orchestration server...\n");

	if (argc == 1) {
		// For now simply continue silently.
	}

	while (*++argv) {
		// Execute command string
		// system(*argv);

		// Log the argument
		syslog(LOG_DEBUG, "Argument: %s\n", *argv);
	}

	// TODO: Get names from command line or ork.conf file
	syslog(LOG_DEBUG, "Log file: %s\n", log_filename);
       	syslog(LOG_DEBUG, "Configuration file: %s\n", configuration_filename);

	// TODO: Determine whether configuration file exists
	// TODO: Parse configuration file
	
	// TODO: If logging enabled, start it up
	FILE* log_file = NULL;
	
	if (true) {
		log_file = fopen(log_filename, "a");
		// TODO; Check for errors
		// TODO: Handle errors
	}


	// Become a daemon
	switch (fork()) {
		case -1: return -1;
		case 0: break;
		default: _exit(EXIT_SUCCESS);
	}

	if (setsid() == -1) {
		return -1;
	}

	switch (fork()) {
		case -1: return -1;
		case 0: break;
		default: _exit(EXIT_SUCCESS);
	}

	//Clear file mode creation mask
	if (!(/*flags &*/ BD_NO_UMASK0)) {
		umask(0);
	}

	// Change to root directory
	if (!(false)) {
		chdir("/");
	}

	// Close all open files
	if ((true)) {
		int maxfd = sysconf(_SC_OPEN_MAX);

		if (maxfd == -1) {
			maxfd = 8192;
		}

		for (int fd = 0; fd < maxfd; ++fd) {
			close(fd);
		}
	}

	// TODO: Register signal handlers
	if (signal(SIGKILL, signal_handler_kill) == SIG_ERR) {
		syslog(LOG_ERR, "Failed to set kill signal handler.\n");
	}

	// Main daemon function
	while (true) {
		; // Just chill
	}

	// Terminate
	// if (true) {
	// 	fclose(log_file);
	// }

	return EXIT_SUCCESS;
}

