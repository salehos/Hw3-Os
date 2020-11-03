#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#define OperatingSystemCourseFall2020(str) write(1,    #str,sizeof(#str))

int main()
{
	OperatingSystemCourseFall2020(A);
	int p = fork();
	sleep(0.1);
	OperatingSystemCourseFall2020(B);
	if(p){
		wait(NULL);
	}
	OperatingSystemCourseFall2020(C);
}
