#include <iostream>
using namespace std;

struct Node{
int data;
Node * next;

};



Node* Reverse(Node* head){
Node *temp=head;
Node *prevnode=nullptr;
Node* previous_node=nullptr;
while(temp!=nullptr){

    previous_node=temp;
    temp=temp->next;
    previous_node->next=prevnode;
    prevnode=previous_node;

}
head=prevnode;
return head;
}

Node* Insert(Node* head,int data){
Node *temp=new Node;
temp->data=data;
temp->next=nullptr;
if (head==nullptr){
    head=temp;
}
else{
    Node* temp1=head;
    while(temp1->next !=nullptr){
        temp1=temp1->next;
    }

    temp1->next=temp;
}
    return head;

}

void Print(Node *a){
if(a==nullptr){
    cout<<endl;
    return;
}
cout<<a->data<<" ";
Print(a->next);
}


void ReversePrint(Node *a){
if(a==nullptr){
    return;
}
ReversePrint(a->next);
cout<<a->data<<" ";
}

int main(){
Node* head=nullptr;
head=Insert(head,2);
head=Insert(head,4);
head=Insert(head,6);
head=Insert(head,8);
Print(head);
ReversePrint(head);

return 0;
}

