a=3
if int(input('请输入第一次猜想的数字')) == a:
    print('你猜对了')
elif int(input('猜错了，再猜一次')) == a:
    print('你猜对了')
elif int(input('又错了，再猜一次')) == a:
    print('你猜对了')
else:
    print(f'你又猜错了，我想的是{a}')