//
//  06_string_01_basic.c
//  数据结构
//
//  Created by xiy3 on 2025-01-13.
//  Copyright © 2025 Kabilou. All rights reserved.
//

#include "06_string_01_basic.h"
#include "common.h"

/*
 字符串匹配问题。
 子串相关问题。
 前缀 / 后缀相关问题；
 回文串相关问题。
 子序列相关问题
 */

//dir 1: 向右, -1 向左; output p pointer.
char str_0125_get_next_char ( char ** p, int direction)
{
    int offset_c = 'A' - 'a';
    char tmp_c = 0,  small_c = 0;
    
//    tmp_c = **p; // try to get this char
//    if ( tmp_c >= 'A' && tmp_c <= 'Z') { //translate from A to a
//        small_c = 'A' - offset_c;
//    } else if (tmp_c >= 'a' && tmp_c <= 'z') { //  get a
//        small_c = tmp_c;
//    }
//    if (small_c == 0) {
//        // non-character; need to skip it.
//        *p = (*p) + direction;
//        //go to 26.
//    }
    
    while (small_c == 0) { // means we didn't get expected char
        tmp_c = **p; // try to get this char
//        if (tmp_c == 'P')
//            printf("\n");
        if ( tmp_c >= 'A' && tmp_c <= 'Z') { //translate from A to a
            small_c = tmp_c - offset_c;
        } else if (tmp_c >= 'a' && tmp_c <= 'z') { //  get a
            small_c = tmp_c;
        }
        *p = (*p) + direction;
    }
    //printf("get char %c, %s\n", small_c, *p);
    return small_c;
}
bool str_0125_valid_palindrome (char *str)
{
    bool ret = TRUE;
    char *p_head, *p_tail ;
    //check if str..
    unsigned long str_len = strlen(str);
    
    p_head = str;
    p_tail = str + str_len- 1;
    while (p_head != p_tail && p_head < p_tail) {
        if (str_0125_get_next_char(&p_head, 1) ==
            str_0125_get_next_char(&p_tail, -1)) {
            //potential parlindrome
        } else {
            ret = FALSE;
            break;
        }
    }
    return ret;
}
void str_0125_test (void)
{
    char * str1 = "A man, a plan, a canal: Panama";
    char * str2 = "race a -car";
    char * str3 = "race a e-car";
    printf("0125 parlindrome %d\n", str_0125_valid_palindrome(str1));
    printf("0125 parlindrome %d\n", str_0125_valid_palindrome(str2));
    printf("0125 parlindrome %d\n", str_0125_valid_palindrome(str3));
}
void str_0344_reverse_string (char *str) // array, must pass size; unless string
{
    //char * s = *str;
    printf("str %p  \n", str );
/*
 s2 0x7ffeefbff474 , &s2 0x7ffeefbff474
 str 0x7ffeefbff474
 */
    
//    str[0]= 'K';
    unsigned long i_h =0 , i_t = strlen(str) -1;
    char tmp ;
    while ( i_h <= i_t) {
//        printf("string: %s\n", str);
        tmp = str[i_h];
        str[i_h] = str[i_t];
        str[i_t] = tmp;
        i_h ++;
        i_t --;
    }
//    printf("final string: %s\n", str);

    
}

/*
 数组名字作为参数, 传递是 内存地址. 指针参数传递的是 指针上内存的内容.
 add  |_____|
      |_____|
0x7ff |_____|
 array|_____|  // 传递的是 0x7ff...
      |_____|
      |_____|
      |_____|
char*p|__a__| // 传递s的是a
 */
void str_0344_test (void)
{
    char s1 [10] = {"hellkkko"};
    char s2 [10] = {"Hannah"}; //  如果只声明变量, 获得的10内存s内容是乱的, 一旦赋值,\0后面的都是\0
    printf("s2 %p , &s2 %p\n", s2,&s2 );
    str_0344_reverse_string(s2);
    printf("%s\n", s2);
    str_0344_reverse_string(s1);
    printf("%s\n", s1);
    
    char s3[10] = {"heo"};
    str_0344_reverse_string(s3);
    printf("%s\n", s3);

}
void str_0557_reverse_str (char *str)
{
    unsigned int i_h = 0, i_t = strlen(str) -1 ;
    char tmp;
    while (i_h<i_t) {
        tmp = str[i_h];
        str[i_h] = str[i_t];
        str[i_t] = tmp;
        i_h ++;
        i_t --;
    }
}
void str_0557_reverse_words_in_string_iii (char *str, char * ret_out)
{
    char * p_space, *p_head = str ;
    char * p_out_mem = ret_out;
    char print_buf[100] = {0};
    /*
     //step 1 try to print all words
//    p_space = strchr(p_head, ' ');
    while (p_space = strchr(p_head, ' ') )
    {
        printf("p_head %s\n", p_head);
        // update p_head
        p_head = p_space +1;
    }
    printf("p_head %s\n", p_head);
     */
    
    while ((p_space = strchr(p_head, ' ') ))
    {
        //step 2 verify each word
        strncpy(print_buf, p_head, p_space-p_head);
        
        // step 3 try to reverse and verify
        str_0557_reverse_str(print_buf);
        printf("p_head %s\n", print_buf);

        // step 4 fill out str
        strcpy(p_out_mem, print_buf);
        p_out_mem += strlen(print_buf); // update immediately
        p_out_mem[0] = ' ';
        p_out_mem++;
        
        // update p_head
        p_head = p_space +1;
        memset(print_buf,0,100);
        
    }
    
    // step 5: exception: add last word
    printf("p_head %s\n", p_head);
    strcpy(print_buf, p_head);
    str_0557_reverse_str(print_buf);
    strcpy(p_out_mem, print_buf);
    
    

}
void str_0557_test (void)
{
    //要求：将字符串中每个单词的字符顺序进行反装，同时仍保留空格和单词的初始顺序。
    char * s1 = "Let's take LeetCode contest";
    char ret[100] = {0};
    str_0557_reverse_words_in_string_iii(s1, ret);
    printf("result: %s\n", ret);
    memset(ret, 0, 100);
    
    s1 ="God Ding";
    str_0557_reverse_words_in_string_iii(s1, ret);
    printf("result: %s\n", ret);
    memset(ret, 0, 100);
    
}

void str_0415_add_string_step1_struct_desgin (char *num1, char *num2, char * ret_out)
{
    int i_1_tail = strlen(num1)-1;
    int i_2_tail = strlen(num2)-1;
    char print_buf[SIZE_BUF] = {0};
    
    //print both
    while (i_1_tail  >= 0 && i_2_tail >= 0 ) {
        printf("&& num 1: %c\n", num1[i_1_tail]);
        printf("&& num 2: %c\n", num2[i_2_tail]);
        
        i_1_tail--;
        i_2_tail--;
    }
    if (i_1_tail >= 0)
    {
        strncpy(print_buf,num1, i_1_tail+1 );
        printf("-- num 1: %s\n", print_buf);
    }
    
    if (i_2_tail >= 0)
    {
        strncpy(print_buf,num1, i_2_tail+1 );
        printf("-- num 2: %s\n", print_buf);
    }
}

void str_0415_add_string_step_2_draft (char *num1, char *num2, char * ret_out)
{
    int i_1_tail = strlen(num1)-1;
    int i_2_tail = strlen(num2)-1;
    char print_buf[SIZE_BUF] = {0};
    
    char tmp_res[SIZE_BUF] = {0};
    int i_res =i_1_tail> i_2_tail? i_1_tail: i_2_tail;
    
    bool more_than_10 = FALSE;
    int sum;
    
    //print both
    while (i_1_tail  >= 0 && i_2_tail >= 0 ) {
        
        printf("&& num 1: %c\n", num1[i_1_tail]);
        printf("&& num 2: %c\n", num2[i_2_tail]);
        //
        sum = num1[i_1_tail] - '0' +num2[i_2_tail] - '0' ;
        if (more_than_10 == TRUE) { // 进位
            sum += 1;
        }
        printf("sum = %d\n", sum);
        more_than_10 = sum>=10? TRUE: FALSE;
        tmp_res[i_res] = sum%10 + '0';
        
        i_1_tail--;
        i_2_tail--;
        i_res --;
        sum = 0;
    }
    while (i_1_tail >= 0)
    {
        sum =more_than_10 == TRUE ? num1[i_1_tail] - '0' + 1 :
                                    num1[i_1_tail] - '0';
        
        more_than_10 = sum>=10? TRUE: FALSE;
        tmp_res[i_res] = sum%10 + '0';
        
        i_1_tail--;
        i_res --;
    }
    
    if (i_2_tail >= 0)
    {
        strncpy(print_buf,num1, i_2_tail+1 );
        printf("-- num 2: %s\n", print_buf);
        if (more_than_10 == TRUE) {
        }
    }
    
    // fill memory
    printf("tmp_res =%s; more_than_10 = %d\n", tmp_res, more_than_10);
    if (more_than_10 == TRUE) {
        ret_out[0]= '1';
        strcpy(ret_out+1, tmp_res);
    } else {
        strcpy(ret_out, tmp_res);
    }

}


void str_0415_add_string (char *s1, char *s2, char * ret_out)
{
    //suppose num1 len > num2 len;
    char *num1;
    char *num2;
    
    if (strlen(s1) < strlen(s2)) {
        num1 = s2;
        num2 = s1;
    } else {
        num1 = s1;
        num2 = s2;
    }
    
    int i_1_tail = strlen(num1)-1;
    int i_2_tail = strlen(num2)-1;
    
    char tmp_res[SIZE_BUF] = {0};
    unsigned long i_res =i_1_tail> i_2_tail? i_1_tail: i_2_tail;
    
    bool more_than_10 = FALSE;
    int sum;
    
    //print both
    while (i_1_tail  >= 0 && i_2_tail >= 0 ) {
        sum = num1[i_1_tail] - '0' +num2[i_2_tail] - '0' ;
        if (more_than_10 == TRUE) { // 进位
            sum += 1;
        }
        printf("sum = %d\n", sum);
        more_than_10 = sum>=10? TRUE: FALSE;
        tmp_res[i_res] = sum%10 + '0';
        
        i_1_tail--;
        i_2_tail--;
        i_res --;
        sum = 0;
    }
    while (i_1_tail >= 0)
    {
        sum =more_than_10 == TRUE ? num1[i_1_tail] - '0' + 1 :
                                    num1[i_1_tail] - '0';
        more_than_10 = sum>=10? TRUE: FALSE;
        tmp_res[i_res] = sum%10 + '0';
        
        i_1_tail--;
        i_res --;
        sum = 0;
    }
    
    // 填写最高位
    if (more_than_10 == TRUE) {
        ret_out[0]= '1';
        strcpy(ret_out+1, tmp_res);
    } else {
        strcpy(ret_out, tmp_res);
    }

}
void str_0415_test (void)
{
    char *num1 = "999", *num2 = "11"; // 1245//1010
    char ret_buff[SIZE_BUF]= {0};
    str_0415_add_string(num1, num2, ret_buff);
    printf("ret_buff =%s\n", ret_buff);

}

void str_0014_longest_common_prefix (char ** arr_str, int arr_size, char *out)
{
    int i, i_str =0 , i_fill =0 ;
    bool stop = FALSE;
    char char_common = '\0';
    
    for (i=0;stop == FALSE; i ++, char_common = '\0')
    {
        for (i_str =0; i_str < arr_size ; i_str++) {
            if (char_common == '\0') {
                char_common = arr_str[i_str][i];
            }
            if (arr_str[i_str][i] == char_common) {
                // same, continue;
            } else {
                printf("%c - %c\n",arr_str[i_str][i], char_common);
                // not the same, stop searching.
                stop = TRUE;
                break;
            }
                
        }
        if(stop == TRUE) {
            break;
        }
    }
    for ( i_fill =0; i_fill < i; i_fill ++) {
        out[i_fill] = arr_str[0][i_fill];
    }
    
}
                                    
void str_0014_test (void)
{
    char ret_buff[SIZE_BUF]= {0};
    char* strs[3] = {"flower","flow","flowight"};
    str_0014_longest_common_prefix(strs, 3, ret_buff);
    printf("common prefix: %s\n", ret_buff);
}

int check_arr(int* arr, int arr_len, int k)
{
    int i, max_sub=-1, total =0 ;
    for (i =0 ; i< arr_len; i++) {
        max_sub = max_sub>arr[i] ?max_sub :i;
    }
    for (i =0 ; i< arr_len; i++) {
        if(i == max_sub) {
            continue;
        }
        total += arr[i];
    }
    if (total<= k) {
        return arr[max_sub] + total;
    } else {
        return -1;
    }
}
int characterReplacement(char* s, int k) {
    int diff_char = 0;
    int h,t, str_len = strlen(s);
    int arr[26] ={0};
    int tmp_max_len =0, ret = 0 ;

    for(h=0; h<str_len-1; h ++) {
        for(t = h; t<str_len; t++) {
            arr[s[t] -'A'] += 1;
            tmp_max_len = check_arr(arr, 26, k);
//            printf("h=%d, t=%d, tmp_max_len = %d\n",h,t, tmp_max_len);
            if ( tmp_max_len > 0) {
                // can continue
            } else {
                //reach window size limit
                break;
            }
            printf("ret = %d, tmp_max_len =%d\n", ret, tmp_max_len);
            ret = ret>tmp_max_len?ret:tmp_max_len;

        }

        memset(arr,0, sizeof(char)*26);
    }
    printf("ret = %d\n", ret);
    return ret;
}
void str_0424_test()
{
    characterReplacement("AABABBA", 1);
    
}

int check_str_anagrams (char *s, int s_len, char* p) {
    // option: for debug
    char buff[SIZE_BUF] = {0};
    snprintf(buff,s_len+1, "%s",s); // +1 : '\0'
    printf("%s\n", buff);
    
    int arr[26] = {0}, i ;
    for (i=0;i < s_len; i++) {
        arr[s[i]-'a'] ++;
    }
    for (i=0;i< strlen(p); i++) {
        arr[p[i] -'a'] --;
        if (arr[p[i] -'a'] < 0 ) {
            //not match
            return -1;
        } //else continue
    }
    
    return 0;
}
int* findAnagrams(char* s, char* p, int* returnSize) {
    int i, window_size, check_rc;
    
    //memory
    int mem_size =0, mem_i= 0 ;
    int *ret_mem = NULL; // alloc for return


    window_size = strlen(p);
    for (i=0; i<= strlen(s) -window_size ;i++) {
        check_rc = check_str_anagrams(s+i, window_size, p);
        if (check_rc == 0) {
            //record subscript
            mem_size ++;
        }
    }
    printf("fill subscript\n");
    if (mem_size != 0) {
        ret_mem = (int *)malloc(sizeof(int) * mem_size);
        
        for (i=0; i<= strlen(s) -window_size ;i++) {
            check_rc = check_str_anagrams(s+i, window_size, p);
            if (check_rc == 0) {
                //record subscript
                ret_mem[mem_i++] = i;
            }
        }
        *returnSize =mem_size;
    }
    return ret_mem;
}
void str_0438_test()
{
    int * ret_arr = NULL;
    int ret_arr_len;
    ret_arr = findAnagrams("abab", "ab", &ret_arr_len);
    array_print_int(ret_arr,ret_arr_len );
}
void run_string(void)
{
    int num= 0x12345678;
    printf("num=%p, p[0]=%x =%p",
           &num, *((char*)&num), ((char*)&num) );
//    str_0125_test();
//    str_0344_test();
//    str_0557_test(); //反转字符串 和 每个单词
//    str_0415_test();
//    str_0014_test();
//    str_0424_test();
    str_0438_test();
    
    
}
