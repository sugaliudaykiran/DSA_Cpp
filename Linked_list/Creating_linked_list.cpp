
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

Node* takeInput()
{
    int data;
    cin >> data;

    Node *head = NULL;      //  Initially, No Node is created..
    while (data != -1)
    {
        Node *newNode = new Node(data);     //  creates an dynamic node for further, access of node..

        if (head == NULL)
        {
            head = newNode; //  In this case of first node is head of all nodes..
        }

        else            // In wrost case, it takes O(n^2).. Time complexity
        {
            Node *temp = head;          //  Traverse and find the node-> next == NULL to newNode..
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }

            temp -> next = newNode;
        }
        cin >> data;        //  Taking the next input node..
    }
    return head;
}

Node* takeInput_Better()
{
    int data;
    cin >> data;

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






int32_t main()
{
    /*
    Node n1(1);     //  Statically..
    Node *head = &n1;   //  To access the 'first node' by using 'head' pointer..

    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);        //  here we are passing the pointer which doesn't the original node because..
    // print(head);        //    in function there create new pointer..

    // cout << head -> data << "\n";
*/
    
   
/*


    Node *n1 = new Node(10);        //  Dynamicaly alloaction of Node..
    Node *head = n1;

    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    Node *n5 = new Node(50);

    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = n5;
    print(head);    //  may use print(n1) directly..
*/
    
    Node *head = takeInput();
    print(head);
    return 0;
}