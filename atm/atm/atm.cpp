/*	Programer:Parker Davis
	ATM transaction program
	4/15/2015
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
ifstream infile;
void bubsort(int num[],string name[],float check[],float save[], int size);
string format_num(float num);
void bsearch(int num[],int size,int searchvalue, int &ptr);
void printaccount(string name[],int accountnum[],float check[],float savings[],int size);

int main()
{
	//VARIABLE**************************DESCRIPTION
	//name[]							Name with account
	//account[]							account number
	//checkbalance[],savebalance[]		balance of both accounts
	//askbalance,transcode,transaction	account being asked in the transaction	
	//point								pointer variable for the array
	//size,k							size of array,looping variable
	//closecheck						amount given when closing account
	
	string name[25];
	int account[25],size,k,askaccount,transcode,point;
	float checkbalance[25],savebalance[25],transaction,balance,closecheck;
	
	//*****PART ONE*****
	
	infile.open("U:\\cdata\\cACCOUNTS2.TXT"); //opening file

	size=25;
	for (k=0;k<size;k++)//inputs data
	{
		getline(infile,name[k]);
		infile>>account[k];infile.get();
		infile>>checkbalance[k];infile.get();
		infile>>savebalance[k];infile.get();
	}
	
	bubsort(account,name,checkbalance,savebalance,size); //bubble sorts data
		
	printaccount(name,account,checkbalance,savebalance,size);//prints accounts


	infile.close(); //closeing file

	//*****PART TWO*****

	infile.open("U:\\cdata\\cTRANS3.txt"); //opening file
	cout <<"\n\n\nTRANSACTION LOG\n";
	cout <<"================\n\n";
	do
	{
		//inputs account to check
		infile>>askaccount;infile.get();
		infile>>transcode;infile.get();
		infile>>transaction;infile.get();
		
		bsearch(account,size,askaccount,point);
		
		
		if (transcode!=1 && transcode!=2 && transcode!=3 && transcode!=4 && transcode!=5)
		{
			//error #2, checks for illegal transaction codes
		}
		else
		{
			if (point == -1)//error #1, account number doesn't exist
			{
				cout <<"ACOUNT NOT FOUND.\nTRANSACTION CANCELLED\n";
				cout <<"No record of account: "<<askaccount<<"\n\n\n";
				
			}
			else
			{
				if (transcode==1)//deposit
				{
					cout <<"Customer: "<<name[point]<<"\t\t"<<setw(15)<<left<<" Account Number: "<<account[point]<<"\n";
					cout <<"Transaction: DEPOSIT to CHECKING\n";
					cout <<"Beginnings Balance: "<<setw(8)<<left<<format_num(checkbalance[point])<<"\n";
					cout <<"Amount Deposited: "<<setw(8)<<left<<format_num(transaction)<<"\n";
					checkbalance[point]=checkbalance[point]+transaction;
					cout <<"Ending Balance: "<<setw(8)<<left<<format_num(checkbalance[point])<<"\n\n\n";
				}
				if (transcode==2)//withdraw
				{
					cout <<"Customer: "<<name[point]<<"\t\t"<<setw(15)<<left<<" Account Number: "<<account[point]<<"\n";
					cout <<"Transaction: WITHDRAW from CHECKING\n";
					cout <<"Beginnings Balance: "<<setw(8)<<left<<format_num(checkbalance[point])<<"\n";
					cout <<"Amount Withdrawn: "<<setw(8)<<left<<format_num(transaction)<<"\n";
					if (transaction > checkbalance[point])
					{//error #3, amount withdrawn is more than checking balance
						cout <<"***** ERROR - INSUFFICIENT FUNDS - TRANSACTION CANCELED\n";
					}
					else
					{
						checkbalance[point]=checkbalance[point]-transaction;
					}
					
					cout <<"Ending Balance: "<<setw(8)<<left<<format_num(checkbalance[point])<<"\n\n\n";
				}
				if (transcode==3)//transfer checking to savings
				{
					cout <<"Customer: "<<name[point]<<"\t\t"<<setw(15)<<left<<" Account Number: "<<account[point]<<"\n";
					cout <<"TRANSFER from CHECKING to SAVINGS\n";
					cout <<"Beginning Balance - CHECKINS"<<setw(8)<<left<<format_num(checkbalance[point])<<"\n";
					cout <<"Beginning Balance - SAVINGS	"<<setw(8)<<left<<format_num(savebalance[point])<<"\n";
					cout <<"Amount of Transfer:"<<setw(12)<<right<<format_num(transaction)<<"\n";
					if (transaction > checkbalance[point])
					{//error #4, transfering more money than in account
						cout <<"*****  ERROR - INSUFFICIENT FUNDS - TRANSACTION CANCELED\n";
					}
					else
					{
						checkbalance[point]=checkbalance[point]-transaction;
						savebalance[point]=savebalance[point]+transaction;
					}
					cout <<"Ending Balance - CHECKING:"<<setw(10)<<right<<format_num(checkbalance[point])<<"\n";
					cout <<"Ending Balance - SAVINGS: "<<setw(10)<<right<<format_num(savebalance[point])<<"\n";
					cout <<"\n\n\n";
				}
				if (transcode==4)//transfer savings to checking
				{
					
					cout <<"Customer: "<<name[point]<<"\t\t"<<setw(15)<<left<<" Account Number: "<<account[point]<<"\n";
					cout <<"TRANSFER from SAVINGS to CHECKING\n";
					cout <<"Beginning Balance - CHECKINS	"<<setw(8)<<left<<format_num(checkbalance[point])<<"\n";
					cout <<"Beginning Balance - SAVINGS		"<<setw(8)<<left<<format_num(savebalance[point])<<"\n";
					if (transaction > savebalance[point])
					{//error #4, transfering more money than in account
						cout <<"*****  ERROR - INSUFFICIENT FUNDS - TRANSACTION CANCELED\n";
					}
					else
					{
						checkbalance[point]=checkbalance[point]+transaction;
						savebalance[point]=savebalance[point]-transaction;
					}
					cout <<"Ending Balance - CHECKING:"<<setw(10)<<right<<format_num(checkbalance[point])<<"\n";
					cout <<"Ending Balance - SAVINGS: "<<setw(10)<<right<<format_num(savebalance[point])<<"\n";
					cout <<"\n\n\n";
					
				}
				if (transcode==5)//closing account
				{
					cout <<"Customer: "<<name[point]<<"\t\t"<<setw(15)<<left<<" Account Number: "<<account[point]<<"\n";
					cout <<"Ending Balance - CHECKING:"<<setw(10)<<right<<format_num(checkbalance[point])<<"\n";
					cout <<"Ending Balance - SAVINGS: "<<setw(10)<<right<<format_num(savebalance[point])<<"\n";
					closecheck=checkbalance[point]+savebalance[point];
					cout <<"A check in the amount of"<<setw(10)<<right<<format_num(closecheck)<<" will be sent to: "<<setw(10)<<left<<name[point]<<"\n";
					cout <<"account closed\n\n\n";
					checkbalance[point]=0;
					savebalance[point]=0;
					name[point]="";
					account[point]=999999;
				}
			}
		}
	}while(!infile.eof());

	//******PART THREE*****
		
		cout <<"\n\n\n";
		printaccount (name,account,checkbalance,savebalance,size);//prints accounts
		
	system ("pause");
	return 0;
}

		
		
void bubsort(int num[],string name[],float check[],float save[], int size)
{
	int k,flag,temp1;
	string temp2;
	float temp3,temp4;
	do
	{	
		flag=0;
		for (k=0;k<size-1;k++)
		{
			if (num[k]>num[k+1])
			{
				temp1= num[k];
				num[k]=num[k+1];
				num[k+1]=temp1;				
				temp2=name[k];
				name[k]=name[k+1];
				name[k+1]=temp2;				
				temp3=check[k];
				check[k]=check[k+1];
				check[k+1]=temp3;
				temp4=save[k];
				save[k]=save[k+1];
				save[k+1]=temp4;
				
				flag=1;
			}
		}
		size=size-1;
	}while(flag!=0);
}
string format_num(float num)
{
	stringstream add_dollar;
	add_dollar.setf(ios::showpoint);
	add_dollar.setf(ios::fixed);
	add_dollar.precision(2);
	add_dollar << "$" << num;
	return add_dollar.str();
}
void bsearch(int num[],int size,int searchvalue, int &ptr)
{
	int top,btm;
	bool found=false;
	top=0;
	btm=size-1;
	do
	{
		ptr=int((top+btm)/2);
		if (num[ptr]>searchvalue)
		{ 
			btm=ptr-1;
		}
		else if(num[ptr]<searchvalue)
		{ 
			top=ptr+1;
		}
		else
		{
			found=true;
		}
		if (top>btm)
		{
			ptr=-1;
		}
	} while(!found && ptr!=-1);
}
void printaccount(string name[],int accountnum[],float check[],float savings[],int size)
{//prints accounts
	int k=0;//loop variable
	int i=1;//counter variable
	//header
	cout <<setw(9)<<right<<"Name"<<setw(22)<<right<<"Acc. #"<<setw(20)<<right<<"C. Balance"<<setw(20)<<right<<"S. Balance\n\n\n";//prints header
	
	for (k=0;k<size;k++)
	{
		if(name[k]=="")
		{
		}
		else
		{
			//prints
			cout <<setw(2)<<right<<i<<setw(3)<<left<<".  "<<setw(20)<<left<<name[k]<<setw(6)<<right<<accountnum[k]<<setw(20)<<right<<format_num(check[k])<<setw(15)<<right<<format_num(savings[k])<<"\n";
			i=i+1;
		}
	}

}
