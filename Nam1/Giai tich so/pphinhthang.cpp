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
    return pow(sin(x),4)+ pow(cos(x),4);
}
void slove(){
    cin>>n;
    cin>>a>>b;
    double h=(b-a)/n;
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
    for (int i=1;i<n;i++) s+=2*y[i]; 
    cout<<(b-a)*s/(2*n);
}
main(){
    slove();
    cerr<<endl<<"Time: "<<TIME;
}