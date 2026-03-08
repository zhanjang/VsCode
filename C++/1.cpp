#include<iostream>
void test(const int &,int &);
void test(float &,int &b);
int main()
{
    int a1 = 5,a2 = 2;
    test(a1,a2);
    float b1 = 5.0;int b2 = 2;
    test(int (b1),b2);
}
void test(const int &a,int &b)
{
    b+=a;
}
void test(float &a,int &b)
{
    a-=b;
}