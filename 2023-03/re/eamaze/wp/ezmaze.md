

将exe拖入ida

![](https://pic.imgdb.cn/item/643ffbb60d2dde57776baa90.jpg)

观察到change函数

![](https://pic.imgdb.cn/item/643ffc2e0d2dde57776c625f.jpg)

很明显maze有一个加密

![](https://pic.imgdb.cn/item/644007500d2dde57777c8a43.jpg)

提出数据还原一下maze
根据main里面，是6个一行
```cpp
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
```
得到迷宫
```
* s * * * *
. . * . . .
* . . . * .
* . * * t .
* * * * * .
```
按照main中的逻辑
![](https://pic.imgdb.cn/item/64400a7c0d2dde5777815695.jpg)

i往下，k网上，j往左，l往右，
所以走到t就是flag
flag{kkllillkkj}
