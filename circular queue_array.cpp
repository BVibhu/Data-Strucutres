#include<iostream>
using namespace std;
class Queue
{
    int a[5];
    int front, rear, size;

    public: Queue()
    {
        front=0;
        rear=0;
        size=0;
    }

    bool QueueFull()
    {
        if(size==5)
            return true;
        else
            return false;
    }

    bool QueueEmpty()
    {
        if(size==0)
            return true;
        else
            return false;
    }
    void display()
    {
        if(!QueueEmpty())
        {
            cout<<"Queue is: ";
            if(front<rear)
                for(int i=front;i<rear;i++)
                    cout<<a[i]<<"\t";

            else
            {
                int gap=5;
                gap=gap-size;

                for(int i=0;i<rear;i++)
                    cout<<a[i]<<"\t";

                for(int i=(rear+gap);i<5;i++)
                    cout<<a[i]<<"\t";


            }
        }

        else
            cout<<"Queue is empty. "<<endl;

    }
    void add(int x)
    {
        if(!QueueFull())
        {
            a[rear]=x;
            rear=((rear+1)%5);
            size++;
            cout<<"size: "<<size<<endl;
        }
        else
        {
            cout<<"Queue is full. "<<endl;
            return;
        }
    display();
    }

    int del()
    {
        if(!QueueEmpty())
        {
            int x;
            x=a[front];
            front=((front+1)%5);

            size--;
            cout<<"size: "<<size<<endl;
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
        cout<<"1. Add "<<endl<<"2. Delete "<<endl;
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

        else
            cout<<"Invalid choice."<<endl;


      cout<<endl<<endl<<"Do you want to continue? ";
      cin>>ch;
    }
    while(ch=='y'||ch=='Y');
}
