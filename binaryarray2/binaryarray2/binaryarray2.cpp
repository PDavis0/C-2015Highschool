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

void bubsort(int num[],int size);
void bsearch(int numarray[],int size,int searchvalue, int &ptr);
int main()
{
	int size,k,check,usernum;
	
	infile.open("u:\\cdata\\NUMS.DAT");
	infile>>size;infile.ignore();
	int *num=new int[size];
	for (k=0;k<size;k++)
	{
		infile>>num[k];infile.ignore();
	}
	bubsort(num,size);
	do
	{
		cout <<"what number would you like to search, (-1 to end)\n";
		cin>>usernum;cin.get();
		if (usernum!=-1)
		{
			bsearch(num,size,usernum,check);
			if (check==-1)
			{
				cout <<"there is no "<<usernum<<" in the array\n";
			}
			if (check!=-1)
			{
				cout <<"the array found it!\n";
			}
		}
	}while(usernum!=-1);


	system ("pause");
	return 0;
}
void bubsort(int num[],int size)
{
	int k,flag,temp;
	do
	{	
		flag=0;
		for (k=0;k<size-1;k++)
		{
			if (num[k]>num[k+1])
			{
				temp=num[k];
				num[k]=num[k+1];
				num[k+1]=temp;
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


