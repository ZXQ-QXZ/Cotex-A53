#include "function.h"


void log_time()
{
    time_t t = time(NULL);
    bzero(time_log, sizeof(time_log));
    strftime(time_log, sizeof(time_log), "%Y-%m-%d %H:%M:%S", localtime(&t));
}
// // 初始化一个空链表
struct node *initList(void)
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
bool insertNode(struct node *head, datatype data)
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

void insert_data(struct node *head)
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
        sscanf(strtok(NULL, " "), "%d", &data.id);
        strcpy(data.minsrc, strtok(NULL, " "));
        strcpy(data.srcopen, strtok(NULL, " "));
        sscanf(strtok(NULL, " "), "%d", &data.pay);
        insertNode(head, data);
    }
}

/*内核链表结束*/
/*内核链表数据画图*/
void one_share(struct node *head, struct lcd *lcd)
{
    FILE *backgroud = fopen("./src/background.bmp", "r");
    File_draw(backgroud, 0, 0);
    struct node *pos;
    int x1 = 0;
    list_for_each_entry(pos, &(head->list), list)
    {
        if (pos->data.id == 1 && pos->data.bl == 1)
        {
            FILE *fp = fopen(pos->data.minsrc, "r");
            File_draw(fp, 50 + x1 * 250, 10);
            pos->data.x = 50 + x1 * 250;
            pos->data.y = 10;
            x1++;
        }
    }
    Font_exit(lcd, "退出");
}
void doublue_share(struct node *head, struct lcd *lcd)
{
    FILE *backgroud = fopen("./src/background.bmp", "r");
    File_draw(backgroud, 0, 0);
    struct node *pos;
    int x1 = 0;
    list_for_each_entry(pos, &(head->list), list)
    {
        if (pos->data.id == 2 && pos->data.bl == 1)
        {
            FILE *fp = fopen(pos->data.minsrc, "r");
            File_draw(fp, 50 + x1 * 250, 10);
            pos->data.x = 50 + x1 * 250;
            pos->data.y = 10;
            x1++;
        }
    }
    Font_exit(lcd, "退出");
}
void many_share(struct node *head, struct lcd *lcd)
{
    FILE *backgroud = fopen("./src/background.bmp", "r");
    File_draw(backgroud, 0, 0);
    struct node *pos;
    int x1 = 0, y1 = 0;
    list_for_each_entry(pos, &(head->list), list)
    {
        if (pos->data.id == 3 && pos->data.bl == 1)
        {
            if (x1 > 2)
            {
                FILE *fp = fopen(pos->data.minsrc, "r");
                File_draw(fp, 50 + y1 * 250, 200);
                pos->data.x = 50 + y1 * 250;
                pos->data.y = 200;
                y1++;
            }
            else
            {
                FILE *fp = fopen(pos->data.minsrc, "r");
                File_draw(fp, 50 + x1 * 250, 10);
                pos->data.x = 50 + x1 * 250;
                pos->data.y = 10;
                x1++;
            }
        }
    }
    Font_exit(lcd, "退出");
}

/***************************8*/
// 键盘
void keyboard()
{
    FILE *keyboard = fopen("./src/keyboard.bmp", "r");
    File_draw(keyboard, 134, 278);
}
//登录界面
void login()
{
    FILE *filehome1 = fopen("./src/login.bmp", "r");
    File_draw(filehome1, 0, 0);
}
//注册界面
void zc()
{
    FILE *filehome1 = fopen("./src/zc.bmp", "r");
    File_draw(filehome1, 0, 0);
}
// 系统界面
void home()
{
    FILE *filehome = fopen("./src/home.bmp", "r");
    File_draw(filehome, 0, 0);
}
// 覆盖键盘
void perfect()
{
    FILE *fileperfect = fopen("./src/perfect.bmp", "r");
    File_draw(fileperfect, 134, 278);
}
// 用户个人中心
void usercenter()
{
    FILE *file = fopen("./src/usercenter.bmp", "r");
    File_draw(file, 0, 400);
}
// 用户界面
void home1()
{
    FILE *filehome = fopen("./src/home1.bmp", "r");
    File_draw(filehome, 0, 0);
}
// 用户充值界面
void username_pay()
{
    FILE *filehome = fopen("./src/pay.bmp", "r");
    File_draw(filehome, 0, 0);
}
// 通用界面传参
void class_draw(char *name)
{
    FILE *filehome = fopen(name, "r");
    File_draw(filehome, 0, 0);
}
// 倒计时
void time_class(struct lcd *lcd)
{
    int tt = 0, ss = 5;
    char buf[15];
    while (1)
    {
        sleep(1);

        if (ss == 0)
        {
            tt--;
            ss = 60;
        }
        ss--;
        bzero(buf, sizeof(buf));
        sprintf(buf, "%d:%02d", tt, ss);
        Font_num(lcd, buf);
        if (ss == 0 && tt == 0)
        {
            bzero(buf, sizeof(buf));
            sprintf(buf, "到期");
            Font_num(lcd, buf);
            break;
        }
    }
}
// 登录日志写入
void log_write_login(char *str)
{
    char buf[100];
    log_time();
    bzero(buf, sizeof(buf));
    sprintf(buf, "./file/%s.log", username1);
    FILE *file = fopen(buf, "a+");
    if (file == NULL)
        return;
    fprintf(file, "%s %s %s成功\n", username1, time_log, str);
}
// 用户订单生成和管理员日志的写入
void log_write(char *str, int pay) // 日志写入
{
    char buf[100];
    log_time();
    bzero(buf, sizeof(buf));
    sprintf(buf, "./file/%s.log", username1);
    FILE *file = fopen(buf, "a+");
    if (file == NULL)
        return;
    // 时间,user，pay
    fprintf(file, "%s %s %s%d元\n", username1, time_log, str, pay);
    fclose(file);
    bzero(buf, sizeof(buf));
    FILE *file1 = fopen("./file/root.log", "a+");
    if (file1 == NULL)
        return;
    // 时间,user，pay
    fprintf(file1, "用户%s在%s%s%d元\n", username1, time_log, str, pay);
    fclose(file1);
}
// 用户订单信息读取
void log_read(struct lcd *lcd)
{
    char buf[1024];
    bzero(buf, sizeof(buf));
    sprintf(buf, "./file/%s.log", username1);
    FILE *file = fopen(buf, "r");
    if (file == NULL)
        return;
    fread(buf, 1, sizeof(buf), file);
    Font_log(lcd, buf);
    Font_limit(lcd, "返回", 600, 420);
    fclose(file);
}
//系统日志读取
void admin_log_read(struct lcd *lcd)
{
    char buf[1024];
    bzero(buf, sizeof(buf));
    FILE *file = fopen("./file/root.log", "r");
    if (file == NULL)
        return;
    fread(buf, 1, sizeof(buf), file);
    Font_log(lcd, buf);
    Font_limit(lcd, "返回", 650, 420);
    fclose(file);
}
// 登录函数
void login_pd(struct input myinput, struct lcd mylcd)
{
    login();
    while (1)
    {
        int m;
        get_abs_value(&myinput, &m);
        if ((myinput.x_release > 285 && myinput.y_release > 130) && (myinput.x_release < 500 && myinput.y_release < 160))
        {
            keyboard();
            user_password(myinput, mylcd, 0, username1, password1);
        }
        else if ((myinput.x_release > 285 && myinput.y_release > 160) && (myinput.x_release < 500 && myinput.y_release < 190))
        {
            keyboard();
            user_password(myinput, mylcd, 1, username1, password1);
        }
        else if ((myinput.x_release > 275 && myinput.y_release > 240) && (myinput.x_release < 395 && myinput.y_release < 265))
        {
            bool ls = read_file(username1, password1, &bool_pwd, &user_pay);
            if (ls)
            {
                home();
                printf("%s:登录成功\n",username1);
                break;
            }
            printf("账号或密码错误\n");
            bzero(username1, 10);
            bzero(password1, 15);
            login();
            // login_pd(myinput, mylcd);
        }
        else if ((myinput.x_release > 420 && myinput.y_release > 240) && (myinput.x_release < 535 && myinput.y_release < 265))
        {
            bzero(username1, 10);
            bzero(password1, 15);
            zc();
            bool add = false;
            while (1)
            {
                get_abs_value(&myinput, &m);
                if ((myinput.x_release > 285 && myinput.y_release > 130) && (myinput.x_release < 500 && myinput.y_release < 160))
                {
                    keyboard();
                    user_password(myinput, mylcd, 0, username1, password1);
                }
                else if ((myinput.x_release > 285 && myinput.y_release > 160) && (myinput.x_release < 500 && myinput.y_release < 190))
                {
                    keyboard();
                    user_password(myinput, mylcd, 1, username1, password1);
                }
                else if ((myinput.x_release > 275 && myinput.y_release > 240) && (myinput.x_release < 535 && myinput.y_release < 265))
                {
                    add = add_file(username1, password1,&user_pay);
                    if (add)
                    {
                        home();
                        break;
                    }
                    else
                    {
                        printf("账号已存在请重新注册\n");
                        zc();
                    }    
                
                }
            }
            if (add == true)
            {
                break;
            }
        }
        if ((myinput.x_release > 0 && myinput.y_release > 0) && (myinput.x_release < 80 && myinput.y_release < 80))
            break;
        else
        {
            perfect();
        }
    }
}
// 普通用户函数
void Ordinary_user(struct input myinput, struct lcd mylcd)
{
    struct node *head = initList();
    insert_data(head);
    struct node *pos;
    while (1)
    {
        int m;
        get_abs_value(&myinput, &m);
        if ((myinput.x_release > 25 && myinput.y_release > 88) && (myinput.x_release < 250 && myinput.y_release < 230))
        {
            one_share(head, &mylcd);
            while (1)
            {
                get_abs_value(&myinput, &m);
                list_for_each_entry(pos, &(head->list), list)
                {
                    if ((myinput.x_release > pos->data.x && myinput.y_release > pos->data.y) && (myinput.x_release < pos->data.x + 220 && myinput.y_release < pos->data.y + 132) && pos->data.id == 1)
                    {
                        class_draw(pos->data.srcopen);
                        Font_num(&mylcd, "开始");
                        Font_exit(&mylcd, "退出");
                        get_abs_value(&myinput, &m);
                        if ((myinput.x_release > 350 && myinput.y_release > 220) && (myinput.x_release < 450 && myinput.y_release < 260))
                        {
                            printf("%s\n", time_log);
                            time_class(&mylcd);

                            del_pay(pos->data.pay, username1, &user_pay);
                            log_write("单人自习室消费", pos->data.pay);
                        }
                    }
                }
                if ((myinput.x_release > 600 && myinput.y_release > 400) && (myinput.x_release < 700 && myinput.y_release < 440))
                {
                    home1();
                    break;
                }
            }
        }
        else if ((myinput.x_release > 290 && myinput.y_release > 88) && (myinput.x_release < 510 && myinput.y_release < 230))
        {
            doublue_share(head, &mylcd);
            while (1)
            {
                get_abs_value(&myinput, &m);
                list_for_each_entry(pos, &(head->list), list)
                {
                    if ((myinput.x_release > pos->data.x && myinput.y_release > pos->data.y) && (myinput.x_release < pos->data.x + 220 && myinput.y_release < pos->data.y + 132) && pos->data.id == 2)
                    {
                        class_draw(pos->data.srcopen);
                        Font_num(&mylcd, "开始");
                        Font_exit(&mylcd, "退出");
                        get_abs_value(&myinput, &m);
                        if ((myinput.x_release > 350 && myinput.y_release > 220) && (myinput.x_release < 450 && myinput.y_release < 260))
                        {
                            printf("%s\n", time_log);
                            time_class(&mylcd);
                            del_pay(pos->data.pay, username1, &user_pay);
                            log_write("情侣自习室消费", pos->data.pay);
                        }
                    }
                }

                if ((myinput.x_release > 600 && myinput.y_release > 400) && (myinput.x_release < 700 && myinput.y_release < 440))
                {
                    home1();
                    break;
                }
            }
        }
        else if ((myinput.x_release > 550 && myinput.y_release > 88) && (myinput.x_release < 770 && myinput.y_release < 230))
        {
            many_share(head, &mylcd);
            while (1)
            {
                get_abs_value(&myinput, &m);
                list_for_each_entry(pos, &(head->list), list)
                {
                    if ((myinput.x_release > pos->data.x && myinput.y_release > pos->data.y) && (myinput.x_release < pos->data.x + 220 && myinput.y_release < pos->data.y + 132) && pos->data.id == 3)
                    {
                        class_draw(pos->data.srcopen);
                        Font_num(&mylcd, "开始");
                        Font_exit(&mylcd, "退出");
                        get_abs_value(&myinput, &m);
                        if ((myinput.x_release > 350 && myinput.y_release > 220) && (myinput.x_release < 450 && myinput.y_release < 260))
                        {
                            time_class(&mylcd);
                            del_pay(pos->data.pay, username1, &user_pay);
                            // 日志写入
                            log_write("多人自习室消费", pos->data.pay);
                        }
                    }
                }

                if ((myinput.x_release > 600 && myinput.y_release > 400) && (myinput.x_release < 700 && myinput.y_release < 440))
                {
                    home1();
                    break;
                }
            }
        }
        else if ((myinput.x_release > 70 && myinput.y_release > 415) && (myinput.x_release < 180 && myinput.y_release < 455))
        {

            username_pay();
            bzero(pay_str, 10);
            sprintf(pay_str, "%d", user_pay);
            Font_pay(&mylcd, pay_str);
            get_abs_value(&myinput, &m);
            if ((myinput.y_release > 415 && myinput.y_release < 465) && ((myinput.x_release > 600) && (myinput.x_release < 780)))
            {
                user_pay += 50;
                add_pay(user_pay, username1);
                log_write("账户充值", 50);
                home1();
            }
        }
        else if ((myinput.x_release > 320 && myinput.y_release > 415) && (myinput.x_release < 480 && myinput.y_release < 455))
        {
            log_read(&mylcd);
            while (1)
            {
                get_abs_value(&myinput, &m);
                if (myinput.x_release > 600 && myinput.y_release > 420)
                {
                    home1();
                    break;
                }
            }
        }
        else if ((myinput.x_release > 600 && myinput.y_release > 415) && (myinput.x_release < 755 && myinput.y_release < 455))
        {
            class_draw("./src/usercenter.bmp");
            while (1)
            {
                get_abs_value(&myinput, &m);
                if (myinput.x_release < 190 && myinput.y_release > 415)
                {
                    // login();
                    printf("账号退出成功\n");
                    return;
                }
                else if ((myinput.x_release > 285 && myinput.y_release > 160) && (myinput.x_release < 500 && myinput.y_release < 190))
                {
                    bzero(password1, sizeof(password1));
                    keyboard();
                    user_password(myinput, mylcd, 1, username1, password1);
                    while (1)
                    {
                        get_abs_value(&myinput, &m);
                        if ((myinput.x_release > 290 && myinput.y_release > 240) && (myinput.x_release < 400 && myinput.y_release < 270))
                        {
                            if (update_password(username1, password1) && password1[0]!='\0')
                            {
                                // login();
                                printf("密码修改成功请重新登录\n");
                                return;
                            }
                            printf("密码修改失败\n");
                            break;
                        }
                    }
                    class_draw("./src/usercenter.bmp");
                    break;
                }
                else if (myinput.x_release > 648 && myinput.y_release > 415)
                {
                    home1();
                    break;
                }
            }
        }
    }
}
// 管理员用户中自习室的显示
void show()
{
    FILE *backgroud = fopen("./src/background1.bmp", "r");
    File_draw(backgroud, 0, 0);

    struct input myinput;
    struct lcd mylcd;
    if (!LCD_Init(&mylcd))
    {
        return;
    }
    if (!TS_Init(&myinput, mylcd))
    {
        return;
    }
    struct node *head = initList();
    insert_data(head);
    char buf[30];
    struct node *pos;
    int x1 = 0, y1 = 0;
    list_for_each_entry(pos, &(head->list), list)
    {
        if (y1 > 2)
        {
            break;
        }
        bzero(buf, sizeof(buf));
        if (x1 > 2)
        {
            FILE *fp = fopen(pos->data.minsrc, "r");

            pos->data.x = 50 + y1 * 250;
            pos->data.y = 200;
            File_draw(fp, pos->data.x, pos->data.y);
            if (pos->data.bl == 1)
                Font_limit(&mylcd, "已开启", pos->data.x, pos->data.y + 140);
            else
                Font_limit(&mylcd, "已关闭", pos->data.x, pos->data.y + 140);
            sprintf(buf, "%d元", pos->data.pay);
            Font_limit(&mylcd, buf, pos->data.x + 120, pos->data.y + 140);
            y1++;
        }
        else
        {
            FILE *fp = fopen(pos->data.minsrc, "r");

            pos->data.x = 50 + x1 * 250;
            pos->data.y = 10;
            File_draw(fp, pos->data.x, pos->data.y);
            if (pos->data.bl == 1)
                Font_limit(&mylcd, "已开启", pos->data.x, pos->data.y + 140);
            else
                Font_limit(&mylcd, "已关闭", pos->data.x, pos->data.y + 140);
            sprintf(buf, "%d元", pos->data.pay);
            Font_limit(&mylcd, buf, pos->data.x + 120, pos->data.y + 140);
            x1++;
        }
    }
    Font_limit(&mylcd, "权限管理", 650, 400);
    Font_limit(&mylcd, "查看流水", 400, 400);
    Font_limit(&mylcd, "退出登录", 100, 400);
}
void show1()
{
    FILE *backgroud = fopen("./src/background1.bmp", "r");
    File_draw(backgroud, 0, 0);
    struct input myinput;
    struct lcd mylcd;
    if (!LCD_Init(&mylcd))
    {
        return;
    }
    if (!TS_Init(&myinput, mylcd))
    {
        return;
    }
    struct node *head = initList();
    insert_data(head);
    char buf[30];
    struct node *pos;
    int x1 = 0, y1 = 0, n = 0;
    list_for_each_entry(pos, &(head->list), list)
    {
        n++;
        if (n < 6)
        {
            continue;
        }
        if (y1 > 2)
        {
            break;
        }
        bzero(buf, sizeof(buf));
        if (x1 > 2)
        {
            FILE *fp = fopen(pos->data.minsrc, "r");
            pos->data.x = 50 + y1 * 250;
            pos->data.y = 200;
            File_draw(fp, pos->data.x, pos->data.y);
            if (pos->data.bl == 1)
                Font_limit(&mylcd, "已开启", pos->data.x, pos->data.y + 140);
            else
                Font_limit(&mylcd, "已关闭", pos->data.x, pos->data.y + 140);
            sprintf(buf, "%d元", pos->data.pay);
            Font_limit(&mylcd, buf, pos->data.x + 120, pos->data.y + 140);

            y1++;
        }
        else
        {
            FILE *fp = fopen(pos->data.minsrc, "r");

            pos->data.x = 50 + x1 * 250;
            pos->data.y = 10;
            File_draw(fp, pos->data.x, pos->data.y);
            if (pos->data.bl == 1)
                Font_limit(&mylcd, "已开启", pos->data.x, pos->data.y + 140);
            else
                Font_limit(&mylcd, "已关闭", pos->data.x, pos->data.y + 140);
            sprintf(buf, "%d元", pos->data.pay);
            Font_limit(&mylcd, buf, pos->data.x + 120, pos->data.y + 140);
            x1++;
        }
    }
    Font_limit(&mylcd, "权限管理", 650, 400);
    Font_limit(&mylcd, "查看流水", 400, 400);
    Font_limit(&mylcd, "退出登录", 100, 400);
}
// 自习室页面的切换
void show_whole(int m)
{
    static int t = 0;
    if(m>-300 && m<300)
    {
        return;
    }
    if (m > 300)
    {
        t++;
        if (t > 1)
            t = 0;
    }
    if (m < -300)
    {
        t--;
        if (t < 0)
            t = 1;
    }
    if (t == 0)
    {
        show();
    }
    else
        show1();
}
// 权限修改
void Admin_limit()
{
    FILE *backgroud = fopen("./src/background1.bmp", "r");
    File_draw(backgroud, 0, 0);
    struct input myinput;
    struct lcd mylcd;
    if (!LCD_Init(&mylcd))
    {
        return;
    }
    if (!TS_Init(&myinput, mylcd))
    {
        return;
    }
    struct node *head = initList();
    insert_data(head);
    struct node *pos;
    char buf[200], n = 0;
    list_for_each_entry(pos, &(head->list), list)
    {
        n++;
        bzero(buf, sizeof(buf));
        if (pos->data.bl == 1)
        {
            sprintf(buf, "%d房间状态：已开启,收费标准为%d/30min         -    %d    +", pos->data.id, pos->data.pay, pos->data.pay);
            Font_zt(&mylcd, buf, (n * 40) + 1);
        }
        else
        {
            sprintf(buf, "%d房间状态：已关闭,收费标准为%d/30min         -    %d    +", pos->data.id, pos->data.pay, pos->data.pay);
            Font_zt(&mylcd, buf, (n * 40) + 1);
        }
        Font_limit(&mylcd, "退出", 500, 440);
    }
    int m;
    while (1)
    {
        get_abs_value(&myinput, &m);
        m = (int)(myinput.y_release / 40);
        printf("%d %d\n", myinput.x_release, myinput.y_release);
        if (m > 10)
        {
            if (myinput.y_release > 440 && myinput.x_release < 400)
            {
                show();
                return;
            }
        }
        list_for_each_entry(pos, &(head->list), list)
        {
            m--;
            if (m != 0)
            {
                continue;
            }
            if (pos->data.bl == 1)
            {
                if (myinput.x_release < 300)
                {
                    pos->data.bl = 0;
                }
            }
            else
            {
                if (myinput.x_release < 300)
                {
                    pos->data.bl = 1;
                }
            }
            if (myinput.x_release > 560 && myinput.x_release < 630)
            {
                pos->data.pay -= 10;
            }
            if (myinput.x_release > 710 && myinput.x_release < 780)
            {
                pos->data.pay += 10;
            }
        }
        FILE *file = fopen("./file/manage.txt", "w+");

        list_for_each_entry(pos, &(head->list), list)
        {
            fprintf(file, "%d %d %s %s %d\n", pos->data.bl, pos->data.id, pos->data.minsrc, pos->data.srcopen, pos->data.pay);
        }
        fclose(file);
        show();
        break;
    }
}
// 管理员用户函数使用
void Mdin_user(struct input myinput, struct lcd mylcd)
{
    int m;
    
    while (1)
    {
        get_abs_value(&myinput, &m);
        if (myinput.x_release > 650 && myinput.y_release > 400)
        {
            Admin_limit();
        }
        show_whole(m);
        // 日志
        if ((myinput.x_release > 400 && myinput.y_release > 400) && (myinput.x_release < 520 && myinput.y_release < 450))
        {
            admin_log_read(&mylcd);
            while (1)
            {
                get_abs_value(&myinput, &m);
                if (myinput.x_release > 650 && myinput.y_release > 420)
                {
                    show();
                    break;
                }
            }
        }

        if ((myinput.x_release > 100 && myinput.y_release > 400) && (myinput.x_release < 220 && myinput.y_release < 440))
        {
            printf("管理员退出成功\n");
            return;
        }
    }
}