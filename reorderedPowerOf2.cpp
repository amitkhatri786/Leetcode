#include<iostream>
#include<vector>

using namespace std;

vector<int> count_numbers(int N)
{
    vector<int> res;
    int a[10] ={0};
    while(N){
        a[N%10]++;
        N = N/10;
    }
    for(int i=0;i<9;i++)
        res.push_back(a[i]);
    return res;
}

bool reorderedPowerOf2(int N)
{
    vector<int> A = count_numbers(N);
    for(int i=0;i<31;i++){
        vector<int> t = count_numbers(1<<i);
        if(t==A)
            return true;
    }
    return false;
}

int main()
{
    cout<<reorderedPowerOf2(24)<<endl;

    return 0;
}