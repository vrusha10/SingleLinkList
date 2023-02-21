/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
};
node *head=new node;
void print(node *temp)
{
    while(temp!=nullptr)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    delete temp;
}
void reverseprint(node *temp)
{
    if(temp==nullptr)
        return;
    reverseprint(temp->next);
    cout<<temp->data<<"\t";

}
void addlast(node* &head,int new_data)
{
    node *last=new node;
    node *temp=new node;
    temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=last;
    last->data=new_data;
    last->next=nullptr;

}
// void addafter(node* &head,int data)
// {
//     node *newmiddle =new node;
//     node *temp=new node;
//     temp=head;
//     while(temp->data!= data)
//     {
//         temp=temp->next;
//     }
//     temp->next=newmiddle;
//     newmiddle->data=35;
//     newmiddle->next=nullptr;

// }

//   void middleNode(node* head) {
//         node *slow = head, *fast = head;
//         while (fast && fast->next)
//             slow = slow->next, fast = fast->next->next;
//   }

int get_Middle(node *head)
{
    if(!head) return -1;
    int c = 0;
    node *middle = head;
    while( head ) {
        if(c%2 != 0) middle = middle->next;
        c++;
        head = head->next;
    }
    return middle->data;
}
void insertnewhead(node * &head,int data)
{
    node *newhead=new node;
    newhead->data=data;
    newhead->next=head;
    head=newhead;
   }

void deleteatfirst(node* &head)
{
    node *todelete=new node;
    todelete=head;
    head=head->next;
    delete todelete;
}

void deleteatpos(node* &head,int data)
{
   node *temp=new node;
   node *deletenode=new node;
   temp=head;
   while(temp->next->data!=data)
   {
       temp=temp->next;
   }
   deletenode=temp->next;
   temp->next=temp->next->next;
   delete deletenode;
}

void checkcircular(node* &head)
{ 
    node * cur=head;
    node *last;
    while(head->next!=NULL)
    {
        head=head->next;
    }
    last=head->next;
    if(cur==last)
    {
        cout<<"circular"<<endl;
        return;
    }
    else
    {
        cout<<"not circular"<<endl;
        return;
    }
}
int main()
{

    node *second=new node();
    node *third=new node();

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;
    cout<<"\nprinting all node"<<endl;
    print(head);


    cout<<"\nprinting in the reverse "<<endl;
    reverseprint(head);

    cout<<"\nadding the node at start "<<endl;
    insertnewhead(head,5);
    print(head);


    cout<<"\nadding at the last position"<<endl;
    addlast(head,40);
    print(head);


    cout<<"\ndelete at first"<<endl;
    deleteatfirst(head);
    print(head);

    cout<<"\ndelete the any member"<<endl;
    deleteatpos(head,40);
    print(head);

    cout <<"\nSearch Middle = "<<get_Middle(head)<<endl;
    // cout <<"\nSearch Middle"<<endl;
    // middleNode(head);
    
    cout<<"\nCheckCircular"<<endl;
    checkcircular(head);
}

