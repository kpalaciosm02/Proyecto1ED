#include "god.hpp"

#ifndef GNODE
#define GNODE

class godNode{
    //Node from a godList
    private:
        God god;
        godNode * next;
    public:
        God get_god(){
            //returns the god
            return god;
        }
        void set_god(God _god){
            //sets the god
            god = _god;
        }
        godNode * get_next(){
            //returns the pointer to the next god
            return next;
        }
        void set_next(godNode * _node){
            //sets the pointer to the next god
            next = _node;
        }
        godNode(){
            //Constructor method
            god = God();
            next = NULL;
        }
        godNode(God _god){
            //Constructor method
            god = _god;
            next = NULL;
        }
        godNode(string _name, int _followers){
            //Constructor method
            god = God(_followers,_name);
            next = NULL;
        }
        void print(){
            //prints the data of a god
            god.clearPrint();
            cout << "->";
        }
};

#endif