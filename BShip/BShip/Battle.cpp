//Written by: Jack McGinness, P_Davis0 
//Ship Placement subroutine
//Date-4/27/15

#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>

using namespace std;
void shipsearch (int arr[10][10], int row[], int col[], int length[], int direction[],int k, int &hope);


int main()
{
	/*	variable declarations
		coordinates[][]				array for plots on board
		x,y							values in array (0,1,2,3)
		row,column		
			random plot to place ship
		direction					direction of ship(1,2,3,4)
	*/

	int k, x, y, i,j,check;
	//carrier, battle, dest, sub, ding, 
	int coordinates[10][10];
	int row[5];
	int column[5];
	int direction[5];
	int ship[5];

	srand((unsigned)time(0));

	ship[0]=0;//ding
	ship[1]=0;//sub
	ship[2]=0;//dest
	ship[3]=0;//battle
	ship[4]=0;//carrier



	do 
	{
		for(x=0; x<=9; x++)
		{
			for(y=0; y<=9; y++)
			{
				coordinates[x][y]=0;
					
			}
			
		}
		for (k=0;k<5;k++)//loops each ship (carrier,battle...ding)
		{
			row[k] = int(rand()%9);
			column[k] = int(rand()%9);
			if (row[k]==0)
			{
				direction[k] = int(rand()%3+2);
			}
			do
			{
				check=1;
				if (row[k]==9)
				{
					direction[k] =int(rand()%4+1);
					if (direction[k]==3)
					{
						check=0;
					}
				}
			}while(check==0);
			if (column[k]==0)
			{
				direction[k]=int(rand()%3+1);
			}
			do
			{
				check=1;
				if (column[k]==9)
				{
					direction[k] =int(rand()%4+1);
					if (direction[k]==2)
					{
						check=0;
					}
				}
			}while(check==0);

			coordinates[row[k]][column[k]]=1;
		}
			//sets carrier ship
			
		
			if (ship[4]==0)
			{
				if (direction[4]==1)//north
				{
					for (i=0;i<5;i++) 
					{
						coordinates[row[4]][column[4]]=1;
						row[4]=row[4]-1;
						
					}
				}
				else if (direction[4]==2)//east
				{
					for (i=0;i<5;i++) 
					{
						coordinates[row[4]][column[4]]=1;
						column[4]=column[4]+1;						
					}
				}
				else if (direction[4]==3)//south
				{
					for (i=0;i<5;i++) 
					{
						coordinates[row[4]][column[4]]=1;
						row[4]=row[4]+1;
					}
				}
				else if (direction[4]==4)//west
				{
					for (i=0;i<5;i++) 
					{
						coordinates[row[4]][column[4]]=1;
						column[4]=column[4]-1;
					}
				}
			}

			//sets battleship
			if (ship[3]==0)
			{
				if (direction[3]==1)//north
				{
					for (i=0;i<4;i++) 
					{
						coordinates[row[3]][column[3]]=1;
						row[3]=row[3]-1;
					}
				}
				else if (direction[3]==2)//east
				{
					for (i=0;i<4;i++) 
					{
						coordinates[row[3]][column[3]]=1;
						column[3]=column[3]+1;
					}
				}
				else if (direction[3]==3)//south
				{
					for (i=0;i<4;i++) 
					{
						coordinates[row[3]][column[3]]=1;
						row[3]=row[3]+1;
					}
				}
				else if (direction[3]==3)//west
				{
					for (i=0;i<4;i++) 
					{
						coordinates[row[3]][column[3]]=1;					
						column[3]=column[3]-1;
					}
				}
			}
		
			//sets destroyer
			if (ship[2]==0)
			{
				if (direction[2]==1)//north
				{
					for (i=0;i<3;i++) 
					{
						coordinates[row[2]][column[2]]=1;
						row[2]=row[2]-1;
					}
				}
				else if (direction[2]==2)//east
				{
					for (i=0;i<3;i++) 
					{
						coordinates[row[2]][column[2]]=1;
						column[2]=column[2]+1;
					}
				}
				else if (direction[2]==3)//south
				{
					for (i=0;i<3;i++) 
					{
						coordinates[row[2]][column[2]]=1;
						row[2]=row[2]+1;
					}
				}
	
				else if (direction[2]==4)//west
				{
					for (i=0;i<3;i++) 
					{
						coordinates[row[2]][column[2]]=1;
						column[2]=column[2]-1;
					}
				}
			}

			//set submarine
			if (ship[1]==0)
			{
				if (direction[1]==1)//north
				{
					for (i=0;i<3;i++) 
					{
						coordinates[row[1]][column[1]]=1;
						row[1]=row[1]-1;
					}
				}
				else if (direction[1]==2)//east
				{
					for (i=0;i<3;i++) 
					{
						coordinates[row[1]][column[1]]=1;
						column[1]=column[1]+1;
					}
				}
				else if (direction[1]==3)//south
				{
					for (i=0;i<3;i++) 
					{
						coordinates[row[1]][column[1]]=1;
						row[1]=row[1]+1;
					}
				}
				else if (direction[1]==4)//west
				{
					for (i=0;i<3;i++) 
					{
						coordinates[row[1]][column[1]]=1;
						column[1]=column[1]-1;
					}
				}
			}

			//set dinghy
			if (ship[0]==0)
			{
				if (direction[0]==1)//north
				{
					for (i=0;i<2;i++) 
					{
						coordinates[row[0]][column[0]]=1;
						row[0]=row[0]-1;
					}
				}
				else if (direction[0]==2)//east
				{
					for (i=0;i<2;i++) 
					{
						coordinates[row[0]][column[0]]=1;
						column[0]=column[0]+1;
					}
				}
				else if (direction[0]==3)//south
				{
					for (i=0;i<2;i++) 
					{
						coordinates[row[0]][column[0]]=1;
						row[0]=row[0]+1;
					}
				}
				else if (direction[0]==4)//west
				{
					for (i=0;i<2;i++) 
					{
						coordinates[row[0]][column[0]]=1;
						column[0]=column[0]-1;
					}
				}
			}
	
		for (j=0;j<5;j++)
		{
			shipsearch (coordinates,row,column,ship,direction,k,check);
		}
		
		//resets board if ship check came up false
	
	
		system ("cls");
		int cnt, j;
		cnt=0;
		check=0;
		for (k=0;k<=9 ; k++)
		{
			for (j=0; j<=9 ; j++)
			{
				if (coordinates[j][k]==1)
				{
					cnt=cnt+1;
					
				}
			}	
		}
		if (cnt==17)
		{
			check=1;
		}
	}while(check==0);

	for(x=0; x<=9; x++)
	{
		for(y=0; y<=9; y++)
		{
			cout<<setw(1)<<left<<coordinates[x][y];		
		}
		cout<<"\n";
	}


	system("pause");
	system("cls");
	return 0;

}

void shipsearch (int arr[10][10], int row[], int col[], int length[], int direction[],int k, int &hope)
{

	int nrow, ncol;
	nrow= row[k];
	ncol=col[k];
	if (row[k]<0 || row[k]>9  || col[k]<0 || col[k]>9 || arr[row[k]][col[k]]==1)
	{	
		hope=0;
	}
	else
	{
		if (direction[k]==1)
		{	if (arr[nrow][ncol-1]==1  || ncol==-1  || ncol==10)
			{	hope=0;
			}
			else if (length[k]>1)
			{	if (arr[nrow][ncol-1]==1  || ncol==-1 || ncol==10)
				{	hope=0;
				}
				else if	(length[k]>2)
				{	if (arr[nrow][ncol-1]==1 || ncol==-1 || ncol==10)
					{	hope=0;
					}
					else if (length[k]==4)
					{	if (arr[nrow][ncol-1]==1 || ncol==-1 || ncol==10)
						{	hope=0;
						}
						else
						{	hope=1;
						}	
					}
					else
					{	hope=1;
					}
				}
				else
				{	hope=1;
				}
			}
			else
			{	hope=1;
			}
		}
		if (direction[k]==3)
		{
			if (arr[nrow][ncol+1]==1 || ncol==-1 || ncol==10)
			{	hope=0;
			}
			else if (length[k]>1)
			{	if (arr[nrow][ncol+1]==1  || ncol==-1 || ncol==10)
				{	hope=0;
				}
				else if	(length[k]>2)
				{	if (arr[nrow][ncol+1]==1 || ncol==-1 || ncol==10)
					{	hope=0;
					}
					else if (length[k]==4)
					{	if (arr[nrow][ncol+1]==1 || ncol==-1 || ncol==10)
						{	hope=0;
						}
						else
						{	hope=1;
						}	
					}
					else
					{	hope=1;
					}
				}
				else
				{	hope=1;
				}
			}
			else
			{	hope=1;
			}
		}
		if (direction[k]=2)
		{
			if (arr[nrow-1][ncol]==1 || nrow==-1 || nrow==10)
			{	hope=0;
			}
			else if (length[k]>1)
			{	if (arr[nrow-1][ncol]==1  || nrow==-1 || nrow==10)
				{	hope=0;
				}
				else if	(length[k]>2)
				{	if (arr[nrow-1][ncol]==1 || nrow==-1 || nrow==10)
					{	hope=0;
					}
					else if (length[k]==4)
					{	if (arr[nrow-1][ncol]==1 || nrow==-1 || nrow==10)
						{	hope=0;
						}
						else
						{	hope=1;
						}	
					}
					else
					{	hope=1;
					}
				}
				else
				{	hope=1;
				}
			}
			else
			{	hope=1;
			}
		}
		if (direction[k]=4)
		{
			{
			if (arr[nrow+1][ncol]==1 || nrow==-1 || nrow==10)
			{	hope=0;
			}
			else if (length[k]>1)
			{	if (arr[nrow+1][ncol]==1  || nrow==-1 || nrow==10)
				{	hope=0;
				}
				else if	(length[k]>2)
				{	if (arr[nrow+1][ncol]==1 || nrow==-1 || nrow==10)
					{	hope=0;
					}
					else if (length[k]==4)
					{	if (arr[nrow+1][ncol]==1 || nrow==-1 || nrow==10)
						{	hope=0;
						}
						else
						{	hope=1;
						}	
					}
					else
					{	hope=1;
					}
				}
				else
				{	hope=1;
				}
			}
			else
			{	hope=1;
			}
		}
	}
}
}
