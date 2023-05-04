#include<stdio.h>
#include<string.h>
#include<unistd.h>
int notebook[100];
void init()
{
	setbuf(stdin,0);
	setbuf(stdout,0);
	setbuf(stderr,0);
}
void backdoor()
{
	system("echo this is backdoor");
}
int main()
{
	init();
	printf("Enter the password and I'll give you the back door\n");
	read(0,notebook,0x50);
	void (* f)(char *);
	f=*(void(*)(char *))notebook[0];
	(*f)(&notebook[0]);
	return 0;
}
