#include<iostream>
using namespace std;
class Queue
{
    int a[100];
    int front, rear;

    public: Queue()
    {
        front=0;
        rear=0;
    }

    bool QueueFull()
    {
        if(rear==99)
            return true;
        else
            return false;
    }

    bool QueueEmpty()
    {
        if((rear-front)==0)
            return true;
        else
            return false;
    }
    void display()
    {
        if(!QueueEmpty())
        {
            cout<<"Queue is: ";
            for(int i=front;i<rear;i++)
                cout<<a[i]<<"\t";
        }
        else
            cout<<"Queue is empty. "<<endl;

    }
    void add(int x)
    {
        if(!QueueFull())
        {
            a[rear]=x;
            rear++;
        }
        else
            cout<<"Queue is full. "<<endl;

    display();
    }

    int del()
    {
        if(!QueueEmpty())
        {
            int x;
            x=a[front++];
            //front++;
            return x;
        }
        else
            return -1;

    display();
    }

};
int main()
{
    Queue q1;

    char ch;

    do
    {
        int choice;
        cout<<endl<<endl<<"-----------------------------------------------------------------------------"<<endl;
        cout<<"1. Add "<<endl<<"2. Delete "<<endl<<"3. Display "<<endl;
        cout<<endl<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
        {
            int x;
            cout<<"Enter number to be added: ";
            cin>>x;
            q1.add(x);
        }

        else if(choice==2)
        {
            int x;
            x=q1.del();

            if(x==-1)
                cout<<"Queue is empty. "<<endl;

            else
                cout<<"Removed element is "<<x;
        }
        else if(choice==3)
            q1.display();

        else
            cout<<"Invalid choice."<<endl;


      cout<<endl<<endl<<"Do you want to continue? ";
      cin>>ch;
    }
    while(ch=='y'||ch=='Y');
}
