#include <bits/stdc++.h>
using namespace std;
#define main signed main    
void  qsort(int arr[],int l,int r){
    for (int o=l;o<=r;o++) cout << arr[o] << " ";
    int i = l+1;
    int j = r;
    int key = arr[l];
    while (i<=j){
        while (arr[i]<key) i++;
        while (arr[j]>key) j--;
        if (i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[l],arr[j]);
    cout << endl;
    for (int o=l;o<=r;o++) cout << arr[o] << " ";
    cout << endl;
    if (l<j) qsort(arr,l,j-1);
    if (i<r ) qsort(arr,i,r);
}
main(){
    int a[] = {3,2,34,2,3,1,4,3};
    qsort(a,0,7);
    for (int i=0;i<8;i++) cout << a[i] << " ";
}
