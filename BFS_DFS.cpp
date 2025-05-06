/*---------------------------------------------------
Pr no : 06
Title : Represent a given graph using adjacency matrix/list to perform DFS 
and using adjacency list to perform BFS. Use the map of the area around the 
college as the graph. Identify  the prominent land marks as nodes and perform DFS and BFS on that
BFS and DFS->adjus matrix for all case best,av and worst->o(V^2)
BFS and DFS->adjus list for all case best,av and worst->o(V+E)
v=vertex E=edges


-----------------------------------------------------*/

#include<iostream>
using namespace std;
class graph
{
       int a[10][10],vcnt,Rcnt;
       int v[20];
       public:
              graph()
              {
                     Rcnt = 0;
                     vcnt=0;
              }
              void read_adjacency();
              void display_adjacency();
              void BFS();
              void DFS();
              int search(int);
           
};
void graph::read_adjacency()
{
       cout<<"Enter vertex count :";
       cin>>vcnt;
       for(int i=1;i<=vcnt;i++)
       {
              for(int j=1;j<=vcnt;j++)
              {
                     cout<<"Enter edge "<<i<<"to"<<j<<":";
                     cin>>a[i][j];
              }
       }
}
void graph::display_adjacency()
{
       for(int i=1;i<=vcnt;i++)
       {
              for(int j=1;j<=vcnt;j++)
              {
                     cout<<a[i][j]<<"  ";
              }
              cout<<"\n";
       }
}

class Queue
{
       int a[20],f,r;
       public:
       Queue()
       {
              f=0;
              r=0;
       }
       void insert(int key);
       int Delete();
 };

 void Queue::insert(int key)
 {
       if(r!=20)
       {
              a[r++]=key;
       }
       else
       {
              cout<<"Queue is full ";
       }
 }

 int Queue::Delete()
 {
       if(f!=r)
       {
              return (a[f++]);
       }
       else
       {
              cout<<"Queue is Empty ";
       }
}
 
 class stack
 {
       int a[20],top;
       public:
              stack()
              {
               top=-1;
              }
              void push(int key);
              int pop();
};
void stack::push(int key)
{
       if(top!=20)
       {
              a[++top]=key;
       }
       else
       {
              cout<<"Stack is full ";
       }
}
int stack::pop()
{
       if(top!=-1)
       {
              return(a[top--]);
       }
       else
       {
              cout<<"Stack is Empty";
       }
}

int graph::search(int key)
{
       int i;

       for(i = 0; i<Rcnt; i++)
       {
              if(v[i] == key)
              {
                     return(1);
              }
       }
       if(i == Rcnt )
       {
              return(0);
       }
}       



void graph::BFS()
{
       int sv,curr;

       cout<<"Enter starting vertex ";
       cin>>sv;
       v[Rcnt++]=sv;
       
       Queue q;
       q.insert(sv);

       for(int i=1; i<=vcnt; i++)
       {
              curr=q.Delete();

              for(int c=1;c<=vcnt;c++)
              {
                     if(a[curr][c]==1) 
                     {
                  	q.insert(c);
                     	if(search(c)==0)
                     	{	               
                            v[Rcnt++]=c;
                       	}
                     }
              }
       }

       cout<<"BFS=";
       for(int i=0;i<Rcnt;i++)
       {
       		cout<<"   "<<v[i];
       }

}
       

void graph::DFS()
{
       int sv,curr;

       cout<<"Enter starting vertex ";
       cin>>sv;
       v[Rcnt++]=sv;
       
       stack s;
       s.push(sv);

       for(int i=1; i<=vcnt; i++)
       {
              curr=s.pop();

              for(int c=1;c<=vcnt;c++)
              {
                     if(a[curr][c]==1) 
                     {
                  	s.push(c);
                     	if(search(c)==0)
                     	{	               
                            v[Rcnt++]=c;
                       	}
                     }
              }
       }

       cout<<"\nDFS=";
       for(int i=0;i<Rcnt;i++)
       {
       		cout<<"   "<<v[i];
       }
}
       

int main()
{
       int choice,key;
       graph obj;
       Queue q;
       stack s;
       obj.read_adjacency();
       obj.display_adjacency();
       do
       {
	       cout<<"\nMenu\n1.BFS\n2.DFS\n Enter choice ";
	       cin>>choice;
	       switch(choice)
	       {
		      case 1:
		                    obj.BFS();
		       break;                           
		       case 2:
		                    obj.DFS();
		       break;                              
	       }
       }while(choice!=3);
       return 0;
}
