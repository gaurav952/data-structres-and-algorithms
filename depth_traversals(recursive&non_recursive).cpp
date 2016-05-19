/*
Name-Gaurav Sinha

Problem Statement:    Write program using functions for binary tree traversals: Pre-order, In-order and Post-order using both Recursive and Non-recursive approach.
*/


#include<iostream>
#include<stack>
using namespace std;


struct node{
	int data;
	node *left;
	node *right;
};
node *root;

void insertion(node *h)
{
	    cout<<"\nENTER number to insert ";
		int item;
		cin>>item;
		node *New=new node();
		
	if(h==NULL)
	{
		root=New;
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

void InRec(node *h)
{
	if(h!=NULL)
	{
		InRec(h->left);
		cout<<h->data<<" ";
		InRec(h->right);
	}
	
}

void InNon(node *h)
{
	 stack<node *>S;
	 node *temp=h;
	 S.push(temp);
	 temp=temp->left;
	 while((S.size()!=0)||(temp!=NULL))
	 {
	 	if(temp!=NULL)
	 	{
	 		S.push(temp);
	 		temp=temp->left;
		}
		else 
		 {
		    temp=S.top();
		 	S.pop();
		 	cout<<temp->data<<" ";
		 	temp=temp->right;
		 }
		 	 	
	 }  
}

void PreRec(node *h)
{
	if(h!=NULL)
	{
		cout<<h->data<<" ";
		PreRec(h->left);
		PreRec(h->right);
	}
	
}

void PreNon(node *h)
{
	stack<node *>S;
	do
	{
		cout<<h->data<<" ";
		if(h->right!=NULL)
		S.push(h->right);
		if(h->left!=NULL)
		{
			h=h->left;
		}
		else
		{
			if(S.size()==0)
			break;
			h=S.top();
			S.pop();
		}
		
		
	}
		while(S.size()!=0||h!=NULL);
		
}

void PostNon(node *h)
{
	stack<node *>S;
	do
	{
		while(h!=NULL)
		{
			if(h->right!=NULL)
		    S.push(h->right);
			S.push(h);
			h=h->left;
	     	
		}
		
		h=S.top();
		S.pop();
		if(S.size()==0){
			cout<<h->data;
			break;
		}
		
		if(h->right!=NULL&&h->right==S.top())
		{
			S.pop();
			S.push(h);
			h=h->right;
		}
		else{
			cout<<h->data<<" ";
			h=NULL;
		}
	} 
	while(S.size()!=0);
}


void PostRec(node *h)
{
	if(h!=NULL)
	{
		PostRec(h->left);
		PostRec(h->right);
		cout<<h->data<<" ";		
	}
	
}

int main()
{
	root=NULL;
	int c;
	do{
		cout<<"\npress 1 for insertion\n";
		cout<<"press 2 to print inorder recursive\n";
		cout<<"press 3 to print inorder non recursive\n";
		cout<<"press 4 to print preorder recursive\n";
		cout<<"press 5 to print preorder non recursive\n";
		cout<<"press 6 to print postorder recursive\n";
		cout<<"press 7 to print postorder non recursive\n";
		cout<<"press -1 to exit\n";
		cin>>c;
		
		switch(c)
		{
			case 1:
				insertion(root);
				break;
				
									
				case 2:
				    InRec(root);
				    break;
				    
				    case 3:
				    	InNon(root);
				    	break;
				    	
				    	case 4:
				    		PreRec(root);
				    		break;
				    		
				    		case 5:
				    			PreNon(root);
				    			break;
				    			
				    			case 6:
				    				PostRec(root);
				    				break;
				    				
				    				case 7:
				    					PostNon(root);
				    					break;
							
		}
	
	}	
		while(c!=-1);
		return 0;
}
