#include "fileopen.h"

// 初始化一个空链表
struct user *initList1(void)
{
    struct user *head = malloc(sizeof(struct user));
    if (head)
    {
        INIT_LIST_HEAD(&(head->list));
        return head;
    }
    return NULL;
}
// 插入节点
bool insertNode1(struct user *head, datatype1 data)
{
    struct user *new = malloc(sizeof(struct user));
    if (new)
    {
        new->data = data;
        list_add(&(new->list), &(head->list));
        return true;
    }
    return false;
}
void insert_user(struct user *head)
{
    datatype1 data;
    FILE *file = fopen("./file/password.txt", "r");
    if (file == NULL)
    {
        return;
    }
    char buf[50];
    while (1)
    {
        bzero(buf, 50);
        fgets(buf, 50, file);
        if (buf[0] == '\0')
        {
            break;
        }
        sscanf(strtok(buf, " "), "%d", &data.id);
        strcpy(data.username, strtok(NULL, " "));
        strcpy(data.password, strtok(NULL, " "));
        sscanf(strtok(NULL, " "), "%d", &data.pay);
        insertNode1(head, data);
    }
    fclose(file);
}

// 账户登录
bool read_file(char *str, char *str1, int *pwd, int *pay)
{
    struct user *head = initList1();
    insert_user(head);
    struct user *pos;
    list_for_each_entry(pos, &(head->list), list)
    {

        if (strcmp(pos->data.username, str) == 0 && strcmp(pos->data.password, str1) == 0)
        {
            *pwd = pos->data.id;
            *pay = pos->data.pay;
            return true;
        }
    }
    return false;
}
// 添加账户
extern bool add_file(char *str, char *str1,int *pay)
{
    if (str[0] == '\0' || str1 == '\0')
        return false;
    struct user *head = initList1();
    insert_user(head);
    struct user *pos;
    list_for_each_entry(pos, &(head->list), list)
    {

        if (strcmp(pos->data.username, str) == 0)
        {
            return false;
        }
    }
    FILE *file = fopen("./file/password.txt", "r+");
    fseek(file, 0, SEEK_END);
    *pay=0;
    fprintf(file, "%d %s %s %d\n", 0, str, str1, 0);
    fclose(file);
    return true;
}
// 密码修改
bool update_password(char *str, char *password)
{
    struct user *head = initList1();
    insert_user(head);
    struct user *pos;
    int tmp = 0;
    list_for_each_entry(pos, &(head->list), list)
    {
        if (strcmp(pos->data.username, str) == 0)
        {
            bzero(pos->data.password, 15);
            strcpy(pos->data.password, password);
            tmp = 1;
            break;
        }
    }
    if (tmp == 1)
    {
        FILE *file = fopen("./file/password.txt", "w+");
        list_for_each_entry(pos, &(head->list), list)
        {
            fprintf(file, "%d %s %s %d\n", pos->data.id, pos->data.username, pos->data.password, pos->data.pay);
        }
        fclose(file);
        return true;
    }
    return false;
}
// 查询账户余额
int show_pay(char *str)
{
    struct user *head = initList1();
    insert_user(head);
    struct user *pos;
    list_for_each_entry(pos, &(head->list), list)
    {

        if (strcmp(pos->data.username, str) == 0)
        {
            return pos->data.pay;
        }
    }
    return -1;
}
// 添加账户中余额
void add_pay(int pay, char *str)
{
    struct user *head = initList1();
    insert_user(head);
    struct user *pos;
    FILE *file = fopen("./file/password.txt", "w+");
    list_for_each_entry(pos, &(head->list), list)
    {
        if (strcmp(pos->data.username, str) == 0)
        {
            pos->data.pay = pay;
            fprintf(file, "%d %s %s %d\n", pos->data.id, pos->data.username, pos->data.password, pos->data.pay);
        }
        else
            fprintf(file, "%d %s %s %d\n", pos->data.id, pos->data.username, pos->data.password, pos->data.pay);
    }
    fclose(file);
}
// 削减账户余额
void del_pay(int pay, char *str, int *userpay)
{
    struct user *head = initList1();
    insert_user(head);
    struct user *pos;
    FILE *file = fopen("./file/password.txt", "w+");
    list_for_each_entry(pos, &(head->list), list)
    {

        if (strcmp(pos->data.username, str) == 0)
        {

            pos->data.pay -= pay;
            *userpay = pos->data.pay;
            fprintf(file, "%d %s %s %d\n", pos->data.id, pos->data.username, pos->data.password, pos->data.pay);
        }
        else
            fprintf(file, "%d %s %s %d\n", pos->data.id, pos->data.username, pos->data.password, pos->data.pay);
    }
    fclose(file);
}