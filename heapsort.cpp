/*  Name: Gaurav Sinha
    
Problem Statement :    Implement Heap Sort. */

#include<iostream>
using namespace std;
 class heap
 { public :
 
       void max_heap(int a[],int n)
	{ int i;    //a.heapsize=a.length();
              for(i=n / 2 -1;i>=0;i--)
		 max_heapify(a,n,i);
         }
   	    void max_heapify(int a[],int n,int i)
 	{
		int l=2*i+1,r=2*i+2,largest=i,temp;
             if(l<n&& a[i]<a[l])
               largest=l;
              if(r<n&& a[i]<a[r])
               largest=r;
		if (largest!=i)
		{ temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		max_heapify(a,n,largest);
         }
		}

             void heapsort(int a[],int n)
    	{    int temp,i;
		 max_heap(a,n);
  		for(i=n-1;i>=0;i--)
		swap(a[0],a[i]);
                         max_heapify(a,i,0);
            }
	
		void print(int a[],int n)
          {int i;
		cout<<"elements in array after sorting\n";
                for(i=0;i<n;i++)
 		  {	cout<<a[i];
			cout<<"\n";
	             }
		}
	};
 

	int main()
{	int n,i;
	 cout<<"enter the size of array\n";
	cin>>n;
	int a[n];
	cout<<"enter the elements\n";
   	for(i=0;i<n;i++)
          cin>>a[i];
       
        heap  h;	
       h.heapsort(a,n);
	h.print(a,n);  
	
  return 0;
 }
         

		     	 
	    
        
