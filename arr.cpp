#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }

};

int sizeOfLL(node* head){
    int ct =0;
    node* temp=head;

    while(head != NULL){
        ct++;
        head=head->next;
    }
    return ct;
}

void deletefirst(node* &head,node* & tail){
    if(head==nullptr){
        return;
    }
    else if(head==tail){
        node *temp=head;
        delete temp;
        head=tail=NULL;

    }
    else{
        node* temp=head;
        head=head->next;
        delete temp;
        temp==NULL;
    }

}

void deleteLast(node* &head,node* &tail){
    if(head==nullptr){
        return;
    }
    else if(head==tail){
        delete head;
        head=tail=NULL;

    }
    else{
        node* curr=head;
        while(curr->next !=tail){
            curr=curr->next;
        }
        curr->next=tail;
        delete tail;
        tail=curr;
    }

}

void deleteLL(node* &head, node* &tail,int index){
    if(index==0){
        deletefirst(head,tail);
    }
    else if(index<sizeOfLL(head)){
    
        node*curr=head;
        for(int i=0;i<index-1;i++){
            curr=curr->next;
        }
        node* temp=curr->next;
        node* n=temp->next;
        curr->next=n;
        delete temp;
    }

}
void insertatbeginning(node* &head,node* &tail,int data){
    if(head==NULL){
        node *n=new node(data);
        head=n;
        tail=n;
    }
    else{
        node *n= new node(data);
        n->next=head;
        head=n;
    }
}

void print(node *head){
    while(head !=NULL){
        cout<<head ->data<<" ";
        head=head ->next;
    }
    cout<<endl;
}


int main(){
    node* tail,*head;
    head=tail=NULL;
    insertatbeginning(head,tail,1);
    insertatbeginning(head,tail,2);
    insertatbeginning(head,tail,3);
    insertatbeginning(head,tail,4);
    insertatbeginning(head,tail,5);
    // print(head);

    deleteLL(head,tail,3);
    print(head);
    return 0;
}