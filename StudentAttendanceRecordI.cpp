#include <iostream>
#include<string>



using namespace std;

bool checkRecord(string s)
{
	int L = 0,A =0;
	int i;
	if(s[0]=='L')
		L=1;
	else if(s[0] == 'A')
		A=1;
	for (i = 1; i < s.size(); i++)
	{
		if (s[i] == 'L') {
			if (s[i] == s[i - 1]) {
				L++;
				if (L == 3)
					return false;
			}
			else {
				L = 1;
			}
		} else if (s[i] == 'A') {
			A++;
		}
	}
	if (L >= 3)
		return false;
	if (A >= 2)
		return false;
	return (true);
}

int main()
{
	cout << checkRecord("AA") << endl;
	cout << checkRecord("PPALLL") << endl;
	return (0);
}