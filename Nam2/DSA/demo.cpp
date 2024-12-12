#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
//#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    a.erase(a.begin()+2);
    for(auto i:a) cout << i << " ";
    return 0;
}