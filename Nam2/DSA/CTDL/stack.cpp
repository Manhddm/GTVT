//cai dat stack voi danh sach lien ket don
#include <iostream>
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
    int size;
public:
    stack(){
        h = NULL;
        size = 0;
    }
    ~stack(){
        while (h){
            node<T> *p = h;
            h = h->getNext();
            delete p;
        }
    }
    bool empty(){
        return size == 0;
    }
    void push(T x){
        h = new node(x,h); 
        size++;
    }
    void pop(){
        if (size){
            node<T> *p = h;
            h = h->getNext();
            delete p;
            size--;
        }
    }
    T& top(){
        return h->getData();
    }
};
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl;
    s.pop();
    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}