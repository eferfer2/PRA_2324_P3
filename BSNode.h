#ifndef BSNODE
#define BSNODE_H
#include <ostream>

using namespace std;

template <typename T>

class BSNode{
    public:

        //Atributos
        T elem; //Elemento almacenado en el nodo
        BSNode<T> *left; //puntero a nodo de la izq
        BSNode<T> *right; //puntero a nodo de la der

        //Métodos

        //Constructor
        BSNode(T elem, BSNode<T> *left=nullptr, BSNode<T> *right=nullptr): elem{elem}, left{left}, right{right} {}

        //Operador que imprime por pantalla elem

    friend ostream& operator<<(ostream &out, const BSNode<T> &bsn){


        out<<bsn.elem;

        return out;


    }


};

#endif
