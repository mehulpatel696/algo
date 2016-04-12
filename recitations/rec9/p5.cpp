

#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>

using namespace std;

int n;

long long  calcGCD(long long  a, long long  b){
    if(b == 0) return a;
    else return calcGCD(b, a%b);
}


int main(){
    //sievePrimes();
    //cout<<primes[14]<<endl;
    while(cin>>n){
        if(n == 0) break;
        cout<<1<<"/"<<2<<endl;
    }
    return 0;
}


