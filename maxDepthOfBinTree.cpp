#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int maxHeight(Node* root){
    if(root == NULL){
        return 0;
    }

    int lh = maxHeight(root->left);
    int rh = maxHeight(root->right);

    return 1 + max(lh, rh);
}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(5);
    root->left->left->left = new Node(55);
    root->left->left->left->left = new Node(56);

    int ans = maxHeight(root);

    cout << ans;

    return 0;
}