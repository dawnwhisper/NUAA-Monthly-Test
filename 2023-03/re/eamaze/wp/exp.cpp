#include<bits/stdc++.h>
using namespace std;

char maze[] =
{
   42, 114,  40,  41,  46,  47,  40,  41,  34,  39, 
   36,  37,  38,  35,  32,  33,  58,  63,  56,  61, 
   62,  63,  98,  57,  50,  51,  48,  49,  54,  51, 
    0
};

int main(){
	for(int i=0;i<30;i++){
		if(i%6==0)cout<<endl;
		cout<<(char)(maze[i]^i)<<' ';
	}
	return 0;
} 
