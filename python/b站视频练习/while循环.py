a = 68
number = 1
type = True
while type:
    c = int(input('输入你猜的数字'))
    if a == c:
        type = False
    else:
        number += 1
        if c > a:
            print('你猜的数字大了')
        else:
            print('你猜测的数字小了')
print(f'你猜对了,你用了{number}次机会')