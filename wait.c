#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
//	pid_t pid;	
	int pid;
	char *msg;
	int n;
	int exit_code;
	printf("Fork program starting\n");
	pid=fork();
	switch(pid)
	{
		case -1:
			perror("Fork failed");
			exit(1);
		case 0:
			msg ="This is the child";
			n=5;
			exit_code=37;
			break;
		default:
 			msg="This is the parent";
			n=3;
			exit_code=0;
			break;
	}
for(; n>0; n--)
	{
		puts(msg);
		sleep(1);
	}
if(pid != 0)
	{
		int stat_val;
		pid_t child_pid;
		child_pid=wait(&stat_val);
		printf("Child has finished : PID = %d\n",child_pid);
		if (WIFEXITED(stat_val))
			printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
		else
			printf("Child terminated abnormally\n");
	}
	exit(exit_code);
}
			
