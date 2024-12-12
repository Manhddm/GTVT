#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#define TIME (1.0*clock())/CLOCKS_PER_SEC
double cs[100]={};
void fx(){
    int bac;
    cout<<"Phuong trinh bac(chi tinh duoc tu phuong trinh bac 5 do ve): ";cin>>bac;
    switch (bac)
    {
    case 5:
        cout<<"_x^5 + _x^4 + _x^3 + _x^2 + _x + c\n";
        for (int i=5;i>=0;i--){
            cin>>cs[i];
        }
        break;
    case 4:
        cout<<"_x^4 + _x^3 + _x^2 + _x + c\n";
        for (int i=4;i>=0;i--){
                cin>>cs[i];
        }
        break;
    case 3:
        cout<<"_x^3 + _x^2 + _x + c\n";
        for (int i=3;i>=0;i--){
            cin>>cs[i];
        }
        break;
    case 2:
        cout<<"_x^2 + _x + c\n";
        for (int i=2;i>=0;i--){
            cin>>cs[i];
        }
        break;
    case 9:
        for (int i=9;i>=0;i--) cin>>cs[i];
        break;
    }
}
double f(double x){
    return cs[9]*pow(x,9)+cs[8]*pow(x,8)+cs[7]*pow(x,7)+cs[6]*pow(x,6)+cs[5]*pow(x,5) +  cs[4]*pow(x,4) +  cs[3]*pow(x,3) + cs[2]*pow(x,2) + cs[1]*x +cs[0];
}
double f_(double x){
    return cs[9]*9*pow(x,8) +  cs[8]*8*pow(x,7) +  cs[7]*7*pow(x,6) +  cs[6]*6*pow(x,5) +  cs[5]*5*pow(x,4) +  cs[4]*4*pow(x,3) +  cs[3]*3*pow(x,2) + cs[2]*2*x + cs[1];
}
void slove(){
    double a,b,ss;
    cout<<"Nhap a va b voi a la diem fourie!!";cin>>a>>b;
    cout<<"Nhap sai so: ";cin>>ss;
    double x,x0=a;
    x=x0-f(x0)/f_(x0);
    while (abs(x-x0)>=ss)
    {
        x0=x;
       x=x-f(x)/f_(x);
    }
    cout<<x;
}
main(){
    fx();
    slove();
    cerr<<endl<<"Time: "<<TIME;
}