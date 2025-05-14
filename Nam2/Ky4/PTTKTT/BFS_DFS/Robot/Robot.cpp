#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#define TIME (1.0*clock())/CLOCKS_PER_SEC
#define pii pair<int,int>
main(){
    cin.tie(0)->sync_with_stdio(0);
    int x,y;
    cin>>x>>y;
    queue<pii> q;
    set<pii> vis;
    q.push({x,y});  
    vis.insert({x,y});
    while (!q.empty()){
        auto [u,v]=q.front();
        cout<<u<<" "<<v<<endl;
        q.pop();
        if( u%2==0){
            pii z = {v,u/2};
            if (vis.count(z) == 0){
                q.push(z);
                vis.insert(z);
            }
        }
        if (v%2==1){
            pii z = {(v+1)/2,u};
            if (vis.count(z) == 0){
                q.push(z);
                vis.insert(z);
            }
        }
    }
    cout<<vis.size();
    cout<<endl;
    return 0;
}