#include <bits/stdc++.h>
using namespace std;
void nhap(int n, float x[],float y[]){
    for (int i=0;i<=n;i++) cin>>x[i];
    for (int i=0;i<=n;i++) cin>>y[i];
}
void xuat(int n,float x[]){
    for (int i=0;i<=n;i++) cout<<x[i]<<" ";
    cout<<endl;

}
void SP(float sp[],float x[],float y[],int n){
    int c=0;
    while (c<=n)
    {
        sp[c]=y[n-c];
        for (int i=0;i<n-c;i++) y[i]=y[i+1]-y[i];
        c++; 
    }
    
}
float F(float x_,float x[],float sp[],int n){
    float t=(x_-x[n])/(x[1]-x[0]),k;k=t;
    float p=sp[0];
    for (int i=1;i<=n;i++){
        p+=t*sp[i];
        t*=(k+1)/(i+1);
        k+=1;
    }
    return p;
}
main(){
    int n;cin>>n;
    float x[n+3],y[n+3],sp[n+3];
    nhap(n,x,y);
    SP(sp,x,y,n);
    cout<<F(0.5,x,sp,n);
}
