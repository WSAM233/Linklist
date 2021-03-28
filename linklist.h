
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

typedef struct LNodeF{
	struct LNodeF *front;
	ElemType data;
	struct LNodeF *next;
}LNodeF, *LinkedListF;

//????????
typedef enum Status{
	ERROR,
	SUCCESS,
}status;

//???????????
status InitList(LinkedList *L)
{
	if(*L != NULL)
	{
		return ERROR;
	}
	LinkedList forw = *L, head = NULL;
	int i = 1, flag;
	(*L) = NULL;
	do
	{
		head = (LinkedList)malloc(LEN);
		if(i == 1)
		{
			*L = head;
			forw = head;
		}
		head->data = i++;
		forw->next = head;
		forw = head;
		printf("What would like to do next?\n");
		printf("1.continue to construct\n");
		printf("2.return to menu\n");
		do
		{
			flag = get_choice();
			if(flag == 1 || flag == 2) break;
			printf("%d is not 1 or 2,please try again.\n",flag);
			printf("What would like to do next?\n");
			printf("1.continue to construct\n");
			printf("2.return to menu\n");
		}while(1);
	}while(flag != 2);
	forw->next = NULL;
	return SUCCESS;
}

void DestroyList(LinkedList *L)
{
	if(*L == NULL)
	{
		printf("there is no linklist can destroy...QAQ\n");
		printf("go and construct a linklist for me.\n");
		return;
	}
	LinkedList L1 = NULL;
	while(*L != NULL)
	{
		L1 = *L;
		*L = (*L) -> next;
		free(L1);
		L1 = NULL;
	}
	printf("destruction complete!\n");
	printf("NO ONE CAN ESCAPE FROM THIS!\n");
}

enum Status InsertList(LNode *p, LNode *q)
{
	if(p == NULL || q == NULL)
	{
		return ERROR;
	}
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

enum Status DeleteList(LNode *p, ElemType *e)
{
	LinkedList q = NULL;
	if(p == NULL)
	{
		return ERROR;
	}

	q = p ->next;
	if(q == NULL)
	{
		printf("There is no data after the node you appoint.\n");
		return ERROR;
	}
	*e = q ->data;
	p -> next = q -> next;
	free(q);
	q = NULL;
	return SUCCESS;
}

void visit(ElemType e)
{
	printf("%d ",e);
}

void TraverseList(LinkedList *L, void (*visit)(ElemType e))
{
	if(*L == NULL)
	{
		printf("There is no data can show, please construct linklist first.\n");
	}
	LNode *p = NULL;
	p = *L;
	while(p != NULL)
	{
		(*visit)(p->data);
		p = p->next;
	}
	printf("\n");
}

status SearchList(LinkedList *L, ElemType e)
{
	if(*L == NULL)
	{
		printf("There is no data can search, please construct linklist first.\n");
		printf("You may construct the linklist first.\n");
		return ERROR;
	}
	LinkedList L1 = NULL;
	for(L1 = *L; L1 != NULL; L1 = L1 -> next)
	{
		if(L1 -> data == e)
		{
			return SUCCESS;
		}
	}
	printf("The data do not exist.\n");
	printf("Maybe you can try with other data.\n");
	return ERROR;
}

status ReverseList(LinkedList *L)
{
	if(*L == NULL)
	{
		return ERROR;
	}
	LinkedList p = NULL, pN = NULL, pB = NULL;
	p = *L; 
	pN = (*L)->next;
	while(pN != NULL)
	{
		p->next = pB;
		pB = p;
		p = pN;
		pN = pN->next;
	}
	p->next = pB;
	*L = p;
	return SUCCESS;
}

status IsLoopList(LinkedList *L)
{
	if(*L == NULL)
	{
		printf("There is no linklist can judge, please construct linklist first.\n");
		return ERROR;
	}
	LinkedList p1 = NULL, p2 = NULL;
	p1 = *L, p2 = *L;
	while(p1 != NULL && p2 != NULL) //???????,?????????NULL
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
	printf("Nope this is not a looplist.\n");
	return ERROR;
}

LNode* ReverseEvenList(LinkedList *L)
{
	if(*L == NULL)
	{
		printf("There is no Linkedlist can be reverse.\n");
		return *L;
	}
	LNode *p1 = NULL , *p2 = NULL, *p3 = NULL;
	for(p1 = *L; p1 != NULL && p1->next != NULL;p1 = p1->next)
	{
		p2 = p1 ->next;
		p1 ->next = p2 ->next;
		p2 ->next = p1;
		if(p3 != NULL)
		{
			p3->next = p2;
		}
		if(p1 == *L) 
		{
			*L = p2;
			p3 = p1;
		}
		else
		{
			p3 = p1;
		}
	}
	printf("Reverse complete!\n");
	return *L;
}

LNode* FindMidNode(LinkedList *L)
{
	if(*L == NULL)
	{
		printf("There is no linklist can find.\n");
		return NULL;
	}
	LinkedList p1 = NULL, p2 = NULL;
	p1 = *L;
	p2 = *L;
	while (p2 != NULL && p2->next != NULL)
	{
		p2 = p2->next;
		if (p2 == NULL)
		{
			break;
		}
		else
		{
			p2 = p2->next;
		}
		if(p2 == NULL) break;
		p1 = p1->next;
	}
	return p1;
}

LNode* GetNode(LinkedList *L)
{
	if(*L == NULL)
	{
		printf("There is no LinkedList can use.\n");
		printf("Go and construct a new LinkedList.\n");
		return NULL;
	}
	int data;
	LNode *p = NULL;
	printf("Please enter the data of the node you want to operate.\n");
	data = get_choice();
	for(p = *L; p != NULL; p = p->next)
	{
		if(p->data == data)
		{
			printf("Node get success.\n");
			return p;
		}
	}
	printf("Get fail.\n");
	printf("There is no data you want to operate.\n");
	return NULL;
}

LNode* SetupNode(LNode *p)
{
	int data;
	p = (LinkedList)malloc(LEN);
	printf("A new node is ready.\n");
	printf("Now enter a data for this node.\n");
	data = get_choice();
	p->data = data;
	p->next = NULL;
}

status InitListF(LinkedListF *L)
{
	if(*L != NULL)
	{
		return ERROR;
	}
	LinkedListF forw = *L, head = NULL;
	int i = 1, flag;
	(*L) = NULL;
	do
	{
		head = (LinkedListF)malloc(sizeof(struct LNodeF));
		if(i == 1)
		{
			*L = head;
			forw = head;
			forw->front = NULL;
		}
		else
		{
			head->front = forw;
		}
		head->data = i++;
		forw->next = head;
		forw = head;
		printf("What would like to do next?\n");
		printf("1.continue to construct\n");
		printf("2.return to menu\n");
		do
		{
			flag = get_choice();
			if(flag == 1 || flag == 2) break;
			printf("%d is not 1 or 2,please try again.\n",flag);
			printf("What would like to do next?\n");
			printf("1.continue to construct\n");
			printf("2.return to menu\n");
		}while(1);
	}while(flag != 2);
	forw->next = NULL;
	return SUCCESS;
}

void TraverseListF(LinkedListF *L, void (*visit)(ElemType e))
{
	if(*L == NULL)
	{
		printf("There is no data can show, please construct linklist first.\n");
	}
	LNodeF *p = NULL;
	p = *L;
	while(p != NULL)
	{
		(*visit)(p->data);
		p = p->next;
	}
	printf("\n");
}

LNode* ReverseOtherWay(LNode *up,LNode *cur)
{
	if(cur == NULL)
	{
		printf("There is no linklist can be reveerse\n");
		printf("Go and construct a new linklist.\n");
		return NULL;
	}
	if(cur->next == NULL)
	{
		cur->next = up;
		return cur;
	}
	else
	{
		LNode *HeadNode;
		HeadNode = ReverseOtherWay(cur,cur->next);
		cur->next = up;
		return HeadNode;
	}
}

int get_choice()
{
	int input;
	char ch;
	while (scanf("%d", &input) != 1)
	{
		while( (ch = getchar()) != '\n')
			putchar(ch);
		printf("\nthis is not an acceptable input.\n");
		printf("please enter an integer value.\n\n");
		
	}
	return input;
}

void menu()
{
	printf("====================================================\n");
	printf("chose the function you are going to use\n");
	printf("====================================================\n");
	printf("1.construct a new linklist\n");
	printf("2.traverse the linklist and output the data\n");
	printf("3.destroy the linklist which had been already built.\n");
	printf("4.reverse the linklist which had been already built.\n");
	printf("5.search the data in the linklist.\n");
	printf("6.delete the data in the linklist.\n");
	printf("7.insert a data into the linklist.\n");
	printf("8.judge the linklist whether is a looplist.\n");
	printf("9.find the midnode of linklist.\n");
	printf("10.reverse the evenlist.\n");
	printf("11.construct a new two-way linkedlist.\n");
	printf("12.traverse the two-way linklist and output the data\n");
	printf("13.reverse the linklist by using recursion\n");
	printf("0.quit\n");
} 

