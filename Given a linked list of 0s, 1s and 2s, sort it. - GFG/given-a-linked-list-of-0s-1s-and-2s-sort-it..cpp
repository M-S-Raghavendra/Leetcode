//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    private:
    Node* mergeSortedLists(Node* l1, Node* l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        Node* dummy = new Node(0);
        Node* head, *tail, *a, *b;
        head = tail = dummy;
        a = l1;
        b = l2;
        
        while(a and b)          
        {
            if(a->data <= b->data) {
                tail->next = a;
                a = a->next;
                tail = tail->next;
            }
            else {
                tail->next = b;
                b = b->next;
                tail = tail->next;
            }
        }
        
        if(a)
            tail->next = a;
        if(b)
            tail->next = b;
        
        return head->next;
    }
    
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head == NULL or head->next == NULL)
            return head;
        
        Node* slow, *fast, *prev;
        slow = fast = head;
        
        while(fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        
        Node* l1 = segregate(head);
        Node* l2 = segregate(slow);
        
        return mergeSortedLists(l1,l2);
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, dataue, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &dataue);

        if (i == 0) {
            start = new Node(dataue);
            temp = start;
            continue;
        } else {
            temp->next = new Node(dataue);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends