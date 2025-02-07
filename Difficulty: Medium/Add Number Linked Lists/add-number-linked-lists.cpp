//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    Node * reverselist(Node* head)
    {
        Node* prev=NULL,*cur=head,*front=head->next;
        
        while(front)
        {
            cur->next=prev;
            prev=cur;
            cur=front;
            front=front->next;
        }
        
        cur->next=prev;
        Node*tmp=cur;
        /*while(tmp){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
        }
        cout<<endl;*/
        return cur;
    }
    Node * delete_zeros(Node* head)
    {
        Node *tmp=head,*tmp2=head;
        if(head->next==NULL)
        return head;
        while(tmp->data==0)
        {
            tmp2=tmp->next;
            delete tmp;
            tmp=tmp2;
        }
        return tmp;
    }
    
    
    Node* insert_at_first(Node* head,int val)
    {
        Node *add=new Node(val);
        
        if(head==NULL)
        {
            head=add;
            return head;
        }
        
        add->next=head;
        head=add;
        return head;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        int carry=0,sum=0;
        Node *res=NULL;
        
        num1=delete_zeros(num1);
        num2=delete_zeros(num2);
        num1=reverselist(num1);
        num2=reverselist(num2);
         
        
        carry=0;
        while(num1 && num2)
        {
            sum=num1->data+num2->data+carry;
            if(sum > 9)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            res=insert_at_first(res,sum%10);
            sum=0;
            num1=num1->next;
            num2=num2->next;
        }
        
        if(num1)
        {
            while(num1)
            {
                sum=num1->data+carry;
                if(sum > 9)
                carry=1;
                else
                carry=0;
                res=insert_at_first(res,sum%10);
                sum=0;
                
                num1=num1->next;
            }
        }
        if(num2)
        {
            while(num2)
            {
                sum=num2->data+carry;
                if(sum > 9)
                carry=1;
                else
                carry=0;
                res=insert_at_first(res,sum%10);
                sum=0;
                
                num2=num2->next;
            }
        }
        if(carry)
            res=insert_at_first(res,1);
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends