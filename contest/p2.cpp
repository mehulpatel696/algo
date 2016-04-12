

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

bool isReady(string n){
    for(int i = 0; i < n.length(); i++) if(n[i] != '+') return false;
    return true;
}


int main(){
    ifstream ifs("/Users/mehulpatel/Documents/rec1/B-large.in");
    if(ifs){
    int testcases;
    ifs>>testcases;
    int caseNo = 1;
    ofstream ofs("/Users/mehulpatel/Documents/rec1/gnepop.txt");
    while(testcases--){
        string n;
        ifs>>n;
        int flips = 0;
        ofs<<"Case #"<<caseNo++<<": ";
        char last_one = 'p';
        for(int i = 0; i < n.length(); i++){
            if(n[i] == '-'){
                if(last_one == '+') flips++;
                last_one = '-';
                flips++;
                while(n[i]=='-') i++;
                i--;
            } else {
                last_one = '+';
            }
        }
        ofs<<flips<<endl;
        // ofs<<last_num<<endl;

    }
    ofs.close();
    }
}
