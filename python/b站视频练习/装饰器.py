def outer(func):
    def inter():
        print(1)
        func()
        print(2)
    return inter
@outer
def sleep():
    import time
    time.sleep(5)
sleep()