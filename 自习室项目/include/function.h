#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include "input.h"
#include "jpeg.h"
#include "draw.h"
#include "bmp.h"
#include "draw.h"
#include "fileopen.h"
#include "font.h"
#include "kernel_list.h"
int bool_pwd, user_pay;                                                             // 用于判断是否为管理员
static char username1[10] = {0}, password1[15] = {0}, pay_str[10] = {0}, time_log[60] = {0}; // 账号密码和余额存放
/******time获取*******/
extern void log_time();
/*内核链表结构体的创建及使用*/
struct name // 教室及价格结构体
{
    char minsrc[20];  // 小图展示
    char srcopen[20]; // 大图展示
    int bl;           // 是否开启
    int id;           // 1,2,3空间分配
    int x;
    int y;
    int pay; // 教室价格
};
// 用户数据结构体
#define DATATYPE struct name
typedef DATATYPE datatype;
struct node // 大结构体
{
    datatype data;
    struct list_head list; // 小结构体
};
// // 初始化一个空链表
struct node *initList(void);
// 插入节点
bool insertNode(struct node *head, datatype data);
void insert_data(struct node *head);
/*内核链表结束*/
/*内核链表数据画图*/
void one_share(struct node *head, struct lcd *lcd);
void doublue_share(struct node *head, struct lcd *lcd);
void many_share(struct node *head, struct lcd *lcd);
/***************************8*/
// 键盘
extern void keyboard();
//登录界面
extern void login();
//注册界面
extern void zc();
// 系统界面
extern void home();
// 覆盖键盘
extern void perfect();
// 用户个人中心
extern void usercenter();
// 用户界面
extern void home1();
// 用户充值界面
extern void username_pay();
// 通用界面传参
extern void class_draw(char *name);
// 倒计时
extern void time_class(struct lcd *lcd);
// 登录日志写入
extern void log_write_login(char *str);
// 用户订单生成和管理员日志的写入
extern void log_write(char *str, int pay); // 日志写入
// 用户订单信息读取
extern void log_read(struct lcd *lcd);
//系统日志读取
extern void admin_log_read(struct lcd *lcd);
// 登录函数
extern void login_pd(struct input myinput, struct lcd mylcd);
// 普通用户函数
extern void Ordinary_user(struct input myinput, struct lcd mylcd);
// 管理员用户中自习室的显示
extern void show();
extern void show1();
// 自习室页面的切换
void show_whole(int m);
// 权限修改
extern void Admin_limit();
// 管理员用户函数使用
extern void Mdin_user(struct input myinput, struct lcd mylcd);
#endif