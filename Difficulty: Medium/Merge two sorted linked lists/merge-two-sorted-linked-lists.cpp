//{ Driver Code Starts
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

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data) {
    Node *new_node = new Node(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}


// } Driver Code Ends

/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
Node* insert_at_first(Node *tmp1,Node*tmp2)
{
    tmp2->next=tmp1;
    return tmp2;
}


void insert_before(Node* tmp1,Node* tmp2,Node* prev1)
{
    prev1->next=tmp2;
    tmp2->next=tmp1;
}


class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node *tmp1=head1,*tmp2=head2,*tmp,*prev1=head1,*prev2=head2;
        
        while( tmp1 && tmp2 )
        {
            if(tmp1->data > tmp2->data)
            {
                tmp=tmp2->next;
                if(tmp1 == head1){
                head1=insert_at_first(tmp1,tmp2);
                prev1=head1;
                }
                else
                {
                    insert_before(tmp1,tmp2,prev1);
                    prev1=tmp2;
                }
                tmp2=tmp;
            }
            else
            {
                prev1=tmp1;
                tmp1=tmp1->next;
            }
        }
        if(tmp1 == NULL)
        {
            prev1->next=tmp2;
        }
        return head1;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *head2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            head1 = insertSorted(head1, tmp);
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            head2 = insertSorted(head2, tmp);
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends