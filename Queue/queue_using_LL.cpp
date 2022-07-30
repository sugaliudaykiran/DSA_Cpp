#include <iostream>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};


template <typename T>       //  In this by maintain head, tail pointer and inserting and deleting at different ends..
class Queue {                   //  All operation takes O(1)..
	// Define the data members
    Node <T> *head;
    Node<T> *tail;
    int size; 
   public:
    Queue() {
		// Implement the Constructor
        head = NULL, tail = NULL;
        size = 0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		// Implement the getSize() function
        return size;
	}

    bool isEmpty() {
		// Implement the isEmpty() function
        return (size == 0);
	}

    void enqueue(T data) {
		// Implement the enqueue() function
        Node<T> *newNode = new Node<T>(data);
        
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            tail -> next = newNode;
        	tail = newNode;
        }
        size++;
	}

    T dequeue() {
        // Implement the dequeue() function
        if (isEmpty())
        {
            cout << "Queue is Empty..!" << "\n";
            return 0;
        }
        
        int temp = head -> data;        //  int temp = head -> data; 
        Node<T> *temp = head;
        head = head -> next;            //  head = head -> next;   is also better
        delete temp;

        size--;
        return temp;
    }

    T front() {
        // Implement the front() function
        if (isEmpty())
        {
            cout << "Queue is Empty..!" << "\n";
            return 0;
        }
        return head -> data;
    }
};



// #include "solution.h"

int main() {
    Queue<int>q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}