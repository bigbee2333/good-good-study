#include "list.h"

void show()
{
	HANDLE hOut; //  获取输出流的句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\n\n\n\n\n\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("\t\t\t\t\t┄ ┄ ┄ ┄ ┄ ┄ ┄ ┄ ┄ ┄ ┄ ┄ ┄\n");
	printf("\t\t\t\t\t   欢迎进入票务管理系统\n");
	printf("\t\t\t\t\t┄ ┄ ┄ ┄ ┄ ┄ ┄ ┄ ┄ ┄ ┄ ┄ ┄\n");
	printf("\n");
	login(phead);
}

struct user *creat_admin_user(struct user *phead)
{
	phead = (struct user *)malloc(sizeof(struct user));
	phead->next = NULL;
	return phead;
}

void login(struct user *phead)
{
	struct  user *p, *t;
	char a[100], b[100], c[100];
	HANDLE hOut; //  获取输出流的句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("\t\t\t\t\t用户名：");
	while (1)
	{
		int flag = 0;
		t = phead->next;
		scanf_s("%s", a, 100);
		while (t != NULL)
		{
			if (strcmp(t->username, a) == 0)
			{
				flag = 1;
				break;
			}
			else
				t = t->next;
		}
		if (flag == 0)
		{
			printf("没有此用户名，请重新输入.\n");
			system("pause");
			system("cls");
			show();
		}
		else
			break;
	}
	printf("\n\t\t\t\t\t密码：");
	while (1)
	{
		int i = 0, step = 0;
		p = phead->next;
		while ((b[i] = _getch()) != '\r')
		{
			if (b[i] == '\b')
			{
				printf("\b \b");
				i--;
			}
			else
			{
				printf("*");
				i++;
			}
		}
		b[i] = '\0';
		printf("\n");
		while (p != NULL)
		{
			if (strcmp(p->password, b) == 0)
			{
				step = 1;
				strcpy(c, p->type);
				break;
			}
			else
				p = p->next;
		}
		if (step == 0)
		{
			printf("密码输入错误，请重新输入.\n");
			system("pause");
			system("cls");
			show();
		}
		else
			break;
	}
	find_people(phead, c);
}

void show_admin()
{
	system("cls");
	HANDLE hOut; //  获取输出流的句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\n\n\n\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("\t\t\t\t★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                 亲爱的管理员，您好！               ★\n");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                 1.管理用户系统                     ★\n");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                 2.管理放映厅                       ★\n");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                 3.设置座位                         ★\n");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                 0.退出                             ★\n");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n");
	choose_admin();
}

void choose_admin()
{
	int n;
	printf("请输入你需要选择的序号：");
	scanf("%d", &n);
	switch (n)
	{
	case 1:show_admin_1(); break;
	case 2:show_hall_1(); break;
	case 3:show_seat(); break;
	case 0:exit(0);
	}
}

void show_admin_1()
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
	printf("\t\t\t\t★                    1.修改用户信息                  ★\n ");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                    2.增加用户信息                  ★\n ");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                    3.删除用户信息                  ★\n ");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                    4.查询用户信息                  ★\n ");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                    0.返回上一层                    ★\n ");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n");
	choose_admin_1();
}

void choose_admin_1()
{
	int n;
	printf("请输入你需要选择的序号：");
	scanf("%d", &n);
	switch (n)
	{
	case 1:show_admin_2(); break;
	case 2: add(phead); save_user(phead); break;
	case 3:delete_user(phead);break;
	case 4:inquiry(phead); break;
	case 0:show_admin(); break;
	}
}

void show_admin_2()
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
	printf("\t\t\t\t★                    1.修改用户名                    ★\n ");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                    2.修改用户密码                  ★\n ");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★                    0.返回上一层                    ★\n ");
	printf("\t\t\t\t★                                                    ★\n");
	printf("\t\t\t\t★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n");
	choose_admin_2();
}

void choose_admin_2()
{
	int n;
	printf("请输入你需要选择的序号：");
	scanf("%d", &n);
	switch (n)
	{
	case 1:revise_username(phead); save_user(phead); break;
	case 2:revise_password(phead); save_user(phead); break;
	case 0:show_admin_1(); break;
	}
	system("pause");
}

void revise_username(struct user *phead)
{
	system("cls");
	struct user *p;
	char a[100], b[100], c[100], d[100];
	HANDLE hOut; //  获取输出流的句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("\n\n\n\n");
	printf("\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
	printf("\t\t\t★         请输入你的用户类型       ★\n");
	printf("\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	scanf_s("%s", a, 100);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("\n\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
	printf("\t\t\t★         请输入你的原用户名       ★\n");
	printf("\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	scanf_s("%s", b, 100);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("\n\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
	printf("\t\t\t★           请输入你的密码         ★\n");
	printf("\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int i = 0;
	while ((c[i] = _getch()) != '\r')
	{
		if (c[i] == '\b')
		{
			printf("\b \b");
			i--;
		}
		else
		{
			printf("*");
			i++;
		}
	}
	c[i] = '\0';
	printf("\n");
	while (1)
	{
		int flag = 0;
		p = phead->next;
		while (p != NULL)
		{
			if (strcmp(p->type, a) == 0 && strcmp(p->username, b) == 0 && strcmp(p->password, c) == 0)
			{
				flag = 1;
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\n\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
				printf("\t\t\t★         请输入你的新用户名       ★\n");
				printf("\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				scanf_s("%s", d, 100);
				strcpy(p->username, d);
			}
			else
				p = p->next;
		}
		if (flag == 0)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf("\n\t\t\t输入有错误，请重新输入.\n");
			revise_username(phead);
		}
		else
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf("\n\t\t\t修改成功!\n");
			break;
		}
	}
}

void revise_password(struct user *phead)
{
	system("cls");
	struct user *t;
	char a[100], b[100], c[100], d[100];
	HANDLE hOut; //  获取输出流的句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("\n\n\n\n");
	printf("\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
	printf("\t\t\t★         请输入你的用户类型       ★\n");
	printf("\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	scanf_s("%s", a, 100);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("\n\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
	printf("\t\t\t★         请输入你的用户名         ★\n");
	printf("\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	scanf_s("%s", b, 100);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("\n\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
	printf("\t\t\t★           请输入你的原密码       ★\n");
	printf("\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int i = 0;
	while ((c[i] = _getch()) != '\r')
	{
		if (c[i] == '\b')
		{
			printf("\b \b");
			i--;
		}
		else
		{
			printf("*");
			i++;
		}
	}
	c[i] = '\0';
	printf("\n");
	while (1)
	{
		int step = 0;
		t = phead->next;
		while (t != NULL)
		{
			if (strcmp(t->type, a) == 0 && strcmp(t->username, b) == 0 && strcmp(t->password, c) == 0)
			{
				step = 1;
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("\n\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
				printf("\t\t\t★         请输入你的新密码       ★\n");
				printf("\t\t\t★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★\n");
				SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				int j = 0;
				while ((d[j] = _getch()) != '\r')
				{
					if (d[j] == '\b')
					{
						printf("\b\b");
						j--;
					}
					else
					{
						printf("*");
						j++;
					}
				}
				d[j] = '\0';
				printf("\n");
				strcpy(t->password, d);
			}
			else
				t = t->next;
		}
		if (step == 0)
		{
			printf("\t\t\t信息输入错误，请重新输入.\n");
			revise_password(phead);
		}
		else
		{
			printf("\t\t\t修改成功!\n");
			break;
		}
	}
}

void add(struct user *phead)
{
	system("cls");
	print(phead);
	HANDLE hOut; //  获取输出流的句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	struct user *p, *t;
	char a[100];
	int len;
	t = phead;
	p = (struct user *)malloc(sizeof(struct user));
	strcpy(p->nikename, "\\");
	strcpy(p->phonenum, "\\");
	strcpy(p->department, "\\");
	printf("● ○ ● ○ ● ○ ● ○ ● ○ ● ○ ● ○ ●\n");
	printf("●              请输入用户类型            ●\n");
	printf("● ○ ● ○ ● ○ ● ○ ● ○ ● ○ ● ○ ●\n");
	scanf("%s", p->type);
	printf("\n");
	printf("● ○ ● ○ ● ○ ● ○ ● ○ ● ○ ● ○ ●\n");
	printf("●          请输入用户名                  ●\n");
	printf("● ○ ● ○ ● ○ ● ○ ● ○ ● ○ ● ○ ●\n");
	scanf("%s", p->username);
	printf("\n");
	printf("● ○ ● ○ ● ○ ● ○ ● ○ ● ○ ● ○ ●\n");
	printf("●          请输入用户密码                ●\n");
	printf("● ○ ● ○ ● ○ ● ○ ● ○ ● ○ ● ○ ●\n");
	while (1)
	{
		scanf_s("%s", a, 100);
		len = strlen(a);
		if (len <= 6)
			printf("密码不能少于6位，请重新输入.\n");
		else
			break;
	}
	strcpy(p->password, a);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("\n修改成功!\n\n");
	while (t->next != NULL)
		t = t->next;

	p->next = NULL;
	t->next = p;

	print(phead);
}

void print(struct user *phead)
{
	struct user *p;
	p = phead->next;
	while (p != NULL)
	{
		printf("%s\t%s\t%s\n", p->type, p->username, p->password);
		p = p->next;
	}
	printf("\n");
}

void delete_user(struct user *phead)
{
	system("cls");
	HANDLE hOut; //  获取输出流的句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	struct user *p, *t;
	char a[100], b[100];
	int flag = 0;
	t = phead;
	print(phead);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("◇ ◆ ◇ ◆ ◇ ◆ ◇ ◆ ◇ ◆ ◇ ◆ ◇\n");
	printf("◇           用户类型               ◇\n");
	printf("◇ ◆ ◇ ◆ ◇ ◆ ◇ ◆ ◇ ◆ ◇ ◆ ◇\n");
	scanf("%s",a);
	printf("\n");
	printf("◇ ◆ ◇ ◆ ◇ ◆ ◇ ◆ ◇ ◆ ◇ ◆ ◇\n");
	printf("◇            用户名                ◇\n");
	printf("◇ ◆ ◇ ◆ ◇ ◆ ◇ ◆ ◇ ◆ ◇ ◆ ◇\n\n");
	scanf("%s", b);
	printf("\n");
	while (t->next!= NULL)
	{
		if (strcmp(t->next->type, a) == 0 && strcmp(t->next->username, b) == 0)
		{
			flag = 1;
			p = t->next;
			t->next = p->next;
			free(p);
			break;
		}
		else
			t = t->next;
	}
	if (flag == 0)
	{
		printf("没有此用户，请重新输入.\n");
		delete_user(phead);
	}
	save_user(phead);
	print(phead);
}

void inquiry(struct user *phead)
{
	printf("\n");
	HANDLE hOut; //  获取输出流的句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	struct user *p;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	p = phead;
	while (p->next != NULL)
	{
		if (strcmp(p->next->type, "administrator") == 0)
		{
			printf("%s %s %s\n", p->next->type, p->next->username, p->next->password);
			p = p->next;
		}
		else
			p = p->next;
	}
	p = phead->next;
	while (p != NULL)
	{
		if (strcmp(p->type, "manager") == 0)
		{
			printf("%s %s %s\n", p->type, p->username, p->password);
			p = p->next;
		}
		else
			p = p->next;
	}	
	p = phead->next;
	while (p != NULL)
	{
		if (strcmp(p->type, "manager") == 0)
		{
			printf("%s %s %s\n", p->type, p->username, p->password);
			p = p->next;
		}
		else
			p = p->next;
	}
	p = phead->next;
	while (p != NULL)
	{
		if (strcmp(p->type, "conductor") == 0)
		{
			printf("%s %s %s\n", p->type, p->username, p->password);
			p = p->next;
		}
		else
			p = p->next;
	}
}