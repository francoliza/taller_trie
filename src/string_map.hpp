
template <typename T>
string_map<T>::string_map(){
    // COMPLETAR
    raiz = NULL;
    _size = 0;
}
template <typename T>
string_map<T>::Nodo::Nodo() {

    for(unsigned i = 0; i < 256; i++){
        raiz->siguientes[i] = NULL;
        (*raiz->siguientes[i])->significado = NULL;
    }

}


template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR

}


template <typename T>
int string_map<T>::count(const string& clave) const{
    // COMPLETAR
    //si esta definida el significado de la clave devuelve 1 y sino 0

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
}

template <typename T>
bool string_map<T>::empty() const{
    // COMPLETAR

    //if(raiz->siguientes == NULL)
    //    return false;
    //else
    //    return true;
}