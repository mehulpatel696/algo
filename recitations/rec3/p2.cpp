#include <iostream>
#include <math.h>
using namespace std;



int main ()
{
    unsigned long long n,m,a;
    while(cin>>n>>m>>a){
        unsigned long long o1 = (n+a-1)/a;
        unsigned long long o2 = (m+a-1)/a;
        cout<<o1*o2<<endl;

    }

    return 0;

}
