import os.path
def count(file):
    txt = open(file,"r",encoding="utf-8")
    unin = {chr(i): 0 for i in range(65, 91)}
    for line in txt:
        for word in line:
            if word.isalpha():
                upperword = word.upper()
                unin[upperword] +=1
    a = os.path.split(file)
    print(f'文件{a[1]}的字母统计结果为')
    print('字母\t次数')
    for key,value in unin.items():
        if value > 0:
            print(f'{key}\t{value}')
count('D:\\VsCode\\test.txt')