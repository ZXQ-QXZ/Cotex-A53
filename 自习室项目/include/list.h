#ifndef __LIST_H__
#define __LIST_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "kernel_list.h"
struct name
{
    char minsrc[20];  // 小图展示
    char srcopen[20]; // 大图展示
    int bl;           // 是否开启
    int id;           // 1,2,3空间分配
    int x;
    int y;
    int pay; // 教室价格
};
#define DATATYPE struct name
typedef DATATYPE datatype;

struct node // 大结构体
{
    datatype data;
    struct list_head list; // 小结构体
};
// 初始化一个空链表
extern struct node *initList(void)
{
    struct node *head = malloc(sizeof(struct node));
    if (head)
    {
        INIT_LIST_HEAD(&(head->list));
        return head;
    }
    return NULL;
}
// 插入节点
extern bool insertNode(struct node *head, datatype data)
{
    struct node *new = malloc(sizeof(struct node));
    if (new)
    {
        new->data = data;
        list_add(&(new->list), &(head->list));
        return true;
    }
    return false;
}

extern void insert_data(struct node *head)
{
    datatype data;
    FILE *file = fopen("./file/manage.txt", "r");
    if (file == NULL)
        return;
    char buf[50];
    while (1)
    {
        bzero(buf, 50);
        fgets(buf, 50, file);
        if (buf[0] == '\0')
        {
            break;
        }
        sscanf(strtok(buf, " "), "%d", &data.bl);
        printf("bl: %d\n", data.bl);
        sscanf(strtok(NULL, " "), "%d", &data.id);
        printf("id: %d\n", data.id);
        strcpy(data.minsrc, strtok(NULL, " "));
        strcpy(data.srcopen, strtok(NULL, " "));
        sscanf(strtok(NULL, " "), "%d", &data.pay);
        printf("pay: %d\n", data.pay);
        insertNode(head, data);
    }
}

#endif