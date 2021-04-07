#include<iostream>
#include<map>
#include<string>

using namespace std;


bool halvesAreAlike(string s) {
    int i;
    map <char,int> firsthalf,secondhalf;
    int f = 0;
    int se = 0;
    int len = s.length()/2;
    for(i=0;i<len;i++){
        firsthalf[tolower(s[i])]++;
        secondhalf[tolower(s[len + i])]++;
    }
    for(auto it:firsthalf) {
        if(it.first == 'a' || it.first=='e' || it.first == 'i' || it.first == 'o' || it.first == 'u')
        f = f + it.second;
    }
    for(auto it:secondhalf) {
        if(it.first == 'a' || it.first=='e' || it.first == 'i' || it.first == 'o' || it.first == 'u')
        se = se + it.second;
    }
    if(f == se)
        return true;
    return false;
}

int main()
{
    cout<<halvesAreAlike("Uo")<<endl;
    cout<<halvesAreAlike("book")<<endl;
    cout<<halvesAreAlike("textbook")<<endl;
    cout<<halvesAreAlike("MerryChristmas")<<endl;
    cout<<halvesAreAlike("AbCdEfGh")<<endl;
    return(0);

}
