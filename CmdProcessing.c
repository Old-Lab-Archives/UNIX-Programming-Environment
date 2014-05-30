#include "juice.h"
#define MeowToken_ADD 5
void do_line(char *);
void cmd_AddMeow(void);
int get_MeowToken(void);
int main(void)
{
	char line[MAXLINE];
	while(fgets(line, MAXLINE, stdin) != NULL)
		do_line(line);
	exit(0);
}
char *MeowToken_ptr; /* global pointer for get_token() */
void do_line(char *MeowPtr)
	/*processing one line of input */
{
	int MeowCmd;
	MeowToken_ptr = MeowPtr;
	while((MeowCmd = get_MeowToken()) > 0)
	{
		switch(MeowCmd)
		{
		case MeowToken_ADD:
			cmd_AddMeow();
			break;
		}
	}
}
void cmd_AddMeow(void)
{
	int MeowToken;
	MeowToken = get_MeowToken();
}
int get_MeowToken(void)
{
	/* fetch next token from the line pointed to MeowToken_ptr */
}
