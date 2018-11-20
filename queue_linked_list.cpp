#include<iostream>
using namespace std;
struct node
{
    int value;
    node* next;
};

node* front= new node;
node* rear= new node;

void display()
{
    node* t=new node;
    t=(front);

    if(t->next==NULL)
    {
        cout<<"Queue is empty. "<<endl;
        return;
    }

    cout<<endl<<"Final list: ";

    while(t->next!=NULL)
    {
        cout<<(t->value)<<"\t";
        t=t->next;
    }
}

void add()
{
    if(front->value==NULL)
    {
        cout<<"Enter value in queue: ";
        cin>>(front->value);
        front->next=rear;
    }

    else if(front->value!=NULL)
    {
        node* p= new node;
        if(p==NULL)
        {
            cout<<"Queue full. "<<endl;
            return;
        }
        else
        {
            cout<<"Enter value in queue: ";
            cin>>(rear->value);
            rear->next=p;

            p->next=NULL;
            rear=p;
        }

    }
    display();
}

int del()
{
    if(front->next==NULL)
        return -1;

    else
    {
        node* temp;
        int x=front->value;
        temp=front->next;
        delete front;
        front=temp;
        return x;
    }
}

int main()
{
    char ch;

    front->value=NULL;
    rear->next=NULL;

    do
    {
        int choice;
        cout<<endl<<endl<<"-----------------------------------------------------------------------------"<<endl;
        cout<<"1. Add "<<endl<<"2. Delete "<<endl<<"3. Display "<<endl;
        cout<<endl<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
            add();

        else if(choice==2)
        {
            int x;
            x=del();

            if(x==-1)
                cout<<"Queue is empty. "<<endl;

            else
                cout<<"Deleted element is "<<x;
        }

        else if(choice==3)
            display();

        else
            cout<<"Invalid choice."<<endl;


        cout<<endl<<endl<<"Do you want to continue? ";
        cin>>ch;
    }
    while(ch=='y'||ch=='Y');
}
