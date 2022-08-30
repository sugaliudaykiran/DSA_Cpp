#include<bits/stdc++.h>
#include<queue>
using namespace std;

template <typename T>
class TreeNode
{
    public:
    T data;
    vector<TreeNode<T>*> children;  //  Stores address of childrens..

    TreeNode(T data)
    {
        this -> data = data;
    }
};

TreeNode<int>* takeInputLevelwise()
{
    int rootData;
    cout << "Enter rootData : " << "\n";
    cin >> rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNode;
    
    pendingNode.push(root);

    while (!pendingNode.empty())
    {
        TreeNode<int>* front = pendingNode.front();
        pendingNode.pop();

        int num;
        cout << "Enter Number of children of " << front-> data << "\n";
        cin >> num;

        for (int i=0; i<num; i++)
        {
            int childData;
            cout << "Enter " << i << "_th child of " << front -> data << "\n";
            cin >> childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            front-> children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
}



TreeNode<int>* takeInput()
{
    int rootData;
    cout << "Enter Data : " << "\n";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter Num of children of " << rootData << "\n";
    cin >> n;

    for (int i=0; i<n; i++)
    {
        TreeNode<int>* child = takeInput();
        root -> children.push_back(child);
    }
    return root;
}

template <typename T>
void printTree(TreeNode<T>* root)
{
    if (root ==  NULL)
    {                   //  Edge case..
        return;
    }

    cout << root -> data <<": ";
    for (int i=0; i<root->children.size(); i++)
    {
        cout << root-> children[i]-> data << ", ";
    }
    cout << "\n";

    for (int i=0; i<root->children.size(); i++)
    {
        printTree(root-> children[i]);
    }
}

int32_t main()
{
    TreeNode<int>* root = takeInputLevelwise();
    printTree(root);

    return 0;
}