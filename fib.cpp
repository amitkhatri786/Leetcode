#include<iostream>


using namespace std;


int once =1;
int my_vector[32];

int fib(int n)
{
    if (once) {
        for (int i = 0; i < 32; i++)
            my_vector[i] = -1;
        once = 0;
        my_vector[0] = 0;
        my_vector[1] = 1;
        my_vector[2] = 2;
    }
    if(n==0)
        return my_vector[0];
    if(n==1)
        return my_vector[1];
    if(n==2)
        return my_vector[2];
    if(my_vector[n] == -1) {
        my_vector[n] = fib(n-2) + fib(n-1);
        return(my_vector[n]);
    }else {
        return(my_vector[n]);
    }
}


int main()
{
    
    cout<<fib(30)<<"\n";
    return(0);
}
