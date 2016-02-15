#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

int minGasStations(int l, int g){

    pair<int,int> rn[10000];

    for(int i = 0; i < g; i++){
        int x,r;
        cin>>x>>r;
        rn[i] = pair<int,int> (x-r,x+r);
    }

    sort(rn, rn+g);
    int close = 0, total_radius, zero_radius = 0, i = 0;
    while(zero_radius < l){
        total_radius = zero_radius;
        while( rn[i].first <= zero_radius && i < g){
            if(total_radius < rn[i].second) total_radius = rn[i].second;
            i++;
        }
        if(total_radius == zero_radius) break;
        zero_radius = total_radius;
        close++;

    }
    int val;
    (zero_radius < l) ? val =  -1 : val =  g - close;
    return val;

}
int main() {
    int l,g;
    while(cin>>l>>g) {
        if(l == 0 || g == 0) break;
        cout<<minGasStations(l, g)<<endl;
    }
    return 0;
}
