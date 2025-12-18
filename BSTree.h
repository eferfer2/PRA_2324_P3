#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

using namespace std;

template <typename T>
class BSTree{
    private:
        //Atributos

        int nelem; //Numero de elementos almacenados en el ABB
        BSNode<T> *root; //Nodo raiz


        //Buscador de elementos recursivo
        BSNode<T>*  search(BSNode<T>* n, T e) const{
            if(n==nullptr){
                throw runtime_error("elemento no encontrado");
            }
            else if(e>n->elem){
                return search(n->right,e);
            }
            else if(e<n->elem){
                return search(n->left, e);
            }
            else{
                return n;
            }
        }

        //Insertador de elementos
        BSNode<T>* insert(BSNode<T>* n, T e){
            if(n==nullptr){
                nelem++;
                return new BSNode<T>(e);
            }
            else if(n->elem==e){
                throw runtime_error("Elemento ya existente");
            }
            else if(e>n->elem){
                n->right= insert(n->right,e);
            }
            else if(e<n->elem){
                n->left=insert(n->left, e);
            }

            return n;
        }

        void print_inorder(ostream &out, BSNode<T>* n) const{
            if (n != nullptr){
                print_inorder(out, n->left);
                out << n->elem << " ";
                print_inorder(out, n->right);
            }
        }


        T max(BSNode<T>* n) const{
            if (n == nullptr){
                throw runtime_error("Elemento no encontrado");
            }else if (n->right != nullptr){
                return max(n->right);
            }else{
                return n->elem;
            }
        }


        BSNode<T>* remove_max(BSNode<T>* n){
            if (n->right == nullptr){
                BSNode<T>* temp = n->left;
                    delete n;
                nelem--;
                    return temp;
            }else{
                n->right = remove_max(n->right);

                return n;
            }

        }


        BSNode<T>* remove(BSNode<T>* n, T e){
            if (n == nullptr){
                throw runtime_error("No existe el elemento");
            }else if (n->elem < e){
                n->right = remove(n->right, e);
            }else if (n->elem > e){
                n->left = remove(n->left, e);
            }else{
                if (n->left != nullptr && n->right != nullptr){
                    n->elem = max(n->left);
                    n->left = remove_max(n->left);
                }else{
                    BSNode<T>* temp = n;
                    n = (n->left != nullptr) ? n->left : n->right;
                    delete temp;
                    nelem--;
                        }
                }
                return n;
        }



        //elimina en cascada
        void delete_cascade(BSNode<T>* n){
            if (n != nullptr){
                delete_cascade(n->left);
                delete_cascade(n->right);
                delete n;
        }
    }

    public:

        //Constructor
        BSTree():nelem{0}, root {nullptr} {}


        //devuelve nelem
        int size() const{
            return nelem;
        }

        //Busqueda de elementos
        T search(T e) const{

            BSNode<T> *node=search(root, e);

            return node->elem;
        }

        //Operador de interfaz de search
        T operator[](T e) const{
            return search(e);
        }

        //Inserccion de elementos
        void insert(T e){
            root=insert(root, e);
        }

        //Recorrido e impresión de arbol
        friend ostream& operator<<(ostream &out, const BSTree<T> &bst){

            bst.print_inorder(out, bst.root);

            return out;

        }

        //Eliminacion de elementos
        void remove(T e){
            root=remove(root, e);
        }

        //Destructor
        ~BSTree(){
            delete_cascade(root);

        }




};

#endif
