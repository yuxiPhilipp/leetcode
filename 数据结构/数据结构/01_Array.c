//
//  01_Array.c
//  数据结构
//
//  Created by xiy3 on 2025-01-05.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#include "01_Array.h"
#define ARRAY_LEN 10
void array_print (int *arr, int len)
{
    int i;
    printf("[");
    for (i =0 ; i < len; i++) {
        if (i == 0){
            printf("%d", arr[i]);
        } else {
            printf(", %d", arr[i]);
        }
    }
    printf("]\n");
}
void array_sort_01_bubble (int *arr, int len)
{
    
}

void array_sort_02_selection (int *arr, int len)
{
    // small--->big
    int i ,j;
    for (i =0;i < len-1; i ++) {
        for (j = i +1;j < len; j ++ ) {
            if (arr[i] > arr[j] ) {
                arr[i] ^=arr[j];
                arr[j] ^=arr[i];
                arr[i] ^=arr[j];
            }
        }
    }
}
int array_search_01_binary (int *arr, int len, int obj)
{
    // small--->big
    int ret_subscript = -1; //subscription can't be -1; -1 means not found.
    int left =0, right = len -1, mid =0 ;
    
    while (left < right) {
        mid = (left + right) /2;
        if (obj > arr[mid]) {
            //search right part
            left = mid+1;
            
        } else if (obj == arr[mid]) {
            // find it
            ret_subscript = mid;
            break;
        } else if (obj < arr[mid]) {
            // search left part
            right = mid -1;
        }
    }
    return ret_subscript;
}
void run_array () {
    
    int number[ARRAY_LEN] = {2,3,6,7,8,1,4,5,9,0};
    array_print(number, ARRAY_LEN);
    
    array_sort_02_selection(number, ARRAY_LEN);
    array_print(number, ARRAY_LEN);
    
    int ret_subscript=0, search_obj = 1;
    ret_subscript = array_search_01_binary(number, ARRAY_LEN, search_obj);
    if (ret_subscript == -1) {
        printf("search %d in the array, but not found.\n",search_obj);
    } else {
        printf("search %d in the array, and found it in subscrip %d.\n",search_obj,ret_subscript );
    }
    
}
