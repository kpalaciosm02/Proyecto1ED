#include "god.hpp"
#include <map>
#include <iostream>
#include <cassert>
#include "godNode.hpp"
#include "godQueue.hpp"
#include "godAVL.hpp"
using namespace std;

void x(godQueue * queue){   
    while (queue->isEmpty() == false){
        godNode * tmp = queue->dequeue();
        tmp->print();
        cout << endl;
    }

}

void testMap(Node * root, map<string,Node*>TMap){
    Node * tmp = root;
    if (root != NULL){
        cout << tmp->getNode()->get_god().get_name() << endl;
        TMap[tmp->getNode()->get_god().get_name()] = tmp;
        testMap(tmp->get_left(),TMap);
        testMap(tmp->get_right(),TMap);
    }
}

Node * fillAVL(godQueue * queue){
    Node * root = NULL;
    godNode * tmp = queue->first();
    while (tmp != NULL){
        root = insert(root,tmp);
        tmp = tmp->get_next();
    }
    //postOrder(root);
    return root;
}

int main(){
    /*God god1(12000,"Zeus");
    God god2(13000,"Afrodita");
    God god3(25000,"Hades");
    God god4(13000,"Anubis");
    God god5(10000,"Apollo");
    God *g1 = new God(12000,"Zeus");
    God *g2 = new God(13000, "Afrodita");
    God *g3 = new God(25000,"Hades");
    God *g4 = new God(13000,"Anubis");
    God *g5 = new God(10000,"Apollo");
    godNode * gN1 = new godNode("Zeus",12000);
    godNode * gN2 = new godNode("Afrodita",13000);
    godNode * gN3 = new godNode("Hades",25000);
    
    godNode * gN5 = new godNode("Apollo",10000);
    godNode * gN4 = new godNode("Anubis",13000);
    godQueue * q = new godQueue();
    q->enqueue(gN1);
    q->enqueue(gN2);
    q->enqueue(gN3);
    q->enqueue(gN4);
    q->enqueue(gN5);
    q->print();*/
    godNode * gNode = new godNode("Athenea",170);
    godNode * gNode2 = new godNode("Zeus", 160);
    godNode * gNode3 = new godNode("Hades", 200);
    godNode * gNode4 = new godNode("Loki", 100);
    godNode * gNode5 = new godNode("Thor", 160);
    godQueue * gQueue = new godQueue();
    gQueue->print();
    gQueue->enqueue(gNode);
    gQueue->print();
    gQueue->enqueue(gNode2);
    gQueue->print();
    gQueue->enqueue(gNode3);
    gQueue->print();
    gQueue->enqueue(gNode4);
    gQueue->enqueue(gNode5);
    gQueue->print();
    Node * root = fillAVL(gQueue);
    cout << endl;

    map<string,Node*> t;
    /*t[root->getNode()->get_god().get_name()] = root;
    Node * tmp = t.find("Zeus")->second;
    tmp->getNode()->print();*/
    testMap(root,t);
    /*for(auto it = t.cbegin(); it != t.cend(); ++it){
        it->second->getNode()->print();
        //cout << it->first << " " << it->second->getNode()->print() << "\n";
    }*/
    //x(q);
    return 0;
}