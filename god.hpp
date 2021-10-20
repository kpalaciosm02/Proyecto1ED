#include <iostream>
#include <string.h>
using namespace std;

#ifndef GOD
#define GOD

class God{
    private:
        int followers;
        string name;

    public:
        int get_followers(){
            return followers;
        }
        string get_name(){
            return name;
        }
        void set_followers(int _followers){
            followers = _followers;
        }
        void set_name(string _name){
            name = _name;
        }
};

#endif