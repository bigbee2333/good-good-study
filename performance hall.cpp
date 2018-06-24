#include "list.h"

struct hall *create_hall(struct hall *head)
{
	head = (struct hall *)malloc(sizeof(struct hall));
	head->next = NULL;
	return head;
}

void show_hall_1()
{
	system("cls");
	HANDLE hOut; //  ��ȡ������ľ��
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\n\n\n\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("\t\t\t\t�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t��                 �װ��Ĺ���Ա�����ã�               ��\n");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t��                    1.����Ӱ��                      ��\n ");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t��                    2.ɾ��Ӱ��                      ��\n ");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t��                    3.�޸�Ӱ����Ϣ                  ��\n ");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t��                    4.��ѯӰ����Ϣ                  ��\n ");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t��                    0.������һ��                    ��\n ");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
	choose_hall_1();
}

void choose_hall_1()
{
	int n;
	printf("��������Ҫѡ������:");
	scanf("%d", &n);
	switch (n)
	{
		case 1:add_hall(head); break;
		case 2:delete_hall(head); break;
		case 3:show_hall_2(); break;
		case 4:printf("\n"); print_hall(head); break;
		case 0:show_admin(); break;
	}
}

void print_hall(struct hall *head)
{
	HANDLE hOut; //  ��ȡ������ľ��
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("ID   ����     ��   ��   ��λ����\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	struct hall *temp;
	temp = head->next;
	while (temp != NULL)
	{
		printf("%d  %s   %d    %d    %d\n\n", temp->id, temp->name, temp->rows, temp->cols, temp->count);
		temp = temp->next;
	}
	printf("\n");
}

void add_hall(struct hall *head)
{
	system("cls");
	print_hall(head);
	printf("\n");
	HANDLE hOut; //  ��ȡ������ľ��
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,FOREGROUND_RED |FOREGROUND_GREEN |FOREGROUND_BLUE |FOREGROUND_INTENSITY);
	struct hall *p, *t;
	t = head;
	p = (struct hall *)malloc(sizeof(struct hall));
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	printf("��          �ݳ���ID          ��\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	scanf("%d", &p->id);
	printf("\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	printf("��         �ݳ�������         ��\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	scanf("%s", p->name);
	printf("\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	printf("��          ��λ����          ��\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	scanf("%d", &p->rows);
	printf("\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	printf("��          ��λ����          ��\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	scanf("%d", &p->cols);
	printf("\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	printf("��          ��λ����          ��\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	scanf("%d", &p->count);
	printf("\n");

	while (t->next != NULL)
		t = t->next;
	p->next = NULL;
	t->next = p;

	save_hall(head);
	print_hall(head);
}

void delete_hall(struct hall *head)
{
	system("cls");
	print_hall(head);
	printf("\n");
	HANDLE hOut; //  ��ȡ������ľ��
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	struct hall *p, *t;
	int m;
	t = head;
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	printf("��       ɾ�����ݳ���ID       ��\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	scanf("%d", &m);
	while (t->next!= NULL)
	{
		if (t->next->id == m)
		{
			p = t->next;
			t->next = p->next;
			free(p);
			break;
		}
		else
			t = t->next;
	}
	printf("ɾ���ɹ�!\n\n");
	save_hall(head);
	print_hall(head);
}

void show_hall_2()
{
	system("cls");
	HANDLE hOut; //  ��ȡ������ľ��
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("\n\n\n\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("\t\t\t\t�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t��                 �װ��Ĺ���Ա�����ã�               ��\n");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t��                    1.�޸�Ӱ��ID                    ��\n ");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t��                    2.�޸�Ӱ������                  ��\n ");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t��                    3.�޸���λ����                  ��\n ");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t��                    4.�޸���λ����                  ��\n ");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t��                    0.������һ��                    ��\n ");
	printf("\t\t\t\t��                                                    ��\n");
	printf("\t\t\t\t�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
	choose_hall_2();
}

void choose_hall_2()
{
	int n;
	printf("��������Ҫѡ������:");
	scanf("%d", &n);
	switch (n)
	{
		case 1:revise_id(head); break;
		case 2:revise_name(head); break;
		case 3:revise_rows(head); break;
		case 4:revise_cols(head); break;
		case 0:show_hall_1(); break;
	}
}

void revise_id(struct hall *head)
{
	system("cls");
	print_hall(head);
	printf("\n");
	HANDLE hOut; //  ��ȡ������ľ��
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	int m,n;
	struct hall *p;
	p = head;
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	printf("��          �ݳ���ID          ��\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	while (1)
	{
		int flag = 0;
		scanf("%d", &m);
		printf("\n");
		while (p->next != NULL)
		{
			if (p->next->id == m)
			{
				flag = 1;
				printf("�� �� �� �� �� �� �� �� �� �� ��\n");
				printf("��     �޸ĵ��ݳ���ID     ��\n");
				printf("�� �� �� �� �� �� �� �� �� �� ��\n");
				scanf("%d", &n);
				printf("\n");
				p->next->id = n;
				break;
			}
			else
				p = p->next;
		}
		if (flag == 0)
			printf("δ�ҵ������id������������.\n\n");
		else
		{
			printf("�޸ĳɹ�!\n\n");
			break;
		}
	}
	save_hall(head);
	print_hall(head);
}

void revise_name(struct hall *head)
{
	system("cls");
	print_hall(head);
	printf("\n");
	HANDLE hOut; //  ��ȡ������ľ��
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	struct hall *p;
	char a[100];
	int n;
	p = head;
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	printf("��          �ݳ���ID          ��\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	while (1)
	{
		int flag = 0;
		scanf("%d", &n);
		printf("\n");
		while (p->next != NULL)
		{
			if (p->next->id ==n)
			{
				flag = 1;
				printf("�� �� �� �� �� �� �� �� �� �� ��\n");
				printf("��     �µ��ݳ�������     ��\n");
				printf("�� �� �� �� �� �� �� �� �� �� ��\n");
				scanf("%s", a);
				strcpy(p->next->name, a);
				printf("\n");
				break;
			}
			else
				p = p->next;
		}
		if (flag == 0)
			printf("δ�ҵ������id������������.\n\n");
		else
		{
			printf("�޸ĳɹ�!\n\n");
			break;
		}
	}
	save_hall(head);
	print_hall(head);
}

void revise_rows(struct hall *head)
{
	system("cls");
	print_hall(head);
	printf("\n");
	HANDLE hOut; //  ��ȡ������ľ��
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	struct hall *p;
	int n,m;
	p = head;
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	printf("��          �ݳ���ID          ��\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	while (1)
	{
		int flag = 0;
		scanf("%d", &n);
		printf("\n");
		while (p->next != NULL)
		{
			if (p->next->id == n)
			{
				flag = 1;
				printf("�� �� �� �� �� �� �� �� �� �� ��\n");
				printf("��        �µ���λ����        ��\n");
				printf("�� �� �� �� �� �� �� �� �� �� ��\n");
				scanf("%d", &m);
				p->next->rows=m;
				p->next->count = (p->next->rows)*(p->next->cols);
				printf("\n");
				break;
			}
			else
				p = p->next;
		}
		if (flag == 0)
			printf("δ�ҵ������id������������.\n\n");
		else
		{
			printf("�޸ĳɹ�!\n\n");
			break;
		}
	}
	save_hall(head);
	print_hall(head);
}

void revise_cols(struct hall *head)
{
	system("cls");
	print_hall(head);
	printf("\n");
	HANDLE hOut; //  ��ȡ������ľ��
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	struct hall *p;
	int n, m;
	p = head;
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	printf("��          �ݳ���ID          ��\n");
	printf("�� �� �� �� �� �� �� �� �� �� ��\n");
	while (1)
	{
		int flag = 0;
		scanf("%d", &n);
		printf("\n");
		while (p->next != NULL)
		{
			if (p->next->id == n)
			{
				flag = 1;
				printf("�� �� �� �� �� �� �� �� �� �� ��\n");
				printf("��        �µ���λ����        ��\n");
				printf("�� �� �� �� �� �� �� �� �� �� ��\n");
				scanf("%d", &m);
				p->next->cols = m;
				p->next->count = (p->next->rows)*(p->next->cols);
				printf("\n");
				break;
			}
			else
				p = p->next;
		}
		if (flag == 0)
			printf("δ�ҵ������id������������.\n\n");
		else
		{
			printf("�޸ĳɹ�!\n\n");
			break;
		}
	}
	save_hall(head);
	print_hall(head);
}