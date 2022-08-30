#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}


#include<queue>

void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    if (root == NULL)
    {
        return;
    }
    
	queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);
    
    while (!pendingNode.empty())
    {
        TreeNode<int>* front  = pendingNode.front();
        cout << front -> data << ":";
        pendingNode.pop();
        
        int len = front -> children.size();
        for (int i=0; i<len; i++)
        {
            if (i == len-1)
            {
                cout << front -> children[i] -> data;
            }
        	else
            {
                cout << front -> children[i] -> data << ",";
            }
            pendingNode.push(front->children[i]);
        }cout << "\n";
    } 
}



int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}















