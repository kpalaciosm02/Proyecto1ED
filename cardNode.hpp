#include "card.hpp"

#ifndef CNODE
#define CNODE

class cardNode{
    //Node from a cardList
    private:
        Card card;
        cardNode * next;
    public:
        Card get_card(){
            //returns the card
            return card;
        }
        void set_card(Card _card){
            //sets the card
            card = _card;
        }
        cardNode * get_next(){
            //returns the pointer to the next card in the list
            return next;
        }
        void set_next(cardNode * _Node){
            //sets the pointer to the next card in the list
            next = _Node;
        }
        cardNode(){
            //Constructor method
            card = Card();
            next = NULL;
        }
        cardNode(Card _card){
            //Constructor method
            card = _card;
            next = NULL;
        }
        cardNode(string _name){
            //Constructor method
            card = Card(_name);
            next = NULL;
        }
        void print(){
            //prints the data of the node
            if (this != NULL){
                card.cleanPrint();
                cout << "->";
            }
            
        }
};

#endif