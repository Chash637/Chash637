#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to check if two trees are identical
int areIdentical(struct Node* root1, struct Node* root2) {
    // If both are NULL, they are identical
    if (root1 == NULL && root2 == NULL)
        return 1;

    // If one is NULL and the other is not, they are not identical
    if (root1 == NULL || root2 == NULL)
        return 0;

    // Check if the data matches and recursively check the left and right subtrees
    return (root1->data == root2->data) && 
           areIdentical(root1->left, root2->left) && 
           areIdentical(root1->right, root2->right);
}

// Function to check if tree T2 is a subtree of tree T1
int isSubtree(struct Node* T1, struct Node* T2) {
    // If T2 is NULL, it is always a subtree
    if (T2 == NULL)
        return 1;

    // If T1 is NULL, T2 can't be a subtree
    if (T1 == NULL)
        return 0;

    // Check if the current node in T1 matches the root of T2
    if (areIdentical(T1, T2))
        return 1;

    // Recursively check the left and right subtrees of T1
    return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

// Driver function to test the code
int main() {
    // Create the main tree (T1)
    struct Node* T1 = newNode(1);
    T1->left = newNode(2);
    T1->right = newNode(3);
    T1->left->left = newNode(4);
    T1->left->right = newNode(5);
    T1->right->left = newNode(6);
    T1->right->right = newNode(7);

    // Create the subtree (T2)
    struct Node* T2 = newNode(2);
    T2->left = newNode(4);
    T2->right = newNode(5);

    // Check if T2 is a subtree of T1
    if (isSubtree(T1, T2))
        printf("T2 is a subtree of T1.\n");
    else
        printf("T2 is NOT a subtree of T1.\n");

    return 0;
}
