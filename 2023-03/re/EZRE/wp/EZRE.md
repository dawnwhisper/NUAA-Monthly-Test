将exe拖入ida

![](https://pic.imgdb.cn/item/64400e920d2dde5777877f16.jpg)

看起来非常复杂，
但是要输入s，我们跟踪一下s

![](https://pic.imgdb.cn/item/64400f9f0d2dde577788a8a7.jpg)

发现就是跟a[i]异或跟v3进行对比，
于是我们查看a[i],
![](https://pic.imgdb.cn/item/644010200d2dde57778962f9.jpg)

发现a数组是rand的，且随机种子固定，于是我们动态调式出a数组，
![](https://pic.imgdb.cn/item/644010d90d2dde57778a644a.jpg)

于是写出exp
```cpp
#include<bits/stdc++.h>
using namespace std;

char v[30]={2,57,56,81,107,124,26,73,7,19,7,38,52,80,22,93,63,92,44,105,72,124,40,30,2};
char a[30]={0x64, 0x55, 0x59, 0x36, 0x10, 0x25, 0x2A, 0x3C, 0x58, 0x78, 0x69, 0x16, 0x43, 0x0F, 0x62, 0x35, 0x0C, 0x3, 0x58, 0x1B, 0x3D, 0x8, 0x40, 0x3F, 0x7F};
int main(){
	for(int i=0;i<30;i++)
		cout<<(char)(a[i]^v[i]);
	return 0;
}
```

flag{Y0u_kn0w_th3_truth!}
本题考查调用跟动态调试，光分析代码比较复杂全是没用的代码
