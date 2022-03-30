#include <osdef.h>
#if defined(linux)
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#endif
#ifdef linux
void my_handler(int s) {
	puts("\033[0mKILLHANDLER RESET CONSOLE");
	exit(1);

}
void linuxSysHandler(){
	struct sigaction sigIntHandler;

	sigIntHandler.sa_handler = my_handler;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;

	sigaction(SIGINT, &sigIntHandler, NULL);
}
#endif
