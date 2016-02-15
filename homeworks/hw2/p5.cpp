#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define fill(times) for(int i = 1; i <= m; i++) cin>>times[i];
#define set(a,b) if(a<b) a = b;
#define update(mt1,t,mt2) mt1 += (2*t), mt2++

int main() {
    int testcases;
    cin>>testcases;

    while(testcases--){
        int n,t,m;
        cin>>n>>t>>m;
        int times[1500];
        fill(times);
        int rem = m % n;
        int time = m/n;
        int min_time = 0;
        int min_trips = 0;

        /*If number of cars is not divisible by the max cars the boat can take at once -> take the amount left after the even number of trims and set their time as the min times and incrment the trip by one */
        if(rem != 0){
            set(min_time, times[rem]);
            update(min_time,t,min_trips);
        }

        /*also start at rem + n, because if it's even you're good because you want to wait till n cars arrive before you go ahead and if it's odd you already accounted for the cars that wouldn't fit the even tip, increment by n because you want to take n cars at a time*/
        for(int i = (rem + n); i <= m; i+=n ){
            set(min_time, times[i]);
            update(min_time, t, min_trips);
        }

        /*Remove t from the mine time because you don't have to come back on the last trip. The last trip is only one way*/
        cout<<min_time - t<<" "<<min_trips<<endl;

    }
    return 0;
}





