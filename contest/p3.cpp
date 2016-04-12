

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
#include <fstream>

vector<long long> jamCoins;
int n,m;
ofstream ofs("/Users/mehulpatel/Documents/rec1/gnepop.txt");

bool isPrime(long long num) {

    if (num <= 3) {
        return num > 1;
    } else if (num % 2 == 0 || num % 3 == 0) {
        return false;
    } else {
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

bool isJamCoin(long long n){

    for(int i = 2; i <= 10; i++){
        string temp = to_string(n);
        long long a = stoll(temp, 0, i);
       // cout<<a<<endl;

        if(a < 1000000000 && isPrime(a)) return false;
    }
    return true;
}


void generateJamcoinsDriver(char set[2], string p, int l, int len){
   // cout<<("generating")<<endl;
    if(jamCoins.size() == m) return;
    if(len == 0) {
       // cout<<"2"<<endl;

        string ans = '1' + p + '1';

        long long  jc = stoll(ans);
        if(isJamCoin(jc)) jamCoins.push_back(jc);
        return;
    }
    for(int i = 0; i < l; i++){
        //cout<<"1"<<endl;
        string np = p + set[i];
        generateJamcoinsDriver(set, np, l, len-1);
    }
}

long long getDivisor(int n){
    int i = 2;
    while(n%i != 0) i++;
    return i;
}
void printDivisors(long long n){
    for(int i = 2; i <= 10; i++){
        string temp = to_string(n);
        long long a = stoll(temp, 0, i);
        // cout<<a<<endl;
        ofs<<getDivisor(a);
        if(i != 10) ofs<<" ";

    }

}
void generateJamcoins(int n, int m){
    char set[2] = { '1','0'};
    generateJamcoinsDriver(set, "", 2, n-2);
    for(int i = 0; i < jamCoins.size(); i++) {
        ofs<<jamCoins[i]<<" ";
        printDivisors(jamCoins[i]);
        ofs<<endl;
    }

}


int main(){
    ifstream ifs("/Users/mehulpatel/Documents/rec1/c.in");
    if(ifs){
    int testcases;
    ifs>>testcases;
    int caseNo = 1;
    ofstream ofs("/Users/mehulpatel/Documents/rec1/op.txt");
    while(testcases--){

        jamCoins.clear();
        ifs>>n>>m;
        ofs<<"Case #"<<caseNo++<<": ";
        generateJamcoins(n,m);

    }
    ofs.close();
    }
}
