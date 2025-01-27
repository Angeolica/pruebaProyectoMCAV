//
// Created by mauri on 22/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_ARCHIVOS_H
#define PRUEBAPROYECTOMCAV_ARCHIVOS_H


#include "Lista.h"
#include <fstream>
#include "dist/json/json.h"

template<class T, class U>
class Archivos {
private:

public:
    Archivos() {}

    virtual ~Archivos() {

    }
    void guardarDatos(T&);
    void cargarDatos(T&);

};

template<class T, class U>
void Archivos<T, U>::guardarDatos(T& lis) {
    ofstream salida ("pureba.txt");
    //Nodo<T>* temp = _first;
    T* tempT = nullptr;
    Json::StreamWriterBuilder builder;
    builder["commentStyle"]= "None";
    builder["identation"]= "    ";

    std::unique_ptr<Json::StreamWriter> writer (builder.newStreamWriter());//construyo un flujo de datos para escritura
    //Json::Value event;
    Json:: Value arreglo(Json::arrayValue);
    for (int i = 0; i <lis.counter() ; ++i)
    {
        arreglo.append(((lis[i]).salvaDatos(lis[i])));

    }
    writer->write(arreglo,&salida );
    salida.close();
}

template<class T, class U>
void Archivos<T, U>::cargarDatos(T& lis) {
    ifstream entrada ("pureba.txt"); // hay que ver como hacer una validacion que vea si esta vacio
    U* temp = nullptr;
    Json::Value objetos;
    Json::Reader reader;
    reader.parse(entrada, objetos);
    for (int i = 0; i < objetos.size(); ++i) {
        if(temp->cargaDatos(objetos[i]) != NULL){
            temp = temp->cargaDatos(objetos[i]);
            lis.insertEnd(temp);
        }
    }
    entrada.close();
    //return lis;
}



#endif //PRUEBAPROYECTOMCAV_ARCHIVOS_H
