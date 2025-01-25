//
//  common.h
//  数据结构
//
//  Created by xiy3 on 2025-01-13.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#ifndef common_h
#define common_h

#include <stdlib.h>
#include <string.h>

typedef int cerrno;
typedef int bool;
#define OK 0
#define ERROR 1
#define E_FULL 2
#define E_EMPTY 3
#define E_INVALID_OP 4
#define E_NOMEM 5

#define SIZE_STACK 10
#define SIZE_BUF 100
#define FALSE 0
#define TRUE 1

void array_print_int (int *arr, int len);
void array_2_dimension_print_int (int **arr, int arr_len_step, int arr_len_row);

#endif /* common_h */
