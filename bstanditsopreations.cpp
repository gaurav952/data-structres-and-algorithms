/*
Name-Gaurav Sinha

Problem Statement :    Implement following functions for Binary Search Trees
a)	Search a given item (Recursive & Non-Recursive)
b)	Insertion of a new node
c)	Maximum element of the BST
d)	Minimum element of the BST
e)	Successor of the BST
f)	Delete a given node from the BST
*/
#include<iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};
node *head;

void insertion(node *h)
{
	    cout<<"\nENTER number to insert ";
		int item;
		cin>>item;
		node *New=new node();
		
	if(h==NULL)
	{
		head=New;
		New->data=item;
		New->left=New->right=NULL;
		return;
	}
	else
	{
		while(true)
		{
			if(item<=h->data&&h->left==NULL)
		    {
			h->left=New;
			New->data=item;
			New->left=New->right=NULL;
			 cout<<"\nelement inserted to left";
            break;
		    }
		    else if(item<=h->data)
		    h=h->left;
		    else{
		    	if(h->right==NULL)
		    	{
		    	    h->right=New;
					New->data=item;
			        New->left=New->right=NULL;	 
			        cout<<"\nelement inserted to right";
					break;	
				}
				else
				h=h->right;
			}
	    }
	}
}

void search(node *h)
{
	cout<<"\nEnter number to be searched ";	
	int item;
	cin>>item;
	
	{
		while(true)
		{
			if(h==NULL)
	        {
		        cout<<"\nItem not found\n";
		        break;
	        }
			else if(item==h->data)
			{
				cout<<"\nItem found\n";
				break;
			}
			else if(item<h->data)
		    {
				h=h->left;
		    }
		    else
			{
				h=h->right;
			}
	    }
	}
}

void minimum(node *h)
{
	if(h==NULL)
	cout<<"\nEmpty tree\n";
	else if(h->left==NULL)
	cout<<"\nMinimum="<<h->data<<"\n";
	else
	minimum(h->left);
}

int maximum(node *h)
{
	if(h==NULL)
	cout<<"\nEmpty tree\n";
	else if(h->right==NULL)
	cout<<"\nMaximum="<<h->data<<"\n";
	else
	maximum(h->right);
}

void successor(node *h)
{
	cout<<"\nEnter number whose successor is to be searched ";	
	int item;
	cin>>item;
	
		while(true)
		{
			if(h==NULL)
	        {
		        cout<<"\nItem not found!Neither will be successor\n";
		        break;
	        }
			else if(item==h->data)
			{
			    if(h->right==NULL)
			    {
			    	cout<<"\nNo Successor\n";
				}
			
				else
				{
						h=h->right;
					while(true)
					{
						if(h->left==NULL)
						{
							cout<<"\nSuccessor="<<h->data<<"\n";
							break;
						}
						else
						{
							h=h->left;
						}
					}
				}
				break;
			}
			else if(item<h->data)
		    {
				h=h->left;
		    }
		    else
			{
				h=h->right;
			}
	    }
}

void deletion(node *h,int item)
{
	node *parent=NULL;
	int l=0,r=0;
		while(true)
		{
			if(h==NULL)
	        {
		        cout<<"\nItem not found and thus cannot be deleted\n";
		        break;
	        }
			else if(item==h->data)
			{
				if(h->left==NULL&&h->right==NULL)
				{
					if(parent==NULL)
					head=NULL;
					else if(l=1)
					parent->left=NULL;
					else
					parent->right=NULL;
				}
				else if(h->left!=NULL&&h->right!=NULL)
				{
					node *h1=h;
					h=h->right;
					node *parent1=h;
					while(true)
					{
						if(h->left==NULL)
						{
							h1->data=h->data;
							h1->right=h->right;
							
							break;
						}
						else
						{
							parent1=h; 
							h=h->left;
						}
						
					}
				}
				else if(h->left==NULL)
				{
					if(l=1)
					parent->left=h->right;
					else
					parent->right=h->right;
				}
				else
				{
				    if(l=1)
					parent->left=h->left;
					else
					parent->right=h->left;
				}
					
				break;
			}
			else if(item<h->data)
		    {
		    	parent=h;
		    	l=1;r=0;
				h=h->left;
		    }
		    else
			{
				parent=h;
				r=1;l=0;
				h=h->right;
			}
	    }
	
}
void print(node *h)
{
	if(h!=NULL)
	{
		print(h->left);
		cout<<h->data<<" ";
		print(h->right);
	}
	
}

int main()
{
	head=NULL;
	int c;
	do{
		cout<<"\npress 1 for insertion\n";
		cout<<"press 2 for searching\n";
		cout<<"press 3 for minimum\n";
		cout<<"press 4 for maximum\n";
		cout<<"press 5 for successor\n";
		cout<<"press 6 for deletion\n";
		cout<<"press 7 to print inorder\n";
		cout<<"press -1 to exit\n";
		cin>>c;
		
		switch(c)
		{
			case 1:
				insertion(head);
				break;
				
				case 2:
					search(head);
					break;
					
					case 3:
						minimum(head);
						break;
						
						case 4:
							maximum(head);
							break;
							
							case 5:
								successor(head);
								break;
								
								case 6:
									cout<<"\nEnter number you want to delete";	
									int item;
									cin>>item;
									deletion(head,item);
									break;
									
									case 7:
										print(head);
										
								     	default:
										break;
							
		}
	
	}	
		while(c!=-1);
		return 0;
}
