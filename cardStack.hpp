#include "card.hpp"
#include "cardNode.hpp"

#ifndef CSTACK
#define CSTACK

class cardStack{
    private:
        cardNode * top;
    public:
        cardStack(){
            //Constructor method
            top = NULL;
        }
        bool isEmpty(){
            //returns true if the stack is empty
            return top == NULL;
        }
        void push(string _name){
            //adds a card to the top of the stack
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
            //returns the top of the stack, but doesn't delete it
            if (isEmpty()){
                return NULL;
            }
            else{
                return top;
            }
        }
        cardNode * pop(){
            //deletes the top of the stack and returns it
            if (isEmpty())
                cout << "Empty Stack given" << endl;
            else{
                cardNode * tmp = top;
                top = top->get_next();
                return tmp;
            }
        }
        void print(){
            //prints the data in the stack
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