/* EXPERIMENT NO. B5 :
A book consists of chapters, chapters consist of sections and sections consist of
subsections. Construct a tree and print the nodes. Find the time and space requirements
of your method.*/
#include <iostream>
#include <string>
using namespace std;
struct node
{
  string label;
  int chcount;
  struct node *child[10];

} *root;
class GenTree
{
   public:
   GenTree()
   {
     root=NULL;
   }
   
   void create()
   { 
     root= new node;
     cout<<"Enter name of the book : "<<endl;
     cin>>root->label;
     cout<<"Enter no of chapters : "<<endl;
     cin>>root->chcount;
     for (int i =0; i<root->chcount; i++)
     {
       root->child[i]=new node;
       cin.ignore();
       cout<<"Enter name of chapter no. "<<i+1<<" : "<<endl;
       cin>>root->child[i]->label;
       cout<<"Enter no of sections in  chapter no. "<<i+1<<" : "<<endl;
       cin>>root->child[i]->chcount;
       for (int j=0; j<root->child[i]->chcount; j++)
       {
          root->child[i]->child[j]=new node;
          cout<<"Enter name of section no. "<<i+1<<" "<<j+1<<" : "<<endl;
          cin>>root->child[i]->child[j]->label;
          cout<<"Enter no of subsections in  section no. "<<i+1<<" "<<j+1<<" : "<<endl;
          cin>>root->child[i]->child[j]->chcount;
          for (int k=0; k<root->child[i]->child[j]->chcount; k++)
          {
             root->child[i]->child[j]->child[k] = new node;
             cout<<"Enter name of subsection no. "<<i+1<<" "<<j+1<<" "<<k+1<<" : "<<endl;
             cin>>root->child[i]->child[j]->child[k]->label;
          }
       }    
     }
    }
    
    void display(node* r)
    {  
       cout<<"NAME OF THE BOOK IS : "<<root->label<<endl;
       cout<<"NO OF CHAPTERS IS : "<<root->chcount<<endl;
       for(int i=0; i<root->chcount; i++)
       {
         cout<<"\tNAME OF CHAPTER NO. "<<i+1<<" IS : "<<root->child[i]->label<<endl;
         cout<<"\tNO. OF SUBSECTIONS OF CHAPTER NO. "<<i+1<<" IS : "<<root->child[i]->chcount<<endl;
         for (int j=0; j<root->child[i]->chcount; j++)
         {
            cout<<"\t\tNAME OF SECTION NO. "<<i+1<<" "<<j+1<<" IS : "<<root->child[i]->child[j]->label<<endl;
            cout<<"\t\tNO. OF SUBSECTIONS OF SECTION NO. "<<i+1<<" "<<j+1<<" IS : "<<root->child[i]->child[j]->chcount<<endl;
            for (int k=0; k<root->child[i]->child[j]->chcount; k++)
            {
              cout<<"\t\t\tNAME OF SUBSECTION NO. "<<i+1<<" "<<j+1<<" "<<k+1<<" IS : "<<root->child[i]->child[j]->child[k]->label<<endl;
            
            }
         }
       }
    }
};
int main()
{ 
  GenTree t;
  int ch;
  bool flag=true;
  while(flag==true)
  {
     cout<<"MENU: "<<endl;
     cout<<"1. CREATE TREE"<<endl;
     cout<<"2. DISPLAY TREE \n3.EXIT"<<endl;
     cout<<"Enter your choice : "<<endl;
     cin>>ch;
     switch (ch)
     {
       case 1:
       t.create();
       break;
       
       case 2:
       t.display(root);
       break;
       
       case 3:
       cout<<"YOU HAVE EXITED "<<endl;
       flag=false;
       break;
       
       default:
       cout<<"Enter a valid option "<<endl;
       break;
     }
  }
  return 0;
}

/*  OUTPUT 

(base) admin1@Your:~$ g++ b5.cpp
(base) admin1@Your:~$ ./a.out
MENU: 
1. CREATE TREE
2. DISPLAY TREE 
3.EXIT
Enter your choice : 
1
Enter name of the book : 
BOOK
Enter no of chapters : 
2
Enter name of chapter no. 1 : 
CH1
Enter no of sections in  chapter no. 1 : 
2
Enter name of section no. 1 1 : 
SEC1.1
Enter no of subsections in  section no. 1 1 : 
2
Enter name of subsection no. 1 1 1 : 
SU1.1.1
Enter name of subsection no. 1 1 2 : 
SU1.1.2
Enter name of section no. 1 2 : 
SEC1.2
Enter no of subsections in  section no. 1 2 : 
2
Enter name of subsection no. 1 2 1 : 
SU1.2.1
Enter name of subsection no. 1 2 2 : 
SU1.2.2
Enter name of chapter no. 2 : 
CH2
Enter no of sections in  chapter no. 2 : 
2
Enter name of section no. 2 1 : 
SEC2.1
Enter no of subsections in  section no. 2 1 : 
2
Enter name of subsection no. 2 1 1 : 
SU2.1.1
Enter name of subsection no. 2 1 2 : 
SU2.1.2
Enter name of section no. 2 2 : 
SEC2.2
Enter no of subsections in  section no. 2 2 : 
2
Enter name of subsection no. 2 2 1 : 
SU2.2.1
Enter name of subsection no. 2 2 2 : 
SU2.2.2
MENU: 
1. CREATE TREE
2. DISPLAY TREE 
3.EXIT
Enter your choice : 
2
NAME OF THE BOOK IS : BOOK
NO OF CHAPTERS IS : 2
	NAME OF CHAPTER NO. 1 IS : CH1
	NO. OF SUBSECTIONS OF CHAPTER NO. 1 IS : 2
		NAME OF SECTION NO. 1 1 IS : SEC1.1
		NO. OF SUBSECTIONS OF SECTION NO. 1 1 IS : 2
			NAME OF SUBSECTION NO. 1 1 1 IS : SU1.1.1
			NAME OF SUBSECTION NO. 1 1 2 IS : SU1.1.2
		NAME OF SECTION NO. 1 2 IS : SEC1.2
		NO. OF SUBSECTIONS OF SECTION NO. 1 2 IS : 2
			NAME OF SUBSECTION NO. 1 2 1 IS : SU1.2.1
			NAME OF SUBSECTION NO. 1 2 2 IS : SU1.2.2
	NAME OF CHAPTER NO. 2 IS : CH2
	NO. OF SUBSECTIONS OF CHAPTER NO. 2 IS : 2
		NAME OF SECTION NO. 2 1 IS : SEC2.1
		NO. OF SUBSECTIONS OF SECTION NO. 2 1 IS : 2
			NAME OF SUBSECTION NO. 2 1 1 IS : SU2.1.1
			NAME OF SUBSECTION NO. 2 1 2 IS : SU2.1.2
		NAME OF SECTION NO. 2 2 IS : SEC2.2
		NO. OF SUBSECTIONS OF SECTION NO. 2 2 IS : 2
			NAME OF SUBSECTION NO. 2 2 1 IS : SU2.2.1
			NAME OF SUBSECTION NO. 2 2 2 IS : SU2.2.2
MENU: 
1. CREATE TREE
2. DISPLAY TREE 
3.EXIT
Enter your choice : 
4
Enter a valid option 
MENU: 
1. CREATE TREE
2. DISPLAY TREE 
3.EXIT
Enter your choice : 
3
YOU HAVE EXITED 
(base) admin1@Your:~$ 
*/
