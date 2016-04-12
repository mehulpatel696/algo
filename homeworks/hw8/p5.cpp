

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

long long c;



bool anagramaticPrimes[100000001] = {0};
bool primes[100000001] = {true};
int MAX = 10000000;

bool isAnagramaticPrime(long long n);

void sievePrimes(){
    memset(primes, true, sizeof(primes));
    for (long long p=2; p*p<=MAX; p++) if (primes[p] == true) for (long long i=p*2; i<=MAX; i += p) primes[i] = false;
    for(long long i = 2; i < 10000000; i++) if(primes[i]) if(isAnagramaticPrime(i)) anagramaticPrimes[i] = 1;
}

bool isAnagramaticPrime(long long n){
    string temp = to_string(n);
    vector<int> num(temp.length());
    for(int i = 0; i < temp.size(); i++)  num[i] = (int) temp[i] - 48;
    sort(num.begin(), num.end());
    do{
        string new_str = "";
        for(int i = 0; i < num.size(); i++) new_str += (char) (num[i] + 48) ;
        long long new_int = stoi(new_str);
        if(!primes[new_int]) return false;
    } while(next_permutation(num.begin(), num.end()));
    return true;

}


int main(){

    sievePrimes();
    while(cin>>c){
        if(c==0) break;
        string temp = to_string(c);
        bool noout = true;
        //last_check = pow(10,temp.length())
        if(c < 10000) {
            for(long long i = c + 1; i < pow(10,temp.length()); i++){
                if(anagramaticPrimes[i]) {
                    cout<<i<<endl;
                    noout = false;
                    break;
                }
            }
        }
        if(noout) cout<<0<<endl;
    }
    return 0;
}


