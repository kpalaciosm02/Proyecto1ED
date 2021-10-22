#include "god.hpp"

#ifndef GNODE
#define GNODE

class godNode{
    private:
        God god;
        godNode * next;
    public:
        God get_god(){
            return god;
        }
        void set_god(God _god){
            god = _god;
        }
        godNode * get_next(){
            return next;
        }
        void set_next(godNode * _node){
            next = _node;
        }
        godNode(){
            god = God();
            next = NULL;
        }
        godNode(God _god){
            god = _god;
            next = NULL;
        }
        godNode(string _name, int _followers){
            god = God(_followers,_name);
            next = NULL;
        }
        void print(){
            god.clearPrint();
            cout << "->";
        }
};

#endif