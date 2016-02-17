#include <cstdio>
#include <string.h>
#include <climits>
#include <math.h>
#include <iostream>
using namespace std;

#define min(a,b) if (a > b) a = b
#define set(data, n) for(int i = 0;  i < n; i++) data[i] = 0;

int cb(int m){
    return (m == 0) ? 0 : cb(m & (m-1)) + 1;
}

int main() {
    int data[105];
    /* (int) pow(2,15) = 1 << 15 */
    bool on[(int) pow(2,15)];
    int testcases;
    cin>>testcases;
    while(testcases--){
        int p,n;
        cin>>p>>n;
        set(data,n);
        for(int i = 0;  i < n; i++){
           /*set ith data element to 0 */
           for(int j = 0; j < p; j++){
                int c;
                cin>>c;
                /* if the input bit is poitive then set the ith bit to the  0 | 2 ^ j*/
               if(c) {
                   cout<<"Before: "<<data[i];
                   data[i] |= ( 1 << j);
                   cout<<" After: "<<data[i]<<endl;
               }
            }
        }
        int min_leds = INT_MAX;
        for(int i = 0; i < (1 << p); i++){
            size_t s= sizeof(on);
            memset(on, false, s);
            bool f = true;
            for(int j = 0; j < n; j++){
                if(on[i & data[j]]){
                    f = false;
                    break;
                }
                on[i & data[j]] = true;
            }
            if(f) min(min_leds, cb(i));
        }


        cout<<min_leds<<endl;
    }
}

