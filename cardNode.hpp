#include "card.hpp"

#ifndef CNODE
#define CNODE

class cardNode{
    private:
        Card card;
        cardNode * next;
    public:
        Card get_card(){
            return card;
        }
        void set_card(Card _card){
            card = _card;
        }
        cardNode(){
            card = Card();
            next = NULL;
        }
        cardNode(Card _card){
            card = _card;
            next = NULL;
        }
        cardNode(string _name){
            card = Card(_name);
            next = NULL;
        }
        void print(){
            card.cleanPrint();
            cout << "->";
        }
};

#endif