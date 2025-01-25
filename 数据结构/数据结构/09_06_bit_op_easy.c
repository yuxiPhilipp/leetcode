//
//  09_06_bit_op_easy.c
//  数据结构
//
//  Created by xiy3 on 2025-01-21.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#include "09_06_bit_op_easy.h"

void run_bit_op_0504_base_8 (int num)
{
    // 100 > 144
    // 100/8 = 12 ..4  12/8 = 1 .. 4   1/8  = 0.. 1
    
}
void run_bit_op_0504_base_7 (int num)
{
    // 8 --? 11  9 ---12   1 2
    // 14--20 : 7 0; 1 0;
    // 100
    bool negative = FALSE;
    if (num < 0 ) {
        negative == TRUE;
    }
    int n = num;
    int base_i = 0;
    char *p_mem = (char*)calloc(sizeof(char) * 100,0 );
    int i_mem =0 ;
    
    while (n >= 7) {
        printf("save %d\n", n%7);
        p_mem[i_mem++] = '0' + n%7;
        n = n/7;
        
    }
    printf("first digit=%d\n", n);
    p_mem[i_mem] = '0' + n;
    
    printf("result: %s\n", p_mem);
    
            
}
void run_bit_op_0190 ()
{
    
}
void run_bit_op_easy(void)
{
//    run_bit_op_0504_base_7(-7);
    run_bit_op_0190 ();
}
