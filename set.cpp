/******************************************************************************
Group A-04 (Set Operations)
To create ADT that implement the "set" concept.
a. Add (new Element) -Place a value into the set , 
b. Remove (element) Remove the value
c. Contains (element) Return true if element is in collection, d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection, 
e. Intersection of two sets , 
f. Union of two sets, 
g. Difference between two sets, 
h. Subset
best case->all function o(1)
avg case->add,remove,conatin(element),size->o(n)  intersection,diifernce,subset->o(n*m)  union(n+m)
worst case->same as avg case


*******************************************************************************/

using namespace std;
#include <stdio.h>

#include<iostream>

class set 
{
    int a[20],cnt;
    public:
    set()
    {
        cnt=0;
    }
 
    void add();
    void Display();
    int search(int x);
    void Remove();
    void size();
    void union1(set t1,set t2);
    void intersection(set t1,set t2);
    void difference(set t1,set t2);
    void subset(set t1,set t2);
};

void set::add()
{
    int temp;
    cout<<"\nEnter data : ";
    cin>> temp;
    a[cnt] = temp ;
    cnt++;
    cout<<temp <<" is added successfully in the set";
}

void set::Display()
{
    cout<<"\nSet = ";
    for(int i =0; i<cnt ; i++ )
    {
        cout<<a[i]<<" " ;
    }
}

int set::search(int x)
{
    int i;
    for(i =0; i<cnt ; i++ )
    {
        if(x==a[i])
        return (i);
    }
    if(i==cnt)
    {
        return (-1);
    }
}

void set::Remove()
{
    int temp,x,i;
    
    cout<<"\nEnter data to Remove from the set : ";
    cin>>x;
    temp = search(x);
    if(temp != -1)
    {
        for(i=temp; i<cnt-1 ; i++ )
        {
            a[i]=a[i+1];
        }
        cout<<"Given data is Removed : ";
        cnt--;
    }
    else
    cout<<"Given data is not found ";

}

void set::size()
{
    cout<<"Size of the set is : "<<cnt;
}

void set::union1(set t1,set t2)
{
    int i;
    for(i=0;i<t1.cnt;i++)
    {
        a[cnt++]=t1.a[i];
    }
    
    for(i=0;i<t2.cnt;i++)
    {
        if(t1.search(t2.a[i]) == -1)
        {
            a[cnt++]=t2.a[i];
        }
    }
    
}


void set::intersection(set t1,set t2)
{
    int i;
    
    for(i=0;i<t2.cnt;i++)
    {
        if(t1.search(t2.a[i]) != -1)
        {
            a[cnt++]=t2.a[i];
        }
    }
    
}


void set::difference(set t1,set t2)
{
    int i;
    
    for(i=0;i<t1.cnt;i++)
    {
        if(t2.search(t1.a[i]) == -1)
        {
            a[cnt++]=t1.a[i];
        }
    }
    
}


void set::subset(set t1,set t2)
{
    int i, subsetcnt = 0;
    
    for(i=0;i<t1.cnt;i++)
    {
        if(t2.search(t1.a[i]) != -1)
        {
            subsetcnt++;
        }
    }
    if(subsetcnt == t1.cnt)
    {
        cout<<"\nGiven set S1 is subset of S2";
    }
    else
    {
        cout<<"\nGiven set S1 is NOT subset of S2";
    }
}



int main()
{
    set S1;  
    set S2;
    set S3;
    int ch;
    
    do
    {
        cout<<"\n1. Add the data in set";
        cout<<"\n2. Remove the data from set";
        cout<<"\n3. Display";
        cout<<"\n4. search";
        cout<<"\n5. Remove";
        cout<<"\n6. Size";
        cout<<"\n7. union";
        cout<<"\n8. intersection";   
        cout<<"\n9. difference";  
        cout<<"\n10. Subset";
        cout<<"\n11. Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        
        switch(ch)
        {
            case 1: // Add operation.
                S1.add();
            break;
            case 3: // Display operation.
                S1.Display();
            break;
            case 4: // search operation.
                int temp,x;
                cout<<"\nEnter data to search in the set : ";
                cin>>x;
                temp = S1.search(x);
                if(temp != -1)
                    cout<<"Given data is found at the position : "<<temp;
                else
                    cout<<"Given data is not found ";
            break;            
            case 5: // Remove operation.
                S1.Remove();
            break;
            case 6: // Remove operation.
                S1.size();
            break;
            
            case 7: // union operation.
                int i,c1,c2;
                cout<<"\nSet one count : ";
                cin>>c1;
                
                for(i=0;i<c1;i++)
                {
                    S1.add();
                }
                
              
                cout<<"\nSet two count : ";
                cin>>c2;
                
                for(i=0;i<c2;i++)
                {
                    S2.add();
                }
                
                S1.Display();
                S2.Display();
                
                S3.union1(S1,S2);
                cout<<"\nUnion of two set is : "<<endl;
                S3.Display();
                
            break;
            case 8: // intersection operation.
                
                cout<<"\nSet one count : ";
                cin>>c1;
                
                for(i=0;i<c1;i++)
                {
                    S1.add();
                }
                
              
                cout<<"\nSet two count : ";
                cin>>c2;
                
                for(i=0;i<c2;i++)
                {
                    S2.add();
                }
                
                S1.Display();
                S2.Display();
                
                S3.intersection(S1,S2);
                cout<<"\n Intersection of two set is : "<<endl;
                S3.Display();
                
            break;            

            case 9: // intersection operation.
                
                cout<<"\nSet one count : ";
                cin>>c1;
                
                for(i=0;i<c1;i++)
                {
                    S1.add();
                }
                
              
                cout<<"\nSet two count : ";
                cin>>c2;
                
                for(i=0;i<c2;i++)
                {
                    S2.add();
                }
                
                S1.Display();
                S2.Display();
                
                S3.difference(S1,S2);
                cout<<"\n Difference of two set is : "<<endl;
                S3.Display();
                
            break;            

            case 10: // subset operation.
                
                cout<<"\nSet one count : ";
                cin>>c1;
                
                for(i=0;i<c1;i++)
                {
                    S1.add();
                }
                
              
                cout<<"\nSet two count : ";
                cin>>c2;
                
                for(i=0;i<c2;i++)
                {
                    S2.add();
                }
                
                S1.Display();
                S2.Display();
                
                S3.subset(S1,S2);
               
            break;            
            
            default:
                cout<<"\nWrong choice";
            break;
          
          
          
        }
        
    }while (ch != 11);
    
    
    return 0;
}


