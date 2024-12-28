//cai dat stack voi danh sach lien ket don
#include <iostream>
#include <map>
using namespace std;
template <class T>
class node{
    private:
        T data;
        node *next;
    public:
        node(T x, node *p = NULL){
            data = x;
            next = p;
        }
        T &getData(){return data;}
        node* getNext(){return next;}
        void setNext(node *p){next = p;}
};
template <class T>
class stack{
private:
    node<T>* h;
    int num;
public:
    stack(){
        h = NULL;
        num = 0;
    }
    ~stack(){
        while (h){
            node<T> *p = h;
            h = h->getNext();
            delete p;
        }
    }
    bool empty(){
        return num == 0;
    }
    void push(T x){
        h = new node(x,h); 
        num++;
    }
    void pop(){
        if (num){
            node<T> *p = h;
            h = h->getNext();
            delete p;
            num--;
        }
    }
    unsigned size(){return num;}
    T& top(){
        return h->getData();
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(false);
    map<char,int> m={{'C',12},{'O',16},{'H',1},{'(',0}};
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        stack<int> s;
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