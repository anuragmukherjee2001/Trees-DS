#include <bits/stdc++.h>

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

void levelOrder(Node *root, vector<vector<int>> &ans)
{

    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        vector<int> v;

        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *n = q.front();
            q.pop();

            if (n->left != NULL)
            {
                q.push(n->left);
            }
            if (n->right != NULL)
            {
                q.push(n->right);
            }
            v.push_back(n->data);
        }
        ans.push_back(v);
    }
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    vector<vector<int>> ans;

    levelOrder(root, ans);

    for (auto it : ans)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }

    return 0;
}