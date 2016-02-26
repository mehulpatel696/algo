#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;


int i, n, caseNum = 1, order[8];
double a[8], b[8], tg, max_tg;



double gl();

void doWork(){
    double lv = 0, hv = 86400;
    tg = -1;
    while (fabs(lv - hv) >= 1e-3) {
        tg = (lv + hv) / 2.0;
        double rv = gl();
        if (rv <= 1e-2)  lv = tg;
        else  hv = tg;
    }
    max_tg = max(max_tg, tg);
}

double gl() {
    double ll = a[order[0]];
    for (i = 1; i < n; i++) {
        double tlt = ll + tg;
        if (tlt <= b[order[i]]) ll = max(a[order[i]], tlt);
        else  return 1;
    }
    return ll - b[order[n - 1]];
}


int main() {
    while (scanf("%d", &n), n) {
        if(n == 0) break;
        for (i = 0; i < n; i++) {
            scanf("%lf %lf", &a[i], &b[i]);
            a[i] *= 60; b[i] *= 60;
            order[i] = i;
        }
        max_tg = -1;
        doWork();
        while (next_permutation(order, order + n)) doWork();
        max_tg = (int)(max_tg + 0.5);
        printf("Case %d: %d:%0.2d\n", caseNum++, (int)(max_tg / 60), (int)max_tg % 60);
    }
    return 0;
}
