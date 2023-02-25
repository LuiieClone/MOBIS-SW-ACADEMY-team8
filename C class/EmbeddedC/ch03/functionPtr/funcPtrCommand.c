#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcPtrCommand.h"

CMD_TBL cmdTbl[] = {
	CMD_TBL_T1,
	CMD_TBL_END,
	LED_ON,
	LED_OFF
};
	
		
void DisplayPrompt(char *prompt){
	if(prompt == NULL) {
		printf("monitor> ");
	} else {
		printf("%s", prompt);
	}
}

void GetCommand(char *cmd)
{
	fgets(cmd, 79, stdin);
	cmd[strlen(cmd)-1]='\0';
}

void DoPrintfHelp(void){
	CMD_TBL	*cptr;

	printf("The following commands are supported :\n");

	for (cptr=cmdTbl; cptr->cmd!=0; cptr++){
		printf("%s", cptr->usage);
		printf("\n");
	}

	printf("  help        Help for commands.\n");
	printf("  ?           Help for commands.\n");
	printf("  exit        Quit the monitor program.\n");

	printf("\n");
}

int main(void)
{
	char cmd[80];
	int num=0;
	CMD_TBL *cptr;
	int cmd_no=0;

	while(1) {
		DisplayPrompt("CMD> ");
		GetCommand(cmd);
		if(!cmd[0]) continue;
		////
		char *ptr = strtok(cptr->cmd, " ");
		while (ptr != NULL)
		{
			printf("test %s\n", ptr);
			num = atoi(strtok(NULL, " "));
			printf("test %d\n", num);
	    }
		////
		for (cptr=cmdTbl; cptr->cmd; cptr++)
			if(!strcmp(cmd, cptr->cmd)) {
				(cptr->run)(num);
				break;
			}
	
		if (!strcmp(cmd, "help") || !strcmp(cmd, "?")){
			DoPrintfHelp();
		} else if (!strcmp(cmd, "exit")) {
			exit(0);
		} else if (!(cptr->cmd)){
			printf("\tUnknown command\n");
		}
	}
	return 0;
}

void func_t1(int val) 
{
    printf("func_t1 => cal : %d !!\n", val);
}
void f_LED_ON(int num)
{
    printf("ON => LED : %d ON!\n", num);
}
void f_LED_OFF(int num)
{
    printf("OFF => LED : %d OFF!\n", num);
}
