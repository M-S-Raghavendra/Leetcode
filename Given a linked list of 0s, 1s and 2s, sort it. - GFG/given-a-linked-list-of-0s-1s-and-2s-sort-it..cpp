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
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head == NULL or head->next == NULL)
            return head;
        
        Node *d1 = new Node(-1);
        Node *d2 = new Node(-1);
        Node *d3 = new Node(-1);
        Node* h1, *h2, *h3, *t1, *t2, *t3;
        h1 = t1 = d1;
        h2 = t2 = d2;
        h3 = t3 = d3;
        
        Node* cur = head;
        
        while(cur) {
            if(cur->data == 0) {
                t1->next = cur;
                t1 = t1->next;
            } else if(cur->data == 1) {
                t2->next = cur;
                t2 = t2->next;
            } else {
                t3->next = cur;
                t3 = t3->next;
            }
            cur = cur->next;
        }
        
        t3->next = NULL;
        
        t2->next = h3->next;
        t1->next = h2->next;
            
        if(h1->next)
            return h1->next;
        else if(h2->next)
            return h2->next;
        else return h3->next;
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
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
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