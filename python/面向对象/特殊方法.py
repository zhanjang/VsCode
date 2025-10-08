class car:#面向对象里面的方法主要用于实现自定义的各种功能
    _a = None
    #对象创建与初始化
    def __new__(cls):#先于__init__执行,一般很少使用,多用于控制单个实例时使用,若__init__须要传入参数,则__new__需要*args, **kwargs来接收传入数据,否则会报错
        if not cls._a:
            cls._a = super().__new__(cls)
        return cls._a
    def __init__(self):#初始化实例对象,用于设置所有实例都具有的属性,一般不初始化方法
        pass
    def __del__():#在调用del时,输出内容,不可靠,若存在实例则不会输出,需要全部实例都销毁才输出
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
    #容器行为,只能操作数据容器时被响应
    def __len__(self):#调用len函数时使用
        pass
    def __getitem__(self,key):#删除可变数据容器内的数据时调用
        pass
    def __setitem__(self, key, value):#设置容器内的数据时调用
        pass
    def __delitem__(self, key):#删除容器内的数据
        pass
    def __contains__(self, item):#检查元素是否在数据容器内
        pass