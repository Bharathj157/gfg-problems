//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
  
    Node* insert_at_first(Node*head,int val)
    {
        if(head == NULL)
        {
            Node *res=new Node(val);
            return res;
        }
        
        Node *res=new Node(val);
        res->next=head;
        
        return res;
    }
    
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node* prev=NULL,*cur=head,*front=head;
        
        while(cur)
        {
            front=front->next;
            cur->next=prev;
            prev=cur;
            cur=front;
        }
        head=prev;
        
        Node* tmp=head,*res=NULL;
        
        int carry=1,num=0;
        while(tmp)
        {
            num=(tmp->data+carry);
            if(num > 9)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            res=insert_at_first(res,num%10);
            tmp=tmp->next;
        }
        if(carry == 1)
        {
            res=insert_at_first(res,1);
        }
        return res;
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
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends