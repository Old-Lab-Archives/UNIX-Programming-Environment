#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include "juice.h"
#define DEPTH 100 /* directory depth */
#define MeowHome "\home\ashumeow"
#define NAME "BeersVodkaRedWineProgrammingGeekingCodingMicrosoftWindowsUnixDeveloperAndIDontKnowWhatTheFuckIAmDoing"
int main(void)
{
	int i, size;
	char *path;
	if(chdir(MeowHome) < 0)
		err_sys("error");
	for(i=0;i<DEPTH;i++)
	{
		if(mkdir(NAME, DIR_MODE) < 0)
			err_sys("mkdir failed, i = %d", i);
		if(chdir(NAME) < 0)
			err_sys("chdir failed, i = %d", i);
	}
	if(creat("MeowFile", FILE_MODE) < 0)
		err_sys("Error");
	/* After creating deep directory, now let's go ahead with "obtaining pathname" */
	path = path_alloc(&size);
	for(; ;)
	{
		if(getcwd(path, size) != NULL)
			break;
		else
		{
			err_ret("getcwd failed, size = %d", size);
			size += 100;
			if((path = realloc(path, size)) == NULL)
				err_sys("error");
		}
	}
	printf("length = %d\n%s\n", strlen(path), path);
	exit(0);
}

