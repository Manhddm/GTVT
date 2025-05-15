#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#define TIME (1.0*clock())/CLOCKS_PER_SEC
int n,m, res = 1e9;
int a[10005];
void Try(int k,int t,int T){
    if (k-1==n){
        if ((m-T)%a[n] == 0){
            res = min(res, t + (m-T)/a[n]);
            return;
        }
    }else{
        for (int x = 0; x +t < res && T+x*a[k]<=m;x++ ){
            Try(k+1,t+x,T+x*a[k]);
        }
    }
}
main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
    }
    Try(1,0,0);
    if (res == 1e9) cout<<-1;
    else cout<<res;
    return 0;
}