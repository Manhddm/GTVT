#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k,m;
	cin >>n>>k>>m;
	long long a[n], res=0;
	for(int i=0; i<n; i++) cin >> a[i];
	queue<long long> Q;
	for(int i=0; i<n+k-1; i++) {
		if(i<n) {
			Q.push(a[i]);
		}else Q.push(0);
		if(Q.size()>k) Q.pop();
		long long t=0;
		while(Q.size() && t+Q.front() <= m) {
			t+=Q.front();
			Q.pop();
		}
		if(Q.size()) {
			Q.front()-=(m-t);
			t+=(m-t);
		}
		queue<long long> tmp = Q;
		while(tmp.size()) {
			cout << tmp.front() << " ";
			tmp.pop();
		}
		cout << endl;
		res+=t;
	} 
	cout << res;
}