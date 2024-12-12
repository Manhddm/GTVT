#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#define TIME (1.0*clock())/CLOCKS_PER_SEC
double a[100][100],b[100][100];
void out(double a[][100],int n){
      for(int i=0;i<n;i++){
        for (int j=0;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void grauss(int n){
    for (int i=0;i<n-1;i++){
        for(int k=i+1;k<n;k++){
            double p=a[k][i];
            for (int j=i;j<=n;j++){
                a[k][j]=a[i][i]*a[k][j]-p*a[i][j];
            }
        }
    }
        out(a,n);
}

void timx(double x[],int n){
    if (a[n-1][n]==0) {cout<<"ERROR!!";return;}
    x[n-1]=a[n-1][n]/a[n-1][n-1];
    for (int i=n-2;i>=0;i--){
        double s=a[i][n];
        for (int j=i+1;j<n;j++) s-=a[i][j]*x[j];
        x[i]=s/a[i][i];
    }
}
main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for (int j=0;j<=n;j++){
            cin>>a[i][j];
        }
    }
    double x[n]={0};
    grauss(n);
    timx(x,n);
    for (int i=0;i<n;i++) cout<<x[i]<<"\n";
    cerr<<endl<<"Time: "<<TIME;
}