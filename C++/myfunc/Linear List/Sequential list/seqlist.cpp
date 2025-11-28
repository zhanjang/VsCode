#include <stdlib.h>
#include <stdio.h>
#include "seqlist.h"
Seqlist::Seqlist(int num)//构造函数,创建对象时自动调用,创建一个能存num个数据的线性表
{
    m_num = 0;
    m_capacity = num;
    m_data = (Seqtype *)malloc(sizeof(Seqtype)*num);
}
Seqlist::~Seqlist()//析构函数,销毁时自动调用
{
    free(m_data);
}
void Seqlist::Clear()
{
    m_num = 0;//将num设置为0,表示所有元素都能替换
}
size_t Seqlist::Size()
{
    return m_num;//返回存储元素的个数
}
size_t Seqlist::Capacity()
{
    return m_capacity;//返回能存储的元素的个数
}
Seqtype Seqlist::Get(int id)
{
    return m_data[id];//返回id处的元素
}
void Seqlist::Set(int id,Seqtype d)
{
    if (id < 0 || id >=m_capacity)
    {
        return;
    }
    else if (id >= m_num)
    {
        m_data[m_num] = d;
        m_num++;
    }
    else
    {
        m_data[id] = d;
    }
}
void Seqlist::Insert(int id,Seqtype d)
{
    Seqtype *temp = m_data;
    if (id >= 0 && id < m_capacity)
    {
        if (m_capacity < m_num + 1)
        {
            m_capacity *= 2;
            temp = (Seqtype *)malloc(sizeof(Seqtype)*m_capacity);
            for(size_t i = 0; i < m_num; i++)
            {
                temp[i] = m_data[i];
            }
            free(m_data);
            m_data = temp;
        }
        for (size_t i = m_num; i > id; i--)
        {
            m_data[i] = m_data[i - 1];
        }
        m_data[id] = d;
        m_num++;
    }    
}
Seqtype Seqlist::Remove(int id)
{
    if (id >= 0 && id < m_num)
    {
        Seqtype res = m_data[id];//创建一个变量存储id处的元素
        for (size_t i = id + 1; i < m_num; i++)
        {
            m_data[i - 1] = m_data[i];
        }
        m_num--;
        return res;
    }
}
int Seqlist::Index(Seqtype key)
{
    for (size_t i = 0;i < m_num;i++)//循环查找,具体查找方法可以进行替换
    {
        if (m_data[i] == key)
        {
            return i;//查找成功则返回对应地id
        }
    }
    return -1;//如果key不存在则返回-1
}