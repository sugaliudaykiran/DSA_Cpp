
 /* 
 
  Why Linkedlist ?  Because, array can store in continues location, alloaction is memory of array is static.. 
        By using linkedlist we can store each val/Node in random address and were use to linked to one another..
        this linking is store the address of next Node.. 


*/

#include<bits/stdc++.h>
using namespace std;
class Node      
{              
    public:
    int data;       // Node has 'data' and pointer 'next' of Node type..
    Node *next;     

    Node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};



Node* takeInput_Better()
{
    int data;
    cin >> data;            //  TC -> O(n)..

    Node *head = NULL;      //  Initially, No Node is created..
    Node *tail = NULL;      //  By maintain tail pointer to avoid O(n^2) TC..
    while (data != -1)
    {
        Node *newNode = new Node(data);     //  creates an dynamic node for further, access of node..

        if (head == NULL)
        {
            head = newNode; 
            tail = newNode; //  Initial the tail and head points to First node..
        }

        else
        {
            tail -> next = newNode; //  add new node to the last existing node..
            tail = tail -> next;    //  by using tail and update tail..
            // or  tail = newNode;
        }
        cin >> data;        //  Taking the next input node..
    }
    return head;
}


void print(Node *head)
{
    Node *temp = head;  //  Avoid using head directly because, it alwalys uses further..

    while (temp != NULL)        //  To traverse upto the tail node (temp-> next != NULL)..
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }cout << "\n";
}

Node* insertNode_Recursive(Node *head, int i, int data) {
	// Write your code here
    
    if (head == NULL)
    {
        return NULL;    //  Base case..
    }
    
    Node *newNode = new Node(data);
    
    if (i == 0)     //  Do the 1 task.. and does N-1 recursive..
    {
    	newNode -> next = head; 
        head = newNode;
        return head;
    }   //  SmallTask is recursive call of left.. head move next, i decrement by 1..
    
    Node *smallTask = insertNode(head->next, i-1, data);
    
    head -> next = smallTask;   //  Which insert the data in i_th  Index.. and updated to current list..
    
    return head;
}

Node* insertNode(Node *head, int i, int data)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node* newNode = new Node(data);
    int count = 0;
    
    if (i == 0)
    {
        newNode -> next = head;
        head = newNode;
        return head;
    }
    Node* temp = head;
    while (temp && count < i-1)
    {
        count++;
        temp = temp -> next;
    }

    if (temp)
    {
        newNode -> next = temp -> next;     //  or use addition ptr to store the temp -> next..
        temp -> next = newNode;
    }
    return head;
}



Node* deleteNode(Node *head, int i)
{
    if (head == NULL)
    {
        return NULL;
    }
    
    int count = 0;
    
    if (i == 0)
    {
        head = head -> next;
        return head;
    }

    Node* temp = head;
    while (temp && count < i-1)
    {
        count++;
        temp = temp -> next;
    }

    if (temp && temp -> next != NULL)
    {
        Node *del = temp -> next;
        temp -> next = del -> next;
        delete del;
    }
    return head;
}


Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    
    if (head == NULL)
    {
        return NULL;
    }
    
    if (pos == 0)
    {
        return head -> next;
    }
    
    Node *smallTask = deleteNodeRec(head -> next, pos-1);
    
    head -> next = smallTask;   //  Does the updating list and link to head..
    
    return head;
}

int32_t main()
{
    Node *head = takeInput_Better();
    // print(head);
    int choice;
    cin >> choice;

    switch(choice)
    {
        case 1:
            int i, data;
            cin >> i >> data;
            head = insertNode(head, i, data);
            print(head);
        
        case 2:
            int j;
            cin >> j;
            head = deleteNode(head, j);
            print(head);
    }

    return 0;
}