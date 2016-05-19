/*Name:Gaurav Sinha

 
 Problem statement:
  Write a program  using functions for implementation of circular Queue?

 
 
 
*/


#include<stdio.h>
#include<stdbool.h>
#define n 100   //maximum size of the array that will store Queue. 
int queue[n];
int front=-1;
int rear=-1;

void enqueue(int x);
int  dequeue();
int front_ele();
bool isempty();
bool isfull();
void print();

 int main()                      //main function
{
 	int k,i=1,num,x;
while(i)
{	printf("enter the choice  \n1. enqueue\n2.dequeue\n3.	element show\n4.check whether queue is empty \n");
	scanf("%d",&k);       
      switch (k)             // implementing switch case for the choices
{   case 1:
        printf("enter the number to enqueue\n");
	scanf("%d",&x);
       enqueue(x);
	print();
            break;
    case 2:
	num=dequeue();
	printf("%d",num);
         print();
	break;
   case 3:
	num=front_ele();
        printf("%d",num);
	print();
	break;
    case 4:
        isempty();
	printf("queue is empty");
        break;
     default:
	printf("no cases matched re-enter\n");
	break;
 }
}
    return 0;
 }

     
   
     
	void enqueue(int x)   // Inserts an element in queue at rear end
{   int queue[n],front,rear;
        front=-1;
	rear=-1;
     if(isfull())
        { printf("queue is full");
   		return;
        }
     if(isempty())
	{   front=0;
 		rear=0;
        }
	else
       {  rear=(rear+1)%n;
            queue[rear]=x;
      }
}
      int  dequeue()	// Removes an element in Queue from front end. 
{ int num;
    if(isempty())
{     printf("queue is empty \n");
	return;
}
	else if (front==rear)
{        num=queue[front];
	 rear=-1;
	front=rear;
 return num;}
	else
{
        num=queue[front];
         front=(front+1)%n;
return num;
}
        
}
        int front_ele()  // Returns element at front of queue. 
{      if(front==-1)
 	{printf("empty queue cannot display first element");
	return -1;
	}
	else
	 return queue[front];
}

	bool isempty()  // To check wheter Queue is empty or not
{    if(front==-1 && rear ==-1)
      printf("queue is empty\n");
       return (-1);
  }
          
         bool isfull()  // To check whether Queue is full or not
  {    if(front=(rear+1)%n)
      printf("queue is full\n");
       return (front);
  }

          void print() //Printing the elements in queue from front to rear. 
{    int  iterations,i,index;
	iterations=(rear+n-front)%n +1;
       printf("queue	 is :	");
	for(i=0;i<iterations;i++)
	   {    index=front+i;
               printf("  %d",queue[index]);
	}
    printf("\n \n");
}

 
