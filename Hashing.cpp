/******************************************************************************
Group A1 (Hashing)
Title : Consider telephone book database of N clients. Make use of a hash table
implementation to quickly look up client‘s telephone number. Make use of two collision 
handling techniques and compare them using number of comparisons required to find a set 
of telephone numbers    
linear probing and Qudaratic same as follow:
for best: search,insert->o(1)  and display->o(1)  
for worst:search,insert,display-> o(n)
Quadratic probing

**********************************************************************************/
using namespace std;
#include<iostream>
class HashTable
{
	public:
	int index;
    long int mobile;
};

class Hashing
{
	HashTable h[10];
	public:
	Hashing()
	{
	    for(int i=0;i<10;i++)
        {
            h[i].index=i;
            h[i].mobile=-1;
        }
    }

    void display();
    void insert(int);
    void search();
    int LinearProbing(int);
    int QuadraticProbing(long int);

};

int Hashing::QuadraticProbing(long int key)
{
    int a;

    for(int j=0;j<10;j++)
    {
        a=  (key + (j*j))%10;
        if(h[a].mobile==-1)
        {
            return a;
        }
    }
}

int Hashing::LinearProbing(int collision_position)
{
    for(int i=collision_position;i<10;i++)
    {
        if(h[i].mobile==-1)
            return i;

        if(i==9)
            i = -1;
    }
}

void Hashing::display()
{
    for(int i=0;i<10;i++)
    {
        cout<<h[i].index;
        cout<<"  "<<h[i].mobile;
        cout<<endl;
    }
}

void Hashing::insert(int probchoice)
{   
    long int key;
    int position;
    cout<<"\nEnter mobile number to insert in to hash table : ";
    cin>>key;
    position = key % 10;

    cout<<"\nPosition = "<<position;

    if(h[position].mobile==-1)
    {
        h[position].mobile=key;
    }
    else if(probchoice ==1)// Linear Probing collision.
    {
        int temp_position = LinearProbing(position);
        h[temp_position].mobile=key;
    }
    else if(probchoice ==2)// Quadratic Probing for collision.
    {
        int temp_position = QuadraticProbing(key);
        h[temp_position].mobile=key;
    }

}

void Hashing::search()
{   
    long int key;
    int position,i;
    cout<<"\nEnter mobile number to search in the hash table : ";
    cin>>key;
    position = key % 10;
    
    if(h[position].mobile==key)
    {
        cout<<"\nGiven mobile number is found in the hash table ";
    }
    else
    {
        for(i = 0; i<10;i++)
        {
            if(h[i].mobile==key)
            {
                cout<<"\nGiven mobile number is found in the hash table  ";
                break;
            }
        }
        if(i == 10)
        {
            cout<<"\nGiven mobile number is not found in the hash table ";
        }
    }
}


int main()
{
    Hashing H;
    int ch;

    do
    {
        cout<<"\n Menu";
        cout<<"\n 1.insert";
        cout<<"\n 2.display";
        cout<<"\n 3.search";
        cout<<"\n 5. exit";
        cout<<"\n Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1 : //insert
                int probchoice;
                cout<<"\nEnter \n1 for LinearProbing and \n2 for Quadratic probing";
                cin>>probchoice;
                H.insert(probchoice);
            break;
            case 2 : //display
                H.display();
            break;
        
            case 3 : //display
                H.search();
            break;
        
            default:
                cout<<"\nWrong choice :";
            break;
        }
        
    }while(ch != 5);
    H.display();
}

