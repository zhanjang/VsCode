#os哭,文件路径操作库
import os
#基础
print(os.name)#获取操作系统的名称,此为类方法
print(os.getcwd())#获取当前的工作目录,此为函数
print(os.chdir())#改变工作目录,影响open等文件的操作
os.open("python\\test1\\test.txt")#打开文件 flags参数用于指定打开模式,
#常用模式 os.O_RDONLY只读,os.O_WRONLY只写,os.RDWR读写,os.CREAT文件不存在时创建,os.APPEND追加
os.close()#关闭文件,末尾必需使用
#目录创建函数
os.mkdir("python\\test1")#创建单个目录,若父目录不存在则会报错,若目录已经被创建同样报错,具有mode参数这个参数只在linux中有用,用于管理文件的权限由八进制int组成
os.makedirs("python\\test2\\test3")#递归创建目录可同时创建具有多从父子关系的目录,其他与mkidr相同