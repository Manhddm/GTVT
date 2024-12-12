#include <bits/stdc++.h>
using namespace std;
#define flash ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define TIME (1.0*clock())/CLOCKS_PER_SEC

vector <double> sp,x,y;
int n;
double x_;
void inpnttien(){
    cin>>n>>x_;
    for (int i=0;i<=n;i++){
        double tmp;
        cin>>tmp;
        x.push_back(tmp);
    }
    for (int i=0;i<=n;i++){
        double tmp;
        cin>>tmp;
        y.push_back(tmp);
    }
}
void SP(){
    int c=0;
    while (sp.size()<=n){
        sp.push_back(y[0]);
        for (int i=0;i<=n-c;i++){
            y[i]=y[i+1]-y[i];
        }
        c++;
    }
}
void slove(){
    SP();
    double p=sp[0];
    double t=(x_-x[0])/(x[1]-x[0]),k;k=t;
    int gt=1;
    for (int i=1;i<=n;i++){
        p+=t*sp[i]/gt;
        gt*=i+1;
        t*=k-1;
        k--;
    }
    cout<<p<<endl;
}
main(){
    flash;
    inpnttien();
    slove();
    cerr<<endl<<TIME;
}