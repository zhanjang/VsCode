a = int( input("Input a: ") )
b = int( input("Input b: ") )
#普通写法
if a>b:
    max = a
else:
    max = b
print(max)
#两者表述等价
max = a if a>b else b
print(max)
#三次嵌套
a = int( input("Input a: ") )
b = int( input("Input b: ") )
print("a大于b") if a>b else ( print("a小于b") if a<b else print("a等于b") )