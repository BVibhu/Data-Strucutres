#include<iostream>
using namespace std;
struct node
{
    int value;
    int priority;
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
        cout<<"Enter value and it's priority (between the range 0-5) in queue: ";
        cin>>(rear->value);
        cin>>(rear->priority);

        if((rear->priority<0)||(rear->priority>5))
        {
            cout<<"Invalid priority."<<endl;
            rear->value=NULL;
            rear->priority=NULL;
            return;
        }

        front->value=rear->value;
        front->priority=rear->priority;
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
            cout<<"Enter value and it's priority (between the range 0-5) in queue: ";
            cin>>(p->value);
            cin>>(p->priority);

            if((p->priority<0)||(p->priority>5))
            {
                cout<<"Invalid priority."<<endl;
                return;
            }


            bool flag=false;
            node* t= new node;
            t->next=front;
            while(t->next->next!=NULL&&(!flag))
            {
                if((p->priority)>(front->priority))
                {
                    p->next=front;
                    front=p;
                    flag=true;
                }

                else if((p->priority)>(t->next->next->priority))
                {
                   p->next=t->next->next;
                   t->next->next=p;
                   flag=true;
                }
                else
                     t=t->next;
            }
            if(flag==false)
            {
                p->next=rear;
                t->next=p;
            }

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
