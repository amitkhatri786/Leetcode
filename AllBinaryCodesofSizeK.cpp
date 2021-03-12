#include<iostream>
#include<string>
#include<set>
#include <bits/stdc++.h>

using namespace std;

bool hasAllCodes(string s, int k) {
	unordered_set<string> my_set;
	for(int i=0;i<=s.size()-k;i++) {
		my_set.insert(s.substr(i,k));
	}
#if 0
	for(auto it:my_set) 
		cout<<it <<endl;
#endif
	bool res;
	res = (my_set.size() == (1<<k));
	return res;
}


int main()
{
	cout<<hasAllCodes("00111001",2) <<endl;
	cout<<hasAllCodes("0000000001011100",4) <<endl;
	cout<<hasAllCodes("00110",2)<<endl;

}
