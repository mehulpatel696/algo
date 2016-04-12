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

void reverseString(string &a, int start, int end){
    if(start>=end) return;
    else{
        char temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        reverseString(a, start+1, end-1);
    }
}

bool isEmrip(int a){
    string b = to_string(a);
    reverseString(b, 0, b.length() - 1);
    if(b == to_string(a)) return false;
    int c = stoi(b);
    if(primes[c]) return true;
    return false;
}

int main(){


    sievePrimes();
    while(cin>>n){
        bool flag = true;
        if(primes[n]) {
            flag = false;
            if(isEmrip(n)) {
                cout<<n<<" is emirp."<<endl;
            } else cout<<n<<" is prime."<<endl;
        }
        if(flag) cout<<n<<" is not prime."<<endl;
    }

}

