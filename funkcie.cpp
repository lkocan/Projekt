#include "funkcie.h"
#include <stdio.h>
#include <stdlib.h>

BstNode* createNode(int data) {
    BstNode* newNode = (BstNode*)malloc(sizeof(BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void destroyNode(BstNode** node) {
    if ((*node)->left != NULL) {
        destroyNode(&(*node)->left);
    }

    if ((*node)->right != NULL) {
        destroyNode(&(*node)->right);
    }

    free(*node);
    *node = NULL;
}


void insertNode(BstNode** node, int data) {
    if (*node == NULL) {
        *node = createNode(data);
    }
    else if (data > (*node)->data) {
        insertNode(&(*node)->right, data);
    }
    else {
        insertNode(&(*node)->left, data);
    }
}

void inorder(struct BstNode* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct BstNode* minValueNode(struct BstNode* node)
{
    struct BstNode* current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct BstNode* deleteNode(struct BstNode* root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct BstNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct BstNode* temp = root->left;
            free(root);
            return temp;
        }
        struct BstNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
