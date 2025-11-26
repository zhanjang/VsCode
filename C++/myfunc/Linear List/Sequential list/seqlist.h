#ifndef SEQLIST_H
#define SEQLIST_H
//线性表
/*检查头文件是否被引入,反正反复引用*/
typedef int Seqtype;//方便后续进行元素类型的替换
class Seqlist
{
private:
    size_t m_num;//线性表具有的元素个数
    size_t m_capacity;//线性表能存储的元素个数
    Seqtype *m_data;//线性表的首元素地址
public:
    Seqlist(int num = 10);//构造函数,创建对象时使用
    ~Seqlist();//析构函数,销毁时自动调用
    void Clear();//将线性表的元素个数清空
    size_t Size();//查询线性表的元素个数
    size_t Capacity();//查询线性表的最大容量
    Seqtype Get(int id);//获取线性表中第i个元素
    void Set(int id,Seqtype d);//将第id位置的元素设置为d
    void Insert(int id,Seqtype d);//在id位置插入元素d
    Seqtype Remove(int id);//删除id位置的元素,并返回这个元素值
    int Index(int key);//返回值为key的位置
};
#endif