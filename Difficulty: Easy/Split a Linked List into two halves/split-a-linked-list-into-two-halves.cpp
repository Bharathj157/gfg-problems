//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends

/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        // code here
      /*  Node* tmp=head,*prev=head;
        do{
            prev=tmp;
            tmp=tmp->next;
        }
        while(tmp != head);
        
        prev->next=NULL;
        
        tmp=head;
        Node* tmp2=head; 
        
        while(tmp2 && tmp2->next)
        {
            prev=tmp;
            tmp=tmp->next;
            tmp2=tmp2->next->next;
        }
        
        prev->next=NULL;
        
        pair<Node*,Node*> res;
        
        res.first=head;
        res.second=tmp;
    
        return res;
        
    }*/
    if (!head || !head->next) return {head, nullptr};  // Edge case: Empty or single-node list
        Node* tmp = head, *prev = nullptr;
        // Step 1: Find the last node of the circular linked list
        do {
            prev = tmp;
            tmp = tmp->next;
        } while (tmp != head);

        // Now, prev is pointing to the last node
        Node* last = prev;  // Save last node reference

        // Step 2: Use slow/fast pointer approach to find the middle
        tmp = head;
        Node* tmp2 = head; 

        while (tmp2->next != head && tmp2->next->next != head) {
            prev = tmp;
            tmp = tmp->next;
            tmp2 = tmp2->next->next;
        }

        // If even number of nodes, move fast pointer one step further
       /* if (tmp2->next->next == head)
            tmp2 = tmp2->next;
        */
        
        // Step 3: Split the list into two circular halves
        Node* head1 = head;   // First half starts from head
        Node* head2 = tmp->next; // Second half starts from mid+1 node
        
        tmp->next=head;
        last->next=head2;
        return {head1, head2}; // Return two circular halves
    }   
};

//{ Driver Code Starts.

void printList(struct Node *head) {
    struct Node *temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

struct Node *newNode(int key) {
    struct Node *temp = new Node(key);

    return temp;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        struct Node *temp, *head = NULL;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            temp = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                temp->next = new Node(arr[i]);
                temp = temp->next;
            }
        }
        temp->next = head;
        Solution ob;
        auto result = ob.splitList(head);
        struct Node *head1 = result.first;
        struct Node *head2 = result.second;
        printList(head1);
        printList(head2);
    }

    return 0;
}

// } Driver Code Ends