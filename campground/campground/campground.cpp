/* Parker Davis
Program: A.L. Campgrounds
2/24/2015 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
ifstream infile;
int main()
{
	/***Variable****************Description***********
		lastname, name			lastname of family, name of person
		age,size				age of person,size of family
		k						variable for loop
		discount,total			discount for family,total before discount
		amountdue				amount after all deductions 
		numkids					number of kids that apply for deduciton
		**********************************************/

	char lastname[21],name[21];
	int age,size,numkids,k;
	float discount,total,amountdue;
	infile.open("U:\\cdata\\cCamp.TXT");
	
	//loops for each family
	do
	{
		//inputing and printing header of reciept
		infile.get(lastname,21);infile.ignore();
		infile >>size;infile.ignore();
		cout <<"\n\n";
		cout <<setw(30)<<right<<"A.L. Campgrounds"<<"\n\n";
		cout <<"Family name: "<<lastname<<"\n\n";
		cout <<setw(21)<<left<<"Camper"<<setw(15)<<left<<"Age"<<setw(15)<<left<<"Fee"<<"\n\n";
		
		//initializes variables that are
		//custom to each family
		total = 0;
		numkids = 0;
		discount = 0;
		amountdue = 0;
		
		//loops for each person for entire family
		for (k=1;k<=size;k++)
		{
			infile.get(name,21);infile.ignore();
			infile >>age;infile.ignore();
			
			//determines age and cost accordingly
			//then prints each person
			if (age>=18)
			{
				cout <<setw(21)<<left<<name<<setw(15)<<left<<"Adult"<<setw(15)<<left<<"$150"<<"\n";
				total = total+150;
			}
			if (age<=17 && age>=13)
			{
				cout <<setw(21)<<left<<name<<setw(15)<<left<<"Teen"<<setw(15)<<left<<"$110"<<"\n";
				total = total+110;
				numkids = numkids + 1;
			}
			if (age<=12 && age>=3)
			{
				cout <<setw(21)<<left<<name<<setw(15)<<left<<age<<setw(15)<<left<<"$75"<<"\n";
				total = total +75;
				numkids = numkids + 1;
			}
			if (age<3)
			{
				cout <<setw(21)<<left<<name<<setw(15)<<left<<age<<setw(15)<<left<<"$0"<<"\n";

			}
		}
		
		//sets decimal place for numbers
		cout.setf(ios::fixed);
		cout.precision(2);

		//determines if they get a discount
		if (numkids>=3)
		{
			discount = total*.15;
		}
		
		//calculates amount after discount
		amountdue = total-discount;

		//finish printing end of reciept
		cout <<"\nTotal for the "<<lastname<<" family:"<<setw(12)<<right<<"$"<<total<<"\n";
		cout <<setw(28)<<left<<"Discount:"<<setw(13)<<right<<"($"<<discount<<")"<<"\n\n";
		cout <<setw(28)<<left<<"Amount Due:"<<setw(13)<<right<<"$"<<amountdue<<"\n\n";

		system ("pause");
		system ("cls");
	}while (!infile.eof());

	system ("pause");

	return 0;
}