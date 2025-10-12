def myif(num1):#选择语句
    if type(num1) == int:
        return "数字"
    else:
        return "非数字"
def mymatch(num4):#选择语句
    match num4:
        case 1:
            return "星期一"
        case 2:
            return "星期二"
        case _:#匹配任意字符
            return "非公历日期"
def mywhile(num2):#while循环
    while num2 < 10:
        print(num2)
        num2 +=1
    return "循环完成"
def myfor(num3):#for循环
    a = 0
    for i in range(1,num3+1):
        a += i
    return a