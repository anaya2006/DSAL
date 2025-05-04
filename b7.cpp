#include<iostream>
#include<string.h>
using namespace std;
struct node
{
    char data;
    node *left;
    node *right;
};

class tree
{
    char prefix[50];
    public:
        node *top;
        void expression(char []);
        void display(node *);
        void deletion(node *node);
};

class stack1
{
    public:
        node *data[30];
        int top;
        stack1()
		{
            top=-1;
        }
        int empty()
		{
            if(top==-1)
			{
                return 1;
            }
            return 0;
        }
        void push(node *p)
		{
            data[++top]=p;
        }
        
        node *pop()
		{
        
            return(data[top--]);
        }
};

void tree::expression(char prefix[])
{
    //char c;
    stack1 s;
    node *t1,*t2;
    int len,i;
    len=strlen(prefix); //string.h
    for(i=len-1;i>=0;i--)
	{
        top = new node;
        top->left=NULL;
        top->right=NULL;
        
        if(isalpha(prefix[i]))
		{
            top->data=prefix[i];
            s.push(top);
        }
		else if(prefix[i]=='+'||prefix[i]=='-'||prefix[i]=='*'||prefix[i]=='/')
		{
            t2 = s.pop();
            t1=s.pop();
            top->data=prefix[i];
            top->left = t2;
            top->right=t1;
            s.push(top);
        }
    }
    top = s.pop();
}

void tree::display(node *top)
{
    stack1 s1,s2;
    
    node *T = top;
    s1.push(T);
    while(!s1.empty())
	{
        T = s1.pop();
        s2.push(T);
        
        if(T->left!=NULL)
		{
            s1.push(T->left);
        }
        
        if(T->right!=NULL)
		{
            s1.push(T->right);
        }
    }
    
    while(!s2.empty())
	{
        
        top = s2.pop();
        cout<<top->data;
        
    }
    cout<<endl;
}

void tree::deletion(node *node)
{
    if(node==NULL){
        return;
    }
    deletion(node->left);
    deletion(node->right);
    cout<<"Deleting node: "<<node->data<<endl;
    free(node);
}

int main()
{
    tree t;
    char exp1[20];
    
    int ch;
	bool flag=true;
    while (flag==true)
	{
        cout<<"1 Enter prefix expression"<<endl;
        cout<<"2 Display postfix Expression"<<endl;
        cout<<"3 Deletion"<<endl;
        cout<<"4 Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        
        switch(ch){
        
            case 1:
                cout<<"Enter the expression (eg.: +--a*bc/def):"<<endl;
                cin>>exp1;
                t.expression(exp1);
                break;
            case 2:
                t.display(t.top);
                break;
            case 3:
                t.deletion(t.top);
                break;
            case 4:
                cout<<"YOU HAVE EXITED"<<endl;
				flag=false;
                break;
            default:
                cout<<"Choose a valid option";
                break;
        }
    }
}
/*OUTPUT
C:\Users\HP\Desktop\DSAL>g++ b7.cpp

C:\Users\HP\Desktop\DSAL>a.exe
1 Enter prefix expression
2 Display postfix Expression
3 Deletion
4 Exit
Enter your choice : 1
Enter the expression (eg.: +--a*bc/def):
+--a*bc/def
1 Enter prefix expression
2 Display postfix Expression
3 Deletion
4 Exit
Enter your choice : 2
abc*-de/-f+
1 Enter prefix expression
2 Display postfix Expression
3 Deletion
4 Exit
Enter your choice : 3
Deleting node: a
Deleting node: b
Deleting node: c
Deleting node: *
Deleting node: -
Deleting node: d
Deleting node: e
Deleting node: /
Deleting node: -
Deleting node: f
Deleting node: +
1 Enter prefix expression
2 Display postfix Expression
3 Deletion
4 Exit
Enter your choice : 4
YOU HAVE EXITED

C:\Users\HP\Desktop\DSAL>
*/

