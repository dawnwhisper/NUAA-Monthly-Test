 题目难度：签到

打开文件发现是一串base64编码 解码结果如下：
```U2FsdGVkX1/v0XFbWrFpWM71abdM0LxynS5sItvv3FB7xZPSP98= keyisasuri```

可以看到又嵌套了一层有key存在的编码，结合题目47只兔子，兔子？好像有一种rabbit密码需要key
在线网站进行解密，解密网址`https://www.sojson.com/encrypt_rabbit.html`
解密结果如下
```?F224E7L$@toDJ0C`89EbN```
至此，题目中47还没用到，结合解密结果联想到rot47

使用在线网站解密`https://www.qqxiuzi.cn/bianma/ROT5-13-18-47.php`
即可得到flag`nuaactf{SoE@sy_r1ght3}`