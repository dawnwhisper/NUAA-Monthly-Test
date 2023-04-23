#include<bits/stdc++.h>
using namespace std;

char maze[]={42,114,40,41,46,47,40,41,34,39,36,37,38,35,32,33,58,63,56,61,62,63,98,57,50,51,48,49,54,51,0};
char s[10];

void change(){
	int maze_len=30;
	for(int i=0;i<maze_len;i++){
		maze[i]^=i;
		cout<<maze[i]<<' ';
		if(i%6==0)cout<<endl;
	}
}

int main(){
	cout<<"WoW,can you find where the maze is?"<<endl;
	cout<<"please input your step:"<<endl;
	int v0=1;
	cin>>s;
	change();
	int n=strlen(s);
	if(n!=10) {cout<<"Wrong!qwq,try again"<<endl;exit(0);}
	for(int i=0;i<n;i++){
		if(s[i]=='i')v0-=6;
		if(s[i]=='k')v0+=6;
		if(s[i]=='j')v0-=1;
		if(s[i]=='l')v0+=1;
		if(maze[v0]=='*'){cout<<"Wrong!qwq,try again"<<endl;exit(0);}
		if(v0<0||v0>30){cout<<"Wrong!qwq,try again"<<endl;exit(0);}
	}
	if(maze[v0]!='t'){cout<<"Wrong!qwq,try again"<<endl;exit(0);}
	if(maze[v0]=='t')cout<<"Yes,answer is"<<endl<<"flag{yourinput()}"<<endl;
	return 0;
}
