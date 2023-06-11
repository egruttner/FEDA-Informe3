#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map> // Hash table
#include "arbolBinarioBusqueda.h"
#include <fstream>
#include "AVLTree.hpp"


using namespace std;

//PARA TOMAR EL TIEMPO
template <typename Func>
long long execution_time_ms(Func function, string tarea) {
  auto start_time = std::chrono::high_resolution_clock::now();
  
  function(tarea);

  auto end_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

void insert_arbol_userid()
{
    

    //LEE ARCHIVO
	ArbolBinarioBusqueda arbol;
	string university, user_id, user_name, number_tweets, friends_count, followers_count, created_at;
    long long id_key, valor_name;

    long cant_registros = 29245;

    //LEE ARCHIVO
    string filename = "datasets/input1/input1.csv";	//TODO -> DINAMICO COMO PARAMETRO
    ifstream file;

    file.open(filename);
    
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    //LEE ENCABEZADO-NO SIRVE
    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');


    AVLTree<string> tree;





	for(int i = 0; i < cant_registros; i++){

        //cout << "i: " << i << " de " << cant_registros << endl;


        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');
/*
        id_key = stoll(user_id, nullptr, 10);
		bool insertado = arbol.insertar(id_key);

		if(insertado)
			cout << id_key << " insertado!" << endl;
		else{
			cout << id_key << " repetido! intente otro valor" << endl;
		}

*/
        tree.insert("renormalizado");

	}

	//arbol.inOrder();
 
    //cout << "BUSCAR:" << arbol.buscar(0) << endl;

    //tree.display();
    cout << tree.size() << endl;
    cout << tree.find("    ") << endl;



    return;
}

//CENTRO DE LLAMADA DE FUNCIONES
void vector_ordena(string tarea)
{
    if (tarea=="insert-arbol-userid") {return insert_arbol_userid(); } 


/*
  if (tarea=="selection") {return selection(A); }
  if (tarea=="quicksort") {return quicksort_llamada(A); }
  if (tarea=="mergesort") {return mergesort_llamada(A); }
  if (tarea=="sortinterno") {return sortinterno(A); }
*/
}

/*

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) {
        valor = val;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

class ArbolBinarioBusqueda {
private:
    Nodo* raiz;

public:
    ArbolBinarioBusqueda() {
        raiz = nullptr;
    }

    void insertar(int valor) {
        if (raiz == nullptr) {
            raiz = new Nodo(valor);
        } else {
            insertarRecursivamente(raiz, valor);
        }
    }

    void insertarRecursivamente(Nodo* nodo, int valor) {
        if (valor < nodo->valor) {
            if (nodo->izquierdo == nullptr) {
                nodo->izquierdo = new Nodo(valor);
            } else {
                insertarRecursivamente(nodo->izquierdo, valor);
            }
        } else {
            if (nodo->derecho == nullptr) {
                nodo->derecho = new Nodo(valor);
            } else {
                insertarRecursivamente(nodo->derecho, valor);
            }
        }
    }

    bool buscar(int valor) {
        return buscarRecursivamente(raiz, valor);
    }

    bool buscarRecursivamente(Nodo* nodo, int valor) {
        if (nodo == nullptr) {
            return false;
        } else if (valor == nodo->valor) {
            return true;
        } else if (valor < nodo->valor) {
            return buscarRecursivamente(nodo->izquierdo, valor);
        } else {
            return buscarRecursivamente(nodo->derecho, valor);
        }
    }
};

void cargarCSVenArbol(const string& nombreArchivo, ArbolBinarioBusqueda& arbol) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string valorStr;
            while (getline(ss, valorStr, ',')) {
                int valor = stoi(valorStr);
                arbol.insertar(valor);
            }
        }
        archivo.close();
        cout << "Archivo CSV cargado en el árbol binario." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

int main() {
    ArbolBinarioBusqueda arbol;
    string nombreArchivo = "datos.csv";
    cargarCSVenArbol(nombreArchivo, arbol);

    // Ejemplo de búsqueda en el árbol
    int valorBuscado = 1;
    bool encontrado = arbol.buscar(valorBuscado);
    if (encontrado) {
        cout << "El valor " << valorBuscado << " está en el árbol." << endl;
    } else {
        cout << "El valor " << valorBuscado << " no está en el árbol." << endl;
    }

    return 0;
}



*/
