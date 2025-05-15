#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#define TIME (1.0*clock())/CLOCKS_PER_SEC
main(){
    cin.tie(0)->sync_with_stdio(0);
    int  n,m,k;
    cin>>n>>m>>k;
    queue<pair<int,int>> q;
    map<pair<int,int>,int> d;
    q.push({0,0});
    d[{0,0}]=0;
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        cout<<"Trang thai hien tai: "<<x<<" "<<y<<endl;
        cout<<"So buoc: "<<d[{x,y}]<<endl;
       
        if (x==k || y==k){
            cout<<d[{x,y}];
            return 0;
        }
        pair<int,int> a[]={{0,y},{n,y},{x,0},{x,m},{max(0LL,x+y -m), min(x+y,m)}, {min(x+y,n), max(0LL,x+y-n)}};
        cout<<"Cac trang thai co the di: ";
        for (auto z:a){
            cout<<z.first<<" "<<z.second<<", ";
            if (d.find(z)==d.end()){
                d[z]=d[{x,y}]+1;
                q.push(z);
            }
        }
         cout<<"\nQueue sau buoc nay: \n";
        queue<pair<int,int>> tmp=q;
        while(!tmp.empty()){
            cout<<tmp.front().first<<" "<<tmp.front().second<<"\n";
            tmp.pop();
        }
        cout<<endl;
    }
    cout<<"Khong dong duoc nuoc";
    return 0;
}