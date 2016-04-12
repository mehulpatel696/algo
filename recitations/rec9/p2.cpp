


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



bool anagramaticPrimes[100000001] = {0};
bool primes[100000001] = {true};
int allPrimes[1000001];
int MAX = 1000001;
int counter = 0;
int f,g;
int n;


void sievePrimes(){
    memset(primes, true, sizeof(primes));
    for (long long p=2; p*p<=MAX; p++) if (primes[p] == true) for (long long i=p*2; i<=MAX; i += p) primes[i] = false;
    //for(long long i = 2; i < 10000000; i++) if(primes[i]) if(isAnagramaticPrime(i)) anagramaticPrimes[i] = 1;
   // allPrimes[0] = 1;
    for(int p = 3; p < MAX; p++){
        if(primes[p]) {
            allPrimes[counter] = p;
            //cout<<allPrimes[counter]<<endl;
            counter++;
        }
    }
}

//bool addsUp(int a){
//    int l = 0, r = n-1;
//    while(l < r){
//        if(allPrimes[l] + allPrimes[r] == a) {
//            cout<<allPrimes[r]<<" "<<allPrimes[l]<<endl;
//            if(allPrimes[r] - allPrimes[l] > g - f){
//                f = allPrimes[l];
//                g = allPrimes[r];
//            }
//            l++, r--;
//        }
//        else if(allPrimes[l] + allPrimes[r] < a) l++;
//        else r--;
//    }
//    return 0;
//}

int main(){
    sievePrimes();
    while(cin>>n){
        if(n == 0) break;
        bool flag = true;
        for(int i = 3; i < n - 1; i+=2){
            if(primes[i]){
                int b = n - i;
                if(primes[b]) {
                    cout<<n<<" = "<<i<<" + "<<b<<endl;
                    flag = false;
                    break;
                }

            }
        }
        if(flag) cout<<"Goldbach's conjecture is wrong."<<endl;
    }

}
