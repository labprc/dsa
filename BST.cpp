/****************************************************************
Group B1 (Binary Search Tree)
Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree -
i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data value found in the tree, iv. Change a tree so that the roles of the left and right pointers
are swapped at every node, v. Search a value
worst time case->o(n)
avg time->o(log n)



****************************************************************/

using namespace std;
#include<iostream>

class node  // Node declaration for BST.
{
    public:
    int data;
    node * left;
    node * right;
};

class BST
{
    public:
    node * root;
    int cnt;
    
    BST()
    {
        root = NULL;
        cnt=0;
    }
    
    void insert();
    void inorder(node *temp);
    void smallest();
    void largest();
    int search(int key);
    void Mirror(node *r);
    int height(node *r);      
};

int BST::height(node *r)
{
    int Left_Height,Right_Height;
    if(r == NULL)
        return(0);
    
    if(r->left == NULL && r->right == NULL)
        return(0);
        
    Left_Height = height(r->left);
    Right_Height = height(r->right);
    
    if(Left_Height > Right_Height)
        return(Left_Height +1);
    else
        return(Right_Height +1);    
}

void BST::Mirror(node *r)
{
    node *temp;
    if(r != NULL)
    {
        temp = r->left;
        r->left = r->right;
        r->right = temp;
        
        Mirror(r->left);
        Mirror(r->right);
    }
}

int BST :: search(int key)
{
    node *temp;
    temp = root;
    
    while(1)
    {
        if(key < temp->data)
        {
            if(temp->left !=NULL)
            {
                temp=temp->left;
            }
            else
            {
                return(0);
            }
        }
        else if(key > temp->data)
        {
            if(temp->right != NULL)
            {
                temp=temp->right;
            }
            else
            {
                return(0);
            }
        }
        else
        {
            return(1);
        }
    }
}

void BST :: smallest()
{
    node *temp;
    temp = root;
    while(temp ->left !=NULL)
    {
        temp = temp ->left;
    }
    
    cout<<"\nSmallest node in the tree is : "<<temp->data;    
}

void BST :: largest()
{
    node *temp;
    temp = root;
    while(temp ->right !=NULL)
    {
        temp = temp ->right;
    }
    
    cout<<"\nSmallest node in the tree is : "<<temp->data;
}


void BST::insert()
{
    node *new_node, *temp;
    int flag=0;
    
    new_node = new node();  // allocate the memory.
    new_node->left = NULL;
    new_node->right = NULL;
    cout<<"Entre data : ";
    cin>>new_node->data;
    if(root == NULL)
    {
        root = new_node;
    }
    else
    {
        temp = root;
        
        while(flag ==0)
        {
            if(new_node->data < temp->data)
            {
                if(temp->left==NULL)
                {
                    temp->left = new_node;
                    flag=1;
                }
                else
                {
                    temp= temp->left;
                }
            }
            else if(new_node->data > temp->data)
            {
                if(temp->right == NULL)
                {
                    temp->right = new_node;
                    flag =1;
                }
                else
                {
                    temp = temp -> right;
                }
            }
            else
            {
                cout<<"\nData is already exist in the Tree";
                flag++;
            }
        }
    }
}


void BST:: inorder(node * temp)
{
    if(temp != NULL)  
    {
        inorder(temp->left);
        cout<<" "<<temp->data;
        cnt++;
        inorder(temp->right);
        
    }
}

int main()
{
    int ch;
    BST B;
    node *test;
    node test2;
    test = new node();
    
    do{
        cout<<"\n Menu";
        cout<<"\n1. Insert";
        cout<<"\n2. Inorder";
        cout<<"\n3. smallest number";
        cout<<"\n4. Largest number";  
        cout<<"\n5. Search";  
        cout<<"\n6. Mirror";
        cout<<"\n7. Height of the tree";
        cout<<"\n8. Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1 :  //Insert operation.
                B.insert();
            break;
            case 2 :  //Inorder display.
                B.inorder(B.root);
                cout<<"\nCnt = "<<B.cnt;
            break;
            case 3 :  //smallest number in BST.
                B.smallest();
            break;
            case 4 :  //largest number in BST.
                B.largest();
            break;            
            case 5 :  //Search a number in BST.
                int key;
                cout<<"Enter number to Search : ";
                cin>>key;
                if(B.search(key))
                {
                    cout<<"number is found";
                }
                else
                {
                    cout<<"number is not found";
                }
            break;            
            case 6 :  //Mirror image of BST.
                B.Mirror(B.root);
            break;            
            case 7 :  //Height of the BST.
                cout<<"Height of the BSt is " <<B.height(B.root);
            break;            
            default :
                cout<<"\nEnter correct choice ";
            break;
        }
    }while(ch !=8);
    return(1);
}











