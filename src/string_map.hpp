#include "string_map.h"

template<typename T>
string_map<T>::string_map() {
    // COMPLETAR
    raiz = NULL;
    _size = 0;
}

template<typename T>
string_map<T>::Nodo::Nodo() {
    siguientes = vector<Nodo *>(256, NULL);
    significado = NULL;
}


template<typename T>
string_map<T>::string_map(const string_map<T> &aCopiar)
        : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template<typename T>
string_map<T> &string_map<T>::operator=(const string_map<T> &d) {

    return *this;
}

template<typename T>
string_map<T>::~string_map() {
    // COMPLETAR
}

template<typename T>
T &string_map<T>::operator[](const string &clave) {
    // COMPLETAR

    if (raiz == NULL)
        raiz = new Nodo();

    Nodo *aux = raiz;
    int longClave = clave.size();
    int posicion;

    for (int i = 0; i < longClave; ++i) {
        posicion = int(clave[i]);
        if (aux->siguientes[posicion] == NULL) {
            aux->siguientes[posicion] = new Nodo();
        }
        aux = aux->siguientes[posicion];
    }

    if (aux->significado == NULL) {
        aux->significado = new T();
        _size++;
    }

    return *(aux->significado);
}


template<typename T>
int string_map<T>::count(const string &clave) const {
    // COMPLETAR+
    if (raiz == NULL)
        return 0;

    int count = 0;
    int longClave = clave.size();
    int nombre;
    Nodo *aux = raiz;

    for (int i = 0; i < longClave; ++i) {
        nombre = int(clave[i]);
        if (aux->siguientes[nombre] != NULL) {
            count++;
            aux = aux->siguientes[nombre];
        } else {
            return 0;
        }
    }

    if (aux->significado != NULL && count == longClave)
        return 1;
    else
        return 0;
}

template<typename T>
const T &string_map<T>::at(const string &clave) const {
    // COMPLETAR
}

template<typename T>
T &string_map<T>::at(const string &clave) {
    // COMPLETAR
}

template<typename T>
void string_map<T>::erase(const string &clave) {
    // COMPLETAR

    if (count(clave) == 1) { //ya sabemos que esta definida!
        int longClave = clave.size();
        int pos;
        Nodo *aux = raiz;

        if (_size == 1) {
            raiz = NULL;
            delete raiz; //aca si es una unica sola clave la borra
            _size = 0;
            //esta bien
        } else {
            //hay 2 casos mas, borrar una palabra que este en el medio o que el sigficado sea una hoja
            int count = 0;
            int ultimaSeparacion = 0;
            int ultimoSignificado = 0;

            for (int i = 0; i < longClave; ++i) {
                pos = int(clave[i]);
                if (aux->siguientes[pos] != NULL) {
                    for (int j = 0; j < 256; ++j) {
                        if (j != pos && aux->siguientes[j] != NULL) {
                            ultimaSeparacion = i; //no dice si hay mas nodos en ese nivel, o sea hermanos
                        }
                    }

                    aux = aux->siguientes[pos];
                    if (aux->significado != NULL && (i != longClave - 1)) {
                        ultimoSignificado = i;
                    }//con esa condicion nos aseguramos que no sea el ULTIMO EN CUESTION, pero es el ultimo antes del ultimo real
                }


            } //aux llego al final

            for (int j = 0; j < 256; ++j) {
                if (aux->siguientes[j] != NULL) {
                    count++;
                }
            }// se fija que no tenga mas hijos.
            //con ultimoSignificado nos sirve si el que queremos borrar es la hoja!

            Nodo* aBorrar = raiz;
            if (count == 0) {
                //hay que fijarse tuvo una separacion antes
                //vamos a tratar de resolver un caso, el de que borramos la palabra al final

                if(ultimaSeparacion != 0){
                    for (int i = 0; i < ultimaSeparacion; ++i) {
                        pos = int(clave[i]);
                        aBorrar = aBorrar->siguientes[pos];
                    }
                    delete aBorrar->siguientes[int(clave[ultimaSeparacion])];
                    aBorrar->siguientes[int(clave[ultimaSeparacion])] = NULL;
                    _size--; //aca hablo de los 2 casos
                }else if(ultimaSeparacion == 0 && ultimoSignificado != 0) {
                    for (int i = 0; i < ultimoSignificado; ++i) {
                        pos = int(clave[i]);
                        aBorrar = aBorrar->siguientes[pos];
                    }
                    delete aBorrar->siguientes[int(clave[ultimoSignificado])];
                    aBorrar->siguientes[int(clave[ultimoSignificado])] = NULL;
                    _size--;
                }else if(ultimaSeparacion == 0 && ultimoSignificado == 0){
                    delete aBorrar->siguientes[int(clave[0])];
                    aBorrar->siguientes[int(clave[0])] = NULL;
                    _size--;
                }

            } else {
                //es decir esta en el medio, solo borra su significado
                delete aux->significado;
                aux->significado = NULL;
                _size--;
                //este caso anda perfecto
            }
        }
    }
}

template<typename T>
int string_map<T>::size() const {
    return _size;
}

template<typename T>
bool string_map<T>::empty() const {
    // COMPLETAR
    if (_size == 0)
        return true;
    else
        return false;
}