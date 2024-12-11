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
    void inorder(int cnt = 0)
    {
        if (this->root == nullptr)
        {
            return;
        }
        tree *t = new tree();
        t->root = this->root->getLeft();
        t->inorder(cnt + 1);
        cout << this->root->getData() << " " << cnt << "\n";
        t->root = this->root->getRight();
        t->inorder(cnt + 1);
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
};
main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        tree a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.insert(x);
        }
        a.inorder();
        int key =100;
        cout << a.search(key) << endl;
        cout << endl;
    }
    return 0;
}