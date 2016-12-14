//
//  main.c
//  DataStructureStudy
//
//  Created by zhangqi on 14/12/2016.
//  Copyright © 2016 MaxwellQi. All rights reserved.
//

#include <stdio.h>
#include "qi_define_linerlist.h"

int main(int argc, const char * argv[]) {
    SeqList l = SeqListInit();
    l = SeqListInsert(l, 1, 20);
    l = SeqListInsert(l, 1, 13);
    l = SeqListInsert(l, 1, 10);
    ShowData(l);
    
    int x = SeqListLocate(l, 10);
    x == 1 ? printf("10 在线性表中\n") : printf("10 不在线性表中\n");
    
    l = SeqListDelete(l, 2);
    ShowData(l);
    
    SeqList l2 = SeqListInit();
    l2 = SeqListInsert(l2, 1, 44);
    l2 = SeqListInsert(l2, 1, 23);
    l2 = SeqListInsert(l2, 1, 4);
    ShowData(l2);
    l = SeqListMerge(l, l2);
    ShowData(l);
    return 0;
}
