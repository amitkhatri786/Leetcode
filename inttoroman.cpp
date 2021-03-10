#include<iostream>
#include<vector>
#include<string>


using namespace std;

string thousand[3] = {"M","MM","MMM"};
string hundred[9] = { "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
string ten[9] = { "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
string unit[9] = { "I","II","III","IV","V","VI","VII","VIII","IX"};


string intToRoman(int num) {
	int i;
	string res;
	int n[4];
	n[0] = num/1000;num = num%1000;
	n[1] = num/100;num = num%100;
	n[2] = num/10;num = num%10;
	n[3] = num;
	if(n[0]) 
		res = res + thousand[n[0]-1];
	if(n[1])
		res = res + hundred[n[1]-1];
	if(n[2])
		res = res + ten[n[2]-1];
	if(n[3])
		res = res + unit[n[3]-1];

	cout<<"Res "<<res<<endl;
	
	return res;
}

int main()
{
	cout<<intToRoman(58);

	return 0;
}
