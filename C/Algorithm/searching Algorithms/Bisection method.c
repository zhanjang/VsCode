//二分法查找,对排序好的数组进行快速查找
#include <stdio.h>
int main()
{
    int num;
    printf("输入要查找的数字");
    scanf("%d",&num);
    int a[8] = {10,12,23,24,25,37,58,69};
    int left = 0,right = sizeof(a) / sizeof(int) - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] < num)
        {
            left = mid + 1;
        }
        else if (a[mid] > num)
        {
            right = mid -1;
        }
        else if (a[mid] == num)
        {
            printf("找到%d了,下标为%d",num,mid);
            break;
        }
    }
    if (left > right)
    {
        printf("找不到%d",num);
    }
    return 0;
}