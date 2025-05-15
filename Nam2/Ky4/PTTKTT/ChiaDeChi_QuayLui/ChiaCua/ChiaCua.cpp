//Mzeno - chia cua
#include <bits/stdc++.h>
using namespace std;
int res = INT16_MAX;
void Try(int a[], int n,int M , int k, int A, int B){
	if (k - 1 == n){
		res = min (res,abs(B - A));
		return;
	}
	if (A + a[k] <= M/2) Try(a,n,M,k+1,A+a[k],B);
	if (B + a[k] < (M+ res)/2) Try(a,n,M,k+1,A,B+a[k]);
}
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	int M= 0;
	for (int i =1 ;i<=n;i++) cin>>a[i], M+=a[i];
	Try(a,n,M,1,0,0);
	cout<<res;
}   