#include <bits/stdc++.h>
using namespace std;
int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    int x;
    for(int i =1; i <= n; i++){
        cin >> x;
        if (i%2 == 1) {
            l.push(x);
        } else {
            r.push(x);
        }
        if(i>1){
            if (l.top() > r.top()) {
                int tmp = l.top();
                l.pop();
                l.push(r.top());
                r.pop();
                r.push(tmp);
            }
            cout<<l.top() <<" ";
        }
        else {
            cout<<l.top()<<" ";
        }
    }

}
