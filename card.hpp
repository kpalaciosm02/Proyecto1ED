#include <iostream>
#include <string.h>

using namespace std;

#ifndef CARD
#define CARD

class Card{
    //representation of a card
    private:
        string name;

    public:
        Card(){
            //Constructor method
            name  = "";
        }
        Card(string _name){
            //Constructor method
            name = _name;
        }
        string get_name(){
            //returns the name of the card
            return name;
        }
        void set_name(string _name){
            //sets the name of the card
            name = _name;
        }
        void cleanPrint(){
            //prints the name of the card
            cout << name;
        }
};

#endif