#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int num;
    char name[7];
    int graed;
};
struct student *stu = NULL;
int stu_count = 0;
int b = 1;
void luru()
{
    int a = 0, id = 0;
    float add = 0;
    printf("输入学生数量: ");
    scanf("%d",&a);
    if (stu) 
    {
        free(stu);
        stu = NULL;
        stu_count = 0;
    }

    stu = malloc(sizeof *stu * a);
    if (!stu) 
    {
        perror("malloc");
        exit(1);
    }
    stu_count = a;

    for (id = 0; id < a; id++)
    {
        memset(&stu[id], 0, sizeof stu[id]);

        printf("输入第%d个学生的学号 姓名 成绩（空格分隔）: ", id + 1);
        if (scanf("%d %6s %d", &stu[id].num, stu[id].name, &stu[id].graed) != 3)
        {
            printf("输入格式错误，停止录入\n");
            break;
        }
        add += stu[id].graed;
        printf("%d位学生录入完毕, 学号%d, 姓名%s, 成绩%d\n",id + 1, stu[id].num, stu[id].name, stu[id].graed);
    }
    if (stu_count > 0)
        printf("%d位学生的平均成绩是%.2f\n", stu_count, (add / stu_count));
    b = 1;
}
void search()
{
    int stuid = 0,d = 1;
    printf("输入要查找的学号:");
    scanf("%d",&stuid);
    for (int i = 0; i < stu_count;i++) 
    {
        if (stuid == stu[i].num)
        {
            printf("学生%d,姓名%s,成绩%d\n",stu[i].num, stu[i].name, stu[i].graed);
            d = 0;
        }
    }
    if (d)
    {
        printf("未找到学生%d\n",stuid);
    }
    b = 1;
}
int main()
{
    do
    {
        int c = 0;
        printf("欢迎使用系统,学生成绩录入输入1,查找学生信息输入2,退出输入0:");
        scanf("%d", &c);
        if (c == 1) luru();
        else if (c == 2) search();
        else if (c == 0) 
        {
            b = 0; 
        }
    } while (b);
    if (stu) {
        free(stu);
        stu = NULL;
        stu_count = 0;
    }
    return 0;
}