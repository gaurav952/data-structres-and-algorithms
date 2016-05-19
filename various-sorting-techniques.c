/*

Name: GAURAV SINHA
Group: CML1
Question: Q1

 Implement the following programs in C/C++/Python/Java using functions:
a) Insertion Sort
b) Bubble Sort
c) Selection Sort
d) Linear Search
e) Binary Search
f) Shell sort.
Display the total number of comparisons and swaps made by each searching/sorting function for the given input N. 
*/
#include <stdio.h>
    int insertionsort() //insertion sort

	{	int size,count;
		printf("enter the size");
 	 	scanf("%d",&size);
	    		int a[size],i,temp,j;
 		printf("enter the array");
		for(i=0;i<size;i++)
		 scanf("%d",&a[i]);
   		for(i=1;i<size;i++)
     		{ 	temp=a[i];
 			j=i-1;
			while(j>=0 && temp>a[j])
			{  count++;
                a[j+1]=a[j];
				j--;
			}
			a[j+1]=temp;
		}  
		for(i=0;i<size;i++)
   		printf("%d	\n",a[i]);
           printf("No. of comparisons and  swappings = %d",count);
		return 0;
          }  
          
   int  bubblesort() 			//bubble sort
	{ 	int size;
	   	printf("enter the size");
 		scanf("%d",&size);
		int a[size],j,temp,i;
		printf("enter the elements of array \n");
		for(i=0;i<size;i++)
		scanf("%d",&a[i]);
		for (i=0;i<size;i++)
		{  
			for (j=0;j<size-i-1;j++)
			{  if (a[j]>a[j+1])
				{  temp=a[j];
				   a[j]=a[j+1];
				   a[j+1]=temp;
				}
			}
		}
		 for(i=0;i<size;i++)
		printf("%d\n",a[i]);
 return 0;
 	}	
 	
 	int selectionsort()   // selection sort
  {  	int size,count1=0,count2=0;
        printf("enter the size \n");
	scanf("%d",&size);
	int i,j,temp,a[size+1],min;
	printf("enter the elements in the array");
	for(i=0;i<size;i++)
	  scanf("%d",&a[i]);
	for(i=0;i<size-1;i++)
	{      min=i;
        	for(j=i+1;j<size;j++)
		{ 	if(a[j]<a[i])
			count1++;
            { min=j;
			temp= a[i];
			a[i]=a[min];
			a[min]=temp;
			count2++;
             }
		}
	}
  for(i=0;i<size;i++)
	printf("%d \n",a[i]);
    printf(" No. of comparisons = %d \n",count1);
    printf(" No. of swappping = %d \n",count2);
	 return 0;
  }
  
  int l_search()  // linear  search
  { printf("enter the no. to be scanned  \n");
    int n,i,count=0;
    scanf("%d",&n);
    int a[8]={1,4,7,9,11,45,67,78};
    for(i=0;i<8;i++)
    { if(a[i]==n)
     { count++;
        break;}
       }
         printf("element found. index of the element is :%d \n no. of comparsions is: %d \n",i+1,count);
            return 0;
            	}
        
  
   int binary_search()   // binary search
{     printf("enter the number");
	int n;
	scanf("%d",&n);
	   int a[8]={1,4,7,9,11,45,67,78};
	 int  lo=0 , high=7, mid,count=0;
     while ( lo<=high)
      {  
	  mid=(lo+high)/2;		
 	if ( a[mid]==n)
         {  count++; 
         printf("index :%d",mid+1);
           return mid;
}
	else if ( a[mid]<n)
		lo=mid+1;
       	else
         high=mid-1;
       }
        printf(" \nno. of comparisons : %d",count);
  return 0;
}
 	
 	void shellsort()   // shell sort function
 {	int i,size,temp,gap,j;
 	printf("enter the size if array");
     	scanf("%d",&size);
	printf("%d",size);
	int a[size];
  	printf("ENTER THE elements \n");
	for(i=0;i<size;i++)	
	scanf("%d",&a[i]);
	for(gap=size/2;gap>0;gap=gap/2)
	    for(j=gap;j<size;j++)
	{     temp=a[j];		
		i=j;
		while(i>=gap && temp<a[i-gap])
		{    a[i]=a[i-gap];
			i=i-gap;
		}
			a[i]=temp;
	}
	
     for(i=0;i<size;i++)
	printf("%d \n",a[i]);
 }	
	
	int main()   // declaring  main function
{  printf("enter 1 for insertion sort , 2 for bubble sort , 3 for selection sort , 4 for linear search , 5  for binary  search and 6 for shell sort \n");
   		int n;
		scanf("%d",&n);
 	switch (n)     // implementing switch case for selection
 	{ case 1:
            { insertionsort();
              break;
              }
             case 2:
             { 
            bubblesort();
            break;
            }
            case 3:
            {
            selectionsort();
             break;
             }
            case 4:
             {l_search();
              break;
              }
            case 5:
            {binary_search();
            break;
            }
            case 6:
            { shellsort();
	     break;
	    }
	 }  
	  return 0;
	 }		

