//
//  01_array_med.c
//  数据结构
//
//  Created by xiy3 on 2025-01-17.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#include "01_array_med.h"
#include "common.h"


void arr_0498_diagonal_traverse (int nums[][3], int step_len, int arr_size)
{
    int i_x , i_y;
    bool right_up = TRUE; // 1st direction; false means left_down side.
    
    for (i_x =0, i_y =0; i_y < arr_size && i_x < step_len;
         ) {
        // 打印
        printf("get %d\n", nums[i_y][i_x]);
        if (nums[i_y][i_x] == 8) {
            printf("get %d\n", nums[i_y][i_x]);
        }
        //修改下一个坐标
        if (right_up) {
            if (i_y == 0 && i_x == 0) {
                // 初始位置
                i_x ++;
                //如果xy 不能一起动,就改变方向
                right_up = FALSE;
            } else
            if ((i_x + 1 >= 0) && (i_y -1 >=0 )) {
                //如果可以向沿着箭头走, 就正常调整 xy 值
                i_x ++;
                i_y --;
            } else
            if (i_x == step_len -1) {
                i_y ++;
                right_up = FALSE;
            }
            
        } else {
            if (i_x ==0 ) {
                i_y ++;
                //改变方向
                right_up = TRUE;
            } else if (i_y == arr_size -1) {
                //改变方向
                i_x ++;
                right_up = TRUE;
            } else
            if ((i_x -1 >= 0) && ( i_y + 1 >=0)) {
                //如果可以向沿着箭头走, 就正常调整 xy 值
                i_x --;
                i_y ++;
            }
        }
        
    }
}
void arr_0498_test (void)
{
    int nums[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    arr_0498_diagonal_traverse(nums, 3,3);
}

/*
 原地算法 0073 0289
 什么是原地算法？ 原地算法的“原地”是指“in-place”的概念，即在不引入额外空间的情况下就地进行计算和操作。由于原地算法不使用额外的空间，
 */

void arr_0073_set_matrix_zeroes (int *nums[3], int step_len, int arr_size)
{

}
void arr_0073_test()
{
    int arr[][3] = {{1,1,1},{1,0,1},{3,1,1}};
    arr_0073_set_matrix_zeroes(arr, 3, 3 );
}

/*
 矩阵螺旋
 */

void arr_0054_spiral_matrix()
{
    
}
void arr_0054_test()
{
    
}
void run_array_med(void)
{
//    arr_0498_test();
    arr_0073_test();
    arr_0054_test();
}
