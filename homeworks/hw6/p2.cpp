#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <utility>
#include <stdlib.h>

using namespace std;


#define fill_a (a,j) for(int i = 0; i < j; j++) a[i] = i;
#define fill_v (a,j) for(int i = 0; i < j; j++) a.push_back(i);


double distance(int x, int x2, int y, int y2){
    int a = abs(x2 - x);
    int b = abs(y2 - y);
    double hyp = sqrt( ( (a*a) + (b*b)) );
    return hyp;
}


int f(vector<int> a, int i){
    if( i == a[i]) return i;
    else return a[i] = f(a,a[i]);
}

void u(vector<int> &a, int i, int j, int &n){
   if( f(a, a[i]) != f(a, a[j]) ) a[f(a,i)] = f(a,j), n--;
}


int main(){

    int n;
    while(cin>>n){

        double len = 0.0;
        vector< pair< double, pair<int, int> > > al;

        int coord_x[753] = {-1};
        int coord_y[753] = {-1};

        for(int i = 0; i < n; i++)  cin>>coord_x[i]>>coord_y[i];
        //populate the al with distance from each node to other another node
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                double d = distance(coord_x[i], coord_x[j], coord_y[i], coord_y[j]);
                pair<int, int> c(i,j);
                pair<double, pair<int,int> > temp(d,c);
                al.push_back(temp);
            }
        }


        //Initialize a set to all of it's self
        //then union on all the pairs that exist
        //Thnen go through all pairs that exist and if they don't exist then use the already calculated distnace and add it to the counter
        vector<int> nodes(1005, -1);
        int np_n = n;
        for(int i = 0; i < n; i++) nodes[i] = i;
        int m;
        cin>>m;
        for(int i = 0; i < m; i++){
            int x,y;
            cin>>x>>y;
            u(nodes,x - 1,y - 1, np_n);
        }

        //Now we have a union of all existing connectios. Now go through every possible connection and check if that connection exists and if not then make it and add to the pipe

        sort(al.begin(), al.end());

        for(size_t i = 0; i < n; i++){
            if(np_n < 1) break;
            pair< double, pair<int, int> > temp = al[i];
            if( f(nodes, nodes[temp.second.first]) != f(nodes, nodes[temp.second.second])){
                len += temp.first;
                u(nodes, temp.second.first, temp.second.second, np_n);
            }
        }

        cout.precision(3);
        cout<<len<<endl;


    }

}
