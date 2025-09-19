#字符串格式化有三种方式 []中的参数表示可选参数
#1.使用百分号% %[-][+][0][m][.n]这些为可选参数前三个表示填充方式仅在宽度大于实际长度时有效,m表示宽度,n仅在浮点数中有用,表示保留小数点后n位
#常用的格式化符号 %s字符串(采用str()显示) %r字符串(采用repr()显示) %d十进制整数 %b二进制整数 %o八进制整数 %x十六进制整数 %f浮点数 
tmplate1 = "编号:%09d\t公司名称:%s\t官网:http://www.%s.com"
context1 = (1,"百度","baiadu")
context2 = (2,"阿里巴巴","alibaba")
print(tmplate1 % context1)
print(tmplate1 % context2)
#2.使用format方法 format模板用{[index]:[[fill]align][sign][#][0][width][,][.][type]}创建里面包含一些可选参数
#fill空白表示填充的字符 align表示对齐方式<左对齐 >右对齐 ^中对齐 =数字填充 sign表示数字是否有正负号 [0]当fill没有指定时且width长度大于限制用0填充
#[width]宽度限制 [,]千位分隔符 [.]表示小数点的保留位数 [type]表示输出的数据类型
tmplate2 = "编号:{:>09d}\t公司名称:{:s}\t官网:http://www.{:s}.com"
print(tmplate2.format(1,"百度","baiadu"))
print(tmplate2.format(2,"阿里巴巴","alibaba"))
#3.f字符串格式化 f"字符串{变量名:格式化参数}" 变量名可以是表达式格式化参数与format一样
id = 1
name = "百度"
url = "baidu"
print(f"编号:{id:>09}\t公司名称:{name}\t官网:http://www.{url}.com")