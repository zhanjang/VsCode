#include <stdio.h>
//结构体指针
struct stu
{
    char *name;
    int num;
    int age;
}stu1 = {"zha",1,18};
struct stu *pstu = &stu1;//结构体名与数组名不同,故需要取址符号
//两种方式访问结构体指针的数据
int main()
{
    printf("%s,%02d,%d\n",(*pstu).name,(*pstu).num,(*pstu).age);//通过指针访问必须要()与运算优先有关系
    printf("%s,%02d,%d",pstu->name,pstu->num,pstu->age);//通过->访问
}