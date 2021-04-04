#include <iostream>
using namespace std;

struct Node{
int data;
Node *next;
Node *prev;
};

Node* head=nullptr;
Node* tail=nullptr;


void Print(){
Node *temp=head;
while(temp!=nullptr){
    cout<<temp->data<<" ";
    temp=temp->next;
}
cout<<endl;
}

void ReversePrint(){
Node *temp=tail;
while(temp!=nullptr){
    cout<<temp->data<<" ";
    temp=temp->prev;
}

}


Node* CreateNode(int n){
Node* newNode=new Node();
newNode->prev=nullptr;
newNode->next=nullptr;
newNode->data=n;
return newNode;
}



void Insert(int n,int pos){

    Node *newNode=CreateNode(n);
    if(pos==1){
        if (head==nullptr){
            head=newNode;
            tail=head;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        return;
    }

    Node*currentNode=head;
    for(int i=2;i<pos;i++){
        currentNode=currentNode->next;
    }
    if(currentNode->next==nullptr){
        currentNode->next=newNode;
        tail=newNode;
        newNode->prev=currentNode;
    }
    else{
    newNode->next=currentNode->next;
    currentNode->next->prev=newNode;
    newNode->prev=currentNode;
    currentNode->next=newNode;
    }

}

void Delete(int pos){
if(pos==1){
    Node*temp=head;
    if(temp->next==nullptr){
        head==nullptr;
        tail=nullptr;
        delete(temp);
        temp=nullptr;
    }
    else{
    head=temp->next;
    temp->next->prev=nullptr;
    delete temp;
    temp=nullptr;
    }
}

else{
    Node *temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    Node* temp2=temp->next;
    if(temp2->next==nullptr){
        tail=temp;
        delete temp2;
        temp2=nullptr;
        temp->next=nullptr;
    }
    else{
        temp2->next->prev=temp;
        temp->next=temp2->next;
        delete temp2;
        temp2=nullptr;
    }
}

}






int main(){
Insert(4,1);
Insert(5,2);
Insert(6,3);
Insert(7,4);
Insert(8,5);
Insert(10,5);



Delete(5);
Print();
ReversePrint();

return 0;
}


