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
    // COMPLETAR
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR

    if(raiz == NULL){
        raiz = new Nodo();
    }
    bool flag = false;
    Nodo* aux = raiz;

    int longClave = clave.size();
    int nombre;

    for (int i = 0; i < longClave; ++i) {
        nombre = int(clave[i]);
        if (aux->siguientes[nombre] == NULL) {
            aux->siguientes[nombre] = new Nodo();
        }
        aux = aux->siguientes[nombre];
    }

    if(aux->significado == NULL){
        aux->significado = new T();
        _size++;
    }

    return *(aux->significado);
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    // COMPLETAR+


    if(raiz == NULL)
        return 0;

    int longClave = clave.size();
    int nombre;
    Nodo* aux = raiz;

    for (int i = 0; i < longClave; ++i) {
        nombre = int(clave[i]);
        if(aux->siguientes[nombre] != NULL){
            aux = aux->siguientes[nombre];
        } else{
            return 0;
        }
    }

    if(aux->significado != NULL)
        return 1;
    else
        return 0;
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

    if(count(clave) == 1){
        int longClave = clave.size();
        int nombre;
        Nodo* aux = raiz;

        for (int i = 0; i < longClave; ++i) {
            nombre = int(clave[i]);
            if(aux->siguientes[nombre] == NULL){
                return;
            }else{
                aux = aux->siguientes[nombre]; //solo avanzamos
            }
        }

        delete aux->significado;
        aux->significado = NULL;
    }
}

template <typename T>
int string_map<T>::size() const{
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