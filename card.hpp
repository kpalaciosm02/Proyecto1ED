#include <iostream>
#include <string.h>

using namespace std;

#ifndef CARD
#define CARD

class Card{
    private:
        string name;

    public:
        Card(){
            name  = "";
        }
        Card(string _name){
            name = _name;
        }
        string get_name(){
            return name;
        }
        void set_name(string _name){
            name = _name;
        }
};

#endif