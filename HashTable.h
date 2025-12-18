#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2324_P1/ListLinked.h"

template <typename V>

class HashTable: public Dict<V>{

    private:

        //Atributos
        int n;  //Numero de elementos en la tabla
        int max;    //Numero maximo de elementos posibles en la tabla
        ListLinked<TableEntry<V>> *table;   //Lista Enlazada

        //Funcion Hash
        int h(const string &key){

            int sum=0;
            for(int i=0; i<key.length();i++){

                //Multiplicamos por 31 para evitar más colisiones con otros value. Se usa 31 por ser un número primo pequeño
                sum=sum*31+key[i];

            }
            return sum%max;
        }

    public:

        //Constructor
        HashTable(int size): n{0}, max {size}, table{new ListLinked<TableEntry<V>>[max]} {}

        //destructor

        ~HashTable(){
            delete[] table;

        }

        //Devuelve el tamaño maximo posible de la tabla
        int capacity(){
            return max;
        }

        //Imprime el contenido de la tabla
        friend ostream& operator<<(ostream &out, const HashTable<V> &th){

            out<<"HashTable [Número de elementos:"<<th.n<<", capacidad:"<<th.max<<"]"<<endl<<endl;

            out<<"Contenido de cubetas:"<<endl<<endl;

            for(int i=0; i<th.max;i++){
                out<<"Cubeta "<<i<<"-----"<<"List=>"<<th.table[i]<<endl;

            }

            return out;
        }

        //Devuelve valor correspondiente de key
        V operator[](const string &key){

            return search(key);
        }

    //Metodos heredados de Dict


     void insert(const string& key, V value) override{

         //Adaptamos key con la funcion h
         int pos = h(key);
         //Creamos una clase te que tiene el par value y su key
         TableEntry<V>  te(key,value);

         //Comprobamos si te está ya en la tabla con la funcion search, devuelve -1 si sí que está

         if(table[pos].search(te)!=-1){
             throw runtime_error("Clave ya existe");

        }

        //Llamamos a la funcion append que añade el te al final
         table[pos].append(te);
         n++;

    }

     V search(const string& key) override {

         int pos=h(key);

         TableEntry<V>  te(key);
         int num=table[pos].search(te);
         if(num==-1){
             throw  runtime_error("Clave no encotrada");
        }

        //Para obtener el valor, debemos poner la coordenada de la tabla (pos) y la cooredenada del te encontrado (num)
         return table[pos].get(num).value;

    }

     V remove (const string& key) override {
         int pos=h(key);

         TableEntry<V> te(key);
         int num=table[pos].search(te);
         if(num==-1){
             throw runtime_error ("Clave no encontrada");
        }
        V deleted_value= table[pos].get(num).value;

        table[pos].remove(num);
        n--;

        return deleted_value;
    }

     int entries() override {
         return n;
    }


};

#endif
