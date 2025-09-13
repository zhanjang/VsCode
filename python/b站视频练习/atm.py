money = 500000000
e = 0
name = str(input('请输入姓名'))
def a():#查询余额
    print("-----------查询余额-----------")
    print(f'{name}的余额为{money}')
    d()
def b():#取款
    print("----------取款----------")
    money_qu = int(input('其输入取款金额'))
    global money
    money -= money_qu
    print(f'取款成功，您当前余额为{money}')
    d()
def c():#存款
    print('----------存款----------')
    money_exit = int(input('请输入存款金额'))
    global money
    money += money_exit
    print(f'存款成功，您当前余额为{money}')
    d()
def d():#主菜单
    print('-----------主菜单----------')
    print('欢迎你，请选择你要进行的操作') 
    print('查询余额\t[输入1]')
    print('取款\t\t[输入2]')
    print('存款\t\t[输入3]')
    print('退出\t\t[输入4]')
while True:
    if e == 0:
        d()
        e += 1
    caozuo = int(input('请输入您的操作:'))
    if caozuo == 1:
        a()
    elif caozuo == 2:
        b()
    elif caozuo == 3:
        c()
    else:
        break