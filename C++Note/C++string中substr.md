```
string substr(size_type _Off = 0,size_type _Count = npos) const;
```

###<font size=3 color=#B8860B>参数</font>
_Off：所需的子字符串的起始位置。字符串中第一个字符的索引为 0,默认值为0。
_Count：复制的字符数目。
返回值：一个子字符串，从其指定的位置开始。

##示例
```
string str("helloworld");
string strSub = str.substr(0, 5);
```
><font size=3 color=#8A2BE2>若pos的值超过了string的大小，则substr函数会抛出一个out_of_range异常；若pos+n的值超过了string的大小，则substr会调整n的值，只拷贝到string的末尾。</font>
