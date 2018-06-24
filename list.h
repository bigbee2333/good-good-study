#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

const int MAX = 100;

extern struct user *phead;

extern struct hall *head;

extern struct seat *Head;

struct user
{
	char type[MAX];
	char username[MAX];
	char password[MAX];
	char nikename[MAX];
	char phonenum[MAX];
	char department[MAX];
	struct user *next;
};

struct hall
{
	int id;//演出厅ID
	char name[MAX];//演出厅名称；
	int rows;//座位行数
	int cols;//座位列数
	int count;//座位个数
	struct hall *next;
};

struct seat
{
	int id;//座位id
	int roomid;//所在演出厅
	int row;//座位行号
	int status;//座位状态
	struct seat *next;
};

void show();

struct user *creat_admin_user(struct user *phead);

void read_user(struct user *phead);

void save_user(struct user *phead);

void login(struct user *phead);

void show_admin();//进入管理员的页面

void find_people(struct user *phead, char c[100]);//进入三个端口的选择函数

void choose_admin();//管理员进入端口的选择函数

void show_admin_1();//管理用户系统的界面

void choose_admin_1();//管理员进入四大操作的选择函数

void show_admin_2();//管理员修改的界面

void choose_admin_2();//选择修改的函数

void revise_username(struct user *phead);//管理员修改用户名

void revise_password(struct user *phead);//管理员修改密码

void add(struct user *phead);//管理员增加用户信息

void print(struct user *phead);//打印用户信息

void delete_user(struct user *phead);//删除用户信息

void inquiry(struct user *phead);//查询用户的信息

void read_hall(struct hall *head);

void save_hall(struct hall *head);

struct hall *create_hall(struct hall *head);//创建影厅的函数

void show_hall_1();//影厅功能的界面

void print_hall(struct hall *head);//打印影厅的函数

void add_hall(struct hall *head);//增加影厅

void choose_hall_1();//选择影厅功能的函数

void delete_hall(struct hall *head);//删除影厅

void show_hall_2();//修改影厅信息的界面

void choose_hall_2();//修改影厅信息的选择函数

void revise_id(struct hall *head);//修改id

void revise_name(struct hall *head);//修改名称

void revise_rows(struct hall *head);//修改行数

void revise_cols(struct hall *head);//修改列数

void read_seat(struct seat *Head);//座位文件

void save_seat(struct seat *Head);

struct seat *create_seat(struct seat *Head);//创建座位的函数

void show_seat();//座位的界面

int inquiry_row(int m, struct hall *head);//传出行

int inquiry_col(int m, struct hall *head);//传出列

void inquiry_seat(struct seat *Head);//查询座位

void choose_seat_1();//选择座位四大操作的函数

void add_seat(struct seat *Head);//添加座位


