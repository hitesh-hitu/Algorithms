#include "../include/splay_tree.hpp"
#include<stdlib.h>

using namespace std;
 class Node{
	public: 		
		int key ;
 		Node *left;
 		Node *right;
 };

class splay_tree_implementation : public splay_tree
{
	private:
		Node *root;
		int no_of_nodes;	
	
 	public:
   		splay_tree_implementation();
		int get_num_nodes(); 
  		int find(int  );
  		void insert(int );
		void remove(int);
		vector<int> post_order();
		vector<int> pre_order();
		~splay_tree_implementation();
};

vector<int> get_pre_order(Node *);
vector<int> get_post_order(Node *);
vector<int> Vec;
Node *splay(Node*, int );
Node *leftRotate(Node*);
Node *rightRotate(Node*);  
Node* create_new_node(int);


splay_tree_implementation::splay_tree_implementation()
{
  root=NULL;
  no_of_nodes=0;
}



Node *create_new_node(int key)
{
 Node* new_node=(Node*)malloc(sizeof(Node));
 new_node->key=key;
 new_node->left=NULL;
 new_node->right=NULL;
 return new_node;
}


Node *rightRotate(Node *k)  
{  
    Node *y = k->left;  
    k->left = y->right;  
    y->right = k;  
    return y;  
}  
  

Node *leftRotate(Node *k)  
{  
    Node *y = k->right;  
    k->right = y->left;  
    y->left = k;  
    return y;  
}

Node *splay(Node *root, int key) 
{ 
	
	if (root == NULL || root->key == key) 
		return root; 

	
	if (root->key > key) 
	{ 
		 
		if (root->left == NULL) return root; 

		
		if (root->left->key > key) 
		{ 
			
			root->left->left = splay(root->left->left, key); 

			
			root = rightRotate(root); 
		} 
		else if (root->left->key < key)  
		{ 
			 
			root->left->right = splay(root->left->right, key); 

			 
			if (root->left->right != NULL) 
				root->left = leftRotate(root->left); 
		} 

		 
		return (root->left == NULL)? root: rightRotate(root); 
	} 
	else  
	{ 
		 
		if (root->right == NULL) return root; 

		 
		if (root->right->key > key) 
		{ 
			
			root->right->left = splay(root->right->left, key); 

			 
			if (root->right->left != NULL) 
				root->right = rightRotate(root->right); 
		} 
		else if (root->right->key < key) 
		{ 
			 
			root->right->right = splay(root->right->right, key); 
			root = leftRotate(root); 
		} 

		
		return (root->right == NULL)? root: leftRotate(root); 
	} 
		 
}
int splay_tree_implementation::get_num_nodes()
{
	return no_of_nodes;


}

void splay_tree_implementation::insert(int key)
{
	
  	if (root == NULL) 
	{      Node *newnode = create_new_node(key);
               root=newnode;
	       no_of_nodes++;
                return;
        }
	
	root=splay(root,key);
	
	if(root->key==key)
        {
            return;
	}
        else
	{
	Node *temp=root;	
	Node *newnode = create_new_node(key);
	int flag=1;
	while(flag)
          {
           if(newnode->key < temp->key)
	      {
               if (temp->left==NULL)
                { 
                 temp->left = newnode;
		 root=splay(root,key);  
                 flag=0;
                }
               else temp=temp->left;
              }
          else
	      { 
              if (temp->right==NULL)
              {  
                 temp->right = newnode;
      
                 root=splay(root,key);
		 flag=0;
              }
             else temp=temp->right;
              }
           }

	}
no_of_nodes++;
}

int splay_tree_implementation::find(int key)
{
   
    Node *temp,*prev;
    temp=root;
  
    while (temp != NULL) { 
	
        if (key > temp->key) 
	{
	    prev=temp;
            temp = temp->right; 
  	}
         
        else if (key < temp->key) 
	{	
	    prev=temp;
            temp = temp->left; 
	}
        else
	{
	    root=splay(root,key);
            return 1;
	}
    } 
    root=splay(root,prev->key); 
    return 0;
}

void splay_tree_implementation::remove(int key)
{
      Node *parent,*temp,*q,*repl;
      q=NULL;
      temp = root;
      parent=NULL;

      while(temp!=NULL && temp->key!=key)
      {
         parent=temp;
         if(key < temp->key)
            temp=temp->left;
         else
            temp=temp->right;
      }
      
      if(temp==NULL)
	{
       		return;
	}

      else if(temp->left==NULL)
	{   
		q=temp->right;
	}          

      else if(temp->right==NULL)
	{
		q=temp->left;
	}
      else
        {
	    	repl=temp->right;
		while(repl->left!=NULL)
			{             		
			repl=repl->left;
			}
		repl->left=temp->left;
	 	q=temp->right;
	}

       

       if(parent==NULL)
        { 
	  //return q;
          root=q;
         }    
       else if(temp==parent->left)
        {
		 parent->left=q;
		
		 //root = splay(parent , parent->data);
		//root = parent ;
		root = splay(root, parent->key);
		//cout<<root->data<<" root\n";
        }
       else 
        {
	
		 parent->right=q;
		 //root = splay(parent , parent->data);
		//root = parent ;
		root = splay(root, parent->key);
		//cout<<root->data<<" root\n";
        }
    free(temp);
    
    //cout<<parent->data<<" parent\n";    
    
    //root=parent;
    //cout<<root->data<<" root \n";
    no_of_nodes--;
 }
 

vector<int> splay_tree_implementation::post_order()
{	Vec.clear();
	 if(root==NULL)
            return vector<int>();
        Vec=get_post_order(root);
       
	return Vec;
}

vector<int> splay_tree_implementation::pre_order()
{	
	Vec.clear();
	if(root==NULL)
            return vector<int>();
        Vec=get_pre_order(root);
	return Vec;
}


vector<int> get_pre_order(Node *root)
{
        if(root==NULL)
            return vector<int>();
	//cout<<root->data;
        Vec.push_back(root->key);
        get_pre_order(root->left);
        get_pre_order(root->right);
	return Vec;
}

vector<int> get_post_order(Node *root)
{
        if(root==NULL)
            return vector<int>();
	//cout<<root->data\n;
	get_post_order(root->left);
        get_post_order(root->right);
        Vec.push_back(root->key);
        return Vec;
}


splay_tree_implementation::~splay_tree_implementation()
{ 
  no_of_nodes=0;
  root=NULL;
  free(root);
}


