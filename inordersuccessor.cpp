// Given a node, find the in-order successor in binary search tree, with parent pointer
// of each node but no root node available.

#include <stdio.h>
#include <iostream>
#include "Node.cpp"

using namespace std;
//
//Node *findMostLeft(Node *startNode){
//    
//    while (startNode!=NULL){
//        startNode = startNode->left;
//    }
//    
//    return startNode;
//}

int main (){

    int array[] = {1,2,3, 4};
    int length = sizeof(array)/sizeof(int);
    
    if (length%2==0){
        for (int i = 0; i<length; i++){
            array[i] = 0;
        }
    }else{
        for (int i = 0; i<length; i++){
            array[i] = 1;
        }
    }
    
    for (int i = 0; i<length; i++){
        cout << array[i] << " ";
    }
    
//    Node *nodeparent = new Node(2);
//    Node *node1 = new Node(1);
//    nodeparent->left = node1;
//    node1->parent = nodeparent;
//    
//    cout << nodeparent->left->value;
//    cout << node1->value;
//    
//    int result;
//    
//    if (node1->right == NULL){
//        result = node1->parent->value;
//        cout << result;
//    }else{
//        result = findMostLeft(node1->right)->value;
//    }
}