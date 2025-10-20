//一个字符串,字符逐个打出
#include <stdio.h>
#include <windows.h>
int main() 
{
    char arr1[] = "Hello, World!";
    int len = sizeof(arr1) / sizeof(arr1[0]) - 2;
    for (int i = 0; i <= len; i++) 
        {
            printf("%c", arr1[i]);
            Sleep(1000); // 延时500毫秒
        }
    return 0;
}