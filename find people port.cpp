#include "list.h"

void find_people(struct user *phead, char c[100])
{
	struct user *p;
	char a[14] = "administrator";
	char b[8] = "manager";
	char d[10] = "conductor";
	int n;
	p = phead->next;
	while (p != NULL)
	{
		if (strcmp(p->type, a) == 0)
		{
			n = 0;
			break;
		}
		else if (strcmp(p->type, b) == 0)
		{
			n = 1;
			break;
		}
		else if (strcmp(p->type, d) == 0)
		{
			n = 2;
			break;
		}
		else
			p = p->next;
	}
	switch (n)
	{
		case 0:show_admin(); break;
	}
}