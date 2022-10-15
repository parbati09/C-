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
void printlinkedlistnumber(Node *root)
{
    cout<<"NUMBER : ";
    Node *p=root;
    if(p==NULL)
    return;
    while(p!=NULL)
    {
        cout<<p->v;
        p=p->next;
    }
    cout<<endl;
    return;

}
int add(Node *r1,Node *r2)
{
    int num1=0;
    int factor1=1;
    int factor2=1;
    int num2=0;
    Node *ptr=r1;
    Node *ptr2=r2;
    while(ptr!=NULL)
    {
        num1+=(factor1*ptr->v);
        factor1*=10;
        ptr=ptr->next;
    }
    while(ptr2!=NULL)
    {
        num2+=(factor2*ptr2->v);
        factor2*=10;
        ptr2=ptr2->next;
    }
    return num1+num2;
}
int main()
{
    // Node *test=new(Node);
    // test->v=3;
    // test->next=new(Node);
    // test->next->v=6;
    // test->next->next=new(Node);
    // test->next->next->v=8;
    // test->next->next->next=new(Node);
    // test->next->next->next->v=10;
    // test->next->next->next->next=NULL;
    //printlinkedlist(test);
    Node *r1=new(Node);
    Node *r2=new(Node);
    r1->v=2;
    r1->next=new(Node);
    r1->next->v=4;
    r1->next->next=new(Node);
    r1->next->next->v=3;
    r1->next->next->next=NULL;
    r2->v=5;
    r2->next=new(Node);
    r2->next->v=6;
    r2->next->next=new(Node);
    r2->next->next->v=4;
    r2->next->next->next=NULL;
    printlinkedlistnumber(r1);
    printlinkedlistnumber(r2);
    cout<<"THE SUM OF THE TWO NUMBER IS: "<<add(r1,r2);
    //Node *ret=middle(test);
    //printlinkedlist(ret);


}
