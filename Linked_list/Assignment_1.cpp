Find a Node in Linked List
    You have been given a singly linked list of integers. Write a function that returns the index/position of integer data denoted by 'N' (if it exists). Return -1 otherwise.


int findNode(Node *head, int n){
    
    if (head == NULL)
    {
        return -1;
    }
    
    int count = 0;
    Node *temp = head;
    
    while (temp != NULL)
    {
        if (temp -> data == n)
        {
            return count;
        }
        
        temp = temp -> next;
        count++;
    }
    return -1;
}
--------------------------------------->
AppendLastNToFirst
You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if (head == NULL || n <= 0)
    {
        return head;
    }
    
    Node *temp = head;
    int count = 0, len = 0;
    
    while (temp != NULL)
    {
        temp = temp -> next;
        len++;
    }
    
    temp = head;
    
    while (temp && count < (len - n)-1)
    {
        temp = temp -> next;
        count++;
    }
    
    Node* newHead = temp -> next;
    temp -> next = NULL;
    
    temp = newHead;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = head;
    head = newHead;
    
    return head;
    
}
------------------------------------------->
Eliminate duplicates from LL
You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.

Node *removeDuplicates(Node *head)
{
	if (head == NULL)
    {
        return NULL;
    }
    
    Node* temp = head;
    int last_ele = temp -> data;
    
    while (temp != NULL && temp -> next != NULL)
    {
        if (temp -> next -> data == last_ele)
        {
            temp -> next = temp -> next -> next;
        }
        else
        {
            temp = temp -> next;
            last_ele = temp -> data;
        }
    }
    return head;
}
---------------------------------------->
Print Reverse LinkedList
You have been given a singly linked list of integers. Write a function to print the list in a reverse order.
To explain it further, you need to start printing the data from the tail and move towards the head of the list, printing the head data at the end.


void printReverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    
    
    printReverse(head -> next);
    
    if (head)
    {
        cout << head -> data << " ";
    }
}



Node* helper(Node *head)
{
    Node *dummy = NULL;
    
    while (head != NULL)
    {
        Node* next_ptr = head -> next;
        head -> next = dummy;
        dummy = head;
        head = next_ptr;
    }
	return dummy;
}

void printReverse(Node *heads)
{
    if (heads == NULL)
    {
        return;
    }
    
    Node* head = heads;
    Node *dummy = NULL;
    
    while (head != NULL)
    {
        Node* next_ptr = head -> next;
        head -> next = dummy;
        dummy = head;
        head = next_ptr;
    }
    heads = dummy;
    
    while (heads != NULL)
    {
        cout << heads -> data << " ";
        heads = heads -> next;
    }
}



Node* reverse(Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    
    Node* dummy = NULL;
    
    while (head != NULL)
    {
        Node* nextPtr = head -> next;
        head -> next = dummy;
        dummy = head;
        head = nextPtr;
    }
    return dummy;
}

-------------------------------------------->
Palindrome LinkedList
You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.

bool isPalindrome(Node *head)
{
    if (head == NULL || head -> next == NULL)
    {
        return true;
    }
    
	Node* slow = head, *fast = head;
    
    while (fast -> next != NULL and fast -> next -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    Node *newHead = slow -> next;
    slow -> next = reverse(newHead);
    
    slow = slow -> next;
    fast = head;
    
    while (slow != NULL)
    {
		if (fast -> data == slow -> data)
        {
            slow = slow -> next;
        	fast = fast -> next;
        }
        else
        {
            return false;
        }
    }
    return true;
}

