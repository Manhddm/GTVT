#include <bits/stdc++.h>
using namespace std;
string X,Y;
queue<string> q;
void backtrack(string x, int n){
	if (x.size()==n) {
		q.push(x);
	}
	else
		{
			set<char> Next = {X[x.size()], Y[x.size()]};
			for (char c: Next) backtrack(x+c,n);
		}
}
int main()
{
	int n;
	cin>>X>>Y;
	n = X.size();
	backtrack("",n);
	//cout<<q.size()<<"\n";
	while(q.size()){
		cout<<q.front()<<"\n";
		q.pop();
	}
}