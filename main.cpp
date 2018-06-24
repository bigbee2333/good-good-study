#include "list.h"

struct user *phead;
struct hall *head;
struct seat *Head;

int main(void)
{
	phead = creat_admin_user(phead);
	read_user(phead);
	head = create_hall(head);
	read_hall(head);
	Head = create_seat(Head);
	read_seat(Head);
	show();
	system("pause");
}