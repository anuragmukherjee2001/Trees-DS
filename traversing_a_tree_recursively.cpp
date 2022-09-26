#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void preorder(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    v.push_back(root->data);
    preorder(root->left, v);
    preorder(root->right, v);
}

void postorder(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left, v);
    postorder(root->right, v);
    v.push_back(root->data);
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    vector<int> v;

    // inorder(root, v);
    // preorder(root, v);
    postorder(root, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}