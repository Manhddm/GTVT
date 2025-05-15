#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    priority_queue <int,vector<int>,greater<int>> pq;
    for (int i=0;i<n;i++){
        int x;cin>>x;
        pq.push(x);
    }
    int sum=0;
    while (pq.size()>1){
        int tmp1,tmp2;
        tmp1=pq.top();
        pq.pop();
        tmp2=pq.top();
        pq.pop();
        sum+=tmp1+tmp2;
        pq.push(tmp1+tmp2);
    }
    cout<<sum;
}