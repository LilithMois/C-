#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define FALSE 0
#define TRUE 1
#define MAXSIZE 20
typedef int Status;
typedef char Elemtype;
typedef struct Node
{
	Elemtype name[MAXSIZE];
	Elemtype number[MAXSIZE];
	Elemtype sex[MAXSIZE];
	struct Node* next;
}Node;
typedef Node* Linklist;

typedef struct Student
{
	Elemtype name[MAXSIZE];
	struct Student* next;
	struct Node* Next;
}Student;
typedef Student* Stulist;

Status Inserlist(Linklist* Lp);
Status Inserstulist(Stulist* Sp);//插入联系人
void Initstulist(Stulist* Sp, Node* Lp);//对链表进行初始化
void mydisplay(Linklist* Lp);
void studisplay(Stulist* Sp);//显示通讯录
void Deletelist();
void Deletestulist(Stulist* Sp);//删除联系人
Status Findlist(Linklist* Lp);
Status Findstulist(Stulist* Sp);//查找联系人
void Reviselist();
void Revisestulist(Stulist* Sp);//修改联系人
Status Sortlist();//对通讯录进行排序
void studisplay(Linklist* Lp);//进入同学
void begain(Stulist* Sp);

/*＊＊＊＊＊＊＊＊＊＊初始化＊＊＊＊＊＊＊＊＊＊*/ 
void Initstulist(Stulist* Sp, Linklist* Lp) {
	Student* sp = (Student*)malloc(sizeof(Student));
	if (sp == NULL) {
		printf("申请失败");
		return;
	}
	else
	{
		*Sp = sp;
		sp->next = (Student*)malloc(sizeof(Student));
		sp->next = NULL;
		Node* p = (Node*)malloc(sizeof(Node));
		if (p == NULL)
		{
			printf("申请失败");
			return;
		}
		else
		{
			sp->Next = *Lp;
			*Lp = p;
			p->next = (Node*)malloc(sizeof(Node));
			p->next = NULL;
		}
	}
}
/*＊＊＊＊＊＊＊＊＊＊＊添加联系人＊＊＊＊＊＊＊＊＊＊*/
Status Inserlist(Linklist* Lp)//添加联系人
{
	Linklist L = *Lp;
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("申请失败");
		return FALSE;
	}
	else
	{
		Elemtype a[MAXSIZE];
		Elemtype b[MAXSIZE];
		Elemtype c[MAXSIZE];
		printf("请输入要保存的联系人名字:\n");
		scanf_s("%s", a, 20);
		printf("请输入要保存的联系人号码:\n");
		scanf_s("%s", b, 20);
		printf("请输入要保持的联系人性别:\n");
		scanf_s("%s", c, 20);

		while (L != NULL && L->next != NULL)
		{
			L = L->next;
		}
		strcpy_s(p->name, a);
		strcpy_s(p->number, b);
		strcpy_s(p->sex, c);
		L->next = p;
		p->next = NULL;
	}
}
Status Inserstulist(Stulist* Sp)//添加联系人
{
	Stulist L = *Sp;
	Student* sp = (Student*)malloc(sizeof(Student));
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("申请失败");
		return 0;
	}
	else
	{
		sp->Next =p;
		p->next = (Node*)malloc(sizeof(Node));
		p->next = NULL;
	}
	if (sp == NULL)
	{
		printf("申请失败");
		return FALSE;
	}
	else
	{
		Elemtype a[MAXSIZE];
		printf("请输入要保存的同学名字:\n");
		scanf_s("%s", a, 20);
		while (L != NULL && L->next != NULL)
		{
			L = L->next;
		}
		strcpy_s(sp->name, a);
		L->next =sp;
		sp->next = NULL;
	}
}
/*＊＊＊＊＊＊＊＊＊＊显示通讯录＊＊＊＊＊＊＊＊*/
void mydisplay(Linklist* Lp)//显示通讯录
{
	printf("姓名           号码          性别 \n");
	Linklist l = (*Lp)->next;
	while (l != NULL)
	{
		printf("%-15s%-15s%-15s\n", l->name, l->number, l->sex);
		l = l->next;
	}
}
void studisplay(Stulist* Sp)//显示通讯录
{
	printf("姓名           号码          性别 \n");
	Stulist stu = (*Sp)->next;
	while (stu != NULL)
	{
		printf("%-15s%\n", stu->name);
		stu = stu->next;
	}
}
//进入 
void mystudisplay(Linklist* Lp) {

}
/*＊＊＊＊＊＊＊＊＊＊＊查找联系人＊＊＊＊＊＊＊＊＊＊*/
Status Findlist(Linklist* Lp)//查找联系人
{
	int c = 0;
	int sel;
	printf("请输入查询方式：\n 1:按姓名查询\n 2:按电话号码查询\n");
	Elemtype a[MAXSIZE];
	Elemtype b[MAXSIZE];
	while (1)
	{
		scanf_s("%d", &sel);
		getchar();
		Linklist p = (*Lp)->next;
		Linklist q = (*Lp)->next;
		switch (sel)
		{
		case 1:
			printf("请输入要查询的联系人姓名:\n");
			scanf_s("%s", a, 20);
			while (p != NULL)
			{
				if (strcmp(p->name, a) == 0)
				{
					printf("姓名           号码          性别\n");
					printf("%-15s%-15s%-15s\n", p->name, p->number, p->sex);
					c = 1;
				}
				p = p->next;
			}
			if (c == 0)
			{
				printf("该联系人不存在的哟！\n");
			}
			return 0;

		case 2:
			printf("请输入要查询人的电话号码:\n");
			scanf_s("%s", b, 20);
			while (q != NULL)
			{
				if (strcmp(q->number, b) == 0)
				{
					printf("姓名           号码          性别\n");
					printf("%-15s%-15s%-15s\n", q->name, q->number, q->sex);
					c = 1;
				}
				q = q->next;
			}
			if (c == 0)
			{
				printf("该电话号码不存在的哟！\n");
			}
			return 0;

		default:
			printf("无此查询方式\n");
			return 0;
		}
	}
}
Status Findstulist(Stulist* Sp)//查找同学
{  
	int c = 0;
	Elemtype a[MAXSIZE];
	Elemtype b[MAXSIZE];
	while (1)
	{
		getchar();
		Stulist p = (*Sp)->next;
		Stulist q = (*Sp)->next;
			printf("请输入要查询的同学姓名:\n");
			scanf_s("%s", a, 20);
			while (p != NULL)
			{
				if (strcmp(p->name, a) == 0)
				{
					printf("姓名");
					printf("%-15s%\n", p->name);
					c = 1;
				}
				p = p->next;
			}
			if (c == 0)
			{
				printf("该联系人不存在的哟！\n");
			}
			return 0;
	}
}
void Deletelist(Linklist* Lp)//删除联系人
{
	if ((*Lp)->next == NULL)
	{
		printf("当前通讯录为空，无法执行！\n");
	}
	else
	{
		int b = 0;
		Elemtype a[MAXSIZE];
		printf("请输入要删除的联系人\n");
		scanf_s("%s", a, 20);
		Linklist q;
		Linklist p = *Lp;
		while (p != NULL && p->next != NULL)
		{
			if (strcmp(p->next->name, a) == 0)
			{
				q = p->next;
				p->next = p->next->next;
				free(q);
				b = 1;
			}
			p = p->next;
		}
		if (b == 0)//判断循环是否执行，没执行的话，说明该联系人不存在。
			printf("该联系人不存在的哟！\n");
	}
}
void Deletestulist(Stulist* Sp)//删除同学人
{
	if ((*Sp)->next == NULL)
	{
		printf("当前班级同学为空，无法执行！\n");
	}
	else
	{
		int b = 0;
		Elemtype a[MAXSIZE];
		printf("请输入要删除的同学\n");
		scanf_s("%s", a, 20);
		Stulist q;
		Stulist p = *Sp;
		while (p != NULL && p->next != NULL)
		{
			if (strcmp(p->next->name, a) == 0)
			{
				q = p->next;
				p->next = p->next->next;
				free(q);
				b = 1;
			}
			p = p->next;
		}
		if (b == 0)//判断循环是否执行，没执行的话，说明该联系人不存在。
			printf("该同学不存在的哟！\n");
	}
}


/*＊＊＊＊＊＊＊＊＊＊修改联系人＊＊＊＊＊＊＊＊＊＊*/
void Reviselist(Linklist* Lp)//修改联系人
{
	Node* q = (Node*)malloc(sizeof(Node));
	if (q == NULL)
	{
		printf("申请失败");
	}

	if ((*Lp)->next == NULL)
	{
		printf("当前通讯录为空，无法执行！\n");
	}
	else
	{
		int i = 0;
		Elemtype a[MAXSIZE];
		Elemtype b[MAXSIZE];
		Elemtype c[MAXSIZE];
		Elemtype d[MAXSIZE];
		printf("请输入要修改的联系人姓名:\n");
		scanf_s("%s", a, 20);
		Linklist h;
		Linklist p = *Lp;

		while (p != NULL && p->next != NULL)
		{
			if (strcmp(p->next->name, a) == 0)
			{
				printf("请输入修改后的联系人姓名:\n");
				scanf_s("%s", b, 20);
				printf("请输入修改后的联系人号码:\n");
				scanf_s("%s", c, 20);
				printf("请输入修改后的联系人性别:\n");
				scanf_s("%s", d, 20);
				strcpy_s(q->name, b);
				strcpy_s(q->number, c);
				strcpy_s(q->sex, d);
				h = p->next;
				q->next = p->next->next;
				p->next = q;

				free(h);
				i = 1;
			}
			p = p->next;
		}
		if (i == 0)
			printf("你要修改的联系人不存在的哟！\n");
	}
}

void Revisestulist(Stulist* Sp)//修改同学
{
	Student* q = (Student*)malloc(sizeof(Student));
	if (q == NULL)
	{
		printf("申请失败");
	}

	if ((*Sp)->next == NULL)
	{
		printf("当前通讯录为空，无法执行！\n");
	}
	else
	{
		int i = 0;
		Elemtype a[MAXSIZE];
		Elemtype b[MAXSIZE];
		printf("请输入要修改的联系人姓名:\n");
		scanf_s("%s", a, 20);
		Stulist h;
		Stulist p = *Sp;

		while (p != NULL && p->next != NULL)
		{
			if (strcmp(p->next->name, a) == 0)
			{
				printf("请输入修改后的联系人姓名:\n");
				scanf_s("%s", b, 20);
				strcpy_s(q->name, b);
				h = p->next;
				q->next = p->next->next;
				p->next = q;

				free(h);
				i = 1;
			}
			p = p->next;
		}
		if (i == 0)
			printf("你要修改的同学不存在的哟！\n");
	}
}
/*＊＊＊＊＊＊＊＊＊对联系人进行排序＊＊＊＊＊＊＊＊＊＊*/
Status Sortlist(Linklist* Lp)//使用冒泡排序对通讯录进行排序
{
	if (*Lp == NULL)
	{
		printf("当前通讯录为空！\n");
		return FALSE;
	}
	char name[20];
	Node tmp, * r, * p, * q;
	r = (*Lp)->next;
	while (r)
	{
		p = r;
		q = r->next;
		while (q)
		{
			if ((strcmp(p->name, q->name) > 0))
			{
				strcpy_s(tmp.name, q->name);
				strcpy_s(q->name, p->name);
				strcpy_s(p->name, tmp.name);

				strcpy_s(tmp.number, q->number);
				strcpy_s(q->number, p->number);
				strcpy_s(p->number, tmp.number);

				strcpy_s(tmp.sex, q->sex);
				strcpy_s(q->sex, p->sex);
				strcpy_s(p->sex, tmp.sex);
			}
			q = q->next;
		}
		r = r->next;
	}

	printf("姓名           号码          性别\n");
	Linklist l = (*Lp)->next;
	while (l != NULL)
	{
		printf(" %-15s%-15s%-15s\n", l->name, l->number, l->sex);
		l = l->next;
	}

	return TRUE;
}

void mystudisplay(Stulist *Sp) {
		printf("请输入要查询的同学姓名:\n");
	Student* sp = *Sp;
	int c = 0;
	Elemtype a[MAXSIZE];
	Elemtype b[MAXSIZE];
	while (1)
	{
		Stulist p = (*Sp)->next;
		Stulist q = (*Sp)->next;
		scanf_s("%s", a, 20);
		while (p != NULL)
		{
			if (strcmp(p->name, a) == 0)
			{
				printf("姓名");
				printf("%-15s%\n", p->name);
				c = 1;
				sp = p;
				while (1) {
					int se1;
					printf("\t\tmenu: \n");
					printf("\t\t1:添加联系人\n");
					printf("\t\t2:查找联系人\n");
					printf("\t\t3:删除联系人\n");
					printf("\t\t4:修改联系人\n");
					printf("\t\t5:显示联系人\n");
					printf("\t\t6:对通讯录进行排序\n");
					printf("\t\t7:退出通讯录\n");
					printf("请输入要执行的功能所对应的序号，以回车键结束！\n");
					scanf_s("%d", &se1, 20);
					getchar();
					switch (se1)
					{
					case 1:
						Inserlist(&sp->Next);
						printf("*************************\n");//无实际意义，仅为输出界面美化
						break;
					case 2:
						Findlist(&sp->Next);
						printf("*************************\n");
						break;
					case 3:
						Deletelist(&sp->Next);
						printf("*************************\n");
						break;
					case 4:
						Reviselist(&sp->Next);
						printf("************************\n");
						break;
					case 5:
						mydisplay(&sp->Next);
						printf("*************************\n");
						break;
					case 6:
						Sortlist(&sp->Next);
						printf("**************************\n");
						break;
					case 7:
						begain(Sp);
						printf("**************************\n");
						break;
					default:
						break;

					}
				}
			}
			p = p->next;
		}
		if (c == 0)
		{
			printf("该联系人不存在的哟！\n");
		}
	}
	
}
void begain(Stulist* Sp) {

	Student* sp = *Sp;
	int se2;
	Elemtype a[MAXSIZE], b[MAXSIZE];
	while (1) {
		printf("\t\t1:添加同学\n");
		printf("\t\t2:查找同学\n");
		printf("\t\t3:删除同学\n");
		printf("\t\t4:修改同学\n");
		printf("\t\t5:显示同学\n");
		printf("\t\t6:进入同学\n");
		printf("\t\t7:退出同学\n");
		printf("请输入要执行的功能所对应的序号，以回车键结束！\n");
		scanf_s("%d", &se2, 20);
		getchar();
		switch (se2)
		{
		case 1:
			Inserstulist(&sp);
			printf("*************************\n");//无实际意义，仅为输出界面美化
			break;
		case 2:
			Findstulist(&sp);
			printf("*************************\n");
			break;
		case 3:
			Deletestulist(&sp);
			printf("*************************\n");
			break;
		case 4:
			Revisestulist(&sp);
			printf("************************\n");
			break;
		case 5:
			studisplay(&sp);
			printf("*************************\n");
			break;
		case 6:
			mystudisplay(&sp);
			printf("*************************\n");
			break;
		case 7:
			printf("*************************\n");
			system("clear");
			printf("成功退出！\n联系人已保存！\n");

		default:
			break;
		}
	}
}
int main()
{
	printf("*************************\n");
	Linklist Lp;
	Stulist Sp;
	Initstulist(&Sp,&Lp);
	begain(&Sp);
	return 0;
}
