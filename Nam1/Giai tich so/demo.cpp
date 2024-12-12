#include <iostream>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int pow_mod(int x, int exp) {
    int result = 1;
    x = x % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result % mod * x % mod) % mod;
        }
        exp = exp >> 1;
        x = (x * x) % mod;
    }
    return result;
}
double  x[] ={1,3,5,7,10,13,20,30,35,37},x_,n,y[] ={1,3,5,7,10,13,20,30,35,37};
main(){
    for (int i=0;i<10;i++){
        int s=0;
        for (int j=1;j<=x[i];j++){
            s+=pow_mod(j,)
        }
    }
}