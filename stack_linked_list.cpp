#include<iostream>
using namespace std;

struct node
{
    int value;
    node* prev;
};

node* top,head;

void display()
{
    node* t=new node;
    t=top;

    if(t==NULL)
    {
        cout<<"Stack is empty. "<<endl;
        return;
    }

    cout<<endl<<"Final list: ";
    while(t!=NULL)
    {
        cout<<(t->value)<<"\t";
        t=t->prev;
    }
}

void push()
{
    if(top==NULL)
    {
        top=new node;
        cout<<"Enter value in stack: ";
        cin>>top->value;
        top->prev=NULL;
    }
    else if(top!=NULL)
    {
        node* p= new node;
        if(p==NULL)
        {
            cout<<"Stack full. "<<endl;
            return;
        }
        else
        {
            cout<<"Enter value in stack: ";
            cin>>(p->value);

            p->prev=top;
            top=p;
        }

    }
    display();
}

int pop()
{
    if(top==NULL)
        return -1;

    else
    {
        node* temp;
        int x=top->value;
        temp=top->prev;
        delete top;
        top=temp;
        return x;
    }
}

int main()
{
    char ch;

    do
    {
        int choice;
        cout<<endl<<endl<<"-----------------------------------------------------------------------------"<<endl;
        cout<<"1. Push "<<endl<<"2. Pop "<<endl<<"3. Display "<<endl;
        cout<<endl<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
            push();

        else if(choice==2)
        {
            int x;
            x=pop();

            if(x==-1)
                cout<<"Stack is empty. "<<endl;

            else
                cout<<"Popped out element is "<<x;
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
