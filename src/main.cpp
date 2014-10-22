#include <iostream>
#include <unistd.h> //fork
#include <sys/types.h> 
#include <sys/wait.h> //wait pid
#include <stdio.h> //perror

#include <string>
#include <string.h>

using namespace std;

int main(int argc, char *argv)
{

	//char * cmd;
	//char length[10];
	
	int pid = fork();

	if (pid == -1)
	{
		perror("Fork error");
		exit(1);
	}
	else if (pid == 0)
	{
		cout << "Child Process" << endl;
		if (-1 == execvp(argv[0], argv))
		{
			perror("execvp error");
		
			exit(1);
		}
	}

	else if (pid > 0)
	{
		if (-1 == wait(0))
		{
			cout << "I'm a parent." << endl;
			perror("error with wait");
		}
	}

	return 0;




}
