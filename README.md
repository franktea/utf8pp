# utf8pp
utf8编码在C++中的操作方法示例

运行方法：
```
git clone https://github.com/franktea/utf8pp;
mkdir -p build;
cd build;
cmake ..;
make
```

utf8编码：
```
1字节 0xxxxxxx
2字节 110xxxxx 10xxxxxx
3字节 1110xxxx 10xxxxxx 10xxxxxx
4字节 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
5字节 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
6字节 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
```

鉴于以上规律，将utf8字节流切分成字符，可以使用ranges::views::chunk_by，切分以后，就可以求字符串长度、以及获得第n个字符，以及实现substr。

获取长度，用ranges::distance(v);

获取第N个字符，用v | drop(N-1) | take(1);

substr(N, M)，用v | drop(N-1) | take(M);