//
//  01_Array.h
//  数据结构
//
//  Created by xiy3 on 2025-01-05.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#ifndef _1_Array_h
#define _1_Array_h

#include <stdio.h>
void run_array(void);
#endif /* _1_Array_h */

/**
 
 
 内存模型: 数组, 连续的内存地址空间.
 数组特点: 数组, 必须知道长度
 
 数组作为参数的演变.
  一维数组, 二维数组
 int n[10] ===fun===> int n[] or *n
 int n[2][10] ====fun====> int n[][10]: 表示是一个数组. 步长是10
 int n[2][10] ====fun====> int **n: 表示是一个 指向一段连续的(int*) 内存 的指针.  *(n+1) 并不表示一个n[1][10]的地址.
 
 数组的内存模型:
 1 stack 模型: 小规模,临时使用; 二维数组 (caller--> callee , 但是callee ---x---> caller stack上的内存带不出来.
 2 heap 模型: 携带大量数据, 再不同的函数之间传递数据.
    尤其是二维数组的增删改差.
 
  对于 array 下标基本就是指针
    [0, ... , size-1] size]
 
 1# 双下标 i_slow [0, size-1]
 本质: 讨论元素之间的关系
 应用: 数组中,两数只和(差, 乘积)
     使用数组 当作大数值. 比如超越64bit 的大整数.
 

  //双下标 for循环结构
 int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
     int i_slow , i_fast ;
     int *p_mem = (int *) malloc(2*sizeof(int));

     for (i_slow =0; i_slow < numsSize -1; i_slow ++) {
         for (i_fast =i_slow + 1; i_fast < numsSize; i_fast++ ) {
             if (nums[i_slow] + nums[i_fast] == target) {
                 p_mem[0] = i_slow;
                 p_mem[1] = i_fast;
                 *returnSize = 2;
                 return p_mem;
             }
         }
     }
     return NULL;
 }
 
 2# 窗口
 本质: 两个节点 指向窗口的 首尾.
 应用:原数组中寻找 一个 子集(也是连续的数组),
 框架结构:
 
 比如53 maximum subarray.
     int h, t , sum, ret_sum  =0 ;
     int window_max_sum , window_h, window_t;

     if (numsSize == 0) {
         return 0;
     } else  if (numsSize == 1) {
         return nums[0];
     }
     // len > 1;
     for ( h = 0; h < numsSize -1; h ++) { // 讨论窗口首尾的所有变化
         sum = nums[h]; // 窗口所有的数值和
         window_max_sum =0;//窗口里最大的数值和
         window_h = -1; // 窗口首位下标为可选变量
         window_t = -1;
         for (t =h +1 ; t < numsSize; t ++) { // 讨论窗口末尾的所有变化
             sum += nums[t];// at least 2 node
             if (sum > window_max_sum) {
                 window_max_sum = sum;
                 window_h = h;
                 window_t = t;
             }
         }
         printf("compare on h=%d: window_max_sum = %d [%d,%d], ret_sum %d, sum %d\n",
                h, window_max_sum, window_h, window_t, ret_sum, sum);
         ret_sum = window_max_sum > ret_sum? window_max_sum:ret_sum;
     }
     return ret_sum;
 }
 
 
 
 */
