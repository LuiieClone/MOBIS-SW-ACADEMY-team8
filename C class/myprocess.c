#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	if(fork()==0) { // child process
		system("sleep 3");
		system("ps -l");
	exit(0);
	} else { // parent process
		system("sleep 10");
		system("ps -l");
	}
	return 0;
}
