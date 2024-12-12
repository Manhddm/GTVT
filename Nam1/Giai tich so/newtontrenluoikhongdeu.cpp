#include <bits/stdc++.h>
using namespace std;
#define flash ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define TIME (1.0*clock())/CLOCKS_PER_SEC

double x_;
int n;
vector<double> tsp,x,y;
void inpluoikhongdeu(){
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
void TSP(){
    int c=0;
    while (tsp.size()<=n){
        tsp.push_back(y[0]);
        for (int i=0;i<=n-c;i++){
            y[i]=(y[i+1]-y[i])/(x[i+c+1]-x[i]);
        }
        c++;
    }
}
void slove(){
    inpluoikhongdeu();
    TSP();
    double tmp=x_-x[0];
    double p=tsp[0];
    for (int i=1;i<=n;i++){
        p+=tsp[i]*tmp;
        tmp*=x_-x[i];
    }
    cout<<p<<endl;
}
main(){
    flash;
    slove();
    cerr<<endl<<TIME;
}