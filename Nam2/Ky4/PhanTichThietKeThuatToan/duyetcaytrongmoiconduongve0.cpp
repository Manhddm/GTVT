#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define main signed main
#define elif else if
#define endl "\n"
struct Tree{
    vector<Tree*> child;
    int value;
    Tree(int value):value(value){}
    void build(){
        /*
        phân tích chi tiết thuật toán;
        - Đầu vào: value (0 ≤ value ≤ 10^5) - giá trị của nút
        - Xử lý:
            + Duyệt qua các ước của value:
                * Tính giá trị của nút con và thêm vào mảng con
            + Gọi đệ quy cho từng nút con            
        */
        if (value==0) return;
        for (int i=1;i*i<=value;i++){
            if (value%i==0){
                int b = value/i;
                int tmp = (i-1)*(b+1);
                Tree* tr = new Tree(tmp);
                child.push_back(tr);
            }
        }
        for(auto i:child) i->build();
    }
    void preOrder(){
        /*
        phân tích chi tiết thuật toán;
        - Đầu vào: không có
        - Xử lý:
            + In ra giá trị của nút
            + Gọi đệ quy cho từng nút con
        */
        cout << value << " ";
        for(auto i:child) i->preOrder();
    }
    void postOrder(){
        /*
        phân tích chi tiết thuật toán;
        - Đầu vào: không có
        - Xử lý:
            + Gọi đệ quy cho từng nút con
            + In ra giá trị của nút
        */
        for(auto i:child) i->postOrder();
        cout << value << " ";
    }
    void inOrder(){
        /*
        phân tích chi tiết thuật toán;
        - Đầu vào: không có
        - Xử lý:
            + Gọi đệ quy cho nút con đầu tiên
            + In ra giá trị của nút
            + Gọi đệ quy cho nút con thứ hai    
        */
        if (child.size()>0) child[0]->inOrder();
        cout << value << " ";
        for (int i=1;i<child.size();i++) child[i]->inOrder();
    }
};
main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    Tree* tr = new Tree(n);
    tr->build();
    tr->preOrder();
    cout << endl;
    tr->inOrder();
    cout << endl;
    tr->postOrder();    
    return 0;
}