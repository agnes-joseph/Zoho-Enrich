//
//  hex.c
//  
//
//  Created by R.M.D. Engineering College  on 12/03/16.
//
//

#include <stdio.h>


#include<stdio.h>

struct Node
{
    int value;
    struct Node* left,*right;
};

struct Node* newNode(int x)
{
    struct Node* node = (struct Node *)malloc(sizeof(struct Node));
    node->value = x;
    node->left = NULL;
    node->right=NULL;
    return node;
}

int isLeaf(struct Node* head)
{
    if(head!=NULL && head->left == NULL && head->right == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int leftSum(struct Node* head)
{
    int sum=0;
    if(head == NULL)
    {
        return 0;
    }
    if(isLeaf(head->left))
    {
        sum = head->left->value;
    }
    return sum + leftSum(head->left)+ leftSum(head->right);
}

int main()
{
    struct Node *root=NULL;
    root = newNode(10);
    root->left = newNode(1);
    root->right = newNode(10);
    
    root->left->right = newNode(4);
    root->left->left = newNode(3);
    
    root->right->left = newNode(15);
    printf("The sum is %d",leftSum(root));
    
}
