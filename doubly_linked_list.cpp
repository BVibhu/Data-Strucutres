//DOUBLY LINKED LIST
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int val;
    node *next;
    node *prev;
};
    node* head=(node*) malloc (sizeof(node));
    node* tail=(node*) malloc (sizeof(node));
    node* t= (node*) malloc (sizeof(node));

int size;

void display()
{
    cout<<endl<<"Final List(from head): ";
    t=head;
    int i=0;
    while(t!=NULL)
    {
        cout<<(t->val)<<"\t";
        t=t->next;
        i++;
    }

    cout<<endl<<"Final list(from tail): ";
    t=tail;
    i=0;
    while(t!=NULL)
    {
        cout<<(t->val)<<"\t";
        t=t->prev;
        i++;
    }
    cout<<endl<<endl<<"Size of the list = "<<size;
}

void del()
{
    if(size==0)
    {
        cout<<endl<<"Size is 0. Can't delete further."<<endl;
        return;
    }

    else
    {
        int x;
        cout<<endl<<endl<<"Enter element to be deleted (x): ";
        cin>>x;

        bool found=false;
        t=head;

        //This 'if case' checks if the first value is the one to be deleted.
        if(t->val==x)
        {
            head=t->next;
            head->prev=NULL;
            delete t;
            size--;
        }

        //This 'if case' checks if the last value is the one to be deleted.
        else if(tail->val==x)
        {
            t=tail;
            tail=t->prev;
            tail->next=NULL;
            delete t;
            size--;
        }

        else
        {
            //This loop searches for the value to be deleted.
            while((t->next!=NULL)&&(!found))
            {
                if(t->next->val==x)
                    found=true;

                else
                    t=t->next;
            }

            //If the value is found, then it is deleted in this if construct.
            if(found==true)
            {
                node* temp=(node*) malloc(sizeof(node));
                temp=t->next->next;
                temp->prev=t->next->prev;
                delete t->next;
                t->next=temp;
                size--;
            }

            else
            {
                cout<<endl<<"The number you are trying to delete is not in the list."<<endl;
                return;
            }

        }

    display();
    }
}

void ins_before()
{
    int x,y;
    cout<<endl<<endl<<"Enter element to be inserted (x): ";
    cin>>x;
    cout<<"Enter element before which you want the element x to be inserted (y): ";
    cin>>y;


    //This 'if case' checks if the first value is the position before which the element is to be inserted.

    bool found=false,header=false;
    t=head;

    if(head->val==y)
    {
        node* temp=(node*) malloc(sizeof(node));
        temp->val=x;
        temp->next=t;
        t->prev=temp;
        temp->prev=NULL;
        head=temp;
        header=true;    //header is a flag variable which is being used to indicate if the reference value is the first value in the list.
        size++;
    }

    //This loop searches the reference value.
    while((t->next!=NULL)&&(!found))
    {

        if(t->next->val==y)
            found=true;

        else
            t=t->next;
    }

    //If the value is found, then it is inserted in this if construct.
    if(found==true)
    {
        node* temp=(node*) malloc(sizeof(node));
        temp->val=x;
        t->next->prev=temp;
        temp->next=t->next;

        t->next=temp;
        temp->prev=t;
        size++;

    }
    else if(header==true)
    {}

    else
    {
        cout<<endl<<"The value (y) you are trying to use as a reference is not in the list."<<endl;
        return;
    }

display();
}

void ins_after()
{
    int x,y;
    cout<<endl<<endl<<"Enter element to be inserted (x): ";
    cin>>x;
    cout<<"Enter element after which you want the element x to be inserted (y): ";
    cin>>y;

    //This 'if case' checks if the last value is the position after which the element is to be inserted.

    bool found=false; bool footer=false;

    if(tail->val==y)
    {
        t=tail;

        node* temp=(node*) malloc(sizeof(node));
        temp->val=x;
        temp->next=NULL;
        t->next=temp;
        temp->prev=t;
        tail=temp;
        footer=true;    //footer is a flag variable which is being used to indicate if the reference value is the first value in the list.
        size++;
    }

    else
    {
        t=head;

        //This loop searches for the reference value.
        while((t->next!=NULL)&&(!found))
        {
            if(t->val==y)
                found=true;

            else
                t=t->next;
        }

        //If the value is found, then it is inserted in this if construct.
        if(found==true)
        {
            node* temp=(node*) malloc (sizeof(node));
            temp->val=x;
            t->next->prev=temp;
            temp->next=t->next;

            t->next=temp;
            temp->prev=t;
            size++;
        }
        else if(footer==true)
        {}
        else
        {
            cout<<endl<<"The value (y) you are trying to use as a reference is not in the list."<<endl;
            return;
        }

    }
display();
}

void ins_index()
{
    int x,pos;
    cout<<endl<<endl<<"Enter element to be inserted (x): ";
    cin>>x;
    cout<<"Enter index at which you want the element x to be inserted (pos): ";
    cin>>pos;




    bool found=false;
    t=head;

    if(pos<0||pos>size)
    {
        cout<<endl<<"The index you are trying to access is not in the list."<<endl;
        return;
    }

    //This 'if case' checks if the 0th index is the position where the element is to be inserted.
    else if(pos==0)
    {
        node* temp=(node*) malloc(sizeof(node));
        temp->val=x;
        temp->prev=NULL;
        temp->next=t;
        t->prev=temp;
        head=temp;
        size++;
    }

    //This 'if case' checks if the last index (that is equal to size) is the position where the element is to be inserted.
    else if(pos==size)
    {
        t=tail;
        node* temp=(node*) malloc (sizeof(node));
        temp->val=x;
        temp->next=NULL;
        temp->prev=t;
        t->next=temp;
        tail=temp;
        size++;
    }

    else
    {
        //This loop searches and inserts the value to be inserted.
        int i=1;
        while((i<size)&&(!found))
        {

            if(pos==i)
                found=true;

            else
                t=t->next;

            i++;
        }

        //If the index is found, then value is inserted in this if construct.
        if(found==true)
        {
            node* temp=(node*) malloc (sizeof(node));
            temp->val=x;
            temp->next=t->next;
            t->next->prev=temp;
            t->next=temp;
            temp->prev=t;
            size++;
        }

    }
display();
}

void ins_index_rev()
{
    int x,pos;
    cout<<endl<<endl<<"Enter element to be inserted (x): ";
    cin>>x;
    cout<<"Enter index at which you want the element x to be inserted (pos): ";
    cin>>pos;


    bool found=false;
    t=tail;

    if(pos<0||pos>size)
    {
        cout<<endl<<"The index you are trying to access is not in the list."<<endl;
        return;
    }

    //This 'if case' checks if the 0th index from the tail is the position where the element is to be inserted.
    else if(pos==0)
    {
        node* temp=(node*) malloc(sizeof(node));
        temp->val=x;
        temp->next=NULL;
        temp->prev=t;
        t->next=temp;
        tail=temp;
        size++;
    }

    //This 'if case' checks if the last index from the tail (that is equal to size) is the position where the element is to be inserted.
    else if(pos==size)
    {
        t=head;
        node* temp=(node*) malloc(sizeof(node));
        temp->val=x;
        temp->prev=NULL;
        temp->next=t;
        t->prev=temp;
        head=temp;
        size++;
    }

    else
    {
        //This loop searches and inserts the value to be inserted.
        int i=1;
        while((i<size+1)&&(!found))
        {

            if(pos==i)
                found=true;

            else
                t=t->prev;

            i++;
        }

        //If the index is found, then value is inserted in this if construct.
        if(found==true)
        {
            node* temp=(node*) malloc (sizeof(node));
            temp->val=x;
            temp->next=t;
            t->prev->next=temp;

            temp->prev=t->prev;
            t->prev=temp;
            size++;
        }

    }
display();
}

void ins_between()
{
    int x,y,z;
    cout<<endl<<endl<<"Enter element to be inserted (x): ";
    cin>>x;
    cout<<"Enter element after which you want the element x to be inserted (y): ";
    cin>>y;
    cout<<"Enter element before which you want the element x to be inserted (z): ";
    cin>>z;

    if((tail->val==y)||(head->val==z))
    {
        cout<<endl<<"You are trying to input before head or after tail which is not possible."<<endl;
        return;
    }
    t=head;
    bool found=false;
        while((t->next!=NULL)&&(!found))
        {
            //This 'if case' checks for value after which the element is to be inserted.
                if(t->val==y)
                {
                    //This 'if case' checks for the value (which should be consecutive) before which the element is to be inserted.
                    if(t->next->val==z)
                        found=true;

                    else
                    {
                        cout<<endl<<"The elements are not consecutive in the correct order. "<<endl;
                        return;
                    }

                }

                else
                    t=t->next;
        }

        if(found==true)
        {
            node* temp= (node*) malloc (sizeof(node));
            temp->val=x;
            temp->prev=t;
            temp->next=t->next;
            t->next->prev=temp;
            t->next=temp;
        }
        else
        {
            cout<<endl<<"The values between which you want the element to be inserted, aren't in the list. "<<endl;
            return;
        }

display();
}

int main()
{
    char ch;

    cout<<"Enter size: ";
    cin>>size;

    int ar[size], i;

    cout<<endl<<"Enter array: ";
    for(i=0;i<size;i++)
        cin>>ar[i];



    head->val=ar[0];
    head->next= NULL;
    head->prev= NULL;

    t=head;

    i=1;

    //This loop is making a linked list which is getting VALUES from an ARRAY ar[].
    while(i<size)
    {

        node* p=(node*) malloc(sizeof(node));
        p->val=ar[i];
        p->next= NULL;

        t->next=p;
        p->prev= t;
        t=p;
        i++;
    }
    tail=t;     //Copying the value of last element of linked list into tail.


    //This loop is OUTPUTING the linked list.
    cout<<endl<<"Original list: ";
    t=head;
    while(t!=NULL)
    {
        cout<<(t->val)<<"\t";
        t=t->next;
    }

    do
    {
        int choice;
        cout<<endl<<endl<<"-----------------------------------------------------------------------------"<<endl;
        cout<<"1. Deletion "<<endl<<"2. Insertion before a certain value "<<endl<<"3. Insertion after a certain value "<<endl<<"4. Insertion at specified index "<<endl<<"5. Insertion at specified index counted from tail "<<endl<<"6. Insertion between two specified values "<<endl<<"7. Display "<<endl;
        cout<<endl<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
            del();

        else if(choice==2)
            ins_before();

        else if(choice==3)
            ins_after();

        else if(choice==4)
            ins_index();

        else if(choice==5)
            ins_index_rev();

        else if(choice==6)
            ins_between();

        else if(choice==7)
            display();

        else
            cout<<"Invalid choice."<<endl;


      cout<<endl<<endl<<"Do you want to continue? ";
      cin>>ch;
    }
    while(ch=='y'||ch=='Y');
}
