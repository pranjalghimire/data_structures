
#include <iostream>
using namespace std;


struct Node{
int data;
Node * next;
};

Node *head =nullptr;


void Print(){
Node*temp=head;
while(temp!=nullptr){
 cout<<temp->data<<endl;
 temp=temp->next;
}
return;
}




void Insert(int data,int n){
Node *newnode=new Node();
newnode->data=data;
newnode->next=nullptr;

if(n==1){
    newnode->next=head;
    head=newnode;
    return;
}

Node* temp=head;
for(int i=1;i<=n-2 && temp!=nullptr ;i++){
    temp=temp->next;

}
newnode->next=temp->next;
temp->next=newnode;

}

void Delete(int n){
    Node*temp=head;
    if (n==1){
        head=temp->next;
        delete temp;
        return;
    }

    for(int i=1;i<=n-2;i++){
        temp=temp->next;

    }
    Node *temp2=temp->next;
    temp->next=temp2->next;
    delete temp2;



}



int main()
{
    Insert(1,1);
    Insert(2,2);
    Insert(3,2);
    Insert(4,2);
    Insert(6,5);
    Delete(2);
    Delete(1);

    Print();
    return 0;
}

