//
//  02_linked_list_easy.h
//  数据结构
//
//  Created by xiy3 on 2025-01-22.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#ifndef _2_linked_list_easy_h
#define _2_linked_list_easy_h

#include <stdio.h>

#endif /* _2_linked_list_easy_h */
/*
 基本语言,
 1 (增删)插入 node, 删除node,
 2 (改)移动node 到head 前面 //  0206 反向链表
 3 (查)node->i  给定node, 统计第几个节点,
   i->node  给定i, 找到node
   // 0876 返回中间点
 
 单指针
 1 两个node 临近, 可以用一个 指针维护
  0203 移除指定元素 // 只是需要第二个指针free , 如果涉及移动,那么就变成了双指针#1了
 2 遍历 list
 
 双指针.
 1# 分两部分, 双指针各记录一部分
 0206 反向链表: 一个p_left记录排序好的一端, 一个p_right记录未处理的一端 && p_left->next==p_right
 2# 快慢指针next差一个,一倍速和2倍速 遍历;
 应用:找中.侦测环路
 0141 0142 ?? 环形链表med 题目
 0876 返回中间点: 快慢指针差一步.
 扩展如果差2 或 3个 next ? 就是 1/4 处 , 1/3 处.
 
 ??? 思考 链表回文..
 1 找到前一半 // 3 (查)
 2 逆向排序,
 3 双指针遍历两段, 看是不是一样.
 ???? 总结两个笔记的easy 题目
 

 
 https:github.com/itcharge/LeetCode-Py/blob/main/Contents/02.Linked-List/01.Linked-List-Basic/02.Linked-List-Basic-List.md
 0083 删除链表多余元素
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     struct ListNode *next;
  * };

 struct ListNode* deleteDuplicates(struct ListNode* head) {
     struct ListNode* lcur, *rcur;
     //0 node
     if(head == NULL )
     {
         return head;
     }
     
     // 1 head ->NULL
     lcur = head;
     rcur =head->next ;
     
     
     while(rcur) // 至少 head->node->NULL
     {
         // keep lcur ;
         if(rcur->val == lcur->val )
         {
             lcur->next= rcur->next;
             struct ListNode* releaseM = rcur;
             rcur=rcur->next;
             free(releaseM);
         }
         else
         {
             rcur= rcur->next;
         lcur=lcur->next;
         }
         
     }
   
     return head;
 }
 
 0206 反向链表  https://leetcode.com/problems/reverse-linked-list/description/
 struct ListNode* reverseList(struct ListNode* head) {
     
     struct ListNode  *low, *fast ;
     
     // 0 node ||  head->NULL. // no need to reverse
     if(head == NULL || head->next ==NULL )
     {
         return head;
     }

     low = head; // origin left node. never be changed.
     fast = low->next;  // next node that should be reversed
     
     while(fast)
     {
         // head--->...--> low ----> fast-----> nextX
         // 1 跨越节点, 修改fast 左面的 箭头连接, low 连接 nextX
         low->next = fast->next ;  // 指向下一个不相邻的node
         // 2 修改fast 右面的箭头, 移动到head 左面
         fast->next= head; // head 表示 临时的最左面的 node
         // 3 更新 head 地址
         head = fast; // 更新最左面的node
         // 4 更新 fast 地址
         fast = low->next; // 更新 fast 永远都是 low的下一个.
     }
     return head;
 }
 
 
 0203 移除指定元素
 struct ListNode* removeElements(struct ListNode* head, int val) {
     // 0 node
      if(head == NULL)
      {
          return NULL ;
      }
      //如果一跳, p_fast= p_slow->next. 那么维护一个指针就够了
      // struct ListNode *p_slow, *p_fast, *new_head, *to_be_freed, *dummy_node;
      struct ListNode *p_slow , *to_be_freed, *dummy_node;

      dummy_node = (struct ListNode *)malloc (sizeof(struct ListNode));
      dummy_node ->next = head;

      p_slow = dummy_node;
      
      while (p_slow->next) { // dummy->head
              printf("p_slow= %d\n", p_slow->val);

          if (p_slow->next->val == val) {
              to_be_freed = p_slow->next;
              p_slow->next = p_slow->next->next;
              
              printf("check node, remove %d\n", to_be_freed->val);
              free(to_be_freed);

          }else {
              p_slow = p_slow->next;
          }
      }
      return dummy_node->next;
 }
 
 0234 回文链表
 1 找到中间点,
 2 反向连接
 
 0141 环形链表 linked list cycle
 
 */
