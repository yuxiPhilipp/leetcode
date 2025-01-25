//
//  01_array_easy.c
//  数据结构
//
//  Created by xiy3 on 2025-01-17.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#include "01_array_easy.h"
#include "common.h"


void arr_0189_rotate_array (int * nums, int nums_len, int k, int * ret_out)
{
    int i, subsript;
    
    for (i =0; i< nums_len; i++) {
        // nums[i] should be in subscript of  i+k
        subsript = (i + k)% nums_len;
        ret_out[subsript]  = nums[i];
        //printf("get nums: %d\n",  nums[subsript]);
        
    }
    array_print_int(ret_out, nums_len);
}
void arr_0189_test (void)
{
    int nums[] = {1,2,3,4,5,6,7}, k = 3;
    int ret_nums[7] = {0};
    arr_0189_rotate_array(nums, sizeof(nums)/sizeof(int), k, ret_nums);
    array_print_int(ret_nums, 7);

}
void arr_0066_plus_one (int * arr, int arr_len, int ** out_mem, int *out_len)
{
    int i = arr_len -1;
    int sum, carry = 0  ;
    int buf_tmp[SIZE_BUF] = {0};
    int *ret_mem = NULL;
    
    while (i >=0) {
        if (i == arr_len -1) {
            sum = arr[i] + 1;
        } else {
            sum = arr[i] + carry;
        }
        
        carry = sum/10;
        
        // update arr
        buf_tmp[i] = sum%10;
        
        i --;
        sum =0 ;
    }
    
    array_print_int(buf_tmp,arr_len );
    if (carry == 1) {
        // 进位
        ret_mem = (int*)malloc(sizeof(int) * (arr_len+1));
        *ret_mem = 1;
        memcpy(ret_mem+1, buf_tmp, sizeof(int)*arr_len);
        *out_len = arr_len +1;
    } else {
        // fill the ret_out directly
        ret_mem = (int*)malloc(sizeof(int) * arr_len);
        memcpy(ret_mem, buf_tmp, arr_len);
        *out_len = arr_len ;
    }
    *out_mem =ret_mem;
}
void arr_0066_test (void)
{
    int digits_1[] = {9,9,9};
//    int ret_out[SIZE_BUF] = {0};
    int *out_mem , out_len;
    arr_0066_plus_one(digits_1, sizeof(digits_1)/sizeof(int),
                      &out_mem, &out_len);
    array_print_int(out_mem, out_len);
    
    
    if (out_mem) {
        free(out_mem);
        out_mem = NULL;
    }
}

void arr_0724_find_pivot_index (int* nums, int nums_len)
{
    int i_head = 0 , i_tail = nums_len-1;
    int sum_head =0, sum_tail =0;
    
    while (i_head < i_tail) {
        if(sum_head == 0) {
            sum_head += nums[i_head];
            i_head ++;
        }
        printf("1 left sum =%d, right sum = %d; but i_head=%d, i_tail=%d.\n",
               sum_head, sum_tail, i_head, i_tail);

        if (sum_head > sum_tail) {
            sum_tail += nums[i_tail];
            i_tail --;
        }
        printf("2 left sum =%d, right sum = %d; but i_head=%d, i_tail=%d.\n",
               sum_head, sum_tail, i_head, i_tail);


        if (sum_head < sum_tail) {
            sum_head += nums[i_head];
            i_head ++;
        }
        printf("3 left sum =%d, right sum = %d; but i_head=%d, i_tail=%d.\n",
               sum_head, sum_tail, i_head, i_tail);


        if (sum_head == sum_tail) {
            // 预判失误if ((i_head + 1) == (i_tail -1))
            if(i_head == i_tail)
            {
                printf("found the pivot index: %d\n", i_head +1 );
            } else {
                printf("left sum == right sum; but i_head=%d, i_tail=%d.\n",
                       i_head, i_tail);
            }
        }
    }
}
void arr_0724_test (void)
{
    int n1[] = {1, 7, 3, 6, 5, 6};
    int n2[] = {1,2,3};
    int n3[] = {1,2,3,4};
    arr_0724_find_pivot_index(n1,  sizeof(n1)/sizeof(int));
    arr_0724_find_pivot_index(n2,  sizeof(n2)/sizeof(int));
    arr_0724_find_pivot_index(n3,  sizeof(n3)/sizeof(int));
}

void arr_0485_max_consecutive_ones (int *nums, int nums_len)
{
    // 准备一个窗口 2个大小, [0,1] 分段,计算.
    int i_window = 0;
    int cnt_ret =0, cnt_tmp =0;
    
    while (i_window +1 < nums_len) {
        if (nums[0] == 1) {
            printf("process 1st group as an exception\n");
            while (nums[i_window] == 1) {
                cnt_tmp ++;
                i_window ++;
            }
            printf("cnt_ret: %d, \n",cnt_tmp );

            cnt_ret = cnt_ret>cnt_tmp?cnt_ret:cnt_tmp;
            
        }
        if (nums[i_window] == 0 && nums[i_window+ 1] ==1) {
            printf("find next group\n");
            i_window ++; //move i to 1
            cnt_tmp = 0;
            while (nums[i_window] == 1) {
                cnt_tmp ++;
                i_window ++;
            }
            printf("cnt_ret: %d, \n",cnt_tmp );

            cnt_ret = cnt_ret>cnt_tmp?cnt_ret:cnt_tmp;
        }
        // i_window 瞄到了下一个.
//        i_window ++;// 2 zeros between 1.
    }
    printf("# longest 1: %d\n",cnt_ret );
}
void arr_0485_test(void)
{
    int n1[] = {1,1,0,1,1,1,0,1,1,1,1};
    arr_0485_max_consecutive_ones(n1,  sizeof(n1)/sizeof(int));
}

void arr_0238_product_of_array_except_self(int *nums, int nums_len)
{
    int i , j, tmp_res =1;
    int arr_result[SIZE_BUF] = {0};
    
    for( i =0; i< nums_len; i++) {
        for ( j =0 ;j <nums_len;j++) {
            if (j == i) {
                continue;
            }
            //printf("tmp_res = %d\n", tmp_res);
            tmp_res *= nums[j];
        }
        arr_result[i] = tmp_res;
        tmp_res = 1;
    }
    array_print_int(arr_result, nums_len);
}
void arr_0238_test(void)
{
    int n1[] = {1,2,3,4};
    int n2[]={-1,1,0,-3,3};
    arr_0238_product_of_array_except_self(n1,  sizeof(n1)/sizeof(int));
    arr_0238_product_of_array_except_self(n2,  sizeof(n2)/sizeof(int));

}
void run_array_easy(void)
{
    //arr_0189_test();
    //arr_0066_test();
//    arr_0724_test();
//    arr_0485_test();
    arr_0238_test();
}
