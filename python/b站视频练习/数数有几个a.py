name = str(input('输入内容'))
i = 0
d = str(input('要数的字母'))
for c in name:
   if c == d:
       i +=1
print(f'文中有{i}个{d}')