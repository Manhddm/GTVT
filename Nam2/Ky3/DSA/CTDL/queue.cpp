//Queue với mảng
#include <iostream>
using namespace std;
template <class T>
class Queue
{
    private:
        T *elems;
        int f,r,space,size;
    public:
        Queue(){f=r=space=size=0;elems = NULL;}
        ~Queue(){delete []elems;}
        unsigned sizeQ(){return size;}
        bool empty(){return size==0;}
        void push(T x){
            if (size == space){
                space = space?space*2:1;
                T *new_elems = new T[space];
                for (int i=0, j=f;j<f+size;j++,i++)
                    new_elems[i] = elems[j%size];
                if (elems) delete []elems;
                elems = new_elems;
                f = 0; r = size;
            }
            elems[r] = x;
            r = (r+1)%space;
            size++; 
        }
        void pop(){
            if (size){
                f = (f+1)%space;
                size--;
            }
        }
        T& front(){
            return elems[f];
        }
        T& back(){
            return elems[(r+space-1)%space];
        }
};
int main(){
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.pop();
    while (!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    
    cout<<q.sizeQ()<<endl;
    return 0;
}