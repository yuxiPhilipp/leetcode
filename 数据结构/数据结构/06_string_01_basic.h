//
//  06_string_01_basic.h
//  数据结构
//
//  Created by xiy3 on 2025-01-13.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#ifndef _6_string_01_basic_h
#define _6_string_01_basic_h

#include <stdio.h>
void run_string (void);

#endif /* _6_string_01_basic_h */

/*
 ASCII code '0' -'9'; 'a'-'z' 'A' -'Z'
 内存模型: 本质数组, 连续的内存地址空间.
 和数组区别: 字符后面插入 '\0' 表示字符串结束.
 所有问题都是讨论字符(通过下标遍历完成), 子字符串(两个下标之间的窗口)
 
 基本操作:
 增: 字符串 一个 字符 换成几个字符(也就是 字符变成字符串) //面试题
    char/str ---> str//增加原来字符串内存空间
 删: 字符串中 减小一个字符 或 减小几个字符(也就是字符串) //原理同上
    char/str ---> str//减小原来字符串内存空间
 改: 字符串中 把一个字符/一个字符串  修改为 另一个字符串.
    1# 改内容: 相对位置不变, 内存大小有变化
    2# 改位置: 内存内容不变, 位置变化 //比如 字符串取段换位置
        扩展: 反转字符串里的字符; 反转字符串里的子字符 //面试题

 查;
 1 双下标便利:搜索子字符串 比较两个y字符, 获取下标[x,y] 或指针[str+x, str+y]
    应用: 比较两个y字符 palindrome; 0557_reverse_str
 2 窗口: 比较 两个 字符 中间 的 所有字符
    字符串里寻找子字符串:
    https://leetcode.com/problems/longest-substring-without-repeating-characters/
 3 统计
    2.1 某个 char 出现的次数
        扩展: 转换k个字符后出现的个数. // 0424. 替换后的最长重复字符.md
    2.2 某个 子字符串 出现的次数
 
 比较字符串:
 字符串的特点: 就是两个及以上用了比较的.
 由于是h跨越字符串比较, 所以, 不能用双下标, 窗口了.
 往往需要建立一个临时的 arr stack, 作为hash table.
 应用:
     比较2个单独的字符串: 0242 Valid Anagram :
        结构参考 check_str_anagrams()
     比较字符串和自己 的子字符串(一般就是window里的字符串)  0438-/find-all-anagrams-in-a-string
 
 
 */
