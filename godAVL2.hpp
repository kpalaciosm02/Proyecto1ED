#include <iostream>
using namespace std;
#include "godNode.hpp"

#ifndef AVLNODE
#define AVLNODE

class avl_node{
    public:
    godNode * god;
    int data;
    avl_node * left;
    avl_node * right;
};

#endif

#ifndef AVL
#define AVL

class avlTree{
    public:
        avl_node * root;
        avlTree(){//constructor method
            root = NULL;
        }
        int height(avl_node * tmp){//returns the height of the tree
            int h = 0;
            if (tmp != NULL){
                int l_height = height(tmp->left);
                int r_height = height(tmp->right);
                int max_height = max(l_height, r_height);
                h = max_height + 1;
            }
            return h;
        }
        int diff(avl_node * tmp){//returns the difference between the height of 2 trees
            int l_height = height(tmp->left);
	        int r_height = height(tmp->right);
	        int f = l_height - r_height;
	        return f;
        }
        //methods to rotate nodes in the tree
        avl_node * rightRotate(avl_node * y){
            avl_node * x = y->left;
            avl_node * t2 = x->right;
            x->right = y;
            y->left = t2;
            return x;
        }
        avl_node * leftRotate(avl_node * x){
            avl_node * y = x->right;
            avl_node * t2 = y->left;
            y->left = x;
            x->right = t2;
            return y;
        }
        avl_node * rr_rotation(avl_node * parent){//right-right case
            avl_node * tmp = parent->right;
            parent->right = tmp->left;
            tmp->left = parent;
            return tmp;
        }
        avl_node * ll_rotation(avl_node * parent){//left-left case
            avl_node * tmp = parent->left;
	        parent->left = tmp->right;
	        tmp->right = parent;
	        return tmp;
        }
        avl_node * lr_rotation(avl_node * parent){//left-right case
            avl_node * tmp = parent->left;
            parent->left = rr_rotation(tmp);
            return ll_rotation(parent);
        }
        avl_node * rl_rotation(avl_node * parent){//right-left case
            avl_node * tmp = parent->right;
            parent->right = ll_rotation(tmp);
            return rr_rotation(parent);
        }
        avl_node * balance(avl_node * tmp){//uses the balance factor to know which rotation to apply
            int factor = diff(tmp);
            if (factor > 1){
                if (diff(tmp->left) > 0)
                    tmp = ll_rotation(tmp);
                else
                    tmp = lr_rotation(tmp);
            }
            else if (factor < -1){
                if (diff(tmp->right) > 0)
                    tmp = rl_rotation(tmp);
                else
                    tmp = rr_rotation(tmp);
            }
            return tmp;
        }
        avl_node * insert(avl_node * root, godNode * god){//inserts new nodes in order and balances the three
            int data = god->get_god().get_followers();
            if (root == NULL){
                root = new avl_node;
                root->data = data;
                root->god = god;
                root->left = NULL;
                root->right = NULL;
                return root;
            }
            else if (data < root->data){
                root->left = insert(root->left,god);
                root = balance(root);
            }
            else if (data >= root->data){
                root->right = insert(root->right,god);
                root = balance(root);
            }
            return root;
        }
        avl_node * findMin(avl_node * t){
            if (t == NULL)
                return NULL;
            else if (t->left == NULL)
                return t;
            else
                return findMin(t->left);
        }
        avl_node * remove(avl_node * root, godNode * god){//searches god by followers and name and deletes it if found.
            int key = god->get_god().get_followers();//searching node
            if (root == NULL)
                return root;
            else if (key < root->data)
                root->left = remove(root->left, god);
            else if (key > root->data)
                root->right = remove(root->right, god);
            else if (god->get_god().get_name() != root->god->get_god().get_name()){
                root->right = remove(root->right, god);
            }
            else{//node found
                if ((root->left == NULL) || root->right == NULL){
                    avl_node * tmp = root->left ? root->left : root->right;
                    if (tmp == NULL){
                        tmp = root;
                        root = NULL;
                    }
                    else{
                        *root = *tmp;
                    }
                    free(tmp);
                }
                /*else if((root->left == NULL) && (root->right == NULL)){
                    root = NULL;
                }*/
                else{
                   avl_node * tmp = findMin(root->right);
                   root->data = tmp->data;
                   root->god = tmp->god; 
                   root->right = remove(root->right, tmp->god);
                }
            }
            if (root == NULL)
                return NULL;
            root = balance(root);
            /*int balanceFactor = diff(root);
            if (balanceFactor > 1){
                if (diff(root->left) >= 0 ){
                    return rightRotate(root);
                }
                else{
                    root->left = leftRotate(root->left);
                    return rightRotate(root);
                }
            }
            else if (balanceFactor < -1){
                if (diff(root->right) <= 0){
                    return leftRotate(root);
                }
                else{
                    root->right = rightRotate(root->right);
                    return leftRotate(root);
                }
            }*/
            return root; 
        }
        void printAVL(avl_node * root){
            if (root != NULL){
                cout << root->god->get_god().get_name() << ":" << root->god->get_god().get_followers() << "[";
                printAVL(root->right);
                cout << "][";
                printAVL(root->left);
                cout << "]";
            }
        }
        void preOrder(avl_node * root){
            if (root != NULL){
                cout << root->god->get_god().get_name() << ":" << root->god->get_god().get_followers() << "[";
                preOrder(root->left);
                cout << "][";
                preOrder(root->right);
                cout << "]";
            }
        } 
};

#endif