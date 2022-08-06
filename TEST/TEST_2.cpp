void deleteAlternateNodes(Node *head) {
    //Write your code here
    Node* temp = head;
    while (temp && temp -> next)
    {
        Node* Next = temp -> next;
        temp -> next = Next -> next;
        
        Next -> next = NULL;
        delete Next;

        temp = temp -> next;
    }
}
//delete alternate Node in a linked list
#include <iostream>

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    ~Node() {
        if(next) {
            delete next;
        }
    }
};

using namespace std;
#include "solution.h"

Node* takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}
----------------------------------------------->

class Deque {
	int *data;
    int capacity, front, rear;
    
    public:
    Deque(int size)
    {
        data = new int[size];
        capacity = size;
        front = -1;
        rear = 0;
    }
    
    bool isFull()
    {
        return (front == (rear+1)% capacity);
    }
    
    bool isEmpty()
    {
        return (front == -1);
    }
    
    void insertFront(int input)
    {
        if (isFull())
        {
            cout << "-1" << "\n";
            return;
        }
        
        if (front == -1)
        {
            front = 0, rear = 0;
        }
        
        else
        {
            front = ((front-1)%capacity+capacity)%capacity;
        }
        data[front] = input;
    }
  
	void insertRear(int input)
    {
        if (isFull())
        {
            cout << "-1" << "\n";
            return;
        }
        
        if (front == -1)
        {
            front = 0, rear = 0;
        }
        
        else
        {
            rear = (rear+1)%capacity;
        }
        data[rear] = input;
    }
    
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return data[front];
    }
    
	int getRear()
    {
        if (isEmpty() || rear < 0)
        {
            return -1;
        }
        return data[rear];
    }
    
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << -1 << "\n";
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        
        else
        {
        	front = (front +1) % capacity;
        }
    }
    
    
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << -1 << "\n";
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        
        else
        {
        	rear = ((rear-1) % capacity + capacity) % capacity;
        }
    }
};

// C++ implementation of De-queue using circular
// array
#include<iostream>
using namespace std;


// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}


------------------------------------------------->


Node* reverse(Node* head)
{
    Node* dummy = NULL;
    while (head)
    {
        Node* Next = head -> next;
        head -> next = dummy;
        dummy = head;
        head = Next;
    }
    return dummy;
}

Node* addoneUtil(Node *head)
{
    Node *res = head;
    Node *tail;
    int carry = 1, sum;
    
    while (head)
    {
        sum = carry + head -> data;
        carry = (sum >= 10)? 1: 0;
        sum = (sum % 10);
        
        head -> data = sum;
        
        tail = head;
        head = head -> next;
    }
    if (carry > 0)
    {
        tail -> next = new Node(carry);
    }
    
    return res;
}

Node* NextLargeNumber(Node *head) {
    
    	head = reverse(head);
    	head = addoneUtil(head);
    return reverse(head);
    
}

#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}



