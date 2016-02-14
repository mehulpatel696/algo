#include<iostream>

using namespace std;

long sum_digits(long x)
{
    if(x<10) return x;
    long sum = 0;
    long temp = x;

    while(temp>0){
        sum+=temp%10;
        temp/=10;
    }
    return sum_digits(sum);
}
int main ()
{
    long num;
    long result;
    while(cin>>num)
    {
        if(num==0) break;
        result = sum_digits(num);
        cout<<result<<endl;

    }
    return 0;
}
