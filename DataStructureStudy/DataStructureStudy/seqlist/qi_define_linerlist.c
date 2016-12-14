//
//  qi_define_linerlist.c
//  DataStructureStudy
//
//  Created by zhangqi on 14/12/2016.
//  Copyright © 2016 MaxwellQi. All rights reserved.
//

#include "qi_define_linerlist.h"

// 初始化顺序表
SeqList SeqListInit()
{
    SeqList L;
    L.last = 0;  // 顺序表长度为 0
    return L;
}

// 查找元素
// 在顺序表 L 中查找值为 x 的元素。若查找成功，则返回它在顺序表中的位置，否则返回 -1
int SeqListLocate(SeqList L,int x)
{
    int i = 1;
    while (i < L.last && L.data[i-1] != x) {
        i++;
    }
    return i < L.last ? i : 0;
}

// 判断线性表是否有元素
int IsEmpty(SeqList L)
{
    return L.last == 0 ? TRUE : FALSE;
}

// 插入运算
SeqList SeqListInsert(SeqList L,int i,int x)
{
    int j;
    if(L.last == MAXSIZE)
    {
        printf("表满\n");            // 表满，退出
        exit(0);
    }
    if(i < 1 || i > L.last + 1)
    {
        printf("插入位置错误\n");     // 插入位置错，退出
        exit(0);
    }
    for(j = L.last - 1; j >= i - 1; j--)
    {
        L.data[j + 1] = L.data[j];  // 第i个位置后的数组元素逐一后移
    }
    L.data[i - 1] = x;              // 新元素插入到第i个位置
    L.last++;                       // 顺序表长度增1
    return (L);                     // 返回插入元素后的顺序表
}

// 删除运算
SeqList SeqListDelete(SeqList L,int i)
{
    int j;
    if (i < 1 || i > L.last) {
        printf("位置非法\n");
        exit(0);
    }
    for (j = i; j <= L.last -1; j++) {
        L.data[j -1]  = L.data[j];
    }
    L.last--;
    return (L);
}

// 合并非递减有序顺序表
SeqList SeqListMerge(SeqList Sla, SeqList Slb)
{// 将非递减有序的顺序表Sla和Slb合并成一个新的顺序表Slc，Slc也是非递减有序的
    // 初始化
    SeqList Slc;
    Slc.last = 0;
    int i = 0, j = 0, k = -1;
    while(i < Sla.last && j < Slb.last)     // Sla和Slb均非空
    {
        if(Sla.data[i] <= Slb.data[j])
        {
            Slc.data[++k] = Sla.data[i++];  // Sla中元素插入Slc
        }
        else
        {
            Slc.data[++k] = Slb.data[j++];  // Slb中元素插入Slc
        }
    }
    while(i < Sla.last)
    {
        Slc.data[++k] = Sla.data[i++];      // Slb已空，将Sla表的剩余部分复制到新表
    }
    while(j < Slb.last)
    {
        Slc.data[++k] = Slb.data[j++];      // Sla已空，将Slb表的剩余部分复制到新表
    }
    Slc.last = k + 1;
    return (Slc);
}

// 展示SeqList的内容
void ShowData(SeqList L)
{
    int i = 0;
    for (; i < L.last; ++i)
    {
        printf("%d\t", L.data[i]);
    }
    printf("\n");
}

