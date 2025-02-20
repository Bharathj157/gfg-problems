//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*
Node* sort_ll(Node* head)
{
    Node *prev=NULL,*cur=head;front=head;
    
    while(cur)
    {
        front=front->next;
        cur->next=prev;
        prev=cur;
        cur=front;
    }
    return prev;
}*/

void delete_node(Node*head)
{
    Node* tmp=head->next;
    
    head->next=head->next->next;
    
    delete tmp;
}

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
       // head=sort_ll(head);
        std::unordered_set<int> seen;
        seen.insert(head->data);

        Node* tmp=head->next,*prev=head;
        int inc=1;
        while(tmp)
        {
            if( seen.find(tmp->data) != seen.end() )
            {
                delete_node(prev);
                tmp = prev->next;
               // cout<<"delete called"<<endl;
            }
            else
            {
                seen.insert(tmp->data);
                prev=tmp;
                tmp=tmp->next;
               // cout<<"Inserted "<<endl;
            }
           // cout<<"while loop executed this times "<<inc++<<endl;
        }
        return head;
    }
};


//{ Driver Code Starts.

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

        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        Node *head = new Node(arr[0]);
        Node *tail = head;

        for (size_t i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        Node *result = ob.removeDuplicates(head);
        printList(result);
    }

    return 0;
}

// } Driver Code Ends