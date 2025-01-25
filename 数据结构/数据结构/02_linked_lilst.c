//
//  02_linked_lilst.c
//  数据结构
//
//  Created by xiy3 on 2025-01-10.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#include "02_linked_lilst.h"
#include <stdlib.h>
#define OK 0
#define ERROR 1
typedef int cerrno;

typedef struct lnode {
    int element;
    struct lnode *next;
}lnode;

cerrno list_init (lnode **  link_node)
{
    lnode * p = NULL;
    p = (lnode *) malloc(sizeof(lnode));
    if (p == NULL) {
        return ERROR;
    }
    p->element = 0;
    p->next = NULL;
    *link_node = p ;
    return OK;
}

// old method
// [head] -0-[node1]-1-  // 如果插入2,  p=node1, i=1,
// [head] -0-[node1] -1-[node2]--2- //
// p i =0
cerrno list_insert(lnode * link_list_head, int insert_subscript, int e)
{
    lnode *new_node = NULL;

    // 指针计数
    int i =0;
    lnode * i_p = link_list_head;
    
    if(insert_subscript < 0 ||link_list_head==NULL ) { //invalide node
        return ERROR;
    }
    
    while (i_p && i<insert_subscript) {
        i_p = i_p->next;
        i ++;
    }
    if (i_p == NULL || i> insert_subscript) { // invalid insert position
        return ERROR;
    }
    new_node = (lnode *) malloc (sizeof(lnode));
    new_node->element = e;
    new_node->next = i_p->next;
    i_p->next = new_node; //上面必须判断 i_p !=NULL
    return OK;
}

// [head] -0-[node1]-1-  // 如果插入2,  p=node1, i=1,
// [head] -0-[node1] -1-[node2]--2- //
// p i =0

// [head] --[node1]  // 如果插入2,  p=node1, i=1,
// [head] --[node1] --[node2]--- //
cerrno list_delete (lnode *list_head, int insert_subscript, int *e)
{
    if (list_head == NULL) {
        return ERROR;
    }
    
//    int i;
//    lnode *i_p = list_head;
//    while (i_p && i )
    {
        
    }
    return OK;
}

// insert element after 'previous' in the list
cerrno list_coco_insert (lnode * list_head, int previous, int e)
{
    lnode *i_p = list_head;
    lnode * new_p= NULL;

    if (list_head == NULL) {
        return ERROR;
    }

    while ((i_p = i_p->next)) {
        if (i_p->element == previous) {
            new_p = (lnode *)malloc(sizeof(lnode));
            //check null
            new_p->element= e;
            new_p->next = i_p->next;
            i_p->next = new_p;
            
            break;
        }
    }
    if (new_p == NULL) {
        // previous node is not found, add to list_head
        new_p = (lnode *)malloc(sizeof(lnode));
        new_p->element = e;
        new_p->next = list_head ->next;
        list_head->next = new_p;
    }
    return OK;
}
cerrno list_coco_delete (lnode * list_head, int e)
{
    lnode *i_p = list_head;
    lnode *delete_p ;
    
    if (list_head == NULL) {
        return ERROR;
    }
    
    //while ((i_p = i_p->next)) {
    while (i_p) {
        if (i_p->next && i_p->next->element == e) {
            //remove i_p next
            delete_p =i_p->next;
            i_p->next = delete_p ->next;
            free(delete_p);
            break;
        }
        i_p = i_p->next;
    }
    return OK;
}
cerrno list_coco_enqueue (lnode * list_head, int e)
{
    lnode * i_p = list_head;
    lnode * new_p ;
    if (list_head == NULL) {
        return ERROR;
    }
    new_p = (lnode*)malloc(sizeof(lnode));
    new_p->element = e;
    new_p->next = NULL;
    
    while ( i_p->next) {
        i_p =i_p->next;
    }
    
    // noww i_p->next == NULL; i_p is the last node
    i_p->next = new_p;
    
    return OK;
}
cerrno list_coco_dequeue (lnode * list_head)
{
    lnode * i_p = list_head;
    lnode * delete_p;
    if (list_head == NULL) {
        return ERROR;
    }
    
    if (i_p->next) {
        // there is a node after head.
        delete_p = i_p->next;
        i_p->next = delete_p->next;
        free(delete_p);
    }
    return OK;
}

void list_print (lnode * link_list_head){
    lnode * i_p = link_list_head;

    // 跳过头节点
    while((i_p = i_p ->next)) {
        printf(" %d ", i_p->element);
    }
    printf("\n");
}

int link_len (lnode *link_list_head)
{
    int i =0;
    lnode * i_p = link_list_head;
    
    if (link_list_head == NULL) {
        return -1;
    }
    while ((i_p = i_p->next)) {
        i ++;
    }
    return i;
}

void run_linked_list(void)
{
    lnode * link_list_head = NULL;
    list_init(&link_list_head);
    int i;
    for (i =0 ;i< 10; i++) {
        // add to head 9  8  7  6  5  4  3  2  1  0
        //list_insert(link_list_head, 0, i);
        
        // add to tail  0  1  2  3  4  5  6  7  8  9
        //list_insert(link_list_head, i, i); //
        
        // 0  1  2  3  4  5  6  7  8  9
        // list_coco_insert(link_list_head, i-1, i);
        
        // 9  8  7  6  5  4  3  2  1  0
        list_coco_insert(link_list_head, i, i);
    }
    list_print(link_list_head);
    
    int delete_list[4] = {3,4,9,0};
    for(i =0; i < 4; i++) {
        list_coco_delete(link_list_head, delete_list[i]);
        list_print(link_list_head);

    }
    
    printf("FIFO: test dequeue enqueue\n");
    for (i =0 ; i<4 ;i++) {
        list_coco_enqueue(link_list_head, delete_list[i]);
        list_coco_dequeue(link_list_head);
        list_print(link_list_head);
    }
    
    printf("length of link %d\n", link_len(link_list_head));
}
