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
	int id;//�ݳ���ID
	char name[MAX];//�ݳ������ƣ�
	int rows;//��λ����
	int cols;//��λ����
	int count;//��λ����
	struct hall *next;
};

struct seat
{
	int id;//��λid
	int roomid;//�����ݳ���
	int row;//��λ�к�
	int status;//��λ״̬
	struct seat *next;
};

void show();

struct user *creat_admin_user(struct user *phead);

void read_user(struct user *phead);

void save_user(struct user *phead);

void login(struct user *phead);

void show_admin();//�������Ա��ҳ��

void find_people(struct user *phead, char c[100]);//���������˿ڵ�ѡ����

void choose_admin();//����Ա����˿ڵ�ѡ����

void show_admin_1();//�����û�ϵͳ�Ľ���

void choose_admin_1();//����Ա�����Ĵ������ѡ����

void show_admin_2();//����Ա�޸ĵĽ���

void choose_admin_2();//ѡ���޸ĵĺ���

void revise_username(struct user *phead);//����Ա�޸��û���

void revise_password(struct user *phead);//����Ա�޸�����

void add(struct user *phead);//����Ա�����û���Ϣ

void print(struct user *phead);//��ӡ�û���Ϣ

void delete_user(struct user *phead);//ɾ���û���Ϣ

void inquiry(struct user *phead);//��ѯ�û�����Ϣ

void read_hall(struct hall *head);

void save_hall(struct hall *head);

struct hall *create_hall(struct hall *head);//����Ӱ���ĺ���

void show_hall_1();//Ӱ�����ܵĽ���

void print_hall(struct hall *head);//��ӡӰ���ĺ���

void add_hall(struct hall *head);//����Ӱ��

void choose_hall_1();//ѡ��Ӱ�����ܵĺ���

void delete_hall(struct hall *head);//ɾ��Ӱ��

void show_hall_2();//�޸�Ӱ����Ϣ�Ľ���

void choose_hall_2();//�޸�Ӱ����Ϣ��ѡ����

void revise_id(struct hall *head);//�޸�id

void revise_name(struct hall *head);//�޸�����

void revise_rows(struct hall *head);//�޸�����

void revise_cols(struct hall *head);//�޸�����

void read_seat(struct seat *Head);//��λ�ļ�

void save_seat(struct seat *Head);

struct seat *create_seat(struct seat *Head);//������λ�ĺ���

void show_seat();//��λ�Ľ���

int inquiry_row(int m, struct hall *head);//������

int inquiry_col(int m, struct hall *head);//������

void inquiry_seat(struct seat *Head);//��ѯ��λ

void choose_seat_1();//ѡ����λ�Ĵ�����ĺ���

void add_seat(struct seat *Head);//�����λ


