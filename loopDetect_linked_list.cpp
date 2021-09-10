//Using Floyd's Cycle Algo

#include<iostream>

using namespace std;

struct node
{
int data;
struct node *next;
}*head;

void push(node**,int);
int detect_loop(node*);
void print();
int main()
{
head=NULL;

push(&head,2);
push(&head,3);
push(&head,4);
push(&head,5);

head->next->next->next->next=head;

//print();
detect_loop(head);


}

void push(node **head_ref,int value)
{
  node * new_node= new node();
  new_node->data=value;
  new_node->next=(*head_ref);   //For first node " new_node->next=NULL "as initially head_ref=NULL,here link old list to new node
  (*head_ref)=new_node;         //pointing head at new node.

}

int detect_loop(node *head_ref)
{
    node *slow,*fast;

    slow=head_ref;
    fast=head_ref;

    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        {
          cout<<"Loop detected";
          return 0;
        }

    }

            cout<<"Loop not detected";
            return 0;

}

/*void print()
{
    int i;
    node *p=head;

    while(p!=NULL)
    {
        cout<<p->data;
        p=p->next;
    }

}*/
