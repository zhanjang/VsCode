num=5
a = int(input('请输入数字'))
if a == num:
    print('你猜对了')
else:
    if a>num:
        print('你猜错了，数字大了')
    else:
        print('你猜错了，数字小了')
    b=int(input('再猜一次吧'))
    if b == num:
        print('你猜对了')
    else:
        if b>num:
            print('你猜错了，数字大了')
        else:
            print('你猜错了，数字小了')
        c=int(input('再给你一次机会'))
        if c == num:
            print('你猜对了')
        else:
            print('你失败了，游戏结束')