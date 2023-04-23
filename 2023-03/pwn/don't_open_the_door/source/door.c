#include<stdio.h>
#include<unistd.h>
#include<string.h>
void init()
{
	setbuf(stdin,0);
	setbuf(stdout,0);
	setbuf(stderr,0);
}
void open_the_door()
{
	char buf[160];
	int v1;
	int v2;
	puts("Mom hasn't come back, can't open the door");
	puts("Where is the rabbit's home:");
	scanf("%d",&v2);
	memcpy(&buf[160+8],&buf[v2],0x8);
	puts("Where can you find rabbit's mother:");
	read(0, buf, 0xA0uLL);
	v2 = strlen(buf);
	puts("How many moms did you find:");
	scanf("%d", &v1);
	v1 = v2 + v1;
	buf[v1] = 0;
}
int main()
{
	init();
	open_the_door();
	return 0;
}
