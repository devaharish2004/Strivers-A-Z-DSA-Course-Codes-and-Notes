#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
BinaryTreeNode<int>* MarkParents(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>* > &parents, int start) {
    queue<BinaryTreeNode<int>* > q;
    q.push(root);
    BinaryTreeNode<int>* startNode;
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            BinaryTreeNode<int> * node = q.front();
            q.pop();
            if(node->data == start) {
                startNode = node;
            }
            if(node->left) {
                q.push(node->left);
                parents[node->left] = node;
            }
            if(node->right) {
                q.push(node->right);
                parents[node->right] = node;
            }
        }
    }

    return startNode;
}


int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>* > parents;
    //getting the start node pointer while traversing to find the parents
    BinaryTreeNode<int>* startNode = MarkParents(root, parents, start);
    //bfs
    queue<BinaryTreeNode<int>* > q;
    unordered_map<BinaryTreeNode<int>*, bool> visited;
    //since we are given the integer and not the treeNode, we have to find it using any traversal
    q.push(startNode);
    visited[startNode] = true;
    int levels = 0;
    while(!q.empty()) {
        int size = q.size();
        //int flag = 0;
        for(int i= 0; i < size; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            if(node->left && visited[node->left] == false) {
                //flag = 1;
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && visited[node->right] == false) {
                //flag = 1;
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parents[node] && visited[parents[node]] == false) {
                //flag = 1;
                q.push(parents[node]);
                visited[parents[node]] = true;
            }
        }
        // if(flag){
        //     levels++;
        // } 
        levels++;
    }
    //since for leaf nodes the levels will be increased
    return levels-1;
}
