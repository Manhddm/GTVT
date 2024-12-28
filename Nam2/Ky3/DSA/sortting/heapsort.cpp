#include <bits/stdc++.h>
using namespace std;
#define main signed main
void push(int arr[] , int i, int n){
    int j=i;
    int max;
    int kt = 0;
    while (j<=n/2 && kt ==0){
        if (2*j==n) max = 2*j;
        else{
            if (arr[2*j]>arr[2*j+1]) max = 2*j;
            else max = 2*j+1;
        } 
        if (arr[j]<arr[max]){
            swap(arr[j],arr[max]);
            j = max;
        }
        else kt = 1;
    }
}
void sortHeap(int arr[],int n){
    
    for (int i=n/2;i>=1;i--){
        push(arr,i,n);
    }
    for (int i=n;i>=2;i--){
        swap(arr[1],arr[i]);
        push(arr,1,i-1);
    }
}
int bsearch(int ar[], int n,int x){
    int l,r,mid;
    l = 1;
    r = n;
    while (l<=r){
        mid = (l+r)/2;
        if (ar[mid]==x) return mid;
        if (ar[mid]<x) l = mid+1;
        else r = mid-1; 
    }
    return -1;
}
main()
{
    int arr[]={0,23, 54, 1, 53, 76, 123, 43, 87, 321, 43};
    int n = 10;
    sortHeap(arr,n);
    for (int i=1;i<=n;i++) cout << arr[i] << " ";
    int x;
    return 0;   
}
/*
1 2 3 4 5 6 7 8 9
*/