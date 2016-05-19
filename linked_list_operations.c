/*


Problem Statement:  Write a program to perform following operations on Link List
a) Insertion 
	at the beginning
	at the end
	at the given location
in the sorted list
b) Deletion 
	of first node
	of last node
	of given item of node
	of given item from sorted list
c) Given a list, split it into two sublists — one for the front half, and one for the back half. 
If the number of elements is odd, the extra element should go in the front list. So 
FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7, 11}.
d) Given two one-way-link lists A and B. Sort them independently and then Merge as list.
e) Two way link list insertion and Deletion
f) Header link list insertion and deletion


Name:Gaurav Sinha




*/

#include<stdio.h>
#include<stdlib.h>
 struct node                         //defining  structure of one way linked list
  {
 	int data;
 	struct node* next;
  };

struct dnode 			//  defining structure of two way linked list
{
 int data;
 struct dnode* prv;
 struct dnode* next;
  };	
 struct node* head;
struct dnode* head2;



/*int delete_fn();
 void  insert(int data, int n);
 void print();
void insert_end(int n);
void split_linked_list();	
int delete_ln();
int delete_pr(int n);
void split_linked_list();
*/

   void insert(int  data,int n)						//insertion at n position
   { int i;
      struct node* temp1= (node*)malloc(sizeof(struct node));
	temp1->next=NULL;
 	temp1->data=data;
  	if( n==1)
	{
     		temp1->next=head;
		head=temp1;
       return;
	}
 	struct node* temp2=(node*)malloc(sizeof(node*));
          temp2=head;
        for(i=0;i<n-2;i++)
        {  temp2=temp2->next;				//  moving to the current location required
        }
  		temp1->next=temp2->next;
		temp2->next= head;

	 }

  void insert_beg(int n)				// insert at beginning
{  
	struct  node* temp=(node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->next=NULL;
	head=temp;
}   
   void insert_end(int n)                                     // inserting at the end
{ 	struct node* temp=(node*)malloc(sizeof(struct node));
           temp->data=n;
	   temp->next=NULL;
	struct node* temp2=(node*)malloc(sizeof(struct node));
        temp2=head;
      while(temp2->next!=NULL)
{    temp2=temp2->next;
}
    temp2=temp->next;
} 


void insert_sort(struct node* head,int data)                          // insertion in sorted list
{
	struct node* prev;
	struct node* temp=head;
	while(temp!=NULL)
	{
		prev=temp;
		if(temp->data<data)
		{
			temp=temp->next;
		}
		else
		break;
		
	}
	struct node* newNode=(node*)malloc(sizeof(struct node));
	newNode->next=prev->next;
	prev->next=newNode;
	
}

      int delete_fn()							//  deleting first node
{      struct node* temp=head;
      if (head==NULL)
   {  printf("list is empty\n");
      return -1;
   }
     else
{	head=(temp->next);
	 free(temp);	         
	printf("first node deleted\n");

}
return 0;
}

	int delete_ln()                                                 // deleting last node
{ int q,j;
	struct node* temp=head;
  struct node* prel;
     if (head=NULL)
{   printf("list empty \n");
    return -1;
}
       while(temp->next!=NULL)
{	prel=temp;    
	temp=temp->next;
         }
      	prel->next=NULL;
	free(temp);
    printf("last node deleted\n");
		return 0;

} 


     int delete_pr(int n)						// deleting particular node
{   struct node* temp=head;
         
    struct node* temp2=(node*)malloc(sizeof(struct node));
    
     while(temp->data==n)
{     temp2=temp;
temp=temp->next;
        }
	temp2=temp;
          temp=NULL;
 	free(temp);
}

void delete_sort(struct node* head,int data)				//deleting sorted linklist
{
	struct node* prev;
	struct node* temp=head;
	if(temp!=NULL && temp->data==data)
	{
		head=temp->next;
		free(temp);
		return;
	}
	
	while(temp!=NULL && temp->data!=data)
	{
		prev=temp;
		temp=temp->next;
	}
	
	if(temp==NULL)
	return;
	
	prev->next=temp->next;
	
	free(temp);	
}



  void split_linked_list()					//   splitting linked list
{ int num,i,num2,count;
	struct node* temp=(node*)malloc(sizeof(struct node));
          temp=head;
  if (head==NULL)
  {
  printf("linked list empty\n");
      return ;
}
       while(temp!=NULL)
{	temp=temp->next;
	count++;
}
    if(count%2==1)
      num=count/2 +1;
    struct node* first=(node*)malloc(sizeof(struct node));
    first=head;
	temp=head;
       for(i=0;i<num;i++)
{	   first->data=temp->data;
           first->next=temp->next;
		first=first->next;
		temp=temp->next;   	
 }
  first->next=NULL;
 
  struct node*  back=(node*)malloc(sizeof(struct node));
     num2=count-num-1;
	for(i=num;i<count;i++)
       {  back->data=temp->data;
	  back->next=temp->next;
	back=back->next;             
	temp=temp->next;
}
      back->next=NULL;

	printf("front linked list\n");     
	for(i=0;i<num;i++)
{       printf("%d	",first->data);
         first=first->next;        
  printf("\n");
    }
	printf("back list : \n");
      for(i=num2;i<count;i++)
  {	 printf("%d	",back->data);
      back=back->next;
	if(back==NULL)
      break;
      printf("\n");
   }
        
}


void insertion_dll(int num, int n)					// insertion  doubly linked list
    {   int i,count;
    	struct dnode* temp=(dnode*)malloc(sizeof(struct dnode));
         temp->data=num;
         temp->next=NULL;
         temp->prv=NULL;
    		struct dnode* temp1=(dnode*)malloc(sizeof(struct dnode));
    		temp1=head2;
    		if(head==NULL)
      {   printf("linked list is empty\n");
           head2=temp;
           temp->prv=head2;
           return;
           }
    	
    		for(i=0;i<n-2;i++)
    	  {
    	    temp1=temp1->next;
    	    }
    	   temp->prv=temp1;
    	   temp->next=temp1->next;
    	   temp->next->prv=temp;
    	   temp1->next=temp;
      
       temp=head2;    	   
 while(temp!=NULL)
    	          {  count++;
    	   temp=temp->next;
    	  }    
    	    if(n>count)
    	      {  printf("overflow\n"); 
    	           return;
    	            }
    	             }


   void deletion_dll(int n)						//deletion   doubly linked list
  { int i ,count ;
       struct  dnode* temp=(dnode*)malloc(sizeof(struct dnode));
       struct  dnode* temp1=(dnode*)malloc(sizeof(struct dnode));
         temp=head2;
         if(head==NULL)
           {  printf("list is empty\n");
                 return;
                 }  
           for(i=0;i<n-2;i++)
          {     temp1=temp;
              temp=temp->next;
    	    }
    	       temp1->next=temp->next;
    	       temp->prv=NULL;
    	        temp->next->prv= temp1;
    	        temp->next=NULL;
    	  temp=head2;
    	           while(temp!=NULL)
    	          {  count++;
    	   temp=temp->next;
    	  }    
    	    if(n>count)
    	      {  printf("overflow\n"); 
    	           return;
    	            }
    	             }
	


 void header_llins(int num,int n)							//headergrounded linked list insertion
   {   int count,i;
 	
   struct node* temp=(node*)malloc(sizeof(struct node));
     struct node* temp2=(node*)malloc(sizeof(struct node));
struct node* temp3=(node*)malloc(sizeof(struct node));
     temp2->data=100000;
     temp=temp2;
while(head!=NULL)
 { 	count++;
 	temp2=(temp2->next);
}
  // if(head=NULL)
{  printf("list is empty\n");
    return;
}
      head=temp;
   // head->next=temp;
//head=head->next;
     for(i=0;i<n-2;i++)
{     temp3=temp2; 
temp2=temp2->next;
}
        temp->data=num;
      temp->next=temp2;
       temp3->next=temp;
       }

  void headar_lldel(int n)								//header grounded linked list deletion
 { int i,count;
	  struct node* ptr=(node*)malloc(sizeof(struct node));
      ptr->data=0;
  struct node* temp=(node*)malloc(sizeof(struct node));
        temp=ptr;
 	while(temp!=NULL)
 { 	count++;
 	ptr=(ptr->next);
}
      ptr=temp;
 if(n<count)
{	for(i=0;i<n-2;i++)
  {   ptr->next=temp;
      temp=temp->next;
    }
   	  ptr->next=temp->next;
		temp->next=NULL;
 }

}



    node* mergeSort(struct node* a,struct node* b)                     //two one way link list sorting and merging
{
        node *result = NULL;
        if(a ==  NULL)
            return b;
        else if(b == NULL)
            return a;
     
        // For the first node
          if(a->data <= b->data){
             result = a;
            
             result->next = mergeSort(a->next,b);
          }
          else {
            result = b;
           /*Result's next will point to smaller one in lists 
             starting at a and b->next */
            result->next = mergeSort(a,b->next);
          }
          return result;
    }
      

void print()
{  struct node* ptr;
   ptr=head;
    while(ptr!=NULL)
   {   printf("%d",ptr->data);
	ptr=ptr->next;
    }
     }
  

int  main()
 {  head=NULL;
    head2=NULL;
     int n,num,k,x;
while(1)
{


  printf("enter the choice  from  1 to 12 \n");
 printf(" 1. insertion at nth postion\n 2.insert at beginning\n 3. insert at end\n 4.delete first node\n 5. delete last node \n 6.delete a  node containing given item \n 7. splitting of link list into two \n8.insertion in a doubly link list\n9.deletion in a doubly link list 10.insertion in sorted link list\n 11. deletion in a sorted link list \n12.sort two one way link list and merge\n");  
      printf("enter the choice\n");
      scanf("%d",&k);
	switch (k)
{
      case 1:
{	  printf("insert at nth position\n");
	  scanf("%d",&n);
	printf("enter the number\n");
	   scanf("%d",&num);
          printf("list is :	");
          insert(num,n);
          printf("\n");
break;
}
       case 2:
         { 
		printf("enter at the beginning \n");
	printf("enter the number: \n");
 		scanf("%d",&x);
		insert_beg(x);	
		print();
		break;
}


	case 3:
        {   printf("enter at the end\n");
		scanf("%d",&n);
               insert_end(n);
             print();
		 break;
}
       case 4:
    {        printf("delete first node \n");
	  delete_fn();
	print();
	break;
 }
     case 5:
{         printf("delete the last node \n");
	  delete_ln();
	print();
            break;
}
       case 6:
{         printf("delete the  node  containing the given item in linked list");
	num=scanf("%d",&num);
	  delete_pr(num);
	print();
	break;
	}
	case 7:
{	printf("splitting the link list\n");
         split_linked_list();
      print();
	      break;
}
        case 8:
    {	    printf("enter the number and location  for insertion\n");
    	   scanf("%d %d",&num,&n);
    	  insertion_dll(num,n);
    		print();
    	  break;
    }	
    	case 9:
    	{    printf("enter the location for deletion\n");
    	      scanf("%d",&n);
    	deletion_dll(n);
    		 print();
    	  break;       
    }	              
	case 10:
           {  printf("insertion in sorted list enter data\n");
    		scanf("%d",&num);
		insert_beg(3);
		insert_beg(2);
 		insert_beg(1);
		insert_sort(head,num); 
 		print();
		 break;
}

	case 11:
           {  printf("deletion in sorted list \n");
  		printf("enter the number to delete\n");
		scanf("%d",&num);
		insert_beg(3);
		insert_beg(2);
 		insert_beg(1);
		delete_sort(head,num);
		print();
		break;
}


	case 12:
  	{   printf("two one way link list  sorting individually and  merging \n");
		insert_beg(3);
		insert_beg(2);
 		insert_beg(1);
		node* a=head;
		insert_beg(34);
		insert_beg(223);
 		insert_beg(11);
		node* b=head;
		node* mergesort(node* a,node* b);
		print();
  		break;
}
    default:
	printf("wrong choice\n");
}
}		
return 0;
}



	
 
    	
