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
using namespace std;


#define fill_a (a,j) for(int i = 0; i < j; j++) a[i] = i;
#define fill_v (a,j) for(int i = 0; i < j; j++) a.push_back(i);


char ZERO = '0';


//Check if there is a one in the digits after the decimal place after converting it to base 3
bool isMember(int one, int two, int three){
    unordered_set<int> vals;
    while(true){
        if( two*3/three == 1 ) return true;
        two = (two*3)%three;
        if(vals.find(two) != vals.end()) break;
        vals.insert(two);
    }
    return false;
}


//Seperate the digits before and after the decimal place
void seperate_vars(int &one, int &two, string n, int &three){
    one = two = 0;
    int d;
    three = 1;
    for(int i = 0; i < n.size(); i++){
        if(n[i] != '.') one = (one*10) + (n[i] - ZERO);
        else {
            for(i++; n[i]; i++, d++) {
                two = (two * 10) + (n[i] - ZERO);
                three *= 10;
            }
            break;
        }
    }

}


int main(){

    string n;
    while(cin>>n){
        if(n == "END") return 0;
        int one, two, three;
        seperate_vars(one, two, n, three);
        if((one == 0 && two == 0) || (one == 1 && two == 0) ) {
            cout<<"MEMBER"<<endl;
            continue;
        }
        if(!isMember(one, two, three)) cout<<"MEMBER"<<endl;
        else cout<<"NON-MEMBER"<<endl;
    }
    return 0;

}
