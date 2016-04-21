

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
#include <random>

using namespace std;



int n,m;
#define logbb(i,b) log(i)/log(b)

string convertToBase(long long numB10, int baseX, string numBX){
    //cout<<numBX<<endl;
    if(numB10 < baseX) return to_string(numB10) + numBX;
    string t = to_string(numB10%baseX) + numBX;
    return convertToBase(numB10/baseX, baseX, t);

}

int sumOfDigits(long long num, int base){
    cout<<num<<" "<<base<<endl;
    if(num < base) return num;
    return num%base + sumOfDigits(num/base, base);
}

// SOURCE : used comeoncodeon to get the formula
int numDigits(long long x, int b){
    double numDigits = 1;
    for(int i = 1; i <= x; i++) numDigits += logbb(i,b);
    return floor(numDigits);
}


//formula - SOURCE : used comeoncodeon to get the formula
//B = ap1 * bp2 * cp3 * …
long long numZeros(long long num, int base){
    long long numz = num;
    int b = base;
    for(int i = 2; i <= base; i++){
        if(b%i == 0){
            long long p = 0;
            //determine the power of the prime pactor i for the base
            while(b%i == 0){
                p++;
                b /= i;
            }
            int a = 0, k = num;
            //cal the number of factors of i in n
            while(k/i > 0){
                a += k/i;
                k /= i;
            }
            numz = min(numz, a/p);
        }
    }
    return numz;

}



int main(){
    while(cin>>n>>m) cout<<numZeros(n,m)<<" "<<numDigits(n, m)<<endl;
    return 0;
}


