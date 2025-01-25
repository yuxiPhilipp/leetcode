//
//  03_stack.c
//  数据结构
//
//  Created by xiy3 on 2025-01-13.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#include "03_stack.h"
#include "common.h"

//sequential & linked data structure.
typedef struct stack {
    int * stack_buf; // allocate stack on heap
    int max_size;
    int top;
}stack;

cerrno stack_seq_init (stack ** s, int size)
{
    stack * s_p = (stack*)malloc(sizeof(stack));
    //if s_p
    *s = s_p;
    s_p -> max_size = size;
    s_p -> top = -1;
    s_p -> stack_buf = (int *)malloc(sizeof(int)*size);
    return OK;
}
cerrno stack_seq_deinit (stack ** s)
{
    stack * s_p = *s;
    if (s == NULL){
        return ERROR;
    }
    if (s_p->max_size >0 && s_p->stack_buf == NULL){
        return ERROR;
    }
    free(s_p->stack_buf);
    free(s_p);
    *s = NULL;
    return OK;
}
int stack_seq_empty (stack *s)
{
    return s->top == -1;
}
int stack_seq_full (stack *s)
{
    return s->top +1 ==s->max_size;
}
cerrno stack_seq_push (stack *s, int e)
{
    if (stack_seq_full(s) == FALSE) {
        s->top ++;
        s->stack_buf[s->top]=e;
        return OK;
    } else {
        // full
        return E_FULL;
    }
}
cerrno stack_seq_pop (stack *s, int *e)
{
    if (s==NULL){
        return ERROR;
    }
    if (stack_seq_empty(s) ==TRUE ) {
        return E_INVALID_OP;
    }
    *e = s->stack_buf[s->top];
    s->top --;
    return OK;
}
cerrno stack_seq_peek (stack *s, int *e)
{
    if (s == NULL){
        return ERROR;
    }
    if (stack_seq_empty(s) == TRUE) {
        return E_INVALID_OP;
    }
    *e  = s->stack_buf[s->top];
    return OK;
}
void stack_seq_traverse (stack *s) {
    int i;
    for (i =0; i <= s->top; i ++) {
        printf(" %d ", s->stack_buf[i]);
    }
    printf("\n");
}
void run_stack_seq(void)
{
    stack *stack;
    stack_seq_init(&stack, SIZE_STACK);
    int i , rc, e;
    rc = stack_seq_pop(stack, &e);
    printf("Stack %p, pop error %d\n",
           stack, rc);
    
    for(i =0;i < SIZE_STACK * 2; i++) {
        e = i*10;
        rc = stack_seq_push(stack, e);
        if (rc != OK){
            printf("Stack %p, push error %d, when push %d\n",
                   stack, rc, e);
            break;
        }
        printf("traverse stack after push: ");
        stack_seq_traverse(stack);

        if ((i & 1) == 1) {
            rc = stack_seq_pop(stack, &e);
            if (rc != OK) {
                printf("Stack %p, pop error %d\n",
                       stack, rc);
            } else {
                printf("Stack %p, pop value %d\n",
                       stack, e);
            }
            printf("traverse stack after pop: ");
            stack_seq_traverse(stack);
        }

    }
    
    stack_seq_peek(stack,&e);
    printf("Stack %p, peek value %d\n",
           stack, e);

    printf("traverse stack after peek: ");
    stack_seq_traverse(stack);
}



//sequential & linked data structure.
typedef struct stack_head {
    int * stack_buf; // allocate stack on heap
    int max_size;
    int top;
}stack_head;

void run_stack(void)
{
    
}
