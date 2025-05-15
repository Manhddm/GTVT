#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int,int>> pq;
    int x ;
    for (int i = 1; i <= n; i++) {
        cin >>x;
        pq.push({x, i});
        while (i-pq.top().s >= k) {
            pq.pop();
        }
        if (i >= k) {
            cout << pq.top().f << " ";
        }
    }
}