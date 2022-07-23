/*
Given a singly linked list of integers and an integer n, find and return the index for the first occurrence of 'n' in the linked list. -1 otherwise.
Follow a recursive approach to solve this.

    Sample Input 2 :
        2
        10 20010 30 400 600 -1
        20010
        100 200 300 400 9000 -34 -1
        -34
    Sample Output 2 :
        1
        5

*/

    
int findNodeRec(Node *head, int n, int count = 0)
{

     if (head == NULL)
    {
        return -1;
    }
    
    if (head && head -> data == n)
    {
        return count;
    }
    int smallTask = findNodeRec(head -> next, n, count+=1);
    
     return smallTask;

}
// ---------------------------------------------->
/*
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.

    Sample Input 2 :
        2
        1 11 3 6 8 0 9 -1
        10 20 30 40 -1
    Sample Output 2 :
        1 11 3 9 6 8 0
        10 20 30 40
*/ 
Node *evenAfterOdd(Node *temp)
{
	//write your code here
    Node* head = temp;
    
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    
    Node* OH = NULL, *OT = NULL, *EH = NULL, *ET = NULL;
    
    while (head != NULL)
    {
        if ((head -> data) % 2 != 0)	//	Odd
        {
            if (OH == NULL)
            {
                OH = head, OT = head;
            }
            
            else 
            {
                OT -> next = head;
                OT = OT -> next;
            }
        }
        
        if ((head -> data) % 2 == 0)
        {
            if (EH == NULL)
            {
                EH = head, ET = head;
            }
            else 
            {
                ET -> next = head;
                ET = ET -> next;
            }
        }
        head = head -> next;
    }
    
    if (OT && ET)
    {
        ET -> next = NULL;
        OT -> next = NULL;
        OT -> next = EH;
        return OH;
    }
    

    else if (OT == NULL)
    {
        ET -> next = NULL;
    }
    return (EH != NULL) ? EH:OH;
}


// --------------------------------------------->

/*

You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.

        Sample Input 2 :
            2
            10 20 30 40 50 60 -1
            0 1
            1 2 3 4 5 6 7 8 -1
            2 3
    Sample Output 2 :
        1 2 6 7

*/ 



Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
     if (N == 0 && M >= 0)
    {
        return head;
    }
    
    if (M == 0 && N > 0)
    {
        return NULL;
    }
    
    Node*temp = head, *t2;
    int count;
    
    while (temp != NULL)
    {
        for(count = 1; count < M && temp != NULL; count++)
        {
            temp = temp -> next;
        }
        
        if (temp == NULL)
        {
            return head;
        }
        
        t2 = temp-> next;
        for (count = 1; count <= N && t2 != NULL; count++)		
        {
            Node* prev = t2;
            t2 = t2 -> next;
            free(prev); //	delete all element upto 'N'
        }
        
        temp -> next = t2;
        temp = temp -> next;
    }
    return head;
}