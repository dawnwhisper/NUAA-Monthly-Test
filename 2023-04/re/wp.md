# crackme wp

windows x64 upx

修改节表，段名改为UPX0...

然后upx脱壳。

对于题目花指令进行去除以后，发现是非标准rc4，直接套题目代码跑一遍即可。

exp:

```c++
#include <iostream>
#include <cstring>
// flag{20b7c1e1164edb818dcdeb28a5220ca1}

void rc4_init(unsigned char*s, unsigned char*key, unsigned long Len)
{
    int i=0,j=0;
    unsigned char k[512]={0};
    unsigned char tmp=0;
    for(i=0;i<512;i++) {
        s[i]=i;
        k[i]=key[i%Len];
    }
    for(i=0;i<512;i++) {
        j=(j+s[i]+k[i])%512;
        tmp=s[i];
        s[i]=s[j];//交换s[i]和s[j]
        s[j]=tmp;
    }
}
void rc4_crypt(unsigned char*s,unsigned char*Data,unsigned long Len)
{
    int i=0,j=0,t=0;
    unsigned long k=0;
    unsigned char tmp;
    for(k=0;k<Len;k++)
    {
        i=(i+1)%512;
        j=(j+s[i])%512;
        tmp=s[i];
        s[i]=s[j];//交换s[x]和s[y]
        s[j]=tmp;
        t=(s[i]+s[j])%512;
        Data[k]^=s[t];
    }
}

bool check(unsigned char* a){
	unsigned char aim[] = {0x3c, 0xb7, 0xa2, 0xa0, 0xce, 0x17, 0x60, 0xdd, 0xfd, 0x80, 0xbd, 0x6f, 0x92, 0xba, 0x70, 0xb6, 0xd8, 0x99, 0x1b, 0xf0, 0x8d, 0x22, 0xda, 0x51, 0x35, 0x4f, 0x59, 0x6e, 0x26, 0x9e, 0xcd, 0x67, 0x88, 0xf9, 0x05, 0x47, 0x9a, 0x6a};
	for (int i = 0; i < 38; i ++){
		if (a[i] != aim[i]){
			return false;
		}
	}
	return true;
}

void run(){
	unsigned char aim[] = {0x3c, 0xb7, 0xa2, 0xa0, 0xce, 0x17, 0x60, 0xdd, 0xfd, 0x80, 0xbd, 0x6f, 0x92, 0xba, 0x70, 0xb6, 0xd8, 0x99, 0x1b, 0xf0, 0x8d, 0x22, 0xda, 0x51, 0x35, 0x4f, 0x59, 0x6e, 0x26, 0x9e, 0xcd, 0x67, 0x88, 0xf9, 0x05, 0x47, 0x9a, 0x6a};
	
	unsigned char s[512] = {0};   // sbox
	unsigned char key[512] = {0};
	strcpy((char*)key, "wuwuwuwuwuwuwuwuwuwu_re_is_so_hard");
	int text_len = strlen((char*)aim);
	int key_len = strlen((char*)key);
	// printf("key_len: %d textlen: %d \n", key_len, text_len);
	rc4_init(s, key, key_len);    //初始化
	rc4_crypt(s, aim, text_len);  //加密
	
	for (int i = 0; i < text_len; i ++){
		printf("0x%02x, ", aim[i]);
	} 
	for (int i = 0; i < text_len; i ++){
		printf("%c", aim[i]);
	} 

	
} 



void game(){
	run();
}

int main(){
	game();
	return 0;
}
```

