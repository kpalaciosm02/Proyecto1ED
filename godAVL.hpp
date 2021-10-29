#include <iostream>
#include "godNode.hpp"
using namespace std;
#ifndef TREENODE
#define TREENODE

class Node{
    private:
        int key;
        Node * left;
        Node * right;
        int height;
        godNode * godN;
    public:
        Node(godNode * tmp){
            godN = tmp;
            key = godN->get_god().get_followers();
            left = NULL;
            right = NULL;
            height = 1;
        }
        int get_key(){
            return key;
        }
        Node * get_left(){
            return left;
        }
        Node * get_right(){
            return right;
        }
        int get_height(){
            return height;
        }
        void set_key(){
            key = godN->get_god().get_followers();
        }
        void set_left(Node * tmp){
            left = tmp;
        }
        void set_right(Node * tmp){
            right = tmp;
        }
        void set_height(int _height){
            height = _height;
        }
};

int max(int a, int b){
    return (a > b)? a : b;
}

int height(Node * N){
    if (N == NULL){
        return 0;
    }
    else{
        return N->get_height();
    }
}

Node * rightRotate(Node * y){
    Node * x = y->get_left();
    Node * t2 = x->get_right();
    //rotate
    x->set_right(y);
    y->set_left(t2);
    //new heights
    y->set_height(max(height(y->get_left()), height(y->get_right())) + 1);
    x->set_height(max(height(x->get_left()), height(x->get_right())) + 1);
    //new root
    return x;
}

Node * leftRotate(Node * x){
    Node * y = x->get_right();
    Node * t2 = y->get_left();
    //rotate
    y->set_left(x);
    x->set_right(t2);
    //new heights
    x->set_height(max(height(x->get_left()), height(x->get_right())) + 1);
    y->set_height(max(height(y->get_left()), height(y->get_right())) + 1);
    //new root
    return y;
}

int getBalance(Node * N){
    //returns balance factor of a node
    if (N == NULL){
        return 0;
    }
    else{
        return height(N->get_left()) - height(N->get_right());
    }
}

Node * insert(Node * node, godNode * tmp){
    int key = tmp->get_god().get_followers();
    //insert normally
    if (node == NULL){
        Node * node = new Node(tmp);
        return (node);
    }
    if (key <= node->get_key()){
        node->set_left(insert(node->get_left(), tmp));
    }
    else{
        node->set_right(insert(node->get_right(), tmp));
    }
    //new height
    node->set_height(1 + max(height(node->get_left()), height(node->get_right())));
    //rebalance
    int balance = getBalance(node);
    //left left case
    if (balance > 1 && key < node->get_left()->get_key())
        return rightRotate(node);
    //right right case
    if (balance < -1 && key > node->get_right()->get_key())
        return leftRotate(node);
    //left right case
    if (balance > 1 && key > node->get_left()->get_key()){
        node->set_left(leftRotate(node->get_left()));
        return rightRotate(node);
    }
    //right left case
    if (balance < -1 &&  key < node->get_right()->get_key()){
        node->set_right(rightRotate(node->get_right()));
        return leftRotate(node);
    }

    return node;
}

void postOrder(Node * root){
    if (root != NULL){
        cout << root->get_key() << "[";
        postOrder(root->get_right());
        cout << "][";
        postOrder(root->get_left());
        cout << "]";
    }
}
#endif