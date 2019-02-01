/*	Parker Davis
	testing arrays
	3/9/2015
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;
string format_num(float num);
int main()
{
	int i;
	float age[5],money[5];
	string name[5];
	for (i=0,i<5,i++)
	{
		cout <<"enter a name ";
		getline(cin,name[i]);
		cout <<"enter an age ";
		cin >>age[i];cin.get();
		money[i]=age[i]*15.23;
	}
	system ("cls");
	for (i=0,i<5,i++)
	{
		cout <<setw(21)<<left<<"NAME"<<setw(10)<<left<<"AGE"<<setw(10)<<left<<"MONEY$"<<"\n\n";
		cout <<setw(21)<<left<<name[i]<<setw(10)<<left<<age[i]<<setw(10)<<left<<format_num(money)<<'\n';
	return 0;
}
format_num(float num)
{
	stringstream add_dollar;
	add_dollar.setf(ios::showpoint);
	add_dollar.setf(ios::fixed);
	add_dollar.precision(2);
	add_dollar << "$" << num;
	return add_dollar.str();
}
