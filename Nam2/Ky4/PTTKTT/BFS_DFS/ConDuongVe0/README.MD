# DFS_BFS

**Môn học:** PTTKTT  
**Trạng thái:** Đang học  
**Độ ưu tiên:** Cao  
**Ngày tạo:** 9/5/2025  
**Ghi chú:** Bài học bao gồm công thức và các ví dụ giải phương trình bậc hai

---

## Thuật toán BFS

**Bài:** Liệt kê các số trong mọi con đường trở về 0  
[Link bài gốc](http://laptrinhonline.club/problem/tichpxlietkezero)

Sử dụng hàng đợi và tập hợp (set) để giải quyết bài toán. Với $m = (a-1) \times (b+1)$, số $m$ có thể lặp lại nhiều lần nên ta cần dùng set. Với đầu vào là $n$, ta thêm $n$ vào trong queue và set, sau đó thực hiện duyệt BFS. Trong lúc duyệt, ta chạy vòng lặp for từ 1 đến căn bậc hai của phần tử đầu queue để tìm số mới. Nếu tìm thấy số mới, ta thêm vào cả queue và set.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    queue<int> q;
    q.push(n);
    set<int> st;
    st.insert(n);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int  i = 1; i*i<=u; i++){
            if (u % i == 0){
               if (st.find((i-1)*(u/i + 1)) == st.end()){
                st.insert((i-1)*(u/i + 1));
                q.push((i-1)*(u/i + 1));
               }
            }
        }
    }   
    for (int x : st){
        cout << x << " ";
    }
    return 0;
}
```

---

**Code bởi Mạnh Đồng aka Mzeno**  
Liên hệ qua fb: Đồng Đức Mạnh

![Minh họa](avaGa.jpg)