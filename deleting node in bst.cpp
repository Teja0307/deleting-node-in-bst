#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *left,*right;
}*root;

void createBST(int n){
    int data,i;
    struct node *temp,*newnode;
    root=(struct node *)malloc(sizeof(struct node));
    cin>>data;
    root->data=data;
    root->left=root->right=NULL;
    for(i=2;i<=n;i++)
    {
        temp=root;
        newnode=(struct node *)malloc(sizeof(struct node));
        cin>>data;
        newnode->data=data;
        newnode->left=newnode->right=NULL;
        while(temp!=NULL)
        {
            if(newnode->data==temp->data)
              cout<<"value already exists";
            else if((newnode->data<temp->data) && (temp->left==NULL))
            {
                temp->left=newnode;
                break;
            }
            else if(newnode->data<temp->data)
              temp=temp->left;
            else if((newnode->data>temp->data) && (temp->right==NULL))
            {
                temp->right=newnode;
                break;
            }
            else
              temp=temp->right;
        }
    }
}

void inorder(struct node *r){
    if(r!=NULL)
    {
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }
}

struct node *minvalue(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}


struct node *deletenode(struct node *r,int value){
    if(r==NULL)
      return r;
    else if(value<r->data)
    {
        r->left=deletenode(r->left,value);
    }
    else if(value>r->data)
    {
        r->right=deletenode(r->right,value);
    }
    else
    {
        if(r->left==NULL)
        {
            struct node *temp=r->right;
            free(r);
            return temp;
        }
        else if(r->right==NULL)
        {
            struct node *temp=r->left;
            free(r);
            return temp;
        }
      else {
        struct node * temp = minvalue(r -> right);
        r -> data = temp -> data;
        r -> right = deletenode(r -> right, temp -> data);
      }
    }
    return r;
}

int main()
{
    int n;
    cin>>n;
    createBST(n);
    inorder(root);
    int value;
    cout<<"\nEnter the value to be deleted:";
    cin>>value;
    root=deletenode(root,value);
    inorder(root);
}