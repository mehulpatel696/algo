
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

int n,b;

bool primes[1060001] = {1};
int MAX = 1060001;

void sievePrimes(){
    memset(primes, false, sizeof(primes));
    //memset(primes2, true, sizeof(primes2));
    primes[0] = 0;
    primes[1] = 0;
    for (long long p=2; p*p<=MAX; p++) if (primes[p] == false) for (long long i=p*2; i<=MAX; i += p) primes[i] = true;
    for (long long p=4; p <= MAX; p++) if (primes[p] == true) for (long long i=p*2; i<=MAX; i += p) primes[i] = false;
    //for(long long i = 2; i < 10000000; i++) if(primes[i]) if(isAnagramaticPrime(i)) anagramaticPrimes[i] = 1;
}

int main(){
    sievePrimes();
    //cout<<primes[14]<<endl;
    while(cin>>n){
        int counter = 0;
        for(int i = 0; i < n; i++){
            cin>>b;
            if(primes[b]) counter++;
        }
        cout<<counter<<endl;
    }
    return 0;
}



