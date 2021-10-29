#include "card.hpp"
#include "god.hpp"
#include "godQueue.hpp"
#include "cardNode.hpp"
#include "cardStack.hpp"
#include "godAVL.hpp"

using namespace std;

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
    godNode * gNode2 = new godNode("Zeus", 150);
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
    God * god = new God(100, "Athenea");

    Node * root = NULL;
    root = insert(root,gNode);
    root = insert(root,gNode2);
    root = insert(root,gNode3);
    root = insert(root,gNode4);
    root = insert(root,gNode5);
    postOrder(root);

    //god->clearPrint();
    
}