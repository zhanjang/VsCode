#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <stdio.h>
typedef struct binarytree Btree;
typedef int Btype;
struct tree
{
    Btype data;
    struct tree* TreeRight;
    struct tree* TreeLeft;
};

struct binarytree
{
    size_t height;
    struct tree* treeroot;
};
Btree* btree_creat();//创建一个二叉树的头
void btree_destory(Btree* tree);//删除一个二叉树
void btree_clear(Btree* tree);//清空二叉树里面的所有元素
size_t btree_height(Btree* tree);//获取二叉树的高度
size_t btree_size(Btree* tree);//获取二叉树的元素个数
#endif