#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Node {
   public:
    T data;   //  int data;
    Node <T> *next;     //  Node* next;

    Node(T data) {      //  int data
        this->data = data;
        next = NULL;
    }
};


template <typename T>  // need to create while declaring class and using template in it..

class Stack {
	// Define the data members
    Node<T> *head;
    int size;
   
    public:
    Stack() {
        // Implement the Constructor
        size = 0;
    	head = NULL;    
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return (head == NULL);
    }

    void push(T element) {
        // Implement the push() function
        Node <T> *newNode = new Node<T>(element);
        
        if (head == NULL)
        {
            head = newNode;
        }
        else if (head != NULL)
        {
            newNode -> next = head;
            head = newNode;
        }
        size++;
    }

    T pop() {
        // Implement the pop() function
        if (head == NULL)
        {
            return -1;
        }
        
        T res = head -> data;
        Node <T> *temp = head;       //  Need to store temp node and delete that node..
        head = head -> next;
        delete temp;
        size--;
        return res;
    }

    T top() {
        // Implement the top() function
        if (head == NULL)
        {
            return -1;
        }
        
        T res = head -> data;
        return res;
    }
};



int32_t main() {
    Stack <int>st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}


/*

Code : Stack Using LL
    Implement a Stack Data Structure specifically to store integer data using a Singly Linked List.
    The data members should be private.
    You need to implement the following public functions :
        1. Constructor:
        It initialises the data members as required.
        2. push(data) :
        This function should take one argument of type integer. It pushes the element into the stack and returns nothing.
        3. pop() :
        It pops the element from the top of the stack and in turn, returns the element being popped or deleted. In case the stack is empty, it returns -1.
        4. top :
        It returns the element being kept at the top of the stack. In case the stack is empty, it returns -1.
        5. size() :
        It returns the size of the stack at any given instance of time.
        6. isEmpty() :
        It returns a boolean value indicating whether the stack is empty or not.
    
    Sample Input 1:
        6
        1 13
        1 47
        4
        5
        2
        3
    Sample Output 1:
        2
        false
        47
        13




	/*----------------- Public Functions of Stack -----------------

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return (head == NULL);
    }

    void push(int element) {
        // Implement the push() function
        Node *newNode = new Node(element);
        
        if (head == NULL)
        {
            head = newNode;
        }
        else if (head != NULL)      //  No-need of pointing head_case..
        {
            newNode -> next = head;
            head = newNode;
        }
        
        size++;
    }

    int pop() {
        // Implement the pop() function
        if (head == NULL)
        {
            return -1;
        }
        
        int res = head -> data;
        Node* temp = head;
        head = head -> next;
        delete temp;

        size--;
        return res;
    }

    int top() {
        // Implement the top() function
        if (head == NULL)
        {
            return -1;
        }
        
        int res = head -> data;
        return res;
    }
};

*/ 