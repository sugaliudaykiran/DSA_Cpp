#include<bits/stdc++.h>
using namespace std;

template <typename T>

class TreeNode
{
    public:
    T data;       // Node's data.. of T type.
    vector <TreeNode<T> *> children; //  stores the address of childrens.. of parent Type.

    TreeNode(T data)
    {
        this -> data = data;
    }
};

int32_t main()
{

    TreeNode<int> *root = new TreeNode<int>(10);
    TreeNode<int> *node1 = new TreeNode<int>(20);
    TreeNode<int> *node2 = new TreeNode<int>(30);

    root -> children.push_back(node1);
    root -> children.push_back(node2);

    return 0;
}