#include "list.h"

void read_user(struct user *phead)
{
	FILE *fp;
	struct user *p1, *p2;
	p1 = phead;
	fp = fopen("user.txt", "rt");
	if (fp == NULL)
		printf("此链表为空.\n");
	while (1)
	{
		p2 = (struct user *)malloc(sizeof(struct user));
		if (fscanf(fp, "%s %s %s %s %s %s", p2->type, p2->username, p2->password, p2->nikename, p2->phonenum, p2->department) != 6)
			break;
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;
	}
	fclose(fp);
}

void save_user(struct user *phead)
{
	FILE *fp;
	struct user *ptemp;
	ptemp = phead->next;
	fp = fopen("user.txt", "wt");
	if (fp == NULL)
	{
		printf("无法打开此文件，请按任意键退出.\n");
		exit(0);
	}
	while (ptemp != NULL)
	{
		fprintf(fp, "%s %s %s %s %s %s\n", ptemp->type, ptemp->username, ptemp->password, ptemp->nikename, ptemp->phonenum, ptemp->department);
		ptemp = ptemp->next;
	}
	fclose(fp);
}