#include "godNode.hpp"

#ifndef GLIST
#define GLIST

class godList{
    //List of gods
    private:
        godNode * firstNode;
    public:
        godList(){
            //Constructor method
            firstNode = NULL;
        }
        bool isEmpty(){
            //returns true if the list is empty
            return firstNode == NULL;
        }
        void append(godNode * _node){
            //adds a god at the end of the list
            if (isEmpty())
                firstNode = _node;
            else{
                godNode * tmp = firstNode;
                while (tmp != NULL){
                    tmp = tmp->get_next();
                }
                tmp = _node;
            }
        }
        void addStart(godNode * _node){
            //adds a god at the start of the list
            if (isEmpty())
                firstNode = _node;
            else{
                _node->set_next(firstNode);
                firstNode = _node;
            }
        }
        int length(){
            //returns the length of the list
            if (isEmpty())
                return 0;
            else{
                int length = 1;
                godNode * tmp = firstNode;
                while (tmp!=NULL){
                    tmp = tmp->get_next();
                    length += 1;
                }
                return length;
            }
        }
};

#endif