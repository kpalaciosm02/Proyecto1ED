#include "card.hpp"
#include "cardNode.hpp"

#ifndef CSTACK
#define CSTACK

class cardStack{
    private:
        cardNode * top;
    public:
        cardStack(){
            top = NULL;
        }
        bool isEmpty(){
            return top == NULL;
        }
        bool push(string _name){
            cardNode * tmpNode = new cardNode(_name);
            if (isEmpty()){
                top = tmpNode;
            }
            else{
                tmpNode->set_next(top);
                top = tmpNode;
            }
        }
        cardNode * get_top(){
            if (isEmpty()){
                return NULL;
            }
            else{
                return top;
            }
        }
        void print(){
            if (isEmpty()){
                cout << "Empty Stack" << endl;
            }
            else{
                cardNode * tmp = top;
                while (tmp != NULL){
                    tmp->print();
                    tmp = tmp->get_next();
                }
                cout << endl;
            }
        }
};

#endif