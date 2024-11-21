#include<stdio.h>
//#include<stdlib.h>
#include<unistd.h>
int main()
{
	int pipefds1[2];
	int returnstatus1;
	int pid;
	char msg1[20]="Hello World";
	char msg2[20]="Hello SPPU";
	char msg3[20]="Linux is Funny";
	char readmsg[20];
 	returnstatus1==pipe(pipefds1);
 	if(returnstatus1==-1)
 	{
 		printf("Unable to create pipe\n");
 		return 1;
 	}
 	pid=fork();
 	if(pid!=0)
 	{
 		close(pipefds1[0]);
 		printf("Parent:Writing to pipe1-Message is %s\n",msg1);
 		write(pipefds1[1],msg1,sizeof(msg1));
 		sleep(1);
 		printf("Parent:Writing to pipe1-Message is %s\n",msg2);
 		write(pipefds1[1],msg2,sizeof(msg2));
 		sleep(1);
 		printf("Parent:Writing to pipe1-Message is %s\n",msg3);
 		write(pipefds1[1],msg3,sizeof(msg3));	
 		sleep(1);
 	}
 	else
 	{
 		close(pipefds1[0]);
 		read(pipefds1[0],readmsg,sizeof(readmsg));
 		printf("Child:Reading from pipe1-Message is %s\n",msg1);
 		sleep(1);
 		read(pipefds1[0],readmsg,sizeof(readmsg));
 		printf("Child:Reading from pipe1-Message is %s\n",msg2);
 		sleep(1);
 		read(pipefds1[0],readmsg,sizeof(readmsg));
 		printf("Child:Reading from pipe1-Message is %s\n",msg3);
 		sleep(3);
 	}
 	return 0;
 }
 		
 		
 		
