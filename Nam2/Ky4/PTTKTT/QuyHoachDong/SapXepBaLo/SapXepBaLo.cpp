#include <bits/stdc++.h>
using namespace std;
int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n;
    int KT[n+5], GT[n+5], M;
    for (int i = 1; i <= n; i++) {
        cin >> KT[i] >> GT[i];
    }
    int C[n+5][10005];
        memset(C, 0, sizeof(C));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 10005; j++){
                C[i][j] = C[i-1][j];
                if (j >= KT[i]){
                    C[i][j] = max(C[i][j], C[i-1][j-KT[i]] + GT[i]);
                }
            }
        }
    cin>>q;
    while(q--){
        cin>>M;
        cout<<C[n][M]<<"\n";
    }
}