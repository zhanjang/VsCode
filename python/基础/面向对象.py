class car:
    _a = None
    def __new__(cls):#先于__init__执行,一般很少使用,多用于控制单个实例时使用,若__init__须要传入参数,则__new__需要*args, **kwargs来接收传入数据,否则会报错
        if not cls._a:
            cls._a = super().__new__(cls)
        return cls._a
    def __init__(self):#初始化实例对象,用于设置所有实例都具有的属性,一般不初始化方法
        pass