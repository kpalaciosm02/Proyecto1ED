#include "god.hpp"
#include <map>
#include <iostream>
#include <cassert>
#include "godNode.hpp"
using namespace std;

int main(){
    God *g1 = new God(12000,"Zeus");
    God *g2 = new God(13000, "Afrodita");
    God *g3 = new God(25000,"Hades");
    God *g4 = new God(13000,"Anubis");
    God *g5 = new God(10000,"Apollo");
    godNode * gN1 = new godNode(*g1);

    map<std::string,God> m;
    m["Zeus"] = *g1;
    m.insert(std::make_pair("Afrodita",*g2));
    map<std::string,God>::iterator i = m.find("Afrodita");
    assert(i != m.end());
    std::cout << "Key: " << i->second.get_name() << " Value: " << i->second.get_followers() << '\n';
    return 0;

    map<std::string,godNode*> gNodeMap;
    gNodeMap.insert(std::make_pair("Zeus",gN1));
    gNodeMap[gN1->get_god().get_name()] = gN1;

}