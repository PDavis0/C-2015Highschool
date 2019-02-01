/*	Parker Davis
	Horse race program
	3/10/2015
*/
#include <iostream>
#include <fstream>	
#include <iomanip>
#include <sstream>

using namespace std;
string format_num(float num);
ifstream infile;
int main()
{
	infile.open("U:\\cdata\\cHORSES.txt");
	/*	VARIABLE					DESCRIPTION
		k							counter variable
		count						print for 							
		first[],second[],third[]	places finished
		name[]						name of horse
		money[]						money earned
	*/
	
	int k,count,first[15],second[15],third[15],i;
	string name[15];
	float money[15];
	
	k=0;
	count=0;

	do
	{
		
		//inputs info for arrays
		getline(infile,name[k]);
		infile>>first[k];infile.ignore();	
		infile>>second[k];infile.ignore();	
		infile>>third[k];infile.ignore();
		k++;
	} while(!infile.eof());
	
	//printing title
	cout <<setw(3)<<left<<"#"<<setw(15)<<left<<"NAME"<<setw(10)<<right<<"RACE#1"<<setw(10)<<right<<"RACE#2"<<setw(10)<<right<<"RACE#3"<<setw(12)<<right<<"MONEY"<<"\n\n";
	
	for(i=k;i>=0;i--)
	{
		// printing each horses info and calc. the info
		count=count+1;
		money[i]=(first[i]*1050.75)+(second[i]*855.43)+(third[i]*287.56);
		cout <<setw(3)<<left<<count<<setw(15)<<left<<name[i]<<setw(10)<<right<<first[i]<<setw(10)<<right<<second[i]<<setw(10)<<right<<third[i]<<setw(15)<<format_num(money[i])<<"\n";
	}
	
	system ("pause");
	return 0;
}
string format_num(float num);
string format_num(float num)
{
	stringstream add_dollar;
	add_dollar.setf(ios::showpoint);
	add_dollar.setf(ios::fixed);
	add_dollar.precision(2);
	add_dollar << "$" << num;
	return add_dollar.str();
}
