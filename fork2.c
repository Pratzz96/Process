#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int childpid;
	int count1=0, count2=0;
	printf("Before it forks!\n");
	childpid=fork();
	if (childpid==0)
	{
		printf("This is a child process\n");
		while(count1<10)
		{
			printf("Child process: %d\n",count1);
			sleep(1);
			count1++;
		}
	}
	else
	{
		printf("This is the parent process\n");
		while(count2<20)
		{
		printf("Parent process:%d\n",count2);
		sleep(1);
		count2++;
		}	
	}
return 0;
}
