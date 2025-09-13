#通过构造函数创建空 bytes
b1 = bytes()
#通过空字符串创建空 bytes
b2 = b''

#通过b前缀将字符串转换成 bytes
b3 = b'http://c.biancheng.net/python/'
print("b3: ", b3)
print(b3[3])
print(b3[7:22])

#为 bytes() 方法指定字符集
b4 = bytes('C语言中文网8岁了', encoding='UTF-8')
print("b4: ", b4)

#通过 encode() 方法将字符串转换成 bytes
b5 = "C语言中文网8岁了".encode('UTF-8')
print("b5: ", b5)
#通过 decode() 方法将 bytes 转换成字符串
str1 = b5.decode('UTF-8')
print("str1: ", str1)