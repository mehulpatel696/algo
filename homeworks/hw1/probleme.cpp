#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;


#define set(n, arr) for(int i = 0; i < n; i++) arr[i] = 0
#define o_o(val, one) if(val) printf("0"), one = true
#define o_p(val, one) if(val % 2 == 0) printf("+"), one = true
#define o_n printf("-")


class BIT{

    private:
        int *s;
        int size;

    public:

        BIT(int n){
            s = new int[n +1];
            size = n + 1;
            set(size,s);
        }

        int n_r(int n) {
            return n & (-n);
        }

        int read(int b){
            int sum = 0;
            while(b) sum += s[b], b -= n_r(b);
            return sum;
        }

        int read(int a, int b){
            return read(b) - (a == 1 ? 0 : read(a - 1));
        }
        void update(int k, int v){
            while(k<size) s[k] += v, k+= n_r(k);
        }
};



int main(){
        int n,k,a,b;
        char op;
        while (scanf("%d %d", &n, &k) != EOF) {

            int val[100005];
            BIT ng(n);
            BIT z(n);
            for(int i = 1; i <= n; i++){
                scanf("%d", &val[i]);
                if(val[i] == 0) z.update(i, 1);
                if(val[i] < 0) ng.update(i, 1);
            }
            for(int i = 0; i < k; i++){
                scanf("%c", &op);
                while (op != 'P' && op != 'C') scanf("%c", &op);
                scanf("%d %d", &a, &b);
                if(op == 'C'){
                    if(val[a] >= 0 && b < 0) ng.update(a,1);
                    else if(val[a] < 0 && b >= 0) ng.update(a,1);
                    if (val[a] != 0 && b == 0) z.update(a, 1);
                    else if (val[a] == 0 && b != 0) z.update(a, -1);
                    val[a] = b;

                } else if(op == 'P'){
                    bool set = false;
                    o_o(z.read(a,b), set);
                    o_p(ng.read(a,b),set);
                    if(!set) o_n;
                }
            }
            printf("\n");
         }




    return 0;
}
