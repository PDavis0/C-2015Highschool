/*	Parker Davis
	Dice program
	2/27/2015 */
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{
	//randomize timer
	srand((unsigned)time(0));

	/*	Variable		description
		roll(1-3)		the number on the dice
		k				looping variable
		games			number of games to be played
		winnings		accumulated money won during 1 game
		money			money the user has
		chance			chances of win/loss
		win				if games was won
		counter			games played up to that point
	*/

	int money,roll1,roll2,roll3,games,k,win,counter;
	float chance;
	
	win = 0;
	money = 0;
	counter = 0;

	cout <<"how many games would you like to play\n";
	cin >>games;cin.get();
	system ("cls");
	
	
	
	//looping for each roll of dice
	for (k=1;k<=games;k++)
	{
		do
		{

			//sets money
			money = money -5;
		

			//rolls dice
			roll1 = rand()%6+1;
			roll2 = rand()%6+1;			
			roll3 = rand()%6+1;
			counter++;
			cout <<"You have: $"<<money<<"\n";
			cout <<"You have played: "<<counter<<" games"<<"\n\n";
			cout <<"you rolled a: "<<roll1<<"\n";
			cout <<"you rolled a: "<<roll2<<"\n";
			cout <<"you rolled a: "<<roll3<<"\n\n";
			
			//checks to see if any earnings
			if (roll1>roll2+roll3 || roll2>roll1+roll3 || roll3>roll1+roll2)
			{
				money = money + 15;
				cout <<"you had a dice roll a greater number than the sum of the other two!\n";
				cout <<"You won $15!"<<"\n\n\n";
				win++;
			}
			if (roll1 == roll2 && roll2 == roll3)
			{
				money = money + 50;
				cout <<"all your dice rolled a: "<<roll1<<"\n";
				cout <<"you won $50"<<"\n\n\n";
				win++;			
			} 

			system ("pause");
			system ("cls");
		} while (money>-100 && money<100);
		if (money<=-100 || money >=100)
		{
			break;
		}

	}
		
	chance = win/games;
	//checks win/loss
	if (money >= 100)
	{
		cout <<"You won! You ended the game with: "<<money<<"\n";
		cout <<"Your win percentage is: "<<chance<<" games\n";
		cout <<"CONGRATS!"<<"\n\n\n";
	}
	if (money <= 0)
	{
		cout <<"You lost :( you ended the game with: "<<money<<"\n";
		cout <<"Your win percentage is: "<<chance<<" games\n";
		cout <<"sorry"<<"\n\n\n";
	}
	system ("pause");

	return 0;
}

		

