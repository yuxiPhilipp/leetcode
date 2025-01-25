//
//  06_string_03_trie.c
//  数据结构
//
//  Created by xiy3 on 2025-01-13.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#include "06_string_03_trie.h"
#include "common.h"
#define TRIE_BUF 26
#define BUF_COMMON 100
typedef struct trie_node {
    bool is_end;
    struct trie_node* children[TRIE_BUF];
}trie_node;

trie_node* trie_init_node (trie_node **tn)
{
    trie_node *p_tn = (trie_node *)malloc(sizeof(trie_node));
    //if...
    p_tn->is_end = FALSE;
    memset(p_tn->children, 0, TRIE_BUF*sizeof(trie_node *));
    
    if (tn) {
        *tn = p_tn;
    }
    return p_tn;
}
void trie_insert (trie_node *tn , char * str)
{
    trie_node *p_node = tn;
    int i , i_sub;
    char c;
    for (i=0; i < strlen(str); i ++) {
        c =str[i];
        i_sub = c -'a';
        if (p_node->children[i_sub] == NULL) {
            // not saved
            p_node->children[i_sub] =trie_init_node(NULL);
        }
        p_node =p_node->children[i_sub];
    }
    p_node->is_end = TRUE;
}
bool trie_search_word_exist (trie_node *tn, char *str)
{
    bool ret = TRUE;
    trie_node *p_tn = tn;
    int i, i_sub;
    for (i=0;i<strlen(str); i++) {
        i_sub = str[i] -'a';
        if (p_tn->children[i_sub] != NULL) {
            //found this char.
            p_tn = p_tn->children[i_sub];
        } else {
            // not found, return false
            ret = FALSE;
            break;
        }
    }
    if (p_tn->is_end == FALSE) {
        ret = FALSE;
    }
    return ret;
}
bool trie_search_prefix_exist (trie_node *tn, char *str)
{
    bool ret = TRUE;
    trie_node *p_tn = tn;
    int i, i_sub;
    for (i =0 ; i< strlen(str); i ++) {
        i_sub = str[i] - 'a';
        
        if (p_tn->children[i_sub] != NULL) {
            //found this char.
            p_tn = p_tn->children[i_sub];
        } else {
            ret = FALSE;
            break;
        }
    }
    return ret;
}
int trie_count_children_of_node (trie_node **tn)
{
    int i, counter =0 ;
    for (i =0; i<TRIE_BUF; i ++)  {
        if (tn[i] != NULL) {
            counter ++;
        }
    }
    return counter;
}
int trie_find_first_node (trie_node **tn) {
    int i;
    for (i =0; i< TRIE_BUF; i++) {
        if (tn[i] != NULL) {
            break;
        }
    }
    return i;
}
void trie_release_node_to_leave (trie_node *tn)
{
    int i_sub = 0 ;
    trie_node *p_tn;
    if (tn->is_end == TRUE) {
        //last node
        return;
    } else {
        i_sub = trie_find_first_node (tn->children);
        p_tn =tn->children[i_sub];
        trie_release_node_to_leave(p_tn);
        free(p_tn);
        tn->children[i_sub] = NULL;
        tn->is_end = TRUE;
        if (trie_count_children_of_node(tn->children) != 0) {
            printf("***have errors in trie_release_node_to_leave ****\n");
        }
    }
}
cerrno trie_delete_str (trie_node *tn, char *str)
{
    trie_node *p_tn = tn;
    int i , i_sub;
    if (trie_search_word_exist(tn, str) == FALSE) {
        return  E_INVALID_OP;
    }
    for (i =0 ; i< strlen(str); i++) {
        i_sub = str[i] - 'a';
        // check p_tn->children : how many non-NULL
        if (trie_count_children_of_node(p_tn->children) > 1) {
            // there are other nodes. go deeper
            p_tn = p_tn->children[i_sub];
        } else {
            // count ==1: 该 p_tn 就是树上的最后一个节点了.
            trie_release_node_to_leave(p_tn->children[i_sub]);
            p_tn->is_end = TRUE;
        }
    }
    return OK;
}
void trie_traverse_v1 (trie_node *tn)
{
    int i;
    char print_buf[BUF_COMMON];
    int i_pb =0;
    if (tn->is_end == TRUE) {
        return;
    }
    for (i=0; i<TRIE_BUF; i++) {
        if (tn->children[i] != NULL) {
            //find a path ; save this char
            printf("get char: %c\n",i + 'a' );
            print_buf[i_pb++] = i + 'a';
            
            //check next node.
            trie_traverse_v1(tn->children[i]);
        }
    }
    // print all str
}

static char print_buf[BUF_COMMON] = {0};
static int i_pb = 0;
void trie_traverse (trie_node *tn)
{
    int i;
    if (tn->is_end == TRUE) {
        printf("find a word: %s\n",print_buf);
//        // adj print_buf
//        print_buf[i_pb-1] = '\0';
//        i_pb --;
    }
    if (trie_count_children_of_node(tn->children) == 0) {
        return ;
    }
    for (i=0; i<TRIE_BUF; i++) {
        if (tn->children[i] != NULL) {
            //find a path ; save this char
            printf("get char: %c\n",i + 'a' );
            print_buf[i_pb++] = i + 'a';
            printf("      print_buf :[%s],%d \n", print_buf, i_pb);

            //check next node.
            trie_traverse(tn->children[i]);
            
            
            printf("+++   print_buf :[%s],%d \n", print_buf, i_pb);
            print_buf[i_pb-1] = '\0';
            i_pb --;
            printf("---   print_buf :[%s],%d \n", print_buf, i_pb);
        }
    }
 }
void trie_free(trie_node* obj) {
}
/*
  a
b p
c p
  l
  e
 */
void run_trie (void)
{
    trie_node * trie_head = trie_init_node(NULL);
    char *test[9]={"apple", "app", "abc"};
    trie_insert(trie_head, test[0]);
    printf("search apple %d\n",
           trie_search_word_exist(trie_head, test[0]));
    printf("search %s %d\n",
           test[1],
           trie_search_word_exist(trie_head, test[1]));
    
    printf("search prefix %s %d\n",
           test[1],
           trie_search_prefix_exist(trie_head, test[1]));
    trie_insert(trie_head, test[2]);
    trie_insert(trie_head, test[1]);
    printf("search %s %d\n",
           test[1],
           trie_search_word_exist(trie_head, test[1]));
    
    printf("search prefix %s %d\n",
           test[1],
           trie_search_prefix_exist(trie_head, test[1]));
    
    printf("search apple %d\n",
           trie_search_word_exist(trie_head, test[0]));

//    printf("traverse trie\n");
//    trie_traverse(trie_head);
}
/*
 Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。

 请你实现 Trie 类：

 Trie() 初始化前缀树对象。
 void insert(String word) 向前缀树中插入字符串 word 。
 boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
 boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
 */



typedef struct {
    
} Trie;


//Trie* trie_create() {
//
//}
//
//void trie_insert(Trie* obj, char* word) {
//
//}
//
//bool trie_search(Trie* obj, char* word) {
//
//}
//
//bool trie_startsWith(Trie* obj, char* prefix) {
//
//}
//
//void trie_free(Trie* obj) {
//
//}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
