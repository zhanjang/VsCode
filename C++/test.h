#ifndef TEST_H
#define TEST_H
class Stock
{
private:
    int shares;
    double share_val;
    double total_val;
    void set_tot()
    {
        total_val = shares*share_val;
    }
public:
    void acquire(int s,double pr);
    void buy(int num,double price);
    void sell(int num,double price);
    void update(double price);
    void show();
};
#endif