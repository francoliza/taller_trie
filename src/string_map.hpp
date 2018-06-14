
template <typename T>
string_map<T>::string_map(){
    // COMPLETAR
    raiz = NULL;
    _size = 0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    //asigna el significado

}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
    //nos devuelve el signidicado dada la clave, o sea es OBTENER

    int count = 0;

    if(raiz == NULL){
        raiz = new Nodo();
    }

    Nodo* aux = raiz;

    for (int i = 0; i < clave.size(); i++) {
        int nombre = int(clave[i]);
        if (aux->siguientes[nombre] == NULL) {
            aux->siguientes[nombre] = new Nodo();
            count++;
        }

    }

    if(count > 0){
        _size++;
        aux->significado = new T();
    }

    return *(aux->significado);
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    // COMPLETAR
    //si esta definida el significado de la clave devuelve 1 y sino 0

    if(raiz == NULL){
        return 0;
    }

    Nodo* aux = raiz;

    for (int i = 0; i < clave.size(); i++) {
        int nombre = int(clave[i]);

        if (aux->siguientes[nombre] == NULL) {
            return 0;
        }
    }

    if(aux->significado != NULL){
        return 1;
    }else{
        return 0;
    }

}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    // COMPLETAR
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    // COMPLETAR
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
}

template <typename T>
int string_map<T>::size() const{
    // COMPLETAR

    return _size;

}

template <typename T>
bool string_map<T>::empty() const{
    // COMPLETAR
    if(_size == 0)
        return true;
    else
        return false;
}