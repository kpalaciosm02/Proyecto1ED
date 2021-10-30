#include <iostream>
using namespace std;
#include "godNode.hpp"

#ifndef AVLNODE
#define AVLNODE

struct avl_node{
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
            else if (data <= root->data){
                root->left = insert(root->left,god);
                root = balance(root);
            }
            else if (data > root->data){
                root->right = insert(root->right,god);
                root = balance(root);
            }
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
};

#endif