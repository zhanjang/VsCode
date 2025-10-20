import time
import sys
a = list("hello world")
b = list("###########")
left = 0
right = len(a) - 1
while (left <= right):
    b[left] = a[left]
    b[right] = a[right]
    for i in b:
        print(i,end="")
        sys.stdout.flush()
    print("",end="\r")
    left += 1
    right -= 1
    time.sleep(1)