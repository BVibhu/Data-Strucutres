//SINGLY LINKED LIST
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int val;
    node *next;
};
    node* head=(node*) malloc (sizeof(node));
    node* t= (node*) malloc (sizeof(node));

int size;

void display()
{
    cout<<endl<<"Final list: ";
    t=head;
    while(t->next!=NULL)
    {
        cout<<(t->val)<<"\t";
        t=t->next;
    }
    cout<<endl<<endl<<"Size of the list = "<<size;
}
void del()
{
    if(size==0)
        cout<<endl<<"Size is 0. Can't delete further."<<endl;
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
                delete t->next;
                t->next=temp;
                size--;
            }

            else
                cout<<endl<<"The number you are trying to delete is not in the list."<<endl;

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
        temp->next=t->next;
        t->next=temp;
        size++;

    }
    else if(header==true)
    {}

    else
    {
        cout<<endl<<"The number (y) you are trying to use as a reference is not in the list."<<endl;
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


    bool found=false;
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
        temp->next=t->next;
        t->next=temp;
        size++;
    }
    else
    {
        cout<<endl<<"The number (y) you are trying to use as a reference is not in the list."<<endl;
        return;
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


    //This 'if case' checks if the first value is the position where the element is to be inserted.

    bool found=false;
    t=head;

    if(pos==0)
    {
        node* temp=(node*) malloc(sizeof(node));
        temp->val=x;
        temp->next=t;
        head=temp;
        size++;
    }

    else if(pos<0||pos>size)
    {
        cout<<endl<<"The index you are trying to access is not in the list."<<endl;
        return;
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
                t=t->next;

            i++;
        }

        //If the index is found, then value is inserted in this if construct.
        if(found==true)
        {
            node* temp=(node*) malloc (sizeof(node));
            temp->val=x;
            temp->next=t->next;
            t->next=temp;
            size++;
        }

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
    t=head;

    i=1;
    //This loop is making a linked list which is getting VALUES from an ARRAY ar[] and is OUTPUTING them.

    cout<<endl<<"Original list: ";
    while(i<(size+1))
    {
        cout<<(t->val)<<"\t";

        node* p=(node*) malloc(sizeof(node));
        p->val=ar[i];
        p->next= NULL;

        t->next=p;
        t=p;
        i++;

    }

    do
    {
        int choice;
        cout<<endl<<endl<<"-----------------------------------------------------------------------------"<<endl;
        cout<<"1. Deletion "<<endl<<"2. Insertion before a certain value "<<endl<<"3. Insertion after a certain value "<<endl<<"4. Insertion at specified index "<<endl<<"5. Display "<<endl;
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
            display();

        else
            cout<<"Invalid choice."<<endl;


      cout<<endl<<endl<<"Do you want to continue? ";
      cin>>ch;
    }
    while(ch=='y'||ch=='Y');
}
