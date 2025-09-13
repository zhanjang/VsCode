#len函数的用法:len（string）其中 string 用于指定要进行长度统计的字符串。
a='http://c.biancheng.net'
len(a)
#使用encode可获取占用的字节数
str1 = "人生苦短，我用Python"
len(str1.encode())
#encode后面的()可指定编码方式
str1 = "人生苦短，我用Python"
len(str1.encode('gbk'))
#split使用方法:str.split(sep,maxsplit).str：表示要进行分割的字符串；sep：用于指定分隔符，可以包含多个字符。此参数默认为 None，表示所有空字符，包括空格、换行符“\n”、制表符“\t”等。maxsplit：可选参数，用于指定分割的次数，最后列表中子串的个数最多为 maxsplit+1。如果不指定或者指定为 -1，则表示分割次数没有限制。
str = "C语言中文网 >>> c.biancheng.net"
list1 = str.split() #使用默认分割符
list2 = str.split('>>>') #使用>>>为分隔符
