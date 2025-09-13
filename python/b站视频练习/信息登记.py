class Student:
    def __init__(self,name,age,dersser):
        self.name = name
        self.age = age
        self.dersser = dersser
stu = ['stu1','stu2','stu3','stu4','stu5','stu6','stu7','stu8','stu9','stu10']
a = 0
for i in stu:
    print(f'你当前正在录入第{i}位人的信息')
    name = str(input('请输入姓名'))
    age = int(input('请输入年龄'))
    dersser = str(input('请输入住址'))
    i = Student(name,age,dersser)
    print(f'第{i}位学生录入完毕,姓名为{i.name},年龄为{i.age},住址为{i.dersser}')
    print(stu.name)