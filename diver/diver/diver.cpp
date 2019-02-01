/* Diving scores program
Parker Davis
2/3/15 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

ifstream infile;

int main()

{
	
	/************************************************************************
		variable			variable description
		diver,windiver		diver's name,divers name winning competition
		highest,lowest		highest and lowest score from judge
		s1,s2,s3,s4,s5		all 5 scores taken into account for total score
		stotal				total score from 5 judges
		difficulty			difficulty of dive
		final				final score the diver gets
		oldwinner			variable to compare diver to previous diver 
		highscore			winning score of diving competition
		********************************************************************/

	char diver[21],windiver[21];
	float highest,lowest,s1,s2,s3,s4,s5,s6,s7,stotal,difficulty,final,oldwinner,highscore;

	oldwinner = 0;
	
	//opening file
	infile.open("U:\\cdata\\cDIVERS2.DAT");
	
	//looping for each diver
	do 
	{
		//sets percision for scores
		cout.setf(ios::fixed);
		cout.precision(1);
		
		//inputing all scores and calculating high/low
		infile.get(diver,21);infile.ignore();
		infile >>s1;infile.ignore();
		highest = s1;
		infile >>s2;infile.ignore();
		if (s2 > highest)
		{
			highest = s2;
		}
		
		infile >>s3;infile.ignore();
		if (s3 > highest)
		{
			highest = s3;
		}
		infile >>s4;infile.ignore();
		if (s4 > highest)
		{
			highest = s4;
		}
		infile >>s5;infile.ignore();
		if (s5 > highest)
		{
			highest = s5;
		}
		infile >>s6;infile.ignore();
		if (s6 > highest)
		{
			highest = s6;
		}
		infile >>s7;infile.ignore();
		if (s7 > highest)
		{
			highest = s7;
		}
	
		lowest = s1;
		if (s2 < lowest)
		{	
			lowest = s2; 
		}
		if (s3 < lowest)
		{
			lowest = s3;
		}
		if (s4 < lowest)
		{
			lowest = s4;
		}
		if (s5 < lowest)
		{	
			lowest = s5;
		}
		if (s6 < lowest)
		{
			lowest = s6;
		}
		if (s7 < lowest)
		{
			lowest = s7;
		}
		infile >>difficulty;infile.ignore();
		
		//calulating scores
		stotal = (s1+s2+s3+s4+s5+s6+s7)-lowest-highest;
		final = stotal*difficulty;
		
		//printing score card
		cout <<"Diver: "<<diver<<'\n'<<'\n';
		cout <<"Scores:"<<'\n';
		cout <<setw(20)<<right<<"Judge #1:"<<setw(10)<<right<<s1<<'\n';
		cout <<setw(20)<<right<<"Judge #2:"<<setw(10)<<right<<s2<<'\n';
		cout <<setw(20)<<right<<"Judge #3:"<<setw(10)<<right<<s3<<'\n';
		cout <<setw(20)<<right<<"Judge #4:"<<setw(10)<<right<<s4<<'\n';
		cout <<setw(20)<<right<<"Judge #5:"<<setw(10)<<right<<s5<<'\n';
		cout <<setw(20)<<right<<"Judge #6:"<<setw(10)<<right<<s6<<'\n';
		cout <<setw(20)<<right<<"Judge #7:"<<setw(10)<<right<<s7<<'\n'<<'\n';
		cout <<"Discard: "<<lowest<<" and "<<highest<<'\n'<<'\n';
		cout <<setw(25)<<left<<"5 judge score total:"<<setw(10)<<right<<stotal<<'\n';
		cout <<setw(25)<<left<<"Dive Difficulty:"<<setw(10)<<right<<difficulty<<'\n'<<'\n';
		
		//sets percision for final score (2 decimal places)
		cout.setf(ios::fixed);
		cout.precision(2);
		 
		//prints final score
		cout <<"Final score:"<<setw(30)<<right<<final<<"\n\n\n\n";
		system ("pause");
		system ("cls");
		
		//figures out winning diver
		if (final > oldwinner)
		{
			strcpy_s (windiver,diver);
			oldwinner = final;
			highscore = final;
		}
	} while (!infile.eof());

	//prints winning diver
	cout <<"Diver: "<<windiver<<'\n'<<'\n';
	cout <<"Final score: "<<highscore<<"\n\n\n\n";
	system ("pause");
	
	return 0;
}