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

Node* convertArray2LL(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }

    return head;
}


//print
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

//remove head
Node* removeHead(Node* head){
    if(head==NULL)
    return head;

    Node* temp=head;
    head=head->next;

    delete temp;

    return head;
}

//remove kth node
Node* removeKthNode(Node* head,int k){
    if(head==NULL)
    return head;

    if(k==1){
        Node* temp=head;
        head=head->next;

        delete temp;

        return head;
    }

    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;

    while(temp!=NULL){
        cnt++;

        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }

        prev=temp;
        temp=temp->next;
    }

    return head;
}


int main()
{
    vector<int>arr={3,5,8,2,1,10};
    Node *head=convertArray2LL(arr);
    
    Node* head2=removeKthNode(head,1);
    
    print(head2);
}