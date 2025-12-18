#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <ostream>
#include <string>
using namespace std;

template <typename V>

class TableEntry {
    public:
        //Atributos
        string key;
        V value;

        //Constructores
        /*Poner : key{key}, value{value} {} es lo mismo que
         this->key = key;
         this->value = value;
         Inicializa las variables, es importante el {} del final */

        TableEntry(string key, V value): key{key}, value{value} {}
        TableEntry(string key): key{key} {}
        TableEntry(): key {""} {}

        //Sobrecarga de operadores

        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
            if(te1.key==te2.key){
                return true;
            }else{
            return false;
            }
        }

        friend bool operator!=(const TableEntry<V> &te1,const TableEntry<V> &te2 ){
            if(te1.key!=te2.key){
                return true;
            }else{
                return false;
            }

        }

        friend ostream& operator<<(ostream &out, const TableEntry<V> &te){
            out<<"("<<te.key<<"->"<<te.value<<")"; return out;

        }

};



#endif
