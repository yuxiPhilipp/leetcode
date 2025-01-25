//
//  07_binary_tree.c
//  数据结构
//
//  Created by xiy3 on 2025-01-06.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#include "07_binary_tree.h"
#include <stdlib.h>
#include "common.h"
/*
 full binary tree
 balanced binary tree (avl)  棵树是平衡二叉搜索树，最后一棵树不是平衡二叉搜索树，因为这棵树的左右子树的高度差的绝对值超过了 1.
 */

/*
 * 顺序存储,  i, 的左孩子是 2 x i + 1, 右孩子是 2 x i + 2
 */

/*
 * 链式存储: [left | val | right]
 */
/*
   4
 2   5
1 3 8 9
  */
int tree_value_pre_order_1[15] = {4, 2, 1, -1, -1, 3, -1,-1,5,8,-1,-1,9,-1,-1};
/*
          4
     2        5
  1    3
22 33
  */
int tree_value_pre_order_2[20] = {4, 2, 1, 22,-1, -1, 33, -1, -1, 3, -1,-1,5,-1,-1};
// remove 33
int tree_value_pre_order_3[20] = {4, 2, 1, 22,-1, -1, -1, 3, -1,-1,5,-1,-1};

int *tree_value_pre_order =tree_value_pre_order_3;
int tree_value_i = 0;

typedef struct tree_node {
    int element;
    struct tree_node  *left, *right;
} tree;

void pre_create_tree (tree **t)
{
    int e;
    //scanf("%d", &e);
    e = tree_value_pre_order[tree_value_i++];
//    printf("inserted e = %d\n", e);
    if (e == -1){
        *t = NULL;
    } else {
        *t = (tree*) malloc(sizeof(tree));
        (*t)->element = e;
        pre_create_tree(&((*t)->left));
        pre_create_tree(&((*t)->right));
    }
}
int * arr = NULL;
int i_arr = 0;
void pre_order_traverse (tree * t)
{
    if (t) {
        printf(" %d ", t->element);
        arr[i_arr++] = t->element;
        pre_order_traverse(t->left);
        pre_order_traverse(t->right);
    }
}
void in_order_traverse (tree *t)
{
    if (t) {
        in_order_traverse(t->left);
        printf(" %d ", t->element);
        in_order_traverse(t->right);
    }
}
void post_order_traverse (tree *t)
{
    if (t) {
        post_order_traverse(t->left);
        post_order_traverse(t->right);
        printf(" %d ", t->element);

    }
}
// counting the last layer
void level_traverse_layer_into_array (tree *t)
{
    // step1 define 2 dimensional array in c
    int whole_array[10][10] = {0};
    int wa_i =0 ;
    
    tree * tree_array[100] = {0}, *e;
    int rear =0, front =0 , depth_first_sub= 0, depth_edge =0, depth = 0 ;
    if (t) {
        tree_array[rear ++] = t; // rear is always pointing to a blank position in the array
        depth_edge = 1;
    }
    
    while(front < rear) {
        e=tree_array[front ++]; // simulate dequeue a node and move front++
        printf(" %d ", e->element); // print a node in this layer
        
        // step2: save to array
        whole_array[depth][wa_i++] =e->element;
        
        if (e->left) {              //if it has left node, then put the left node pointer in the array and move rear pointer
            tree_array[rear++] = e->left;
        }
        if (e->right) { // doing the same as left node
            tree_array[rear++] = e->right;
        }
        if(front ==depth_edge){
            //record current rear
            if (front != rear) {
                depth_first_sub = depth_edge;
            }
            depth_edge = rear;
            depth ++;
            printf("layer %d\n", depth);
            
            // adjust whole array
            wa_i =0 ;
        }

        // next iteration: until front == rear.
    }
    
    printf("depth = %d, 1st of the last layer is %d\n",
           depth, tree_array[depth_first_sub]->element );
    
    
}

void level_traverse (tree *t)
{
//    level_traverse_print_last_layer(t);
    level_traverse_layer_into_array(t);
}
// counting the last layer
void level_traverse_print_last_layer (tree *t)
{
    tree * tree_array[100] = {0}, *e;
    int rear =0, front =0;
    
    //step 1 define new variables
    // depth: only used to print the depth of this tree
    int depth_first_sub= 0, depth_edge =0, depth = 0 ;
    
    if (t) {
        tree_array[rear ++] = t; // rear is always pointing to a blank position in the array
        
        //step 2 add depth_edge
        depth_edge = 1;
    }
    
    while(front < rear) {
        e=tree_array[front ++]; // simulate dequeue a node and move front++
        printf(" %d ", e->element); // print a node in this layer
        if (e->left) {              //if it has left node, then put the left node pointer in the array and move rear pointer
            tree_array[rear++] = e->left;
        }
        if (e->right) { // doing the same as left node
            tree_array[rear++] = e->right;
        }
        
        //step 3 depth control
        if(front == depth_edge){
            //record current rear
            if (front != rear) {
                // record the first subsript of this depth'th layer
                depth_first_sub = depth_edge;
            }
            depth_edge = rear;
            depth ++;
            printf("layer %d\n", depth);
        }

        // next iteration: until front == rear.
    }
    
    printf("depth = %d, 1st of the last layer is %d\n",
           depth, tree_array[depth_first_sub]->element );
}


void level_traverse_pure (tree *t)
{
    tree * tree_array[100] = {0}, *e;
    int rear =0, front =0;
    if (t) {
        tree_array[rear ++] = t; // rear is always pointing to a blank position in the array
    }
    
    while(front < rear) {
        e=tree_array[front ++]; // simulate dequeue a node and move front++
        printf(" %d ", e->element); // print a node in this layer
        if (e->left) {              //if it has left node, then put the left node pointer in the array and move rear pointer
            tree_array[rear++] = e->left;
        }
        if (e->right) { // doing the same as left node
            tree_array[rear++] = e->right;
        }
        // next iteration: until front == rear.
    }
}

int g_num ;
void count_leaf_num(tree * t)
{
    if(t) {
        g_num ++;
        count_leaf_num(t->left);
        count_leaf_num(t->right);
    }
}

void count_leaf_num_ptr (tree * t, int * num)
{
    if(t) {
        (*num) ++;
        count_leaf_num_ptr(t->left, num);
        count_leaf_num_ptr(t->right,num);
    }
}

int get_depth (tree *t){
    int depth_val =0, depth_left =0, depth_right = 0;
    
    if ( t == NULL) {
        return depth_val;
    }
    // t node exist, the depth must be > 1;
    depth_val += 1; // self node means depth 1;
    // calc left,right node
    depth_left =get_depth(t->left) ;
    depth_right =get_depth(t->right);
    depth_val += depth_left >depth_right ? depth_left : depth_right;
    // can put this before or after left/right    depth_val += 1; // self node means depth 1;

    return depth_val;
}

// 0236:
bool g_common_ancester_found = FALSE;
int get_common_ancester (tree *t, int n1, int n2 ) {
    int cnt = 0;
    // step 1 prepare a traverse module
    if (t == NULL) {
        return 0;
    }
    
    cnt += get_common_ancester(t->left, n1, n2);
    cnt += get_common_ancester(t->right, n1, n2);
    
    // step 2 post order should be better:
    // try to use a counter to
    printf(" *%d* ", t->element);
    if (t->element == n1 || t->element == n2) {
        printf("\nfound matching :%d\n", t->element);
        cnt ++;
    }
    
    printf("accumulated cnt = %d\n", cnt);
    if (cnt == 2) {
        if (g_common_ancester_found == FALSE) {
            printf ("found the nearest common ancester: %d\n", t->element);
            g_common_ancester_found = TRUE;
        }
        
    }
    return cnt;

}
void run_binary_tree(void)
{
    tree * t=NULL;
    pre_create_tree(&t);
    tree_value_i = 0;
    
    /*
     
    printf("pre_order_traverse");
    arr=(int*)malloc(sizeof(int) * 10);
    pre_order_traverse(t);
    array_print_int(arr, i_arr);
    printf("\n");
    
    printf("in_order_traverse");
    in_order_traverse(t);
    printf("\n");
    
    printf("post_order_traverse");
    post_order_traverse(t);
    printf("\n");
    
    printf("level_traverse");
    level_traverse(t);
    printf("\n");
    
    count_leaf_num(t);
    printf("count leaves %d\n", g_num);
    
    int leaf_number =0;
    count_leaf_num_ptr(t, &leaf_number);
    printf("count leaves ptr %d\n", leaf_number);

    printf("get depth =%d\n", get_depth(t));
     
     */
    get_common_ancester(t, 2, 3);
}
