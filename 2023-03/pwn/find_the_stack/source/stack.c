#include<stdio.h>
#include<string.h>
#include<unistd.h>
long long much=0;
void init()
{
	setbuf(stdin,0);
	setbuf(stdout,0);
	setbuf(stderr,0);
}
int main()
{
	init();
	char *a;
	much++;
	if(much==1)
	{
		puts("Where is the stack:");
		read(0,&a,0x8);
		puts("What information do you want to write on the stack:");
		read(0,a,0x80);
	}
	return 0;
}
