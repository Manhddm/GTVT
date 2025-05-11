#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout.tie(nullptr);
    int n; cin >> n;
    queue<int> q;
    q.push(n);
    set<int> st;
    st.insert(n);
    while(!q.empty()){          
        int u = q.front(); q.pop();
        for (int  i = 1; i*i<=u; i++){
            if (u % i == 0){
               if (st.find((i-1)*(u/i + 1)) == st.end()){
                st.insert((i-1)*(u/i + 1));
                q.push((i-1)*(u/i + 1));
               }
            }
        }
    }   
    for (int x : st){
        cout << x << " ";
    }
    return 0;
}