from PIL import Image
import time
time1 = time.perf_counter()
a = Image.open()#填入文件路径
c = [0,0,80,80]
for i in range(1,197):
    b = a.crop(tuple(c))
    b.save()#填入文件地址
    if c[2] < 1120 and c[3] < 1120:
        c[0] += 80
        c[2] = c[0] + 80
        c[3] = c[1] + 80
    elif c[2] == 1120:
        c[0] = 0
        c[1] += 80
        c[2] = c[0] + 80
        c[3] = c[1] + 80
    else:
        c[0] += 80
        c[2] = c[0] + 80
        c[3] = c[1] + 80
time2 = time.perf_counter()
print("用时%.6f"%(time2 - time1))