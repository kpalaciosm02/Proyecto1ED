#include <iostream>
#include <string.h>
using namespace std;

#ifndef GOD
#define GOD

class God{
    //representation of a god
    private:
        int followers;
        string name;

    public:
        God(){
            //Constructor method
            followers = 0;
            name = "";
        }
        God(int _followers, string _name){
            //Constructor method
            followers = _followers;
            name = _name;
        }
        int get_followers(){
            //returns the followers of a god
            return followers;
        }
        string get_name(){
            //returns the name of a god
            return name;
        }
        void set_followers(int _followers){
            //sets the followers of a god
            followers = _followers;
        }
        void set_name(string _name){
            //sets the name of a god
            name = _name;
        }
        void clearPrint(){
            //prints the data of a god
            cout << name << ":" << followers;
        }
};

#endif