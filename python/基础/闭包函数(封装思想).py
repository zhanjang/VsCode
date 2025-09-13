def a (num1):
    def b (num2):
        return num2**num1
    return b
i = a(3) #a函数的结果是把b函数和num1变量一起赋予了i
print(i(5))