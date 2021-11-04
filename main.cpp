#include "card.hpp"
#include "god.hpp"
#include "godQueue.hpp"
#include "cardNode.hpp"
#include "cardStack.hpp"
//#include "godAVL.hpp"
#include "godAVL2.hpp"
#include <ctime>
//#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
//Para correr el programa en terminal
//g++ ./main.cpp
//./a.exe
using namespace std;

cardStack * fillStack(cardStack * stack, int milagro, int traicion, int nuevo_dios, int retorno, int muerte, int anarquia, int uni){
    //fills the stack of cards
    int actual_milagro = 0;
    int actual_traicion = 0;
    int actual_nuevo_dios = 0;
    int actual_retorno = 0;
    int actual_muerte = 0;
    int actual_anarquia = 0;
    int actual_union = 0;
    int actual_size = 0;
    int max_size = milagro+traicion+nuevo_dios+retorno+muerte+anarquia+uni;
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
        else if (number == 5){
            if (actual_muerte < muerte){
                stack->push("Muerte");
                actual_muerte++;
                actual_size++;
            }
        }
        else if (number == 6){
            if (actual_anarquia < anarquia){
                stack->push("Anarquia");
                actual_anarquia ++;
                actual_size ++;
            }
        }
        else if (number == 7){
            if (actual_union < uni){
                stack->push("Union");
                actual_union ++;
                actual_size ++;
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
        tmp = tmp->get_next();
    }
    return avl;
}

avlTree milagro(avlTree avl, godQueue * queue){
    cout << "\n------Milagro------" << endl << endl;
    //realiza la accion de la carta milagro
    godNode * a = queue->dequeue();
    godNode * b = queue->dequeue();
    cout << "Dios 1:";
    a->print();
    cout << "Dios 2:";
    b->print();
    cout << "\nRealizando milagro." << endl;
    int extra20 = b->get_god().get_followers()*0.2;
    avl.root = avl.remove(avl.root,a);
    avl.root = avl.remove(avl.root,b);
    God gb = b->get_god();
    God ga = a->get_god();
    gb.set_followers(gb.get_followers()-extra20);
    ga.set_followers(ga.get_followers()+extra20);
    a->set_god(ga);
    b->set_god(gb);
    cout << "Dios 1:";
    a->print();
    cout << "Dios 2:";
    b->print();
    cout << endl;
    queue->enqueue(a);
    queue->enqueue(b);
    avl.root = avl.insert(avl.root,a);
    avl.root = avl.insert(avl.root,b);
    return avl;
}

avlTree traicion(avlTree avl, godQueue * queue){
    //realiza la accion de la carta traicion
    cout << "\n-------Traicion--------" << endl << endl;
    godNode * a = queue->dequeue();
    godNode * b = queue->dequeue();
    cout << "Dios 1:";
    a->print();
    cout << "Dios 2:";
    b->print();
    int extra30 = a->get_god().get_followers()*0.3;
    avl.root = avl.remove(avl.root,a);
    avl.root = avl.remove(avl.root,b);
    God ga = a->get_god();
    God gb = b->get_god();
    ga.set_followers(ga.get_followers()-extra30);
    gb.set_followers(gb.get_followers()+extra30);
    a->set_god(ga);
    b->set_god(gb);
    cout << "\nRealizando traicion." << endl;
    cout << "Dios 1:";
    a->print();
    cout << "Dios 2:";
    b->print();
    cout << endl;
    queue->enqueue(a);
    queue->enqueue(b);
    avl.root = avl.insert(avl.root,a);
    avl.root = avl.insert(avl.root,b);
    return avl;
}

void anarquia(avlTree avl, godQueue * queue){
    cout << "Realizando anarquia" << endl;
    /*godNode * a = queue->dequeue();
    int key = a->get_god().get_followers();
    avl_node * tmp = avl.root;
    if (tmp == NULL)
        return NULL;*/
}

void retorno(cardStack * cStack, cardStack * memory){
    cout << "\n -------Retorno--------" << endl << endl;
    cStack->print();
    if (memory->isEmpty() == false){
        cardNode * retorno = memory->pop(); // retorno
        cardNode * tmp1 = memory->pop();
        cardNode * tmp2 = memory->pop();
        cardNode * tmp3 = memory->pop();
        if (tmp2 == NULL){
            cStack->push(tmp1->get_card().get_name());
        }
        else if (tmp3 == NULL){
            cStack->push(tmp1->get_card().get_name());
            cStack->push(tmp2->get_card().get_name());
        }
        else{
            cStack->push(tmp1->get_card().get_name());
            cStack->push(tmp2->get_card().get_name());
            cStack->push(tmp3->get_card().get_name());
        }
    }
    cStack->print();
}

string create_new_name(int counter){
    string name = "New God " + to_string(counter);
    return name;
}

avlTree new_god(avlTree avl, godQueue * queue, int new_god_counter){
    cout << "\n--------Nuevo Dios--------" << endl << endl;
    godNode * a = queue->dequeue();
    godNode * b = queue->dequeue();
    cout << "Dios 1:";
    a->print();
    cout << "Dios 2:";
    b->print();
    int new_follower_amount = a->get_god().get_followers() + b->get_god().get_followers();
    string new_name = create_new_name(new_god_counter);
    godNode * new_node = new godNode(new_name,new_follower_amount);
    avl.root = avl.insert(avl.root,new_node);
    cout << "\nNuevo Dios:";
    new_node->print();
    cout << endl;
    queue->enqueue(a);
    queue->enqueue(b);
    queue->enqueue(new_node);
    return avl;
}

avlTree muerte(avlTree avl, godQueue  * queue){
    cout << "\n--------Muerte--------" << endl << endl;
    godNode * a = queue->dequeue();
    cout << "Dios 1:";
    a->print();
    cout << endl;
    avl.root = avl.remove(avl.root,a);
    God ga = a->get_god();
    ga.set_followers(ga.get_followers()*0.9);
    a->set_god(ga);
    cout << "Dios 1 muere.\nDios 1:";
    a->print();
    cout << endl;
    queue->enqueue(a);
    avl.root = avl.insert(avl.root,a);
    return avl;
}

avlTree unionT(avlTree avlPrincipal, avl_node * root_secundario){
    if (root_secundario != NULL){
        avlPrincipal.insert(avlPrincipal.root,root_secundario->god);
        unionT(avlPrincipal,root_secundario->right);
        unionT(avlPrincipal,root_secundario->left);
    }
}

cardNode * fillRetornoMemory(cardNode array[], cardNode cardToAdd){
    if (array[0].get_card().get_name() == ""){
        array[0] = cardToAdd;
    }
    else if (array[1].get_card().get_name() == ""){
        array[1] = array[0];
        array[0] = cardToAdd;
    }
    else if (array[2].get_card().get_name() == ""){
        array[2] = array[1];
        array[1] = array[0];
        array[0] = cardToAdd;
    }
    else{
        array[0] = array[1];
        array[1] = array[2];
        array[2] = cardToAdd;
    }
    return array;
}

void turno(avlTree  avl, godQueue * gQueue){
    cardStack * retornoMemory = new cardStack();
    int new_god_counter = 0;
    cardStack * cStack = new cardStack();
    cStack = fillStack(cStack,5,4,4,6,10,0,0);
    //cout <<cStack->size() << endl;
    cStack->print();
    char key;
    while (true){
        if (cStack->isEmpty() == true){
            cStack = fillStack(cStack,5,4,4,0,10,0,0);
        }
        cardNode * card = cStack->pop();
        retornoMemory->push(card->get_card().get_name());
        string cardS = card->get_card().get_name();
        if (cardS == "Milagro"){
            avl = milagro(avl, gQueue);
        }
        else if (cardS == "Traicion"){
            avl = traicion(avl,gQueue);
        }
        else if (cardS == "Nuevo Dios"){
            avl = new_god(avl,gQueue,new_god_counter);
            new_god_counter ++;
        }
        else if (cardS == "Retorno"){
            retorno(cStack,retornoMemory);
        }
        else if (cardS == "Muerte"){
            avl = muerte(avl,gQueue);
        }
        else if (cardS == "Anarquia"){
            cout << "No hay anarquia" << endl;
        }
        else if (cardS == "Union"){
            cout << "No hay union" << endl;
        }
        Sleep(3000);
        //retornoMemory->print();
        /*cout << "Desea continuar? s/n:";
        cin >> key;
        cout << endl;
        //avl.printAVL(avl.root);
        if (key == 'n'){
            avl.printAVL(avl.root);
            break;
        }*/
    }
}

int main(){
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
    godNode * gNode12 = new godNode("Thoth", 154);
    godNode * gNode13 = new godNode("Poseidon", 119);
    godNode * gNode14 = new godNode("Hercules", 302);
    godNode * gNode15 = new godNode("Freya", 132);
    godNode * gNode16 = new godNode("Khepri", 231);
    godNode * gNode17 = new godNode("Tepin", 174);
    godNode * gNode18 = new godNode("Odin", 300);
    godNode * gNode19 = new godNode("Anubis", 176);
    godNode * gNode20 = new godNode("Medusa", 247);
    godQueue * gQueue = new godQueue();
    gQueue->enqueue(gNode);
    gQueue->enqueue(gNode2);
    gQueue->enqueue(gNode3);
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
    gQueue->enqueue(gNode15);
    gQueue->enqueue(gNode16);
    gQueue->enqueue(gNode17);
    gQueue->enqueue(gNode18);
    gQueue->enqueue(gNode19);
    gQueue->enqueue(gNode20);

    gQueue->print();
    //arbol AVL
    avlTree avl;
    avl = llenarAVL(avl,gQueue);
    turno(avl,gQueue);
    return 0;
}