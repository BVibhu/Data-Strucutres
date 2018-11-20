#include<iostream>
using namespace std;
struct node
{
    int value;
    node* next;
    node* prev;
};

node* front;
node* rear;

bool last_del=false, first_del=false;

void display()
{
    node* t=new node;
    t=(front);

    if(t==NULL)
    {
        cout<<"Queue is empty. "<<endl;
        return;
    }

    cout<<endl<<"Final list: ";

    while(t!=NULL)
    {
        cout<<(t->value)<<"\t";
        t=t->next;
    }
}

void add()
{
    if(front==NULL)
    {
		cout<<"add if."<<endl;
		rear= new node;

        cout<<"Enter value in queue: ";
        cin>>(rear->value);

        rear->next=NULL;
        rear->prev=NULL;
        front=rear;

    }

    else if(front!=NULL)
    {
		cout<<"add else."<<endl;
        node* p= new node;

        if(p==NULL)
        {
            cout<<"Queue full. "<<endl;
            return;
        }
        else
        {
            cout<<"Enter value in queue: ";
            cin>>(p->value);

            p->next=NULL;
            p->prev=rear;
            rear->next=p;
            rear=p;
        }

    }
    display();
}

void add_front()
{
    if(rear==NULL)
    {
        cout<<"add_front if."<<endl;
		front=new node;

        cout<<"Enter value in queue: ";
        cin>>(front->value);

        front->next=NULL;
        front->prev=NULL;
        rear=front;

    }

    else if(rear!=NULL)
    {
        cout<<"add_front else."<<endl;
        node* p= new node;

        if(p==NULL)
        {
            cout<<"Queue full. "<<endl;
            return;
        }
        else
        {
            cout<<"Enter value in queue: ";
            cin>>(p->value);

            p->prev=NULL;
            p->next=front;
            front->prev=p;
            front=p;
        }

    }
    display();
}

int del()
{
	if(last_del==true || front==NULL)
    {
        last_del=false;
        front=NULL;
        rear=NULL;
        return -1;
    }

	if(front->prev==NULL && front->next==NULL)
	{
	    cout<<"delete from if."<<endl;
		int x=front->value;
		delete front;
		last_del=true;
		rear=NULL;
		front=NULL;
		return x;
	}
    else
    {
        cout<<"delete from else."<<endl;
        node* temp=new node;
        int x=front->value;
        temp=front->next;
        delete front;
        front=temp;
        front->prev=NULL;
        return x;
    }
}

int del_rear()
{
    if(first_del==true || rear==NULL)
    {
        first_del=false;
        rear=NULL;
        front=NULL;
        return -1;
    }

	if(rear->prev==NULL && rear->next==NULL)
	{
	    cout<<"delete from if."<<endl;
		int x=rear->value;
		delete rear;
		first_del=true;
		front=NULL;
		rear=NULL;
		return x;
	}
    else
    {
        cout<<"delete from else."<<endl;
        node* temp=new node;
        int x=rear->value;
        temp=rear->prev;
        delete rear;
        rear=temp;
        rear->next=NULL;
        return x;
    }
}

int main()
{
    char ch;

    front=NULL;
    rear=NULL;

    do
    {
        int choice;
        cout<<endl<<endl<<"-----------------------------------------------------------------------------"<<endl;
        cout<<"1. Add "<<endl<<"2. Add @ front "<<endl<<"3. Delete "<<endl<<"4. Delete @ rear "<<endl<<"5. Display "<<endl;
        cout<<endl<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
            add();

        else if(choice==2)
            add_front();

        else if(choice==3)
        {
            int x;
            x=del();

            if(x==-1)
                cout<<"Now, Queue is empty. "<<endl;

            else
                cout<<"Deleted element is "<<x;
        }

        else if(choice==4)
        {
            int x;
            x=del_rear();

            if(x==-1)
                cout<<"Queue is empty. "<<endl;

            else
                cout<<"Deleted element is "<<x;
        }

        else if(choice==5)
            display();

        else
            cout<<"Invalid choice."<<endl;


        cout<<endl<<endl<<"Do you want to continue? ";
        cin>>ch;
    }
    while(ch=='y'||ch=='Y');
}
