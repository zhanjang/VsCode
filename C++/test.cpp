#include <iostream>
#include "test.h"
void Stock::acquire(int s,double pr)   
{
    if (s < 0)
    {
        std::cout<<"erro\n";
    }
    else
    {
        shares = s;
        share_val = pr;
        set_tot();
    }
}
void Stock::buy(int num,double price)
{
    if (num < 0)
    {
        std::cout<<"erro\n";
    }
    else
    {
        shares += num;
        share_val =price;
        set_tot();
    }
}
void Stock::sell(int num,double price)
{
    if (num < 0)
    {
        std::cout<<"erro\n";
    }
    else if(num > shares)
    {
        std::cout<<"erro\n";
    }
    else
    {
        shares -= num;
        share_val =price;
        set_tot();
    }
}
void Stock::update(double price)
{
    share_val = price;
    set_tot();
}
void Stock::show()
{
    std::cout<<"shares:"<<shares<<'\n'
             <<"price"<<share_val 
             <<"total"<<total_val<<'\n';
}
int main()
{
    Stock compny;
    compny.acquire(20,10.5);
    compny.show();
    compny.buy(20,11.0);
    compny.show();
    compny.update(12.0);
    compny.show();
}