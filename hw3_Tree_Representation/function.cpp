#include "function.h"
#include <iostream>
#include <stack>
#include <math.h>
#include <queue>
#include <string>


Node* Implement::constructTree(std::string treeStr)
{
    static int i = 1;
    if(treeStr[i] == ')')
    {
        i++;
        return NULL;
    }

    else
    {
        std::string number;
        while (treeStr[i] !='(')
            number.push_back(treeStr[i++]);
        int num = atoi(number.c_str());
        Node *root = new Node(num);
        i++;
        root -> left = constructTree(treeStr);
        i++;
        root -> right = constructTree(treeStr);
        i++;
        return root;
    }
}

void Implement::Inorder_traversal(Node *root)
{
    Node *current = new Node();
    current = root;
    if (current)
    {
        Inorder_traversal(current->left);
        std::cout << current->weight << " ";
        Inorder_traversal(current->right);
    }

}

void Implement::Preorder_traversal(Node *root)
{
    Node *current = new Node();
    current = root;
    if (current)
    {
        std::cout << current->weight << " ";
        Preorder_traversal(current->left);
        Preorder_traversal(current->right);
    }
}

void Implement::Postorder_traversal(Node *root)
{
    Node *current = new Node();
    current = root;
    if (current)
    {
        Postorder_traversal(current->left);
        Postorder_traversal(current->right);
        std::cout << current->weight << " ";
    }
}

void Implement::Levelorder_traversal(Node *root)
{
    Node *current = new Node();
    current = root;
    std::queue<Node *> q;

    //std::cout << "Levelorder_traversal" << std::endl;

    while (current)
    {
        std::cout << current->weight << " ";
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
        if(q.empty())
            return;

        current = q.front();
        q.pop();
    }

}

Node* Implement::deleteTree(Node *root)
{
    root = NULL;
}

int Implement::TreeHeight( Node *root)
{
    Node *current = new Node();
    current = root;



    if (root == NULL)   return 0;

    int height = std::max(TreeHeight(current -> left), TreeHeight(current -> right));

    return height+1;
}

int ans = 0;
int Implement::TreeWeightSum( Node *root)
{
    Node *current = new Node();
    current = root;
    //int ans;
    if (current)
    {
        TreeWeightSum(current->left);
        ans = ans + current -> weight;
        //std::cout << ans << std::endl;
        TreeWeightSum(current->right);
    }

    return ans;
}


int Implement::MaximumPathSum(Node *root)
{
    Node *current = new Node();
    current = root;

    if(!current) return 0;
    int leftsum = MaximumPathSum(current->left);
    int rightsum = MaximumPathSum(current->right);
    //std::cout << std::max(leftsum, rightsum) + current -> weight << std::endl;
    return std::max(leftsum, rightsum) + current -> weight;

}

Node* Implement::Invert(Node *root)
{
    if (root == NULL)
        return root;

    Node *temp = new Node();
    temp = root->left;
    root->left = Invert(root->right);
    root->right = Invert(temp);

    return root;

}
