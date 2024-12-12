#include <bits/stdc++.h>
using namespace std;
#define flash ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define endl "\n"
#define TIME (1.0*clock())/CLOCKS_PER_SEC
int  x[] ={1,3,5,7,10,13,20,30,35,37},m,n,y[] ={1,3,5,7,10,13,20,30,35,37};
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
double L(double xi){
    double t1=1,t2=1;
    for (int i=0;i<=n;i++){
        if (xi!=x[i]) {
            t1*=(x_-x[i]);
            t2*=(xi-x[i]);
        }
    }
    return t1/t2;
}
int f(int n,int m){
    int s=0;
    for (int i=1;i<=n;i++){
        s+=pow_mod(i,m);
    }
    return s;
}

void inplagrange(){
    
    for(int i=1;i<=n;i++){
        x[i]=x[i-1]+d;
        y[i]=f(x[i]);
    }
}
void slove(){
    inplagrange();
    double p=0;
    for (int i=0;i<=n;i++){
        p+=y[i]*L(x[i]);
    }
    cout<<p<<endl;
}
main(){

    slove();
    cout<<endl;
}