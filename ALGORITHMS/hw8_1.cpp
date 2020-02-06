/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw8/challenges/binary-tree-4/submissions/code/1317352546
 * Title: hw8_1.cpp
 * Abstract: This program will build a binary search tree and preform functions on it with given user input; 
 * Author: Kyle Dilbeck
 * ID: 4444
 * Date: 10/31/19
 * Version: 3.6 
 */
#include <iostream>
#include<string>
#include <queue> 

using namespace std;

struct Node 
{
	// Data part for a node. 
    int data;
    Node* left;
    Node* right;

    // Constructor for a new node.
    Node(int d) 
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};


Node* mkTree(int data, Node* left, Node* right) 
{
    Node* root = new Node(data);
    root->left = left;
    root->right = right;
    return root;
}


void inorder(Node* root) 
{
    if (root != nullptr)  // Or simply "if (root)"
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
//--------------------------------------------------
Node* append(Node* root, int data)
{
    if(root == nullptr)
    {
        return new Node(data);
    }
    queue<Node*> appendQ;
    appendQ.push(root);
    while(!appendQ.empty())
    {
        Node* tempNode = appendQ.front();
        appendQ.pop();

        if(tempNode->left == nullptr)
        {
            tempNode->left = new Node(data);
            break;
        } 
        else
        {
            appendQ.push(tempNode->left);
        }

        if(tempNode->right == nullptr)
        {
            tempNode->right = new Node(data);
            break;
        } 
        else
        {
            appendQ.push(tempNode->right);
        }
    }

    return root;
}
bool function(Node * root , vector<int> &myVector)
{
    if (root != nullptr)  // Or simply "if (root)"
    {
        function(root->left, myVector);
        myVector.push_back(root->data); 
        //cout << "debug pushing:" << root->data<< endl; 
        function(root->right, myVector);
    }
    

return true; 
}

bool isBst(Node * node )
{
    vector<int> vect; 
    function(node, vect);
    for(int i = 0 ; i < (vect.size()-1); i++)
    {
        if(vect[i] > vect[i+1])
        {
            return false; 
        }  
    }
        
    return true; 
    //check if BST :::
    // if(node == nullptr)
    // {
    //     return true;
    // }

    // if((node->left != nullptr && node->left->data > node->data) ||
    // (node->right != nullptr && node->right->data < node->data))
    // {
    //     return false;
    // }

    // if(!isBst(node->left) || !isBst(node->right))
    // {
    //     return false;
    // }
    // return true;
}//end isBST; 
void postOrder(Node * root)
{
    if (root != nullptr)  // Or simply "if (root)"
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}
void preOrder(Node* root)
{
    if (root != nullptr)  // Or simply "if (root)"
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int height(Node * node)
{
    if (node == nullptr)  
    {
        // cout << "test"; 
        return 0; 
    } 

    int lDepth = 1 + height(node->left);  
    int rDepth = 1 + height(node->right);  
    if (lDepth > rDepth)  
        return lDepth;  

    return rDepth;   
}

void print(Node * root)
{
    //cout << "tester"<< endl; 
    inorder(root); 
}
void readMe()
{
    int size , commands, fill; 
    Node* root = nullptr;
    cin >> size; 
    for(int i  = 0 ; i < size; i ++ )
    {
        cin >> fill;
        root = append(root, fill);
    }
    cin >> commands;
    for(int i = 0; i < commands; i++)
    {
        string input; 
        cin >> input;
        if(input == "isBST")
        {
            if(isBst(root))
            {
                cout << "true" << endl;
            }
            else
            {
                cout <<"false" << endl;
            }
        }
        if(input == "height")
        {
            //cout << endl; 
            cout << height(root)-1;  
            cout << endl;
        }
        if(input == "preOrder")
        {
            preOrder(root); 
            cout << endl;
        }
        if(input == "append")
        {
            int fill = 0;
            cin >> fill;
            root = append(root, fill); 
        }
        if(input == "postOrder")
        {
            //cout << endl; 
            postOrder(root);
            cout << endl;
        }
        if(input == "inOrder")
        {
            //cout << endl; 
            inorder(root);
            cout << endl;
        }
        //print(root); 
    }
}

// A sample main to create a binary tree like below.
//       5
//      / \
//     3   4
//    / \
//   1   2
//
int main() 
{
    readMe();
    
    return 0;
}
/* SAMPLE RUNS & OUTPUT
3
20 5 25
4
isBST
inOrder
append 45
isBST

This is the correct output. 

true
5 20 25
false

*/


