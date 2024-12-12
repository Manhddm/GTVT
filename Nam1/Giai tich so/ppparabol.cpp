#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define fix_(x) setprecision(x)<<fixed
#define TIME (1.0*clock())/CLOCKS_PER_SEC
vector <double> sp,x,y;
int n;
double a,b;
double fx(double x){
    return 30*pow(x,3)+3*x-5;
}
void slove(){
    cin>>n;
    cin>>a>>b;
    double h=(b-a)/(2*n);n*=2;
    x.push_back(a);
    int i=1;
    while (i<=n){
        x.push_back(x[i-1]+h);
        i++;
    }
    FOR(i,0,n){
        y.push_back(fx(x[i]));
    }
    double s=y[0]+y[n];
    for (int i=1;i<n;i++) 
        if (i%2) s+=4*y[i];
        else s+=2*y[i];
    cout<<fix_(15)<<h*s/3;
}
main(){
    slove();
    cerr<<endl<<"Time: "<<TIME;
}