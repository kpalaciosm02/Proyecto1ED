#include "card.hpp"
#include "god.hpp"
#include "cardNode.hpp"
#include "cardStack.hpp"

int main(){
    Card card1("milagro");
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
    cStack->print();
}