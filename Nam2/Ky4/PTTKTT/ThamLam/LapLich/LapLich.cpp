#include <bits/stdc++.h>
using namespace std;
int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int s[n],f[n];
    vector<pair<int,int>> a;
    for (int i = 0; i < n; i++){
        cin>>s[i]>>f[i];
        a.push_back({f[i],s[i]});
    }
    sort(a.begin(),a.end());
    int res = 0;
    int last = 0;
    for (int i = 0; i < n; i++){
        if (a[i].second > last){
            res++;
            last = a[i].first;
        }
    }
    cout<<res<<endl;
}