#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main(){
	int select, data, ele, *e;
	LNode *head = NULL, *p1 = NULL, *p2 = NULL;
	LNodeF *headF=NULL;
	void (*pvisit)(ElemType) = visit;
	e = &ele;
	menu();	
	while(1)
	{
		select = get_choice();
		switch(select)
		{
		case 0:	return;
		case 1:	printf("excuting method 1\n\n");
				if((InitList(&head) ) == SUCCESS)
				{
					printf("Construct complete!\n");
				}
				else
				{
					printf("Construct fail!\n");
					printf("The linklist have been construct.\n");
					printf("You can destory it to construct a new one.\n");
				}
				break;
		case 2:	printf("excuting method 2\n\n");
				TraverseList(&head,pvisit);
				break;
		case 3:	printf("excuting method 3\n\n");
				DestroyList(&head);
				break;
		case 4:	printf("excuting method 4\n\n");
				if((ReverseList(&head)) == SUCCESS)
				{
					printf("Reverse complete!\n");
				}
				else
				{
					printf("Reverse fail...\n");
					printf("There is no linklist can reverse\n");
					printf("Go and construct a new linklist\n");
					printf("Returning to the menu.\n\n");
				}
				break;
		case 5:	printf("Enter the data you want to search.\n");
				data = get_choice();
				printf("Excuting method 5\n\n");
				if( (SearchList(&head,data)) == SUCCESS )
				{
					printf("Search complete!\n");
					printf("The data exist in the linklist\n");
					printf("Returning to the menu.\n");
				}
				else
				{
					printf("Search fail!\n");
					printf("Returning to the menu.\n");
				}
				break;
		case 6:	printf("Excuting method 6\n\n");
				if( (p1 = GetNode(&head)) == NULL)
				{
					printf("Delete fail.\n");
					printf("Returning to the menu.\n");
				}
				else
				{
					if( ( DeleteList(p1,e) ) == SUCCESS)
					{
						printf("Delete success\nThe data you delete is %d\n",*e);
						printf("Returning to the menu.\n");
					}
					else
					{
						printf("Delete fail.\n");
						printf("Returning to the menu.\n");	
					}
				}
				break;
		case 7:	printf("Excuting method 7\n\n");
				if( (p1 = GetNode(&head)) == NULL)
				{
						printf("Insert fail.\n");
						printf("Returning to the menu.\n");
				}
				else
				{
					if( (p2 = SetupNode(p2)) == NULL)
					{
						printf("Insert fail.\n");
						printf("Returning to the menu.\n");	
					}
					else
					{
						if( (InsertList(p1,p2)) == SUCCESS)
						{
							printf("Insert success.\n");
							printf("Returning to the menu.\n");
						}
						else
						{
							printf("Insert fail.\n");
							printf("Returning to the menu.\n");
						}
					}
				}
				break;
		case 8:	printf("Excuting method 8\n\n");
				if( (IsLoopList(&head)) == SUCCESS)
				{
					printf("Yes is a looplist.\n");
				}
				printf("Judge complete.\n");
				printf("Returning to the menu.\n");
				break;
		case 9:	printf("Excuting method 9\n\n");
				if( (p1 = FindMidNode(&head)) != NULL)
				{
					printf("The data of the midnode is %d\n",p1->data);
					printf("Finding complete.\n");
				}
				else
				{
					printf("Finding fail.\n");
				}
				printf("Returning to the menu.\n");
				break;		
		case 10:printf("Excuting method 10\n\n");
				ReverseEvenList(&head);
				break;
		case 11:printf("Excuting method 11\n\n");
				if((InitListF(&headF)) == SUCCESS)
				{
					printf("Construct complete!\n");
				}
				else
				{
					printf("Construct fail!\n");
					printf("The linklist have been construct.\n");
					printf("You can destory it to construct a new one.\n");
				}
				break;
		case 12:printf("Excuting method 12\n\n");
				TraverseListF(&headF,pvisit);
				break;
		case 13:printf("Excuting method 13\n\n");
				if( (head = ReverseOtherWay(NULL,head)) == NULL)
				{
					printf("Reverse fail\n");
					printf("Returning to menu\n");
				}
				else
				{
					printf("Reverse complete\n");
					printf("Returning to menu\n");
				}
				break;
		}
		menu();
	}
}


