#include "godNode.hpp"

#ifndef GQUEUE
#define GQUEUE

class godQueue{
    //Priority queue of gods
    private:
        godNode * front, * rear;
    public:
        godQueue(){
            /*front = NULL;
            rear = NULL;
            front->set_next(rear);*/
            front = rear = NULL;
        }
        bool isEmpty(){
            //returns true if the queue is empty
            return front == NULL;
        }
        int size(){
            if (isEmpty())
                return 0;
            else{
                int length = 0;
                godNode * tmp = front;
                while (tmp != NULL){
                    length ++;
                    tmp = tmp->get_next();
                }
                return length;
            }
        }
        void enqueue(godNode * _node){
            if (isEmpty()){
                front = rear = _node;
            }   
            else{
                if (front->get_next() == NULL){
                    if (front->get_god().get_followers() < _node->get_god().get_followers()){
                        rear = _node;
                        front->set_next(rear);
                    }
                    else{
                        _node->set_next(front);
                        front = _node;
                        rear = front->get_next();    
                    }
                }
                else{
                    if (front->get_god().get_followers() > _node->get_god().get_followers()){
                        _node->set_next(front);
                        front = _node;
                    }
                    else if(rear->get_god().get_followers() < _node->get_god().get_followers()){
                        rear->set_next(_node);
                        rear = rear->get_next();
                    }
                    else{
                        godNode * tmp = front;
                        while (tmp->get_next() != NULL){
                            if (tmp->get_next()->get_god().get_followers() > _node->get_god().get_followers() && tmp->get_god().get_followers() < _node->get_god().get_followers()){
                                godNode * tmpNext = tmp->get_next();
                                tmp->set_next(_node);
                                _node->set_next(tmpNext);
                                break;
                            }
                            else{
                                tmp = tmp->get_next();
                            }
                        }
                    }
                }
            }
        }
        godNode * dequeue(){
            godNode * res;
            godNode * tmp;
            if (isEmpty()){
                cout << "Empty queue." << endl;
                return NULL;
            }
            else if(front == rear){
                res = front;
                front = rear = NULL;
                return res;
            }
            else{
                res = rear;
                tmp = front;
                while (tmp->get_next() != res){
                    tmp = tmp->get_next();
                }
                rear = tmp;
                tmp->set_next(NULL);
                return res;
            }
        }
        void print(){
            if (isEmpty())
                cout << "Empty queue." << endl;
            else if(front == rear){
                front->print();
                cout << endl;
            }
            else{
                godNode * tmp = front;
                while (tmp != NULL){
                    tmp->print();
                    tmp = tmp->get_next();
                }
                cout  << endl;
            }
        }
};

#endif