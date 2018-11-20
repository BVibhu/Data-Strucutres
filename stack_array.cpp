#include<iostream>
using namespace std;
class Stack
{
    int a[100];
    int top;

    public: Stack()
    {
        top=-1;
    }

    bool StackFull()
    {
        if(top==99)
            return true;
        else
            return false;
    }

    bool StackEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
    void display()
    {
        if(!StackEmpty())
        {
            cout<<"Stack is: ";
            for(int i=0;i<=top;i++)
                cout<<a[i]<<"\t";
        }
        else
            cout<<"Stack is empty. "<<endl;

    }
    void push(int x)
    {
        if(!StackFull())
        {
            a[top+1]=x;
            top++;
        }
        else
            cout<<"Stack is full. "<<endl;

    display();
    }

    int pop()
    {
        if(!StackEmpty())
        {
            int x;
            x=a[top];
            top--;
            return x;
        }
        else
            return -1;
    }

};
int main()
{
    Stack s1;

    char ch;

    do
    {
        int choice;
        cout<<endl<<endl<<"-----------------------------------------------------------------------------"<<endl;
        cout<<"1. Push "<<endl<<"2. Pop "<<endl<<"3. Display "<<endl;
        cout<<endl<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
        {
            int x;
            cout<<"Enter number to be pushed: ";
            cin>>x;
            s1.push(x);
        }

        else if(choice==2)
        {
            int x;
            x=s1.pop();

            if(x==-1)
                cout<<"Stack is empty. "<<endl;

            else
                cout<<"Popped out element is "<<x;
        }
        else if(choice==3)
            s1.display();

        else
            cout<<"Invalid choice."<<endl;


      cout<<endl<<endl<<"Do you want to continue? ";
      cin>>ch;
    }
    while(ch=='y'||ch=='Y');
}
