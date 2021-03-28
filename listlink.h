
#include <malloc.h>
#define LEN sizeof(struct LNode)
//???????????????????
//????????
typedef int ElemType;

//?????????
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkedList;

//????????
typedef enum Status{
	ERROR,
	SUCCESS
};

//???????????
Status InitList(LinkedList L)
{
	LNode* p1 = NULL, * p2 = NULL;
	if (L == NULL)
	{
		L = (struct LNode*)malloc(LEN);
		L->data = 1;
		L->next = NULL;
	}
	else
	{
		p1 = L;
		while (p1->next != NULL)
		{
			p1 = p1->next;
		}
		p2 = (struct LNode*)malloc(LEN);
		p1->next = p2;
		p2->data = p1->data + 1;
		p2->next = NULL;
	}
	return SUCCESS;
}

void DestroyList(LinkedList L)
{
	LinkedList L1 = NULL;
	while(L != NULL)
	{
		L1 = L;
		L = L -> next;
		free(L1);
	}
	L1 = NULL;
}

Status InsertList(LNode *p, LNode *q)
{
	if(p == NULL || q == NULL)
	{
		return ERROR;
	}

	q = p -> next;
	p -> next = q;

	if(p -> next == q)
	{
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

Status DeleteList(LNode *p, ElemType *e)
{
	LinkedList *q = NULL;
	if(p == NULL)
	{
		return ERROR;
	}

	q = p ->next;
	*e = q ->data;
	p -> next = q -> next;
	free(q);
	q = NULL;
	return SUCCESS;
}

void visit(ElemType e)
{
	printf("%d",e);
}

void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	LNode *p = NULL;
	p = L;
	while(p != NULL)
	{
		*visit(p->data);
		p = p->next;
	}
}

Status SearchList(LinkedList L, ElemType e)
{
	int i;
	LinkedList L1 = NULL;
	for(L1 = L; L1 != NULL; L1 = L1 -> next)
	{
		if(L1 -> data == e)
		{
			return SUCCESS;
		}
	}
	return ERROR;
}

Status ReverseList(LinkedList L)
{
	LinkedList p = NULL, pN = NULL, pB = NULL;
	p = L; 
	pN = L->next;
	while(pN != NULL)
	{
		p->next = pB;
		pB = p;
		p = pN;
		pN = pN->next;
	}
	p->next = pB;
	L = p;
	return SUCCESS;
}

Status IsLoopList(LinkedList L)
{
	LinkedList p1 = NULL, p2 = NULL;
	p1 = L, p2 = L;
	while(p1 != NULL || p2 != NULL) //???????,?????????NULL
	{
		p1 = p1->next;
		p2 = p2->next;
		if (p2 == NULL)            //??p2???NULL?????????????,????????
		{
			break;
		}
		else                      //??p2??NULL??p2???????
		{
			p2 = p2->next;
		}
		if (p1 == p2)
		{
			return SUCCESS;
		}
	}
	return ERROR;
}

LNode* ReverseEvenList(LinkedList L)
{

}

LNode* FindMidNode(LinkedList L)
{
	LinkedList p1 = NULL, p2 = NULL;
	p1 = L;
	p2 = L;
	while (p2 != NULL || p2->next != NULL)
	{
		p2 = p2->next;
		if (p2->next == NULL)
		{
			break;
		}
		else
		{
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return p1;
}

void menu()
{
	printf("请选择你要使用的功能\n");
	printf("====================\n");
} 
