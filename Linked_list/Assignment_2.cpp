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


/****************************************************************
        Swap two Nodes of LL
 
    You have been given a singly linked list of integers along with two integers, 'i,' and 'j.'
 Swap the nodes that are present at the 'i-th' and 'j-th' positions.

Sample Input 2 :
    2
    10 20 30 40 -1
    1 2
    70 80 90 25 65 85 90 -1
    0 6

Sample Output 2 :
    10 30 20 40 
    90 80 90 25 65 85 70 

*****************************************************************/

Node *swapNodes(Node *head, int i, int j)
{
	//	ref - https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/    

    if (head == NULL || head -> next == NULL || i == j)
    {
        return head;
    }
    
    Node* prevX = NULL, *prevY= NULL, *curX= head, *curY= head;
    int count = 0;
    
    while (curX && count != i)
    {
        prevX = curX;
        curX = curX -> next;
        count++;
    }
    
    count = 0;
    while (curY && count != j)
    {
        prevY = curY;
        curY = curY -> next;
        count++;
    }
     
    if (curX == NULL || curY == NULL)	//	If any one is not in given range..
    {
        return head;
    }
    
    if (prevX != NULL)	//	In case of head/tail and next be i and j..
    {
        prevX -> next = curY;
    }
    else
    {
		head = curY;
    }
    
    if (prevY != NULL)	// //	In case of head/tail and next be j and i..
    {
        prevY -> next = curX;
    }
    else
    {
        head = curX;
    }
    						//	Both are at random position..
	Node* temp = curY->next;
    curY->next = curX->next;
    curX->next = temp;
    
    return head;
}



/*
         kReverse
Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
 'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' 
    then left-out nodes, in the end, should be reversed as well.


Sample Input 2 :
    2
    1 2 3 4 5 -1
    0
    10 20 30 40 -1
    4
    
Sample Output 2 :
    1 2 3 4 5 
    40 30 20 10 
*/ 






Node *kReverse(Node *head, int k)
{
    //Write your code here
    if (head == NULL || k == 0)
    {
        return head;
    }
    
    Node* cur = head, *next = NULL, *prev = NULL;
    int count  = 0;
    
    while (cur && count < k)
    {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
        
        count++;
    }
    
    if (next)  // or we can use "cur".. instead of "next"..
    {
        head -> next =  kReverse(next, k);	//	add recursive value to head -> next..
    }
    return prev;
}





/*

Given a singly linked list of integers, sort it using 'Bubble Sort.'

*/ 


Node *bubbleSort(Node *head)
{
	// Write your code here
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    
    Node* i = head;
    while (i)
    {
        Node* j = head ;
        Node*prev = head;
        
        while (j-> next)
        {
            Node*temp = j-> next;
            if (j -> data > temp -> data)
            {
                if (j == head)
                {
                    j -> next = temp-> next;
                    temp -> next = j;
                    prev = temp;
                    head = temp;
                }
                else
                {
                    j -> next = temp-> next;
                    temp -> next = j;
                    prev -> next = temp;
                    prev = temp;
                }
            continue;  
            }
            prev = j;
            j = j -> next;
        }
        i = i-> next;
        
    }
    
    return head;
}
