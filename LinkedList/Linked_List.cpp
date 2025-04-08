#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int x,Node* next1){
        data=x;
        next=next1;
    }

    Node(int x){
        data=x;
        next=nullptr;
    }
};

Node* convert2LL(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }

    return head;
}

int main()
{
    vector<int>arr={3,5,8,2,1,10};
    Node *head=convert2LL(arr);

    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}