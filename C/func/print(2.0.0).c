//一个字符串,两边向中间打印
#include <stdio.h>
#include <windows.h>
int main()
{
    char arr1[] = "Hello, World!";
    char arr2[] = "#############";
    int left = 0, right = sizeof(arr1) / sizeof(arr1[0]) - 2;
    while (left <= right)
    {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        printf("%s\r", arr2);
        left++;
        right--;
        Sleep(500);
    }
    return 0;
}