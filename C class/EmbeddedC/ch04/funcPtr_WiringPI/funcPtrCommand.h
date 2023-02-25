#ifndef _COMMAND_H_
#define _COMMAND_H_

#define MAX_COMMANDS			20


typedef struct _CMD_TBL {
	char 	*cmd;		// command name
	void	(*run)(int);	// function point.
	char	*usage;		// command usage
} CMD_TBL;


#define	CMD_TBL_T1	{"test1", func_t1, 0}
#define	CMD_TBL_END	{0, 0, 0}

extern CMD_TBL cmdTbl[];

// Prototypes.
void	DisplayPrompt(char *prompt);
void	GetCommand(char *cmd);
void func_t1(int val);

#endif		// end _COMMAND_H_
