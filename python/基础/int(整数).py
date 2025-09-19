#十六进制
hex1 = 0x45
hex2 = 0x4Af
print("hex1Value: ", hex1)
print("hex2Value: ", hex2)

#二进制
bin1 = 0b101
print('bin1Value: ', bin1)
bin2 = 0B110
print('bin2Value: ', bin2)

#八进制
oct1 = 0o26
print('oct1Value: ', oct1)
oct2 = 0O41
print('oct2Value: ', oct2)
#int()函数可以将其他进制的字符串转换为十进制整数
a = '1010'#二进制
b = '12'#八进制
c = "A"#十六进制
#base参数指定字符串的进制
a10 = int(a,base=2)
b10 = int(b,base=8)
c10 = int(c,base=16)
print(a10,b10,c10)