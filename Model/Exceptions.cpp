//
// Created by mauri on 22/10/2023.
//

#include "Exceptions.h"
Exceptions::Exceptions(char m)
{
    motivo = m;
}

const char* Exceptions::what() const throw()
{
    switch (motivo) {
        case 'B': return "\x1B[31m ERROR, Silla bloqueada \x1B[37m";
        case 'O': return "\x1B[31m ERROR, Silla ocupada \x1B[37m";
        case 'f': return "\x1B[31m ERROR, de fecha, sintaxis: dd/mm/aa  \x1B[37m";
        case 'h': return "\x1B[31m ERROR, de hora, sintaxis: h:m  \x1B[37m";
        case 'L': return "\x1B[31m ERROR, de lista, esa id no existe  \x1B[37m";
        case 'i': return "\x1B[31m ERROR De int, por favor solo coloca numeros \x1B[37m";
        case 's': return "\x1B[31m ERROR De string, intenta no dejar el espacio en blanco \x1B[37m";
        case 'p': return "\x1B[31m ERROR digite unicamente valores numericos \x1B[37m";
        case 'I': return "\x1B[31m ERROR esa ID no existe \x1B[37m";
        case 'n': return "\x1B[31m ERROR NO DEBERIAS ESTAR AQUI\x1B[37m";
        case 'z': return "\x1B[31m ERROR Ingresa solo valores numericos  \x1B[37m";
        default: return "\x1B[31m ERROR DESCONOCIDO \x1B[37m";
    }
}
