/*	Name:Gaurav Sinha
	
	Problem Statement:    Implement following problems using Greedy Approach:	Partial knapsack

*/

#include<iostream>
using namespace std;
 
void pknapsack_fill()
 {	int n,i,W,check;
	float k;
     cout<<"enter the length of knapsack \n";
   cin>>n;
     cout<<"enter the  weights of small bottles in knapsack\n";
 	int weight[n],value[n];
	for(i=0;i<n;i++)
      	cin>>weight[i];
 cout <<"enter the cost of bottle  available to be filled in knapsack";
		for(i=0;i<n;i++)
		cin>>value[i];
   		cout<<"enter the total weight of knapsack\n";
		cin>>W;	
	int cur_w;
    	float tot_v;
	int maxprf;
	int used[n];

	for (i=0;i<n;i++)
	used[i] = 0;
 	cur_w = W;

    while (cur_w>0) 
{	maxprf = -1;
	for (i=0;i<n;++i)
	if ((used[i] == 0)&&(maxprf==-1) ||((float)value[i]/weight[i] - (float)value[maxprf]/weight[maxprf]))
		maxprf = i;
		used[maxprf] = 1;

        cur_w -= weight[maxprf];
	tot_v += value[maxprf];

        if (cur_w >= 0)
		cout<<"Added object"<<maxprf+1<<"\t"<<value[maxprf]<<"\t"<<weight[maxprf]<<"\tcompletely in the bag. Space left: \n"<< cur_w;

        else {
		 k=(1 + (float)cur_w/weight[maxprf]);
            cout<<"Added"<< (int)((1 + (float)cur_w/weight[maxprf]) * 100)<<"\t"<<value[maxprf]<<"\t"<<weight[maxprf]<<"\tof object "<<maxprf+1<<" 						in the bag.\n";

            tot_v -= value[maxprf];
		tot_v +=(1 + (float)cur_w/weight[maxprf])* value[maxprf];
	     }
		    }
		    cout<<"Filled the bag with objects worth $.\t"<<tot_v;
}

	int main()
    {
		pknapsack_fill();
 		
  return 0;
}
