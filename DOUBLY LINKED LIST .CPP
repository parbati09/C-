#include<iostream>
using namespace std;
struct node{
    node*prev;
    int data;
    node*next;
};
node* create(){
    node*p=new node();
    cout<<"\n"<<"Enter the data:"<<"\n";
    cin>>p->data;
    p->prev=NULL;
    p->next=NULL;
    return p;
}
void display_fwd(node* head){
    node*p;
    p=head;
    while(p->next!=NULL){
        cout<<p->data<<"\t";
        p=p->next;
    }
    cout<<p->data<<"\t";
}

void display_rev(node*head){
    node*p,*q;
    p=head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    q=p;
    while(q->prev!=NULL){
        cout<<q->data<<"\t";
        q=q->prev;
    }
    cout<<q->data<<"\t";
}

node*insert_beg(node*head){
    node*p,*q;
    p=create();
    q=head;
    if(head==NULL){
        head=p;
    }
    else{
    p->next=q;
    q->prev=p;
    head=p;
    }
    return head;
}

node* insert_anypos(node*head,int pos){
    node*p,*q,*r;
    p=create();
    q=head;
    int i=1;
    for(i=i+1;i<pos-1;i++){
        q=q->next;
    }
    r=q->next;
 // p->next=q->next;
 // q->next->prev=p;
    p->next=r;
    r->prev=p;
    q->next=p;
    p->prev=q;
    return head;
}

node*insert_end(node*head){
    node*p,*q;
    p=create();
    q=head;
    if(head==NULL){
        head=p;
    }
    else if(q->next==NULL){
        q->next=p;
        p->prev=q;
    }
    else if(q->next!=NULL){
        while(q->next!=NULL)
        {
        q=q->next;
        }
        q->next=p;
        p->prev=q;
    }
    return head;
}

node* del_beg(node*head){
    node*p,*q;
    q=head;
    p=head->next;
    delete q;
    head=p;
    return head;
}

node* del_end(node*head){
    node*p,*q;
    q=head;
    while(q->next->next!=NULL){
        q=q->next;
    }
    p=q->next;
    q->next=NULL;
    delete p;
    return head;
}

int main(){
    int choice,op,pos;
    node*head;
    head=create();
    display_fwd(head);
    do{
    cout<<"\n"<<"Choose from the dropdown below:"<<"\n";
    cout<<"1.Display"<<"\n";
    cout<<"2.Display reverse"<<"\n";
    cout<<"3.Insert at beginning"<<"\n";
    cout<<"4.Insert at any position"<<"\n";
    cout<<"5.Insert at end"<<"\n";
    cout<<"6.Delete at beginning"<<"\n";
    cout<<"7.Delete at end"<<"\n";

    cin>>choice;
    switch(choice){
        case 1:
        display_fwd(head);
        break;

        case 2:
        display_rev(head);
        break;

        case 3:
        head=insert_beg(head);
        //display_fwd(head);
        break;

        case 4:
        cout<<"\n"<<"Enter the position where you want to insert:"<<"\n";
        cin>>pos;
        head=insert_anypos(head,pos);
        //display_fwd(head);
        break;

        case 5:
        head=insert_end(head);
        //display_fwd(head);
        break;

        case 6:
        head=del_beg(head);
        //display_fwd(head);
        break;

        case 7:
        head=del_end(head);
        //display_fwd(head);
        break;
    }
    cout<<"\n"<<"Do you want to continue(YES=1/NO=0):"<<"\n";
    cin>>op;
    }while(op==1);
    return 0;
}
