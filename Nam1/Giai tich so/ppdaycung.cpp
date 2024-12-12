#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#define TIME (1.0*clock())/CLOCKS_PER_SEC
double f(double x){
    return pow(x,3)+0.2*pow(x,2);
}
double f2(double x){
    return 6.0*x+0.2*2;
}
void slove(){
    double a,b,ss;
    cin>>a>>b;
    cout<<"Nhap sai so: ";cin>>ss;
    if (f2(a)<0) swap(a,b);
    double x,x0=b;
    x=x0-(f(x0)/(f(a)-f(x0)))*(a-x0);
    while (abs(x-x0)>=ss)
    {
        x0=x;
        x=x-(f(x)/(f(a)-f(x)))*(a-x);
    }
    cout<<x;
}
main(){//phuong phap chia doi
    slove();
    cerr<<endl<<"Time: "<<TIME;
}