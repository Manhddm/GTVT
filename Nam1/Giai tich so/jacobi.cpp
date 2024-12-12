#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#define TIME (1.0*clock())/CLOCKS_PER_SEC
bool ktct_hang(){
    return 1;
}
bool ktct_cot(){
    return 1;
}
void slove(){
    int n;cin>>n;
    double ss;cin>>ss;
    double a[n][n],b[n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) cin>>a[i][j];
    }
    for(int i=0;i<n;i++) cin>>b[i];
    if (ktct_cot()==0 && ktct_hang()==0) {
        cout<<"ma tran khong cheo troi!!!\n";
        return;
    }
    for (int i=0;i<n;i++){
        double p=a[i][i];
        for (int j=0;j<n;j++){
            if (j==i) a[i][j]=0;
            else a[i][j]=-1.0*a[i][j]/p;
        }
        b[i]=b[i]/p;
    }
    double x[n],x1[n];
    for (int i=0;i<n;i++) x[i]=b[i];
    while(1){
        for (int i=0;i<n;i++){
            x1[i]=b[i];
            for (int j=0;j<n;j++){
                x1[i]+=x[j]*a[i][j];
            }
        }
        double ssmax=0;
        for (int i=0;i<n;i++) ssmax=max(ssmax,abs(x1[i]-x[i]));
        for (int i=0;i<n;i++) x[i]=x1[i];
        if (ssmax<ss) break;
    }
    for (int i=0;i<n;i++){
        cout<<"x"<<i+1<<" : "<<fix_(5)<<x[i]<<"\n";
    }
    
}
main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    slove();
    cerr<<endl<<"Time: "<<TIME;
}