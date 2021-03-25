#include <iostream>
using namespace std;

struct Node{
int data;
Node * next;

};



Node* Reverse(Node* temp){
    Node*head;
    if (temp->next==nullptr){
        head=temp;
        return head;
    }
    head=Reverse(temp->next);
    Node *temp2=temp->next;
    temp2->next=temp;
    temp->next=nullptr;
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


int main(){
Node* head=nullptr;
head=Insert(head,2);
head=Insert(head,4);
head=Insert(head,6);
head=Insert(head,8);
Print(head);
head=Reverse(head);
Print(head);


return 0;
}

