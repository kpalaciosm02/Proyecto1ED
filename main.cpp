#include "card.hpp"
#include "god.hpp"
#include "cardNode.hpp"

int main(){
    Card card1("milagro");
    card1.cleanPrint();
    cout << endl;
    cardNode cNode1("traicion");
    cNode1.print();
}