#本文件内容为容器都具有的基础操作
#通过索引访问元素
a = [1,2,3,4,5]
print(a[0])  #输出1
print(a[-1]) #输出5
#通过切片访问元素
print(a[1:3]) #输出[2,3]
print(a[:3])  #输出[1,2,3]
print(a[3:])  #输出[4,5]
#加法操作
b = [6,7,8]
c = a + b
print(c) #输出[1,2,3,4,5,6,7,8]
#乘法操作
d = a * 2
print(d) #输出[1,2,3,4,5,1,2,3,4,5]
#成员资格操作
print(3 in a)  #输出True
print(9 in a)  #输出False
#计算长度
print(len(a))  #输出5
#最大值,最小值,实质为对比ASCII码
print(max(a))  #输出5
print(min(a))  #输出1