//直接插入排序,直接抓取某个元素,与前面的元素进行比较,进行插入
int main()
{
    int a[8] = {12,37,25,24,10,69,58,23};
    int len,i,j,temp = 0;
    len = sizeof(a)/sizeof(int);
    for ( i = 1; i < len ; i++)
    {
        temp = a[i];
        for (j = i-1; j>=0 && temp < a[j];j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }
}