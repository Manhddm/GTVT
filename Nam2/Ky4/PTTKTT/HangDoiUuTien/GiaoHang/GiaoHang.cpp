#include <bits/stdc++.h>
using namespace std;
vector<int> a[1000000];
int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<int>> pq;
    int m = 0;
    for (int i = 0; i < n; i++) {
        int t,v;
        cin >> t >> v;
        a[t].push_back(v);
        m = max(m, t);
    }
    int res = 0 ;
    for (int  i = m ; i >= 1; i--) {
        for (auto x : a[i]) {
            pq.push(x);
        }
        if (pq.size() > 0) {
            res += pq.top();
            pq.pop();
        }
    }
   cout<<res<<endl;
}