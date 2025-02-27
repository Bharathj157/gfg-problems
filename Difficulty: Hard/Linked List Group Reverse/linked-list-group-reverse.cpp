//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends

/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/
Node* reverse_list(Node* head)
{
    Node* cur=head,*prev=NULL,*front=head;
    
    while(cur){
        front=front->next;
        cur->next=prev;
        prev=cur;
        cur=front;
    }
    
    return prev;
}

Node* find_kth(Node* tmp,int k)
{
    Node* prev=tmp;
    while(tmp && --k)
    {
        prev=tmp;
        tmp=tmp->next;
    }
    
    if(!k){
    return tmp;}
    else
    return prev;
    
}

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(k == 1 )
        return head;
        int flag=1,n=0;
        Node *tmp=head,*kth,*next_node=head,*cur=head,*prev_first_node=head,*last_node;
        
        
        while(cur)
        {
            kth=find_kth(next_node,k);
            prev_first_node=next_node;
            
            next_node=kth->next;
            kth->next=NULL;
            
            
            cur=reverse_list(cur);
            
            
            if(tmp == head)
            head=cur;
            else
            {
                tmp->next=cur;
                tmp=prev_first_node;
            }
            
            cur=next_node;
            
        }
        return head;
    }
};



//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

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
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends