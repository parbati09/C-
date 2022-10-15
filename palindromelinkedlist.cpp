# include <iostream>
using namespace std;
struct Node
{
    int v;
    Node *next;
};
void printlinkedlist(Node *root)
{
    Node *p=root;
    if(p==NULL)
    return;
    while(p!=NULL)
    {
        cout<<p->v<<" ";
        p=p->next;
    }
    cout<<endl;
    return;

}
Node *rev(Node *root)
{
    Node *p=root;
    Node *parent=NULL;
    if(p==NULL)
    return NULL;
    while(p!=NULL)
    {
        //cout<<p->v<<" ";
        //At a pointer p: Have the parent pointer set it to be the next pointer
        
        Node *temp=p->next;
        p->next=parent;
        parent=p;
        p=temp;
    }
    //parent contains the last node
    Node *start=parent;

    return start;

}
bool palindromelinkedlist(Node *n1,Node *n2)
{
    bool ret;
    while(n1!=NULL)
    {
        if(n1->v!=n2->v)
        return false;
        n1=n1->next;
        n2=n2->next;
    }
    return true;
}
int main()
{
    Node *test=new(Node);
    test->v=3;
    test->next=new(Node);
    test->next->v=6;
    test->next->next=new(Node);
    test->next->next->v=8;
    test->next->next->next=new(Node);
    test->next->next->next->v=10;
    test->next->next->next->next=NULL;
    Node *test2=new(Node);
    test2->v=3;
    test2->next=new(Node);
    test2->next->v=6;
    test2->next->next=new(Node);
    test2->next->next->v=6;
    test2->next->next->next=new(Node);
    test2->next->next->next->v=3;
    test2->next->next->next->next=NULL;
    printlinkedlist(test);
    Node *ret=rev(test);
    printlinkedlist(ret);
    if(palindromelinkedlist(test,ret))
    cout<<"PALINDROME";
    else
    cout<<"NOT PALINDROME";
    cout<<endl;
    printlinkedlist(test2);
    Node *ret2=rev(test2);
    printlinkedlist(ret2);
    if(palindromelinkedlist(test2,ret2))
    cout<<"PALINDROME";
    else
    cout<<"NOT PALINDROME";


}
