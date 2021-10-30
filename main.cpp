#include "card.hpp"
#include "god.hpp"
#include "godQueue.hpp"
#include "cardNode.hpp"
#include "cardStack.hpp"
//#include "godAVL.hpp"
#include "godAVL2.hpp"

using namespace std;

avlTree llenarAVL(avlTree avl, godQueue * queue){
    //uses an AVL and a queue to fill the avl with the gods from the queue
    godNode * tmp = queue->first();
    while (tmp != NULL){
        avl.root = avl.insert(avl.root,tmp);
        tmp = tmp->get_next();
    }
    return avl;
}

avlTree milagro(avlTree avl, godQueue * queue){
    //realiza la accion de la carta milagro
    godNode * a = queue->dequeue();
    godNode * b = queue->dequeue();
    int extra20 = b->get_god().get_followers()*0.2;
    God gb = b->get_god();
    God ga = a->get_god();
    gb.set_followers(b->get_god().get_followers()-extra20);
    ga.set_followers(a->get_god().get_followers()+extra20);
    a->set_god(ga);
    b->set_god(gb);
    queue->enqueue(a);
    queue->enqueue(b);
    avlTree newAVL;
    newAVL = llenarAVL(newAVL,queue);
    return newAVL;
}

int main(){
    /*Card card1("milagro");
    card1.cleanPrint();
    cout << endl;
    cardNode cNode1("traicion");
    cNode1.print();
    cout << endl;

    cardStack * cStack = new cardStack();
    cout << cStack->isEmpty() << endl;
    cStack->print();
    cStack->push("prueba1");
    cStack->print();
    cStack->push("prueba2");
    cStack->print();
    cStack->push("prueba3");
    cStack->print();
    cStack->pop();
    cStack->print();*/
    godNode * gNode = new godNode("Athenea",170);
    godNode * gNode2 = new godNode("Zeus", 160);
    godNode * gNode3 = new godNode("Hades", 200);
    godNode * gNode4 = new godNode("Loki", 160);
    godNode * gNode5 = new godNode("Thor", 100);
    godQueue * gQueue = new godQueue();
    //gQueue->print();
    gQueue->enqueue(gNode);
    //gQueue->print();
    gQueue->enqueue(gNode2);
    //gQueue->print();
    gQueue->enqueue(gNode3);
    //gQueue->print();
    gQueue->enqueue(gNode4);
    gQueue->enqueue(gNode5);
    gQueue->print();
    //arbol AVL
    avlTree avl;
    avl = llenarAVL(avl,gQueue);
    avl.printAVL(avl.root);
    cout << endl;
    avl = milagro(avl,gQueue);
    avl.printAVL(avl.root);
    cout << endl;
    gQueue->print();    
}