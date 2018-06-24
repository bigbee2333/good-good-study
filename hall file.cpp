#include "list.h"

void read_hall(struct hall *head)
{
	FILE *fp;
	struct hall *p1, *p2;
	p1 = head;
	fp = fopen("hall.txt", "rt");
	if (fp == NULL)
		printf("此文件为空!\n");
	while (1)
	{
		p2 = (struct hall *)malloc(sizeof(struct hall));
		if (fscanf(fp, "%d %s %d %d %d", &p2->id, p2->name, &p2->rows, &p2->cols, &p2->count) != 5)
			break;
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;
	}
	fclose(fp);
}

void save_hall(struct hall *head)
{
	FILE *fp;
	struct hall *temp;
	temp = head->next;
	fp = fopen("hall.txt", "wt");
	if (fp == NULL)
	{
		printf("无法打开此文件，请按任意键退出!\n");
		exit(0);
	}
	while (temp != NULL)
	{
		fprintf(fp, "%d %s %d %d %d\n", temp->id, temp->name, temp->rows, temp->cols, temp->count);
		temp = temp->next;
	}
	fclose(fp);
}