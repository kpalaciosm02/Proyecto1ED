#include "godNode.hpp"

#ifndef GLIST
#define GLIST

class godList{
    private:
        godNode * firstNode;
    public:
        godList(){
            firstNode = NULL;
        }
        bool isEmpty(){
            return firstNode == NULL;
        }
        void append(godNode * _node){
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
            if (isEmpty())
                firstNode = _node;
            else{
                _node->set_next(firstNode);
                firstNode = _node;
            }
        }
        int length(){
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