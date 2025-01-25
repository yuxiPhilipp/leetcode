//
//  04_queue.c
//  数据结构
//
//  Created by xiy3 on 2025-01-13.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#include "04_queue.h"
#include "common.h"
// ==== sequential
typedef struct queue_seq_head {
    int size;
    int *q_seq_buf;
    int q_tail;
    int q_front;
}queue_seq_head;

// ===== 2.3 队列的链式存储实现
typedef struct q_link_node {
    int element;
    struct q_link_node * next;
}q_link_node;

typedef struct q_link_head {
    q_link_node *next;
    q_link_node *q_tail; //insert here
    q_link_node *q_front; // get out from here
}q_link_head;

cerrno  queue_link_init(q_link_head ** qh)
{
    // check qh NULL, or return error
    q_link_head * p_qh = (q_link_head*)malloc(sizeof(q_link_head));
    //if...
    *qh = p_qh;
    p_qh->next = NULL;
    p_qh->q_tail= NULL;
    p_qh->q_front = NULL;
    
    return OK;
}
// caller allocate s memory
cerrno queue_link_enqueue (q_link_head *q, q_link_node *e)
{
    if (q == NULL || e == NULL) {
        return E_NOMEM;
    }
    if (q->q_front == NULL) {
        // empty queue
        q->q_front = e;
        q->q_tail = e;
        q->next = e;
    }else if (q->q_front != NULL) {
        // at least 1 item in queue
        q->q_tail->next = e;
        q->q_tail = e;
    }
     
    
    return OK;
}

// caller release the memory
cerrno queue_link_dequeue (q_link_head *q, q_link_node **e)
{
    if (q == NULL || e == NULL) {
        return E_NOMEM;
    }
    if (q->q_front == NULL) {
        // empty queue
        return E_EMPTY;
    }
    if (q->q_front == q->q_tail) {
        // there is only 1 item in queue
        *e = q->q_front;
        q->q_front = NULL;
        q->q_tail = NULL;
        q->next= NULL;
    } else {
        // more than 2 items in queue
        *e = q->q_front;
        q->q_front = q->q_front->next;
        q->next = q->q_front;
    }
     return OK;
}

void queue_link_traverse (q_link_head *q)
{
    // if ....
   
    q_link_node * p_node = q->q_front;
    
    while(p_node) {
        printf(" %d ", p_node->element);
        p_node = p_node->next;
    }
    printf("\n");
}

cerrno queue_link_deinit (q_link_head **qh)
{
    q_link_head * p_qh = *qh;
    q_link_node * p_node;
 
    if (qh == NULL || p_qh == NULL) {
        return E_NOMEM;
    }
    cerrno rc ;
    
    while(1) {
        rc = queue_link_dequeue(p_qh, &p_node);
        if (rc == OK) {
            printf("%s dequeue %d\n", __func__, p_node->element);
            free(p_node);
        } else if (rc == E_EMPTY) {
            // free'd all nods.
            break;
        }
    }
    
    free(p_qh);
    return OK;
}
void run_queue(void)
{
    q_link_head *q_head = NULL;
    queue_link_init(&q_head);
    int i ;
    q_link_node *q_node;
    for(i =0; i< 10; i++) {
        q_node = (q_link_node*)malloc(sizeof(q_link_node));
        // check return
        q_node->element=i;
        q_node->next = NULL;
        queue_link_enqueue(q_head, q_node);
        printf("enqueue :" );
        queue_link_traverse(q_head);
        
        if ((i & 1) == 1) {
            queue_link_dequeue(q_head, &q_node);
            printf("dequeue :" );
            queue_link_traverse(q_head);

        }
    }
    
    queue_link_deinit(&q_head);
    printf("deinit :" );
    queue_link_traverse(q_head);

}
