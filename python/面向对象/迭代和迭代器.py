#迭代对象和迭代器
#迭代器是执行迭代对象的对象
a = iter([1,2,3])#返回迭代对象
print(next(a))#通过next来手动迭代
print(next(a))
print(next(a))
class myrange1:#需要手动传出异常否则会无限迭代
    def __init__(self,strat):
        self.strat = strat
    def __iter__(self):
        return self
    def __next__(self):
        if self.strat <= 0:
            raise StopIteration
        num = self.strat
        self.strat -= 1
        return num
for i in myrange1(5):#这样每次单独获取一个迭代对象故可以多次执行
    print(i)
for i in myrange1(5):
    print(i)

r = myrange1(5)#只获取了一次迭代对象,且第一次已经减到0,故第二次无法执行
for i in r:
    print(i)
for i in r:
    print(i)

class myrange2:#迭代器和对象分离
    def __init__(self,start):
        self.start = start
    def __iter__(self):
        return myrange2iterator(self.start)
class myrange2iterator:
    def __init__(self,start):
        self.start = start
    def __iter__(self):
        return self
    def __next__(self):
        if self.start <= 0:
            raise StopIteration
        num = self.start
        self.start -= 1
        return num
r = myrange2(5)
for a in r:
    print(a)
for a in r:
    print(a)