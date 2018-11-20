#include<iostream>
using namespace std;

struct stack
{
    int value;
    stack* prev;
};

stack* top,head;

void push(int val)
{
    if(top==NULL)
    {
        top=new stack;
        top->value=val;
        top->prev=NULL;
    }
    if(top!=NULL)
    {
        stack* p= new stack;
        if(p==NULL)
        {
            cout<<"Stack full. "<<endl;
            return;
        }
        else
        {
            p->value=val;
            p->prev=top;
            top=p;
        }

    }
}

int pop()
{
    if(top==NULL)
        return -1;

    else
    {
        stack* temp;
        int x=top->value;
        temp=top->prev;
        delete top;
        top=temp;
        return x;
    }
}

struct node
{
    int val;
    node* left;
    node* right;
};

void inorder(node* r)
{
    node* mid=r;
    bool flag_left=false, flag_right=false;
    while(r!=NULL && !flag_left)
    {
        if(r->right!=NULL)
            push(r->right->val);

        push(r->val);

        if(r->left!=NULL)
            r=r->left;

        else
        {
            while(top!=NULL)
            {
                int x=pop();
                if(x!=-1)
                {
                    cout<<x<<" ";
                    flag_left=true;
                }

                else
                {
                    cout<<"Stack empty."<<endl;
                    flag_left=true;
                }
            }


        }
    }
    r=mid->right;
    while(r!=NULL && !flag_right)
    {
        if(r->right!=NULL)
            push(r->right->val);

        push(r->val);

        if(r->left!=NULL)
            r=r->left;

        else
        {
            while(top!=NULL)
            {
                int x=pop();
                if(x!=-1)
                {
                    cout<<x<<" ";
                    flag_right=true;
                }

                else
                {
                    cout<<"Stack empty."<<endl;
                    flag_right=true;
                }
            }
        }
    }
}

int main()
{
    int size,i;
    cout<<"Enter number of nodes: ";
    cin>>size;

    int* ar= new int[size];

    cout<<"Enter values into the array: ";
    for(i=0;i<size;i++)
        cin>>ar[i];

        node* t= new node;
        t->val= ar[0];
        t->left= NULL;
        t->right= NULL;

        node* mid;
        mid=t;

    i=1;
    while(i<size)
    {
        node* p=new node;
        p->val=ar[i];
        p->left= NULL;
        p->right= NULL;

        t=mid;
        if(p->val <= t->val)
        {
            while(t->left!=NULL && p->val <= t->val)
                t=t->left;

            if(p->val <= t->val)
                t->left=p;
            else
                t->right=p;
        }
        else
        {
            while(t->right!=NULL && p->val >= t->val)
                t=t->right;

            if(p->val <= t->val)
                t->left=p;
            else
                t->right=p;
        }
        i++;
    }

    inorder(mid);

}
