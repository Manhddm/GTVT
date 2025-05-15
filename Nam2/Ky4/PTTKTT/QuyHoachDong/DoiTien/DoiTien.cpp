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
main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, q,u;
    cin>>n>>q;
    int a[n];
    for (auto &x:a) cin>>x, dp[x]=1;
    vector <int> dp(10005,1e9);
    dp[0]=0;
    for (auto x:a)
    for (int j=x;j<10000;j++)
    dp[j]=min(dp[j],dp[j-x]+1);
    while (q--)
    {
        int m;
        cin>>m;
        if (dp[m]==1e9) cout<<-1<<"\n";
        else cout<<dp[m]<<"\n";
    }
    return 0;
    cerr<<endl<<"Time: "<<TIME;
}