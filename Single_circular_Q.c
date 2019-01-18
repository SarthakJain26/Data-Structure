//peforming operations on single circular queue
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct qnode
{
	int data;
	struct qnode* next;
}*front,*rear;

//function to check whether the queue is empty or not
bool isempty()
{
	if(!front)
	return true;
	else
	return false;
}

//function to insert data in the queue
void insertq(int data)
{
	struct qnode* nn=(struct qnode*)malloc(sizeof(struct qnode));
	struct qnode* temp;
	nn->data=data;
	nn->next=NULL;
	if(isempty())
	{
		nn->next=nn;
		rear=front=nn;
		return;
	}
	rear->next=nn;
	nn->next=front;
	rear=nn;	
}


//function to delete node from the queue
void deleteq()
{
	struct qnode* temp=front;
	if(isempty())
	{
		printf("\n\tQUEUE IS ALREADY EMPTY \n\tPLEASE TRY SOMETHING ELSE ");
		return;
	}
	if(front==rear)
	{
		front=rear=NULL;
		printf("\n\t%d DELETED",temp->data);
		free(temp);
		return;
	}
	front=temp->next;
	printf("\n\t%d DELETED",temp->data);
	free(temp);
	rear->next=front;
}

//function to count the number of elements in the queue
int count()
{
	struct qnode *temp=front;
	int ctr=0;
	do
	{
		ctr++;
		temp=temp->next;
	}while(temp!=front);
	
	return ctr;
}

//fuction to update element at any position
void updateq(int key,int data)
{
	int a,y;
	a=key;
	int x=count();
	if(key>x)
	{
		printf("\n\tKEY IS TOO LARGE");
		return;
	}
	if(key<0)
	{
		printf("\n\tPLEASE ENTER A VALID KEY");
		return;
	}
	struct qnode* temp=front;
	if(isempty())
	{
		printf("\n\tQUEUE IS EMPTY \n\tITEM UPDATION FAILED!");
		return;
	}
	while(key--)
	{
		temp=temp->next;
	}
	y=temp->data;
	temp->data=data;
	printf("\n\tKEY UPDATED SUCCESFULLY! \n\tPREVIOUS DATA AT %d KEY : %d \n\tUPDATED DATA AT %d KEY : %d",a,y,a,temp->data);
}


//funtion to display the elements of the queue
void displayq()
{
	struct qnode* temp=front;
	if(isempty())
	{
		printf("\n\tQUEUE IS EMPTY!");
		return;
	}
	printf("\n\tELEMENTS IN THE QUEUE ARE : \n");
	do
	{
		printf("\t%d",temp->data);
		temp=temp->next;
	}while(temp!=front);
}

//finding smallest and largest element in the queue
void find()
{
	if(isempty())
	{
		printf("\n\tQUEUE IS EMPTY!");
		return;
	}
	struct qnode*temp=front;
	int small=front->data;
	int large=front->data;
	do
	{
		if(temp->data>large)
		{
			large=temp->data;
		}
		else if(temp->data<small)
		{
			small=temp->data;
		}
		temp=temp->next;
	}while(temp!=front);
	printf("\n\tSMALLEST ELEMENT IS : %d \n\tLARGEST ELEMENT IS : %d",small,large);
}

//function to swap kth node from begining with pth node from end
void swap(int k,int p)
{
	int i,j;
	int x=count();
	printf("x=%d\n",x);
	if(isempty())
	{
		printf("\n\tQUEUE IS EMPTY \n");
		return;
	}
	if(k>x||p>x)
	{
		printf("\n\tINALID POSITION\n");
		return;
	}
	if(k<0||p<0)
	{
		printf("\n\tINVALID POSITION\n");
		return;
	}
	if(k-1==(x-p))
	{
		printf("\n\tKth node from begining and pth node from end are at same position\n");
		return;
	}
		struct qnode* temp1=front;
		struct qnode* temp2=front;
		struct qnode* prev1=front;
		struct qnode* prev2=front;
		struct qnode* temp;

	if(k==1 || p==x)
	{
		prev1=rear;
	}
		
	else
	{
		for(i=1;i<k-1;i++)
		{
			prev1=prev1->next;
		}
	}
	temp1=prev1->next;
	temp=temp1->next;
	for(j=1;j<(x-p);j++)
	{
		prev2=prev2->next;
	}
	temp2=prev2->next;
	printf("%d %d\n",temp1->data,temp2->data);
	
	prev1->next=temp2;
	prev2->next=temp1;
	temp1->next=temp2->next;
	temp2->next=temp;
	if(k==1)
	{
		front=temp2;
	}
	if(p==1)
	{
		rear=temp1;
	}
	
	
} 
//fuction for finding pairs with given sum
void gisum(int sum)
{
if(isempty())
 	{
 		printf("\n\tQUEUE IS EMPTY");
 		return;
	}
   	
struct qnode *temp=front;
struct qnode *prev;
int flag=0;
do
{ 
	temp=temp->next; 
    for(prev=temp->next;prev!=front;prev=prev->next)
  	  {  
	  if(prev->data+temp->data==sum)
      	{
		printf("\n\t PAIR IS : %d , %d",prev->data,temp->data);
	  	flag=1;
    	}
	  }
}while(temp!=front);
if(flag==0)
printf("\n\tNO PAIR FOUND WITH THE GIVEN SUM");
}
//fuction to remove duplicate
void deldup()
 {
 	if(isempty())
 	{
 		printf("\n\tQUEUE IS EMPTY");
 		return;
	}
   struct qnode *temp=rear;
   struct qnode *agla;
   struct qnode *cur;
   struct qnode* prev;
   do
   {
   	   temp=temp->next;
       //printf("temp %d\n",temp->data);
       agla=temp->next;
       prev=temp;
	   do
	   { 
	    cur=agla; 
          if(agla->data==temp->data)
           {
		   	   agla=agla->next;
               free(cur);
               prev->next=agla;
           }
           else
           {
           		prev=prev->next;
               agla=agla->next;
		   }
        }while(agla!=front);
     }while(temp->next->next!=front);
     rear=temp->next;
     //printf("\nrear %d\n",rear->data);
   displayq();
   
}

void main()
{
	printf("\n\t OPERATIONS THAT CAN BE PERFORMED USING THIS PROGRAM : \n\n");
	int ch;
	int indata;
	int del,x,a;
	while(1)
	{
	printf("\n");
	printf("\n\t1:INSERT AN ELEMENT IN THE QUEUE");
	printf("\n\t2:DELETE AN ELEMENT FROM THE QUEUE");
	printf("\n\t3:DISPLAY ELEMENTS OF THE QUEUE");
	printf("\n\t4:UPDATE A KEY IN THE QUEUE");
	printf("\n\t5:FIND SMALLEST AND LARGEST ELEMENT");
	printf("\n\t6:SWAP TWO NODES");
    printf("\n\t7:FIND THE GIVEN SUM PAIR");
    printf("\n\t8:DUPLICATE DELETION");
	printf("\n\n\tPRESS ANY KEY TO EXIT!");
	printf("\n");
	printf("\n\tPLEASE ENTER YOUR CHOICE : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("\n\tENTER THE DATA YOU WANT TO INSERT : ");
			   scanf("%d",&indata);
			   insertq(indata);
			   printf("\n\tDATA INSERTED SUCCESFULLY!");
			   break;
		case 2:deleteq();
		       break;
		case 3:displayq();
			   break;
		case 4:printf("\n\tENTER THE KEY YOU WANT TO UPDATE : ");
			   scanf("%d",&x);
			   printf("\n\tENTER THE DATA TO REPLACE : ");
			   scanf("%d",&a);
			   updateq(x,a);
			   break;
		case 5:find();
			   break;
		case 6:printf("\n\tENTER THE Kth NODE FROM BEGINING : ");
			   scanf("%d",&x);
			   printf("\n\tENTER THE Pth NODE FROM END : ");
			   scanf("%d",&a);
			   swap(x,a);
			   break;
                 case 7:printf("\n\tENTER THE SUM TO BE FOUND: ");
                        scanf("%d",&x);
                        gisum(x);
                         break;
                case 8:printf("\n\tDUPLICATE DELETION:");
                        deldup();
                        break;	 	 
		default:exit(0);	   	   	   	   		
	}
  }
}
