#ifndef __FILEOPEN_H__
#define __FILEOPEN_H__
#include "openfb0.h"
#include <stdbool.h>
#include "kernel_list.h"
struct user_data
{
    int id;
    int pay;
    char username[10];
    char password[15];
};
#define DATATYPEL struct user_data
typedef DATATYPEL datatype1;
struct user // 大结构体
{
    datatype1 data;
    struct list_head list; // 小结构体
};

// 初始化一个空链表
struct user *initList1(void);

// 插入节点
extern bool insertNode1(struct user *head, datatype1 data);
extern void insert_user(struct user *head);
// 账户登录
extern bool read_file(char *str, char *str1, int *pwd, int *pay);
// 添加账户
extern bool add_file(char *str, char *str1,int *pay);
// 密码修改
extern bool update_password(char *str, char *password);
// 查询账户余额
extern int show_pay(char *str);
// 添加账户中余额
extern void add_pay(int pay, char *str);
// 削减账户余额
extern void del_pay(int pay, char *str, int *userpay);
#endif