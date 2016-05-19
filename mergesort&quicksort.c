/* 
Name: GAURAV SINHA

 Q: Implement merge sort and  quick sort
 */
 
#include<stdio.h>
int size;
    void merge(int arr[],int l ,int mid, int h)
{  int low=l,i=l,m=mid+1 ,temp_arr[size],k;
   while (low<=mid && m<=h)
     {
      if(arr[low]<=arr[m])
       {  temp_arr[i]=arr[low];
              low++;
    }
        else
        {  temp_arr[i]=arr[m];
             m++;
             }
               i++;
      }
        
              if(low>mid)
              { for(k=m;k<=h;k++)
		{ temp_arr[i]=arr[k];
                   i++;
              }
}
         else
       {  for(k=l;k<=mid;k++)
         {temp_arr[i]=arr[k];
          i++; 
       }           
}
          for(k=l;k<=h;k++)
	      arr[k]=temp_arr[k];
}
   int mergesort(int arr[], int l , int h)
 {
     if(l<h)
    {  int mid= l+(h-l)/2;
       mergesort(arr,l,mid);
      mergesort(arr,mid+1,h);
      merge(arr,l,mid,h);
   }
 return 0;
}

void quicksort(int x[10],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}



   int main()
 {  int n;
    printf("enter the selection \n:");
   scanf("%d",&n)
       switch (n)
      {
         case 1:
   {      int i;
    printf("enter the size \n");
     scanf("%d",&size);
     int arr[size];
     for(i=0;i<size;i++)
       scanf("%d",&arr[i]);
     mergesort(arr,0,size-1);
      
        printf("sorted array is \n");
         for(i=0;i<size;i++)        
       printf("%d \n",arr[i]);
       }
          case 2:
          {
  int x[20],size,i;

  printf("Enter size of the array: ");
  scanf("%d",&size);

  printf("Enter %d elements: ",size);
  for(i=0;i<size;i++)
    scanf("%d",&x[i]);

  quicksort(x,0,size-1);

  printf("Sorted elements: ");
  for(i=0;i<size;i++)
    printf(" %d",x[i]);
    }

         return 0;
         }
