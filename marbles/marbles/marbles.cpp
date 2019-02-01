/*	Parker Davis (translating Mr. Frisch)
	program: Marbles
	3/5/2015
*/
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
int main()
{
	int marbles,bet,num,count,winnings,guess,ans;

	srand((unsigned)time(0));
	marbles = 1000;
	system ("cls");
	do
	{
		do
		{
			cout <<"You have: "<<marbles<<" marbles.\n";
			cout <<"how many marbles do you wish to bet?";
			cin >>bet;cin.get();
			system ("cls");
			if (bet>marbles)
			{
				cout <<'\a';
				cout <<"You cannot bet more marbles than you have.";
			}
			if (bet<1)
			{
				cout <<'\a';
				cout <<"You must bet at least one marble.";
			}
		} while (bet<1 && bet>marbles);

		num=rand()%100+1;
		
		count=0;
		system ("cls");
		cout<<num;
		do
		{
			cout <<"Guess #\n";
	
			cout <<"enter a guess";
			cin >>guess;cin.get();
			if (guess < num)
			{
				cout <<"higher\n\n";
			}
			if (guess > num)
			{
				cout <<"lower\n\n";
			}
			count=count+1;
		} while(guess != num && count < 5);
		

		system ("cls");

		if (guess==num)
		{
			cout <<"CONGRATZ!!!!	YOU WIN!!\n";
			cout <<"The number was: "<<num<<'\n';
			cout <<"You guess the number on "<<count<<" guess(es)\n";
			if (count==1)
			{
				winnings=bet*10;
			}
			if (count==2)
			{
				winnings=bet*7;
			}
			if (count==3)
			{
				winnings=bet*5;
			}
			if (count==4)
			{
				winnings=bet*3;
			}
			if (count==5)
			{
				winnings=bet;
			}
			cout <<"You bet "<<bet<<" marbles so you win "<<winnings<<" marbles.\n\n\n";
			marbles=marbles+winnings;
		}
		if (count>5)
		{
			cout <<"sorry.....you lose!\n";
			cout <<"The number was: "<<num<<'\n';
			cout <<"you bet: "<<bet<<" marbles. So you lost "<<bet<<"marbles.\n\n\n";
			marbles=marbles-bet;
		}
		

		if (marbles!=0)
		{
			do
			{
				cout <<"You have "<<marbles<<" marbles.\n";
				cout <<"Do you wish to play again?\n";
				cout <<"1=yes	2=no";
				cin >>ans;cin.get();
				system ("pause");
				system ("cls");
			} while(ans!=1 && ans!=2);
		}
		if (marbles==0)
		{
			cout <<"You have lost your marbles\n";
			cout <<"GAME OVER\n";
		}
	} while(ans!=2 && marbles>0);

	system ("pause");
	return 0;
}