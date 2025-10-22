int my_strlen(char *arr)
{
    if (*arr != 0)
    {
        return 1 + my_strlen(arr + 1);
    }
    else 
    {
    return 0;
    }
}
int main()
{
    char arr1[] = "abc";
    int a = my_strlen(arr1);
    return 0;
}