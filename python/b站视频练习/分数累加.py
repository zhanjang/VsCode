a = int(input('输入数字'))
b = 1
for i in range(1,a):
    c = 1/(2*i+1)
    if i%2 == 0:
        b += c
    if i%2 == 1:
        b -= c
print('%.2f'%b)