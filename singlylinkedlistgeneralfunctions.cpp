# include <iostream>
using namespace std;
//Single Linked List
struct Node
{
    int val;
    Node* next;
}*top;
void addend(int v)
{
    Node *p;
    p=new(Node);
    top->next=p;
    p->val=v;
    top=p;
    p->next=NULL;

}
void addstart(int v,Node *&root)
{
     Node *p;
    p=new(Node);
    p->next=root;
    p->val=v;
    root=p;



}
void addafter(int v,Node *root,int va)
{
    Node *present;
    present=root;
    while(true)
    {
        if (present->val==v)
        {
            Node *p;
            p=new(Node);
            p->val=va;
            p->next=present->next;
            present->next=p;
            break;
            

        }
        present=present->next;
    }

}
int lenitr(Node *root)
{
    int n=1;
    Node *p=root;
    while(true)
    {
        if (p->next==NULL)
        break;
        p=p->next;
        n++;
    }
    return n;
}
int lenrec(Node *root)
{
    if (root->next==NULL)
    return 1;
    else
    return 1+lenrec(root->next);
}
Node* findptr(Node *root,int v)
{
    Node *p;
    p=root;
    while(true)
    {
        if (p->val==v)
        {
            return p;
        }
        p=p->next;
    }
}
void traverse(Node *root)
{
    Node *present;
    present=root;
    cout<<present->val;
    while(present->next!=NULL)
    {
        present=present->next;
        cout<<present->val<<" ";
    }
    cout<<endl;
}
void del(Node *root)
{
    Node *present;
    present=root;
    while(true)
    {
        if (present->next==top)
        {
            present->next=NULL;
            top=present;
            break;
        }
        present=present->next;
    }



}
void delkey(Node *root,int v)
{
    Node *present;
    Node *need=findptr(root,v);
    present=root;
    while(true)
    {
        if (present->next==need)
        {
            present->next=need->next;
            break;
        }
        present=present->next;
    }


}
void searchrec(Node *root,int v)
{
    cout<<root;
    if (root->val==v)
    {
        cout<<"Found"<<endl;
        return;
    }
    if (root==NULL)
    {
        cout<<"Not Found"<<endl;
        return;
    }
    cout<<root->val<<" ";
    return searchrec(root->next,v);

}
void searchitr(Node *root,int v)
{
    Node *p=root;
    while(p!=NULL)
    {
        if (p->val==v)
        {
            cout<<"Found"<<endl;
        return;
        }
        p=p->next;
    }
    cout<<"Not Found"<<endl;

}
void delall(Node *root)
{
    while(true)
    {
        if (root->next==NULL)
        {
            cout<<"Reached";
            delete(root);
            break;
        }
        del(root);
    }
}
void nth(Node *root,int v)
{
    Node *present=root;
    int n=1;
    while (true)
    {
        if (n==v)
        {
            cout<<present->val;
            break;
        }
        n++;
        present=present->next;
    }
    
}
void mid(Node *root)
{
    int total=lenitr(root);
    if (total%2==0)
    {
        nth(root,total/2);
        cout<<endl;
        nth(root,(total/2)+1);
    }
    else
    nth(root,(total+1)/2);
}
int main()
{
    Node* root=new(Node);
    top=root;
    root->next=NULL;
    root->val=1;
    addend(2);
    addend(3);
    addend(4);
    addstart(0,root);
    addstart(-1,root);
    addstart(-2,root);
    traverse(root);
    del(root);
    addafter(2,root,5);
    traverse(root);
    delkey(root,1);
    traverse(root);
    cout<<lenitr(root)<<endl;
    cout<<lenrec(root)<<endl;
    searchrec(root,0);
    searchitr(root,0);
    searchitr(root,6);
    //searchrec(root,6);
    nth(root,1);
    cout<<endl;
    mid(root);
    //delall(root);
    //traverse(root);



}
