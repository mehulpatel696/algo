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
#include <climits>
#include <math.h>

using namespace std;
/*

 Sample Input
 ----------------
 0 Fuel consumption 10
 100 Goal
 0 Fuel consumption 5
 100 Fuel consumption 30
 200 Goal
 0 Fuel consumption 20
 10 Leak
 25 Leak
 25 Fuel consumption 30
 50 Gas station
 70 Mechanic
 100 Leak
 120 Goal
 0 Fuel consumption 0

 Sample Output
 ----------------
 10.000
 35.000
 81.000

 Take in an int, string and int

 store current input and last input


 int distace;
 isLeaking;










*/
int main(){

    int start = 0, rate = 0, pos = 0, l_start = 0, leaks = 0;
    double curr = 0.0, resp = 0.0;
    string event = "", temp;
    while(cin>>start>>event){
        curr += ( (start - l_start) / 100.0) * rate;
        curr += ( (start - l_start) * leaks);
        resp = max(curr, resp);
        if(event == "Fuel") cin>>temp>>rate;
        else if (event == "Leak") leaks++;
        else if (event == "Gas"){
            cin>>temp;
            curr = 0;

        }
        else if (event == "Mechanic") leaks = 0;
        else if (event == "Goal"){
            printf("%.3lf\n", resp);
            start = 0, rate = 0, pos = 0, l_start = 0, leaks = 0;
            curr = 0.0, resp = 0.0;

        }
        l_start = start;
    }


    return 0;
}
