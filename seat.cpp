#include "list.h"

struct seat *create_seat(struct seat *Head)
{
	Head = (struct seat *)malloc(sizeof(struct seat));
	Head->next = NULL;
	return Head;
}

void show_seat()
{
	system("cls");
	HANDLE hOut; //  获取输出流的句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\n\n\n\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("\t\t\t\t★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                 亲爱的管理员，您好！               ★\n");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                    1.添加新座位                    ★\n ");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                    2.修改座位                      ★\n ");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                    3.删除座位                      ★\n ");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                    4.查询座位情况                  ★\n ");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                    0.返回上一层                    ★\n ");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n");
	choose_seat_1();
}

void choose_seat_1()
{
	int n;
	printf("请输入你要选择的序号:");
	scanf("%d", &n);
	switch (n)
	{
		case 4: inquiry_seat(Head); break;
		case 0:show_admin(); break;
	}
}

void inquiry_seat(struct seat *Head)
{
	system("cls");
	int m,x,y,count=0,i,j;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,FOREGROUND_RED |FOREGROUND_GREEN |FOREGROUND_BLUE |FOREGROUND_INTENSITY);
	struct seat *p;
	p = Head;
	printf("△ ▽ △ ▽ △ ▽ △ ▽ △ △ ▽ △\n");
	printf("▽             影厅ID            ▽\n");
	printf("△ ▽ △ ▽ △ ▽ △ ▽ △ △ ▽ △\n");
	scanf("%d", &m);
	x=inquiry_row(m, head);
	y=inquiry_col(m, head);
	printf("\t\t\t\t┄    ┄    ┄    ┄    ┄    ┄    ┄    ┄    ┄     ┄\n");
	printf("\t\t\t\t↘                                            ↙\n");
	printf("\t\t\t\t    ↘                                     ↙   \n");
	printf("\t\t\t\t                  这是电影屏幕             \n");
	printf("\t\t\t\t    ↗                                     ↖    \n");
	printf("\t\t\t\t↗                                             ↖\n");
	printf("\t\t\t\t┄    ┄    ┄    ┄    ┄    ┄    ┄    ┄    ┄     ┄\n");
	while (p->next != NULL)
	{
		if (p->next->roomid == m)
		{
			if (count == 0)
				printf("\t\t\t\t");
			if (p->next->status == 0)
				printf("□  ");
			else if (p->next->status == 9)
				printf("     ");
			else
				printf("■  ");
			count++;
			p = p->next;
			if (count == y)
			{
				printf("\n\n");
				count = 0;
			}
		}
		else
			p = p->next;
	}
}

int inquiry_row(int m,struct hall *head)
{
	struct hall *t;
	t = head;
	while (t->next != NULL)
	{
		if (t->next->id == m)
			return t->next->rows;
		else
			t = t->next;
	}
}

int inquiry_col(int m, struct hall *head)
{
	struct hall *t;
	t = head;
	while (t->next != NULL)
	{
		if (t->next->id == m)
			return t->next->cols;
		else
			t = t->next;
	}
}

void add_seat(struct seat *Head)
{
	int m, cow, status, id;
	printf("△ ▽ △ ▽ △ ▽ △ ▽ △ △ ▽ △\n");
	printf("▽             影厅ID            ▽\n");
	printf("△ ▽ △ ▽ △ ▽ △ ▽ △ △ ▽ △\n");
	scanf("%d", &m);
	printf("△ ▽ △ ▽ △ ▽ △ ▽ △ △ ▽ △\n");
	printf("▽             座位ID            ▽\n");
	printf("△ ▽ △ ▽ △ ▽ △ ▽ △ △ ▽ △\n");

	printf("△ ▽ △ ▽ △ ▽ △ ▽ △ △ ▽ △\n");
	printf("▽           座位行数           ▽\n");
	printf("△ ▽ △ ▽ △ ▽ △ ▽ △ △ ▽ △\n");
	printf("△ ▽ △ ▽ △ ▽ △ ▽ △ △ ▽ △\n");
	printf("▽          座位状态          ▽\n");
	printf("△ ▽ △ ▽ △ ▽ △ ▽ △ △ ▽ △\n");
}
