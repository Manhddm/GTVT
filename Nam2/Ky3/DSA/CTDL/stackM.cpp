#include <bits/stdc++.h>
using namespace std;
template<class T>
class Stack{
private:
    T* elem;
    int num,cap;
public:
    Stack(int num=0){
        elem = NULL;
        this->num = num;
        cap = num;
    }
    ~Stack(){
        delete[] elem;
    }
    void push(T val){
        if (num==cap){
            cap = cap?cap*2:1;
            T* tmp; tmp = new T[cap];
            for (int i = 0;i<num;i++){
                tmp[i] = elem[i];
            }
            if (elem ) delete[]  elem;
            elem = tmp;
        }
        elem[num++] = val;
    }
    void pop(){
        num--;
    }
    unsigned size(){return num;}
    int& top(){
        if (num==0) return elem[0]=0;
        return elem[num-1];
    }
    bool empty(){return num==0;}
};
int main(){
    cin.tie(0)->sync_with_stdio(false);
    map<char,int> m={{'C',12},{'O',16},{'H',1},{'(',0}};
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        Stack<int> s;
        string x;
        cin>>x;
        for (char c:x){
            if (m.find(c)!=m.end()){
                s.push(m[c]);
            }
            else if (c==')'){
                int t=0;
                while (s.top()!=0) t+=s.top(),s.pop();
                s.top() = t;
            }
            else s.top()*=(c-'0');
        }
        int ans=0;
        while (s.size()) ans+=s.top(),s.pop();
        cout<<ans<<endl;
    }
}