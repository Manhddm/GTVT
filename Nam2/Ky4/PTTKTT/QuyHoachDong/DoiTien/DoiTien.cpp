#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#define TIME (1.0*clock())/CLOCKS_PER_SEC
// 3 2
// 1 7 5
// 10
// 18
// giải thích đơn giản là dp[i] là số đồng xu tối thiểu để có được số tiền i
// số cách đổi tiền i là dp[i] = min(dp[i],dp[i-x]+1) với x là tờ tiền
// main(){
//     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//     int n, q,u;
//     cin>>n>>q;
//     int a[n];
//     for (auto &x:a) cin>>x, dp[x]=1;
//     vector <int> dp(10005,1e9);
//     dp[0]=0;
//     for (auto x:a)
//     for (int j=x;j<10000;j++)
//     dp[j]=min(dp[j],dp[j-x]+1);
//     while (q--)
//     {
//         int m;
//         cin>>m;
//         if (dp[m]==1e9) cout<<-1<<"\n";
//         else cout<<dp[m]<<"\n";
//     }
//     return 0;
//     cerr<<endl<<"Time: "<<TIME;
// }
//version 2.0 , dp[i][j];
main(){
    int n,M;
    cin>>n>>M;
    int a[n+1],C[n+1][M+1];
    for (int i=1; i<=n; i++) cin>>a[i];
    memset(C,0,sizeof(C));
    for (int j = 1; j <= M; j++) C[0][j] = 1e9;
    for (int i=1; i<=n; i++){
        for (int j = 1; j<= M; j++){
            C[i][j] = C[i-1][j];
            if (j>=a[i])
            C[i][j] = min(C[i][j],C[i][j-a[i]]+1);
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}