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
    // COMPLETAR
}

template<typename T>
string_map<T>::~string_map() {
    // COMPLETAR
}

template<typename T>
T &string_map<T>::operator[](const string &clave) {
    // COMPLETAR

    if (raiz == NULL) {
        raiz = new Nodo();
    }
    bool flag = false;
    Nodo *aux = raiz;

    int longClave = clave.size();
    int nombre;

    for (int i = 0; i < longClave; ++i) {
        nombre = int(clave[i]);
        if (aux->siguientes[nombre] == NULL) {
            aux->siguientes[nombre] = new Nodo();
        }
        aux = aux->siguientes[nombre];
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
    int borrarDesde = 0;

    if (count(clave) == 1) { //ya sabemos que esta definida!
        int longClave = clave.size();
        int pos;
        Nodo *aux = raiz;

        if (longClave == 1) {
            if (_size == 1) {
                delete raiz;
                raiz = NULL;
            } else {
                pos = int(clave[0]);
                delete (aux->siguientes[pos])->significado;
                (aux->siguientes[pos])->significado = NULL;
                //borro el significado y punto
            }
            _size--;
            //esta bien
        } else {
            //hay 2 casos mas, borrar una palabra que este en el medio o que el sigficado sea una hoja
            int count = 0;
            int ultimaSeparacion = 0;
            int ultimoSignificado = 0;

            for (int i = 0; i < longClave; ++i) {
                pos = int(clave[i]);
                if (aux->siguientes[pos] != NULL) {
                    for (int j = 0; j < 256 && j != pos; ++j) {
                        if(aux->siguientes[j] != NULL){
                            ultimaSeparacion = i; //no dice si hay mas nodos en ese nivel, o sea hermanos
                        }
                    }

                    aux = aux->siguientes[pos];
                    if (aux->significado != NULL && (i != longClave - 1)) {
                        ultimoSignificado = i;
                    }//con esa condicion nos aseguramos que no sea el ULTIMO EN CUESTION, pero es el ultimo antes del ultimo real
                }


            } //aux llego al final!

            /*Nodo* otraVez = raiz;

            for (int k = 0; k < longClave; ++k) {
                pos = int(clave[k]);
            }
             */

            //fijemosnó si tiene mas hijos o no

            for (int j = 0; j < 256; ++j) {
                if (aux->siguientes[j] != NULL) {
                    count++;
                }
            }//aca se fija si es hoja o no aux!
            //con ultimoSignificado nos sirve si el que queremos borrar es la hoja!

            if (count == 0) {
                //es decir es hoja
                //aca necesitamos el borrar desde
                //estamos en el ultimo NODO

                Nodo *aBorrar = raiz;
                if (ultimoSignificado == 0) {
                    //es decir no hay nadie en el medio pero se puede seperar la cosa
                    //en este caso es donde tengo que ver que si hay alguno con otro hijo!
                    //me importa la ultima bifurcacion!
                    if(ultimaSeparacion == 0){
                        delete aBorrar->siguientes[int(clave[0])];
                        aBorrar->siguientes = vector<Nodo *>(256,NULL);
                        _size--;
                    }else{
                        for (int i = 0; i <= ultimaSeparacion; ++i) {
                            pos = int(clave[i]);
                            aBorrar = aBorrar->siguientes[pos];
                        }
                        //delete aBorrar;
                        aBorrar->siguientes = vector<Nodo*>(256,NULL);
                        _size--;
                    }
                } else {
                    for (int i = 0; i <= ultimoSignificado; ++i) {
                        pos = int(clave[i]);
                        aBorrar = aBorrar->siguientes[pos];
                    }
                    delete aBorrar;
                    aBorrar->siguientes = vector<Nodo *>(256, NULL);
                    _size--;
                }
            } else {
                //es decir esta en el medio, solo borra su significado
                delete aux->significado;
                aux->significado = NULL;
                _size--;
                //y listo el pollo
            }
        }
    }

    /*if (count(clave) == 1) {
        int longClave = clave.size();
        int nombre;
        Nodo *aux = raiz;

        if (longClave == 1) {
            nombre = int(clave[0]);
            if(aux->siguientes[nombre] != NULL){
                //hay que preguntarse si tiene mas hijos
                int count = 0;
                for (int i = 0; i < 256 ; ++i) {
                    if((aux->siguientes[nombre])->siguientes[i] != NULL){
                        count++;
                    }
                }
                if(count > 1){
                    delete aux->significado;
                }
            }
        } else {
            for (int i = 0; i < longClave; ++i) {
                nombre = int(clave[i]);
                if (aux->siguientes[nombre] == NULL) {
                    return;
                } else {
                    for (int j = 0; j < 256 && (i != longClave - 1) && j != nombre && j != int(clave[i + 1]); ++j) {
                        if ((aux->siguientes[nombre])->siguientes[j] != NULL) {
                            borrarDesde = i; //aca se fija si tiene mas de un hijo y si es asi marcamos desde donde borramos
                        }
                    }
                    aux = aux->siguientes[nombre]; //solo avanzamos
                }
            }
            delete aux->significado;
        }

        Nodo *aBorrar = raiz;

        for (int i = 0; i < longClave; ++i) {
            nombre = int(clave[i]);
            if (borrarDesde == 0) {
                delete raiz;
                raiz = NULL;
            } else if (i < borrarDesde) {
                aBorrar = aBorrar->siguientes[nombre];
            } else {
                delete aBorrar;
            }
        }

        --_size;

        //aux->significado = NULL;
    }*/
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

template<class T>
void string_map<T>::deleteRecursivo(string_map<T>::Nodo *aBorrar, const string &clave, int i) {
    if (aBorrar != NULL) {
        return;
    } else { //ya le tenemos que pasar a borrar la posicion 0
        int pos = int(clave[i]);
        deleteRecursivo(aBorrar->siguientes[pos], clave, i + 1);
        delete aBorrar;
        aBorrar->significado = NULL;
        aBorrar->siguientes = vector<Nodo *>(256, NULL);
    }

}