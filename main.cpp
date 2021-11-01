#include "card.hpp"
#include "god.hpp"
#include "godQueue.hpp"
#include "cardNode.hpp"
#include "cardStack.hpp"
//#include "godAVL.hpp"
#include "godAVL2.hpp"
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

cardStack * fillStack(cardStack * stack, int milagro, int traicion, int nuevo_dios, int retorno, int muerte){
    //fills the stack of cards
    int actual_milagro = 0;
    int actual_traicion = 0;
    int actual_nuevo_dios = 0;
    int actual_retorno = 0;
    int actual_muerte = 0;
    /*for (int i = 0; i < milagro; i++){
        stack->push("Milagro");
    }
    for (int i = 0; i < traicion; i++){
        stack->push("Traicion");
    }
    for (int i = 0; i < nuevo_dios; i++){
        stack->push("Nuevo Dios");
    }
    for (int i = 0; i < retorno; i++){
        stack->push("Retorno");
    }
    for (int i = 0; i < muerte; i++){
        stack->push("Muerte");
    }*/
    int actual_size = 0;
    int max_size = milagro+traicion+nuevo_dios+retorno+muerte;
    while (actual_size < max_size){
        srand(time(0));
        int number = rand() % 5 + 1;
        if (number == 1){
            if (actual_milagro < milagro){
                stack->push("Milagro");
                actual_milagro ++;
                actual_size ++;
            }
            
        }
        else if (number == 2){
            if (actual_traicion < traicion){
                stack->push("Traicion");
                actual_traicion++;
                actual_size++;
            }
        }
        else if (number == 3){
            if (actual_nuevo_dios < nuevo_dios){
                stack->push("Nuevo Dios");
                actual_nuevo_dios++;
                actual_size++;
            }
        }
        else if (number == 4){
            if (actual_retorno < retorno){
                stack->push("Retorno");
                actual_retorno++;
                actual_size++;
            }
        }
        else if (number == muerte){
            if (actual_muerte < muerte){
                stack->push("Muerte");
                actual_muerte++;
                actual_size++;
            }
        }
    Sleep(1000);
    }
    return stack;
}

avlTree llenarAVL(avlTree avl, godQueue * queue){
    //uses an AVL and a queue to fill the avl with the gods from the queue
    godNode * tmp = queue->first();
    while (tmp != NULL){
        avl.root = avl.insert(avl.root,tmp);
        //avl.preOrder(avl.root);
        //cout << endl;
        tmp = tmp->get_next();
    }
    return avl;
}

avlTree milagro(avlTree avl, godQueue * queue){
    //realiza la accion de la carta milagro
    godNode * a = queue->dequeue();
    godNode * b = queue->dequeue();
    int extra20 = b->get_god().get_followers()*0.2;
    avl.root = avl.remove(avl.root,a);
    avl.root = avl.remove(avl.root,b);
    God gb = b->get_god();
    God ga = a->get_god();
    gb.set_followers(gb.get_followers()-extra20);
    ga.set_followers(ga.get_followers()+extra20);
    a->set_god(ga);
    b->set_god(gb);
    queue->enqueue(a);
    queue->enqueue(b);
    avl.root = avl.insert(avl.root,a);
    avl.root = avl.insert(avl.root,b);
    return avl;
}

avlTree traicion(avlTree avl, godQueue * queue){
    //realiza la accion de la carta traicion
    godNode * a = queue->dequeue();
    godNode * b = queue->dequeue();
    int extra30 = a->get_god().get_followers()*0.3;
    avl.root = avl.remove(avl.root,a);
    avl.root = avl.remove(avl.root,b);
    God ga = a->get_god();
    God gb = b->get_god();
    ga.set_followers(ga.get_followers()-extra30);
    gb.set_followers(gb.get_followers()+extra30);
    a->set_god(ga);
    b->set_god(gb);
    queue->enqueue(a);
    queue->enqueue(b);
    avl.root = avl.insert(avl.root,a);
    avl.root = avl.insert(avl.root,b);
    return avl;
}

avl_node * anarquia(avlTree avl, godQueue * queue){
    godNode * a = queue->dequeue();
    int key = a->get_god().get_followers();
    avl_node * tmp = avl.root;
    if (tmp == NULL)
        return NULL;
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
    godNode * gNode6 = new godNode("Ra", 124);
    godNode * gNode7 = new godNode("Isis", 156);
    godNode * gNode8 = new godNode("Afrodita", 181);
    godNode * gNode9 = new godNode("Apollo", 291);
    godNode * gNode10 = new godNode("Ares", 111);
    godNode * gNode11 = new godNode("Artemisa", 165);
    godNode * gNode12 = new godNode("Apollo", 154);
    godNode * gNode13 = new godNode("Poseidon", 119);
    godNode * gNode14 = new godNode("Hercules", 302);
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
    gQueue->enqueue(gNode6);
    gQueue->enqueue(gNode7);
    gQueue->enqueue(gNode8);
    gQueue->enqueue(gNode9);
    gQueue->enqueue(gNode10);
    gQueue->enqueue(gNode11);
    gQueue->enqueue(gNode12);
    gQueue->enqueue(gNode13);
    gQueue->enqueue(gNode14);
    gQueue->print();
    //arbol AVL
    avlTree avl;
    avl = llenarAVL(avl,gQueue);
    avl.printAVL(avl.root); 
    cout << endl << "Milagro1" << endl;  
    avl = milagro(avl,gQueue);
    avl.printAVL(avl.root);
    cout << endl << "Traicion1" << endl;
    gQueue->print();
    avl = traicion(avl,gQueue);
    avl.printAVL(avl.root);
    /*cout << endl << "Milagro2" << endl;
    avl = milagro(avl,gQueue);
    avl.printAVL(avl.root);
    cout << endl << "Traicion2" << endl;
    gQueue->print();
    avl = traicion(avl,gQueue);
    avl.printAVL(avl.root);
    cout << endl << "Milagro3" << endl;
    avl = milagro(avl,gQueue);
    avl.printAVL(avl.root);
    cout << endl << "Traicion3" << endl;
    gQueue->print();
    avl = traicion(avl,gQueue);
    avl.printAVL(avl.root);
    cout << endl << "Milagro4" << endl;
    avl = milagro(avl,gQueue);
    avl.printAVL(avl.root);
    cout << endl << "Traicion4" << endl;
    gQueue->print();
    avl = traicion(avl,gQueue);
    avl.printAVL(avl.root);*/
//    avl.remove(avl.root,gNode3);
//    avl.remove(avl.root,gNode2);
//    avl.printAVL(avl.root);
    cardStack * cStack = new cardStack();
    cout << cStack->isEmpty() << endl;
    cStack->print();
    cStack = fillStack(cStack,1,2,3,4,5);
    cStack->print();
}