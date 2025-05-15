//Tichpx- tim tat ca cac xccdn
#include<bits/stdc++.h>
using namespace std;
string x,y;
int C[105][105]={},n,m;
set<string> P[105][105];
int main()
{
    cin>>x; n=x.size(); x="$"+x;
    cin>>y; m=y.size(); y="$"+y;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++) 
        if(x[i]==y[j]) 
        {
            C[i][j]=C[i-1][j-1]+1;
            if(C[i][j]==1) P[i][j].insert(string(1,x[i]));
            else for(auto s:P[i-1][j-1]) P[i][j].insert(s+x[i]), cout<<s+x[i]<<"\n";
        }
        else 
        {
            C[i][j]=max(C[i-1][j],C[i][j-1]);
            if(C[i-1][j]==C[i][j]) for(auto s:P[i-1][j]) P[i][j].insert(s);
            if(C[i][j-1]==C[i][j]) for(auto s:P[i][j-1]) P[i][j].insert(s);
        }

    for(auto s:P[n][m]) cout<<s<<"\n";
}
c[1][4] = c[0][3] + 1 = 1