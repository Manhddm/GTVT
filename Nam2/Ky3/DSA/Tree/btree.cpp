#include <bits/stdc++.h>
using namespace std;
#define main signed main
#define elif else if
#define endl "\n"
int ma = 0;
class node
{
private:
    int data;
    node *left;
    node *right;

public:
    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
    void setLeft(node *left)
    {
        this->left = left;
    }
    void setRight(node *right)
    {
        this->right = right;
    }
    void setData(int data)
    {
        this->data = data;
    }
    node *getLeft()
    {
        return this->left;
    }
    node *getRight()
    {
        return this->right;
    }
    int getData()
    {
        return this->data;
    }
};
class tree
{
private:
    node *root;

public:
    tree()
    {
        this->root = nullptr;
    }
    void insert(int data)
    {
        if (this->root == nullptr)
        {
            this->root = new node(data);
        }
        elif (data < this->root->getData())
        {
            if (this->root->getLeft() == nullptr)
            {
                this->root->setLeft(new node(data));
            }
            else
            {
                tree *t = new tree();
                t->root = this->root->getLeft();
                t->insert(data);
            }
        }
        elif (data > this->root->getData())
        {
            if (this->root->getRight() == nullptr)
            {
                this->root->setRight(new node(data));
            }
            else
            {
                tree *t = new tree();
                t->root = this->root->getRight();
                t->insert(data);
            }
        }
    }
    void inorder( )
    {
        if (this->root == nullptr)
        {
            return;
        }
        tree *t = new tree();
        t->root = this->root->getLeft();
        t->inorder();
        cout << this->root->getData() << " " ;
        t->root = this->root->getRight();
        t->inorder();
    }
    void preorder(int sau = 0)
    {
        if (this->root == nullptr)
        {
            return;
        }
        cout << this->root->getData() << " ";
        tree *t = new tree();
        t->root = this->root->getLeft();
        t->preorder(sau + 1);
        t->root = this->root->getRight();
        t->preorder(sau + 1);
    }
    void postorder(int sau = 0)
    {
        if (this->root == nullptr)
        {
            return;
        }
        tree *t = new tree();
        t->root = this->root->getLeft();
        t->postorder(sau + 1);
        t->root = this->root->getRight();
        t->postorder(sau + 1);
        cout << this->root->getData() << " ";
    }
    int search(int data){
        if (this->root == nullptr)
        {
            return 0;
        }
        if (this->root->getData() == data)
        {
            return 1;
        }
        tree* t = new tree();
        if (data <this->root->getData())
        {
            t->root = this->root->getLeft();
            return t->search(data);
        }
        else
        {
            t->root = this->root->getRight();
            return t->search(data);
        }
    }
    void remove(int key) {
        if (this->root == nullptr) {
            return;
        }
        if (this->root->getData() == key) {
            if (this->root->getLeft() == nullptr && this->root->getRight() == nullptr) {
                delete this->root;
                this->root = nullptr;
            } else if (this->root->getLeft() == nullptr) {
                node *tmp = this->root;
                this->root = this->root->getRight();
                delete tmp;
            } else if (this->root->getRight() == nullptr) {
                node *tmp = this->root;
                this->root = this->root->getLeft();
                delete tmp;
            } else {
                // Tìm nút nhỏ nhất trong cây con bên phải
                node *parent = this->root;
                node *tmp = this->root->getRight();
                while (tmp->getLeft() != nullptr) {
                    parent = tmp;
                    tmp = tmp->getLeft();
                }
                // Thay thế giá trị của nút cần xóa bằng giá trị của nút nhỏ nhất
                this->root->setData(tmp->getData());
                // Xóa nút nhỏ nhất trong cây con bên phải
                if (parent->getLeft() == tmp) {// tmp không có con trái
                    parent->setLeft(tmp->getRight());//set
                } else {
                    parent->setRight(tmp->getRight());
                }
                delete tmp;
            }
        } else {
            tree *t = new tree();
            if (key < this->root->getData()) {
                t->root = this->root->getLeft();
                t->remove(key);
                this->root->setLeft(t->root);
            } else {
                t->root = this->root->getRight();
                t->remove(key);
                this->root->setRight(t->root);
            }
            delete t;
        }
    }
};
main()
{
    cin.tie(0)->sync_with_stdio(0);
    tree *t = new tree();
    t->insert(5);
    t->insert(3);
    t->insert(7);
    t->insert(2);
    t->insert(4);
    t->insert(6);
    t->insert(8);
    t->inorder();
    cout << endl;
    t->preorder();
    cout << endl;
    t->postorder();
    cout << endl;
    cout << t->search(5) << endl;
    t->remove(5);
    t->inorder();
    return 0;
}