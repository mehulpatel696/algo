

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

int n, r;



int main(){
    //sievePrimes();
    //cout<<primes[14<<endl;
    int caseNo = 1;
    while(cin>>n>>r){
        if(n == 0 && r == 0) break;

        vector<double> probs(n);
        map<string, double> probs_s;

        for(int i = 0; i < n; i++) cin>>probs[i];

        double prob_denom = 0.0;
        string first_perm = "";

        for(int i = r; i < n; i++) first_perm += '0';
        for(int i = 0; i < r; i++) first_perm += '1';

        do{
            // cout<<first_perm<<endl;
            //            double prob_t = 0.0;
            //            for(int i = 0; i < first_perm.length(); i++) if(first_perm[i] == '1') prob_t *= probs[i];
            //            prob_denom += prob_t;
            // cout<<prob_t<<endl;
            double string_prob = 1.0;
            for(int i = 0; i < first_perm.length(); i++){
                if(first_perm[i] == '1') string_prob *= probs[i];
                else string_prob *= (1.0 - probs[i]);
            }
            prob_denom += string_prob;
            pair<string, double> ap(first_perm, string_prob);
            probs_s.insert(ap);

        } while(next_permutation(first_perm.begin(), first_perm.end()));

        //cout<<prob_denom<<endl;
        //Now we have all the string probles so go and find all the ones where i is trye and add them
        // cout<<probs_s.size()<<endl;

        cout<<"Case "<<caseNo++<<":\n";
        for(int counter = 0; counter < n; counter++){
            double prob_neum = 0.0;
            for(map<string, double>::iterator it = probs_s.begin(); it != probs_s.end(); it++){
                if(it->first[counter] == '1') prob_neum += it->second;
            }
            //cout<<prob_neum<<endl;
            //double ans = ;

            printf("%.6f", prob_neum/prob_denom);
            cout<<endl;
        }


    }
    return 0;
}


