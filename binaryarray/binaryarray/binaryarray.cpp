/*	Parker Davis
	binary sort of nums
	3/24/2015
	*/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
ifstream infile;

void bubsort(int numarray[],int size);
void bsearch(int numarray[],int size,int searchvalue, int ptr);
int main()
{
	int x,k;
	infile.open("u:\\cdata\\nums.dat");
	infile>>x;infile.ignore();
	int *num=new int[x];
	for (k=0;k<=x;k++)
	{
		infile>>num[k];cin.ignore();
	}
	bubsort(num,x);
	for (k=0;k<x;k++)
	{
		cout <<num[k]<<"\n";
	}

	system ("pause");
	return 0;
}
void bubsort(int numarray[],int size)
{
	int k,flag,temp;
	do
	{	
		flag=0;
		for (k=0;k<size-1;k++)
		{
			if (numarray[k]>numarray[k+1])
			{
				temp=numarray[k];
				numarray[k]=numarray[k+1];
				numarray[k+1]=temp;
			}
		}
		size=size-1;
	}while(flag!=0);
}
void bsearch(int numarray[],int size,int searchvalue, int &ptr)
{
	int top,btm;
	bool found=false;
	top=0;
	btm=size-1;
	do
	{
		ptr=int((top+btm)/2);
		if (numarray[ptr]>searchvalue)
		{ 
			btm=ptr-1;
		}
		if (numarray[ptr]<searchvalue)
		{ 
			btm=ptr+1;
		}
		if (numarray[ptr]==searchvalue)
		{
			found=true;
		}
		if (top>btm)
		{
			ptr=-1;
		}
	} while(!found&&ptr!=-1);
}


