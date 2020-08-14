#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};


struct node* Insert(int data, struct node* root){
  if(root==NULL){
    root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
  }
  else if(data>root->data){
    root->right = Insert(data, root->right);
  }
  else{
    root->left = Insert(data, root->left);
  }
  return root;
};


int Search(int data, struct node* root){
  if(root==NULL){
    return 0;
  }
  else if(data==root->data){
    return 1;
  }
  else if(data>root->data){
    return Search(data, root->right);
  }
  else{
    return Search(data, root->left);
  }
  
};


int main(){
  struct node* root=NULL;
  root = Insert(2, root);
  root = Insert(4, root);
  root = Insert(1, root);
  root = Insert(5, root);
  root = Insert(15, root);
  root = Insert(10, root);
  root = Insert(0, root);
  
  if(Search(0, root)==1){
    printf("found\n");
  }
  else{
    printf("Not found\n");
  }
  return 0;
}
