

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



int f[10];

bool isFull(){
    for(int i = 0; i<=9; i++) if(f[i] == 0) return false;
    return true;
}

int main(){
    ifstream ifs("/Users/mehulpatel/Documents/rec1/A-large.in");
    if(ifs){
    int testcases;
    ifs>>testcases;
    int caseNo = 1;
    ofstream ofs("/Users/mehulpatel/Documents/rec1/gnepop.txt");
    while(testcases--){
        ofs<<"Case #"<<caseNo++<<": ";
        int n;
        ifs>>n;
        if(n == 0) {
            ofs<<"INSOMNIA"<<endl;
            continue;
        }
        memset(f, 0, sizeof f);
        int j = 1;
        int last_num;
        while(true){
            if(isFull()) break;
            last_num = (j++) * n;
            string temp = to_string(last_num);
            for(int i = 0; i < temp.size(); i++) f[(int)temp[i] - 48] = 1;
        }
        ofs<<last_num<<endl;

    }
    ofs.close();
    }
}
