/*

Name: GAURAV SINHA

Creating a class of 50 students with their details and
performing linear search,bubble sort,binary search and
insertion sort on the data.
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class student                               //creating a class
{
public:    // public variable declaration
	int regno;
	char name[50];
	char branch[10];
	float cgpa;
};
void insertdata(class student s[])                //inserting data
{
	int i;
	cout<<"Enter details of students";
	for(i=0;i<50;i++)
	{
		cout<<"\nEnter reg. no of "<<i+1<<" student";
		cin>>s[i].regno;
		cout<<"\nEnter name of "<<i+1<<" student";
		cin>>s[i].name;
		cout<<"\nEnter branch of "<<i+1<<" student";
		cin>>s[i].branch;
		cout<<"\nEnter cgpa of "<<i+1<<" student";
		cin>>s[i].cgpa;
	}
}  
void linsearch(class student s[])                  //linear search function
{
	int i,rno,loc,flag;
	cout<<"\nEnter regno of student to be searched";
	cin>>rno;
	for(i=0;i<50;i++)
	{
		if(rno==s[i].regno)
		{
		loc=i;
		flag=1;
		break;
	}
	}
	if(flag==1)
	{
	cout<<"\nName: "<<s[loc].name;
	cout<<"\nBranch: "<<s[loc].branch;
	cout<<"\nCgpa: "<<s[loc].cgpa;
    }
    else
    cout<<"record not found";
}
void bsort(class student s[])                //bubble sort function
{
    int i,j,temprno;
    char tempname[50];
    char tempbranch[10];
    float tempcgpa;
	for(i=0;i<50;i++)
	{
		for(j=0;j<50;j++)
		{
			if(s[j].regno>s[j+1].regno)
			{
				temprno=s[j].regno;
			    s[j].regno=s[j+1].regno;
				s[j+1].regno=temprno;
				strcpy(tempname,s[j].name);
				strcpy(s[j].name,s[j+1].name);
				strcpy(s[j+1].name,tempname);
				strcpy(tempbranch,s[j].branch);
				strcpy(s[j].branch,s[j+1].branch);
				strcpy(s[j+1].branch,tempbranch);
				tempcg=s[j].cgpa;
				s[j].cg=s[j+1].cgpa;
				s[j+1].cgpa=tempcg;
			}
		}
	}
	
	cout<<"\nSorted results\n";
	for(i=0;i<50;i ++)
	{
		cout<<"\nRegistration no. "<<s[i].regno<<"\n";
		cout<<"Name "<<s[i].name<<"\n";
		cout<<"Branch "<<s[i].branch<<"\n";
		cout<<"CGPA "<<s[i].cgpa<<"\n";
	}
}
void bsearch(class student s[])                       //binary search function
{
    int start,last,t,mid,loc;
    bsort(s);
    cout<<"Enter reg no of data to be Searched";
	cin>>t;
	start=0;
	last=50;
	
	while(start<last)
	{
		mid=(start+last)/2;
		if(s[start].regno==t)
		{
		loc=start+1;
		break;
	    }
	    if(s[last].regno==t)
		{
		loc=last+1;
		break;
	    }
		
		if(s[mid].regno==t)
		{
		loc=mid;
		break;
	    }
		if(t<s[mid].regno)
		last=mid-1;
		if(t>s[mid].regno)
		start=mid+1;
	}
	cout<<"\nName: "<<s[loc].name;
	cout<<"\nBranch: "<<s[loc].branch;
	cout<<"\nCgpa: "<<s[loc].cgpa;
}
void isort(class student s[])                    //insertion sort function
{
  int i,j,temprno;
    char tempname[50];
    char tempbranch[50];
    float tempcg;
	for(i=1;i<50;i++)
	{
		for(j=i;j>=1;j--)
		{
			if(s[j].cgpa>s[j-1].cgpa)
			{
				temprno=s[j].regno;
			    s[j].regno=s[j-1].regno;
				s[j-1].regno=temprno;
				strcpy(tempname,s[j].name);
				strcpy(s[j].name,s[j-1].name);
				strcpy(s[j-1].name,tempname);
				strcpy(tempbranch,s[j].branch);
				strcpy(s[j].branch,s[j-1].branch);
				strcpy(s[j-1].branch,tempbranch);
				tempcg=s[j].cgpa;
				s[j].cgpa=s[j-1].cgpa;
				s[j-1].cgpa=tempcgpa;
			}
		}
	}
	
	cout<<"\nSorted results\n";
	for(i=0;i<50;i ++)
	{
		cout<<"\nRegistration no. "<<s[i].regno<<"\n";
		cout<<"Name "<<s[i].name<<"\n";
		cout<<"Branch "<<s[i].branch<<"\n";
		cout<<"CGPA "<<s[i].cgpa<<"\n";
	}   
}
int main()                                  //main function
{
    student s[5];
    int f;
    insertdata(s);
    while(f!=5)
    {
    cout<<"Enter choice:\n";
    cout<<"1.Linear Search\n2.Bubble Sort\n3.Binary Search\n4.Insertion Sort\n5.Exit";
    cin>>f;
    switch(f)
    {
	case 1:
	linsearch(s);
	break;
	case 2:
	bsort(s);
	break;
	case 3:
	bsearch(s);
	break;
	case 4:
	isort(s);
	break;
	default:
	exit(0);
    }
    }
return 0;
}
