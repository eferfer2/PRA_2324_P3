#ifndef DICT_H
#define DICT_H


#include <string>
using namespace std;

template<typename V>

class Dict{


    public:
        // virtual.....=0; usado para crear el molde que se usará posteriormente, así puedes  declarar la funcion sin implementarla//

            virtual void insert(const string& key, V value)=0; //inserta key->value
            virtual V search(const string& key)=0; //Busca el value key
            virtual V remove (const string& key)=0; // Elimna key-> value
            virtual int entries()=0; //Nº de elementos en el dicc
            virtual ~Dict(){};  //Destructor



};

#endif
