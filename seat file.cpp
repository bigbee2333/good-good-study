#include "list.h"

void read_seat(struct seat *Head)
{
	FILE *fp;
	struct seat *p1, *p2;
	p1 = Head;
	fp = fopen("seat.txt", "rt");
	if (fp == NULL)
		printf("此文件为空.\n");
	while (1)
	{
		p2 = (struct seat *)malloc(sizeof(struct seat));
		if (fscanf(fp, "%d %d %d %d", &p2->id, &p2->roomid, &p2->row, &p2->status) != 4)
			break;
		p2->next = NULL;
		p1->next = p2;
		p1= p2;
	}
	fclose(fp);
}

void save_seat(struct seat *Head)
{
	FILE *fp;
	struct seat *temp;
	temp = Head->next;
	fp = fopen("seat.txt", "wt");
	if (fp == NULL)
	{
		printf("无法打开此文件，请按任意键退出.\n");
		exit(0);
	}
	while (temp != NULL)
	{
		fprintf(fp, "%d %d %d %d", temp->id, temp->roomid, temp->row, temp->status);
		temp = temp->next;
	}
	fclose(fp);
}