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
Status Inserstulist(Stulist* Sp);//������ϵ��
void Initstulist(Stulist* Sp, Node* Lp);//��������г�ʼ��
void mydisplay(Linklist* Lp);
void studisplay(Stulist* Sp);//��ʾͨѶ¼
void Deletelist();
void Deletestulist(Stulist* Sp);//ɾ����ϵ��
Status Findlist(Linklist* Lp);
Status Findstulist(Stulist* Sp);//������ϵ��
void Reviselist();
void Revisestulist(Stulist* Sp);//�޸���ϵ��
Status Sortlist();//��ͨѶ¼��������
void studisplay(Linklist* Lp);//����ͬѧ
void begain(Stulist* Sp);

/*����������������������ʼ����������������������*/ 
void Initstulist(Stulist* Sp, Linklist* Lp) {
	Student* sp = (Student*)malloc(sizeof(Student));
	if (sp == NULL) {
		printf("����ʧ��");
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
			printf("����ʧ��");
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
/*���������������������������ϵ�ˣ�������������������*/
Status Inserlist(Linklist* Lp)//�����ϵ��
{
	Linklist L = *Lp;
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("����ʧ��");
		return FALSE;
	}
	else
	{
		Elemtype a[MAXSIZE];
		Elemtype b[MAXSIZE];
		Elemtype c[MAXSIZE];
		printf("������Ҫ�������ϵ������:\n");
		scanf_s("%s", a, 20);
		printf("������Ҫ�������ϵ�˺���:\n");
		scanf_s("%s", b, 20);
		printf("������Ҫ���ֵ���ϵ���Ա�:\n");
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
Status Inserstulist(Stulist* Sp)//�����ϵ��
{
	Stulist L = *Sp;
	Student* sp = (Student*)malloc(sizeof(Student));
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("����ʧ��");
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
		printf("����ʧ��");
		return FALSE;
	}
	else
	{
		Elemtype a[MAXSIZE];
		printf("������Ҫ�����ͬѧ����:\n");
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
/*����������������������ʾͨѶ¼����������������*/
void mydisplay(Linklist* Lp)//��ʾͨѶ¼
{
	printf("����           ����          �Ա� \n");
	Linklist l = (*Lp)->next;
	while (l != NULL)
	{
		printf("%-15s%-15s%-15s\n", l->name, l->number, l->sex);
		l = l->next;
	}
}
void studisplay(Stulist* Sp)//��ʾͨѶ¼
{
	printf("����           ����          �Ա� \n");
	Stulist stu = (*Sp)->next;
	while (stu != NULL)
	{
		printf("%-15s%\n", stu->name);
		stu = stu->next;
	}
}
//���� 
void mystudisplay(Linklist* Lp) {

}
/*����������������������������ϵ�ˣ�������������������*/
Status Findlist(Linklist* Lp)//������ϵ��
{
	int c = 0;
	int sel;
	printf("�������ѯ��ʽ��\n 1:��������ѯ\n 2:���绰�����ѯ\n");
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
			printf("������Ҫ��ѯ����ϵ������:\n");
			scanf_s("%s", a, 20);
			while (p != NULL)
			{
				if (strcmp(p->name, a) == 0)
				{
					printf("����           ����          �Ա�\n");
					printf("%-15s%-15s%-15s\n", p->name, p->number, p->sex);
					c = 1;
				}
				p = p->next;
			}
			if (c == 0)
			{
				printf("����ϵ�˲����ڵ�Ӵ��\n");
			}
			return 0;

		case 2:
			printf("������Ҫ��ѯ�˵ĵ绰����:\n");
			scanf_s("%s", b, 20);
			while (q != NULL)
			{
				if (strcmp(q->number, b) == 0)
				{
					printf("����           ����          �Ա�\n");
					printf("%-15s%-15s%-15s\n", q->name, q->number, q->sex);
					c = 1;
				}
				q = q->next;
			}
			if (c == 0)
			{
				printf("�õ绰���벻���ڵ�Ӵ��\n");
			}
			return 0;

		default:
			printf("�޴˲�ѯ��ʽ\n");
			return 0;
		}
	}
}
Status Findstulist(Stulist* Sp)//����ͬѧ
{  
	int c = 0;
	Elemtype a[MAXSIZE];
	Elemtype b[MAXSIZE];
	while (1)
	{
		getchar();
		Stulist p = (*Sp)->next;
		Stulist q = (*Sp)->next;
			printf("������Ҫ��ѯ��ͬѧ����:\n");
			scanf_s("%s", a, 20);
			while (p != NULL)
			{
				if (strcmp(p->name, a) == 0)
				{
					printf("����");
					printf("%-15s%\n", p->name);
					c = 1;
				}
				p = p->next;
			}
			if (c == 0)
			{
				printf("����ϵ�˲����ڵ�Ӵ��\n");
			}
			return 0;
	}
}
void Deletelist(Linklist* Lp)//ɾ����ϵ��
{
	if ((*Lp)->next == NULL)
	{
		printf("��ǰͨѶ¼Ϊ�գ��޷�ִ�У�\n");
	}
	else
	{
		int b = 0;
		Elemtype a[MAXSIZE];
		printf("������Ҫɾ������ϵ��\n");
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
		if (b == 0)//�ж�ѭ���Ƿ�ִ�У�ûִ�еĻ���˵������ϵ�˲����ڡ�
			printf("����ϵ�˲����ڵ�Ӵ��\n");
	}
}
void Deletestulist(Stulist* Sp)//ɾ��ͬѧ��
{
	if ((*Sp)->next == NULL)
	{
		printf("��ǰ�༶ͬѧΪ�գ��޷�ִ�У�\n");
	}
	else
	{
		int b = 0;
		Elemtype a[MAXSIZE];
		printf("������Ҫɾ����ͬѧ\n");
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
		if (b == 0)//�ж�ѭ���Ƿ�ִ�У�ûִ�еĻ���˵������ϵ�˲����ڡ�
			printf("��ͬѧ�����ڵ�Ӵ��\n");
	}
}


/*���������������������޸���ϵ�ˣ�������������������*/
void Reviselist(Linklist* Lp)//�޸���ϵ��
{
	Node* q = (Node*)malloc(sizeof(Node));
	if (q == NULL)
	{
		printf("����ʧ��");
	}

	if ((*Lp)->next == NULL)
	{
		printf("��ǰͨѶ¼Ϊ�գ��޷�ִ�У�\n");
	}
	else
	{
		int i = 0;
		Elemtype a[MAXSIZE];
		Elemtype b[MAXSIZE];
		Elemtype c[MAXSIZE];
		Elemtype d[MAXSIZE];
		printf("������Ҫ�޸ĵ���ϵ������:\n");
		scanf_s("%s", a, 20);
		Linklist h;
		Linklist p = *Lp;

		while (p != NULL && p->next != NULL)
		{
			if (strcmp(p->next->name, a) == 0)
			{
				printf("�������޸ĺ����ϵ������:\n");
				scanf_s("%s", b, 20);
				printf("�������޸ĺ����ϵ�˺���:\n");
				scanf_s("%s", c, 20);
				printf("�������޸ĺ����ϵ���Ա�:\n");
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
			printf("��Ҫ�޸ĵ���ϵ�˲����ڵ�Ӵ��\n");
	}
}

void Revisestulist(Stulist* Sp)//�޸�ͬѧ
{
	Student* q = (Student*)malloc(sizeof(Student));
	if (q == NULL)
	{
		printf("����ʧ��");
	}

	if ((*Sp)->next == NULL)
	{
		printf("��ǰͨѶ¼Ϊ�գ��޷�ִ�У�\n");
	}
	else
	{
		int i = 0;
		Elemtype a[MAXSIZE];
		Elemtype b[MAXSIZE];
		printf("������Ҫ�޸ĵ���ϵ������:\n");
		scanf_s("%s", a, 20);
		Stulist h;
		Stulist p = *Sp;

		while (p != NULL && p->next != NULL)
		{
			if (strcmp(p->next->name, a) == 0)
			{
				printf("�������޸ĺ����ϵ������:\n");
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
			printf("��Ҫ�޸ĵ�ͬѧ�����ڵ�Ӵ��\n");
	}
}
/*����������������������ϵ�˽������򣪣�����������������*/
Status Sortlist(Linklist* Lp)//ʹ��ð�������ͨѶ¼��������
{
	if (*Lp == NULL)
	{
		printf("��ǰͨѶ¼Ϊ�գ�\n");
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

	printf("����           ����          �Ա�\n");
	Linklist l = (*Lp)->next;
	while (l != NULL)
	{
		printf(" %-15s%-15s%-15s\n", l->name, l->number, l->sex);
		l = l->next;
	}

	return TRUE;
}

void mystudisplay(Stulist *Sp) {
		printf("������Ҫ��ѯ��ͬѧ����:\n");
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
				printf("����");
				printf("%-15s%\n", p->name);
				c = 1;
				sp = p;
				while (1) {
					int se1;
					printf("\t\tmenu: \n");
					printf("\t\t1:�����ϵ��\n");
					printf("\t\t2:������ϵ��\n");
					printf("\t\t3:ɾ����ϵ��\n");
					printf("\t\t4:�޸���ϵ��\n");
					printf("\t\t5:��ʾ��ϵ��\n");
					printf("\t\t6:��ͨѶ¼��������\n");
					printf("\t\t7:�˳�ͨѶ¼\n");
					printf("������Ҫִ�еĹ�������Ӧ����ţ��Իس���������\n");
					scanf_s("%d", &se1, 20);
					getchar();
					switch (se1)
					{
					case 1:
						Inserlist(&sp->Next);
						printf("*************************\n");//��ʵ�����壬��Ϊ�����������
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
			printf("����ϵ�˲����ڵ�Ӵ��\n");
		}
	}
	
}
void begain(Stulist* Sp) {

	Student* sp = *Sp;
	int se2;
	Elemtype a[MAXSIZE], b[MAXSIZE];
	while (1) {
		printf("\t\t1:���ͬѧ\n");
		printf("\t\t2:����ͬѧ\n");
		printf("\t\t3:ɾ��ͬѧ\n");
		printf("\t\t4:�޸�ͬѧ\n");
		printf("\t\t5:��ʾͬѧ\n");
		printf("\t\t6:����ͬѧ\n");
		printf("\t\t7:�˳�ͬѧ\n");
		printf("������Ҫִ�еĹ�������Ӧ����ţ��Իس���������\n");
		scanf_s("%d", &se2, 20);
		getchar();
		switch (se2)
		{
		case 1:
			Inserstulist(&sp);
			printf("*************************\n");//��ʵ�����壬��Ϊ�����������
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
			printf("�ɹ��˳���\n��ϵ���ѱ��棡\n");

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
