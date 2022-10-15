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
    return;

}
// void del(Node *root)
// {
//     root->v=root->next->v;
//     root->next=root->next->next;
//     return;

// }
Node *cycledetect(Node *root)
{
    Node *slow;
    Node *fast;
    slow=root;
    fast=root;
    while(fast!=NULL)
    {
        
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        return fast;
    }
    return NULL;
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
    //printlinkedlist(test);
    //del(test->next->next);
    //Node *ret=middle(test);
    if(cycledetect(test)==NULL)
    cout<<"NO CYCLE DETECTED";
    else
    {
        cout<<"Cycle detected at "<<cycledetect(test)->v;
    }
    
    //printlinkedlist(test);


}
