
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

using namespace std;
/*
 greatest common division

 8 6

 8%6 2

 */
long long  calcGCD(long long  a, long long  b){
    if(b == 0) return a;
    else return calcGCD(b, a%b);
}

long long  calcLCM(long long  a, long long  b){
    long long  t = calcGCD(a, b);
    //cout<<t<<endl;
    if(t != 0) return (a / t * b);
    else return 0;
}

int main(){
    long long n,m;
    while(cin>>n>>m){
        cout<<calcGCD(n,m)<<" "<<calcLCM(n,m)<<endl;
    }
}
