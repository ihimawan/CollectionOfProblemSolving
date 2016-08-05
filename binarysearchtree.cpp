//
//  Bst.cpp
//  trying
//
//  Created by Indri Himawan on 2/7/16.
//  Copyright (c) 2016 Indri Himawan. All rights reserved.
//

#include "Node.cpp"
#include <iostream>
#include <queue>

using namespace std;

class Bst{
public:
    Node *root;
    
    Bst(){
        root = NULL;
    }
    
    void insert(Node *root, int x){
        if (root == NULL){
            Node *newNode = new Node();
            root = newNode;
            
        }else if (x < root->value){
            insert(root->left, x);
        }else{
            insert(root -> right, x);
        }
        
        return;
    }
    
    int findMin(Node *root){
        if (root == NULL){
            return -1;
        }else if(root->left == NULL){
            return root->value;
        }else{
            return findMin(root->left);
        }
    }
    
    int findMax(Node *root){
        
        Node *current;
        current = root;
        if (root == NULL){
            return -1;
        }else{
            while (current->right!=NULL){
                current = current->right;
            }
            
            return current->value;
        }
    }
    
    int max (int x, int y){
        return x>y ? x : y;
    }
    
    int height(Node *root){
        
        if (root == NULL){
            return -1;
        }else{
            return max(height(root->left), height(root->right)) + 1;
        }
    
    }
    
    void levelOrderTraversal (Node *root){
        queue<Node*> Q;
        
        if (root == NULL){
            return;
        }
        
        Q.push(root);
        
        while (!Q.empty()){
            
            if (Q.front()->left!=NULL){
                Q.push(Q.front()->left);
            }
            
            if (Q.front()->right!=NULL){
                Q.push(Q.front()->right);
            }
            
            cout << Q.front()->value << " ";
            Q.pop();
        }
        
        return;
    }
    
    void preOrder(Node* root){
        
        if (root == NULL){
            return;
        }
        cout << root -> value;
        preOrder(root->left);
        preOrder(root->right);
    }
    
    void inOrder(Node* root){
        
        if (root == NULL){
            return;
        }
        
        preOrder(root->left);
        cout << root -> value;
        preOrder(root->right);
    }
    
    void postOrder(Node* root){
        
        if (root == NULL){
            return;
        }
        
        preOrder(root->left);
        preOrder(root->right);
        cout << root -> value;
    }
    
    bool isBst(Node* head){
        
        if (head==NULL){
            return true;
        }else if (head->left!=NULL && head->right!=NULL){
            return (head->left->value <= head->value < head->right->value) && isBst(head->left) && isBst(head->right);
        }else if (head->right==NULL){
            return (head->left->value <= head->value) && isBst(head->left);
        }else if (head->left == NULL){
            return (head->right->value > head->value) && isBst(head->left);
        }else{
            return false;
        }

    }
    
    Node* search(Node* root, int i){
        if (root->value == i){
            return root;
        }else if (root == NULL){
            return NULL;
        }else if (i < root->value){
            return search(root->left, i);
        }else{
            return search(root->right, i);
        }
    }
    
    Node* deleteNode(Node* root, int i){
        if (root == NULL){
            return root;
        }else if (i < root->value){
            root -> left = deleteNode(root->left, i);
        }else if (i > root->value){
            root -> right = deleteNode(root->right, i);
        }else{ //found it!
            
            if (root->left == NULL && root->right == NULL){
                delete root;
                root=NULL;
                
            }else if (root->left == NULL){
                Node* temp;
                temp = root;
                root = root->right; // the next node will be equal to root->right
                delete root;
                
            }else if (root->right == NULL){
                Node* temp;
                temp = root;
                root = root->left; // the next node will be equal to root->left
                delete root;
                
            }else{
                Node *temp;
                int temp2;
                temp=root;
                
                while (temp->left != NULL){
                    temp = temp->left;
                }
                
                temp2 = root->value;
                root->value = temp->value;
                temp->value = temp2;
                
                delete temp;
                
            }
        }
        
        return root;
    }
    
    //will return the address of the successor node
    Node* getSuccessor(Node* root, int data){
        
        //search the node
        
        Node* current = search(root, data);
        if (current == NULL){
            return NULL;
        }
        
        //Case 1: if node has right subtree
        if (current->right != NULL){
            Node* temp;
            temp = current;
            temp=temp->right;
            
            while (temp->left!=NULL){
                temp=temp->left;
            }
            
            return temp;
        }
        
        //Case 2: if node does not have right subtree
        else {
            
            /*if root is not known but there is pointer to parent.
             */
            
//            Node* temp;
//            temp = current;
//            temp=temp->parent;
//            
//            while (temp->value<current->value){
//                if (temp->parent!=NULL){
//                    temp=temp->parent;
//                }else{
//                    return NULL; //no successor
//                }
//            }
//            
//            return temp;
            
            /*if root is known but there is no pointer to parent.
             */
            
            Node* successor = NULL;
            Node* ancestor = root;
            
            while (ancestor!=current){
                if (current->value < ancestor->value){
                    successor = ancestor;
                    ancestor = ancestor ->left;
                }else{
                    ancestor = ancestor -> right;
                }
            }

            return successor;
            
            
        }
        
        return NULL;
    }
    
};
