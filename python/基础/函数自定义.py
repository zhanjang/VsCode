def Add(x,/,y,*,z):#/表示前面的只能用位置传参,/和*之间的表示支持位置和关键字两种传参方式,*后面的表示只接受关键字传参
    return x+y+z
print(Add(2,3,z=4))
print(Add(2,y=3,z=4))
che = lambda a,b:a*b
print(che(3,4))