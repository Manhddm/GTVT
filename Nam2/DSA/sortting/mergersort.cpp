#include <bits/stdc++.h>
using namespace std;
#define main signed main
#define elif else if

void msort(int arr[],int l, int r){
    if (l>=r) return;
    int m = (l+r)/2;
    msort(arr,l,m);
    msort(arr,m+1,r);
    int i=l,j=m+1;
    vector<int> tmp;
    while (i<=m && j<=r){
        if (arr[i]<arr[j]) tmp.push_back(arr[i++]);
        else tmp.push_back(arr[j++]);   
    }
    while (i<=m) tmp.push_back(arr[i++]);
    while (j<=r) tmp.push_back(arr[j++]);
    for (int i=l;i<=r;i++) cout << arr[i] << " ";
    cout << endl;   
    for (int i=l;i<=r;i++) arr[i]=tmp[i-l];
    for (int i=l;i<=r;i++) cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int a[]= {7 ,2 ,9 ,4 ,3 ,8 ,6 ,1};
    msort(a,0,7);
    for (int i=0;i<8;i++) cout << a[i] << " ";
}
