//
//  qi_define_linerlist.h
//  DataStructureStudy
//
//  Created by zhangqi on 14/12/2016.
//  Copyright © 2016 MaxwellQi. All rights reserved.
//

#ifndef qi_define_linerlist_h
#define qi_define_linerlist_h

#include <stdio.h>

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0

typedef  struct {
    int data[MAXSIZE];
    int last;
}SeqList;

SeqList SeqListInit();
SeqList SeqListInsert(SeqList L,int i,int x);
void ShowData(SeqList L);
SeqList SeqListDelete(SeqList L,int i);
SeqList SeqListMerge(SeqList Sla, SeqList Slb);

#endif /* qi_define_linerlist_h */
