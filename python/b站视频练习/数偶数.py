b = int(input('数字'))
c = 0
for a in range(1,b):
    if a % 2 == 0:
        c +=1
print(f'有{c}个偶数')    