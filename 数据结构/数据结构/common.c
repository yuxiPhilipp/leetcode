//
//  common.c
//  数据结构
//
//  Created by xiy3 on 2025-01-17.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#include <stdio.h>
void array_print_int (int *arr, int len)
{
    printf("\n");
//    printf("\narray %p, &array %p, array + 1 =%p, &arr + 1 = %p\n",
//           arr, &arr, arr+1 , &arr + 1);
    int i;
    for (i =0; i< len; i++) {
        printf (" %d ", arr[i]);
    }
    printf("\n");
}
void array_2_dimension_print_int (int **arr, int arr_len_step, int arr_len_row)
{
    int i_s, i_r;
    printf("sizeof(int)=%d\n", sizeof(int));
    printf("array %p, &array %p, array + 1 =%p, &arr + 1 = %p, "
           "array[0][1]=%d, array[0][2]=%d \n",
           arr, &arr, arr+1 , &arr + 1,
           *((*arr) + 1), *((*arr) +2));
    for(i_r =0 ; i_r<arr_len_row;  i_r++){
        for(i_s =0; i_s< arr_len_step; i_s ++){
            printf(" %d ", *(((int *)(arr + i_r))+ i_s));
        }
    }
    printf("\n");
}
