#实例方法用于要调用实例属性的方法,静态方法一般不调用实例属性,多用于计算等
class car:
    _a = None
    #对象创建与初始化
    def __new__(cls):#先于__init__执行,一般很少使用,多用于控制单个实例时使用,若__init__须要传入参数,则__new__需要*args, **kwargs来接收传入数据,否则会报错
        if not cls._a:
            cls._a = super().__new__(cls)
        return cls._a
    def __init__(self):#初始化实例对象,用于设置所有实例都具有的属性,一般不初始化方法
        pass
    def __del__():#在调用del时,输出内容,不可靠,若存在实例jian
        print("已销毁")
    #数值运算
    def __add__(self):#在调用加法时按照方法里面的内容进行输出
        pass
    def __sub__(self):#减法使用
        pass
    def __mul__(self):#乘法使用
        pass
    def __truediv__(self):#除法使用
        pass
    def __eq__(self):#判断等于使用
        pass
    def __lt__(self):#判断大于使用
        pass
    def __abs__(self):#调用abs函数时使用
        pass