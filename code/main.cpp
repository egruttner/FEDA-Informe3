#include <iostream>
#include <algorithm>
#include <chrono>
#include <string.h>
#include <fstream>
#include "AVLTree.hpp"
#include "clases_hash.h"

using namespace std;

//CLASES
//EN clases_hash.h

//VARIABLES
string university, user_id, user_name, number_tweets, friends_count, followers_count, created_at;

//ESTRUCTURAS A UTILIZAR
AVLTree<string> tree_string;
AVLTree<long> tree_long;
HashTableAbiertoUser_Id hashAbiertoUser_Id;
HashTableAbiertoUser_Name hashAbiertoUser_Name;
HashTableCerradoUser_Id hashCerradoUser_Id;
HashTableCerradoUser_Name hashCerradoUser_Name;

//PARA TOMAR EL TIEMPO
template <typename Func>
long long execution_time_ms(Func function, string tarea, int id_dataset) 
{
  auto start_time = std::chrono::high_resolution_clock::now();
  
  function(tarea, id_dataset);

  auto end_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

// PROCESOS
//1 - insert_arbol_userid
void insert_arbol_user_id(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    //INPUT
    string filename = "datasets/input/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        tree_long.insert(stol(user_id));

    }

    return;
}

//2 - insert_arbol_user_name
void insert_arbol_user_name(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    //INPUT
    string filename = "datasets/input/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        tree_string.insert(user_name);

    }

    return;
}

//3 - search_in_arbol_user_id
void search_in_arbol_user_id(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    //INPUT
    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');


    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        tree_long.find(stol(user_id));
        cout << user_id << " ENCONTRADO" << endl;

    }

    return;
}

//4 - search_in_arbol_user_name
void search_in_arbol_user_name(int id_dataset)
{

    ifstream file; //ARCHIVO DE ENTRADA

    //INPUT
    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        tree_string.find(user_name);
        cout << user_name << " ENCONTRADO" << endl;

    }

    return;
}

//5 - search_out_arbol_user_id
void search_out_arbol_user_id(int id_dataset)
{

    ifstream file; //ARCHIVO DE ENTRADA

    //INPUT
    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    long aux;

    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        aux = stol(user_id);
        aux++;
        cout << aux << tree_long.find(aux) << endl;

    }

    return;
}

//6 - search_out_arbol_user_name
void search_out_arbol_user_name(int id_dataset)
{

    ifstream file; //ARCHIVO DE ENTRADA

    //INPUT
    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        user_name = user_name + "X";

        cout << user_name << tree_string.find(user_name) << endl;

    }

    return;
}

//7 - insert_hash_abierto_user_id
void insert_hash_abierto_user_id(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    //INPUT
    string filename = "datasets/input/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        hashAbiertoUser_Id.insertItem(stol(user_id), user_name);

    }

    //hashAbiertoUser_Id.displayTable();

    return;
}

//8 - insert_hash_abierto_user_name
void insert_hash_abierto_user_name(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    //INPUT
    string filename = "datasets/input/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        hashAbiertoUser_Name.insertItem(user_name,stol(user_id));

    }

    //hashAbiertoUser_Name.displayTable();

    return;
}

//9 - search_in_hash_abierto_user_id
void search_in_hash_abierto_user_id(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    long aux;
    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        aux = stol(user_id);
        aux++;
        hashAbiertoUser_Id.searchItem(aux);
        //cout << aux << hashAbiertoUser_Id.searchItem(aux) << endl;

    }
    return;
}

//10 - search_in_hash_abierto_user_name
void search_in_hash_abierto_user_name(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    long aux;

    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        hashAbiertoUser_Name.searchItem(user_name);

        //cout << user_name << hashAbiertoUser_Name.searchItem(user_name) << endl;
    }

    
    return;
}

//11 - search_out_hash_abierto_user_id
void search_out_hash_abierto_user_id(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    long aux;
    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        aux = stol(user_id);
        aux++;

        hashAbiertoUser_Id.searchItem(aux);

        //cout << aux << hashAbiertoUser_Id.searchItem(aux) << endl;

    }
    return;
}

//12 - search_out_hash_abierto_user_name
void search_out_hash_abierto_user_name(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        user_name = user_name + "X";

        hashAbiertoUser_Name.searchItem(user_name);

        //cout << user_name << hashAbiertoUser_Name.searchItem(user_name) << endl;

    }
    return;
}

//13 - insert_hash_cerrado_user_id
void insert_hash_cerrado_user_id(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    //INPUT
    string filename = "datasets/input/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        hashCerradoUser_Id.insertItem(stol(user_id), user_name);

    }

    //hashCerradoUser_Id.displayTable();

    return;
}

//14 - insert_hash_cerrado_user_name
void insert_hash_cerrado_user_name(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    //INPUT
    string filename = "datasets/input/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        hashCerradoUser_Name.insertItem(user_name,stol(user_id));

    }

   //hashCerradoUser_Name.displayTable();

    return;
}

//15 - search_in_hash_cerrado_user_id
void search_in_hash_cerrado_user_id(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    long aux;
    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        aux = stol(user_id);
        aux++;
        hashCerradoUser_Id.searchItem(aux);

        //cout << aux << hashCerradoUser_Id.searchItem(aux) << endl;

    }
    return;
}

//16 - search_in_hash_cerrado_user_name
void search_in_hash_cerrado_user_name(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    long aux;

    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        hashCerradoUser_Name.searchItem(user_name);

        //cout << user_name << hashCerradoUser_Name.searchItem(user_name) << endl;
    }

    
    return;
}

//17 - search_out_hash_cerrado_user_id
void search_out_hash_cerrado_user_id(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    long aux;
    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        aux = stol(user_id);
        aux++;
        hashCerradoUser_Id.searchItem(aux); 

        //cout << aux << hashCerradoUser_Id.searchItem(aux) << endl;

    }
    return;
}

//18 - search_out_hash_cerrado_user_name
void search_out_hash_cerrado_user_name(int id_dataset)
{
    ifstream file; //ARCHIVO DE ENTRADA

    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    getline(file, university, ';');
    getline(file, user_id, ';');
    getline(file, user_name, ';');
    getline(file, number_tweets, ';');
    getline(file, friends_count, ';');
    getline(file, followers_count, ';');
    getline(file, created_at, '\n');

    while (!file.eof()) {

        getline(file, university, ';');
        getline(file, user_id, ';');
        getline(file, user_name, ';');
        getline(file, number_tweets, ';');
        getline(file, friends_count, ';');
        getline(file, followers_count, ';');
        getline(file, created_at, '\n');

        user_name = user_name + "X";
        hashCerradoUser_Name.searchItem(user_name);

        //cout << user_name << hashCerradoUser_Name.searchItem(user_name) << endl;

    }
    return;
}


//CENTRO DE LLAMADA DE FUNCIONES
void centro_tareas(string tarea, int id_dataset)
{
    //ARBOL
    if (tarea=="insert_arbol_user_id") {return insert_arbol_user_id(id_dataset); } 
    if (tarea=="insert_arbol_user_name") {return insert_arbol_user_name(id_dataset); } 
    if (tarea=="search_in_arbol_user_id") {return search_in_arbol_user_id(id_dataset); } 
    if (tarea=="search_in_arbol_user_name") {return search_in_arbol_user_name(id_dataset); } 
    if (tarea=="search_out_arbol_user_id") {return search_out_arbol_user_id(id_dataset); } 
    if (tarea=="search_out_arbol_user_name") {return search_out_arbol_user_name(id_dataset); } 

    //HASH ABIERTO
    if (tarea=="insert_hash_abierto_user_id") {return insert_hash_abierto_user_id(id_dataset); } 
    if (tarea=="insert_hash_abierto_user_name") {return insert_hash_abierto_user_name(id_dataset); } 
    if (tarea=="search_in_hash_abierto_user_id") {return search_in_hash_abierto_user_id(id_dataset); } 
    if (tarea=="search_in_hash_abierto_user_name") {return search_in_hash_abierto_user_name(id_dataset); } 
    if (tarea=="search_out_hash_abierto_user_id") {return search_out_hash_abierto_user_id(id_dataset); } 
    if (tarea=="search_out_hash_abierto_user_name") {return search_out_hash_abierto_user_name(id_dataset); } 

    //HASH CERRADO
    if (tarea=="insert_hash_cerrado_user_id") {return insert_hash_cerrado_user_id(id_dataset); } 
    if (tarea=="insert_hash_cerrado_user_name") {return insert_hash_cerrado_user_name(id_dataset); } 
    if (tarea=="search_in_hash_cerrado_user_id") {return search_in_hash_cerrado_user_id(id_dataset); } 
    if (tarea=="search_in_hash_cerrado_user_name") {return search_in_hash_cerrado_user_name(id_dataset); } 
    if (tarea=="search_out_hash_cerrado_user_id") {return search_out_hash_cerrado_user_id(id_dataset); } 
    if (tarea=="search_out_hash_cerrado_user_name") {return search_out_hash_cerrado_user_name(id_dataset); } 

}


//BLOQUE PRINCIPAL
int main(int argv, char* argc[]) {
  srand(time(NULL)); 

  int n; //tamaño muestras (1000, 5000, 10000, 15000 y 20000)
  int id_proceso;

  int numero_de_experimentos;
  string dir_csv;
  string tarea_seleccionada;
  string nombre_archivo_salida;

  dir_csv = "csv/";

  cout<<"INICIO"<<endl;


  //TAREAS DE ACUERDO A PARÁMETRO ENVIADO AL PROGRAMA
  id_proceso=atoi(argc[1]);
  switch(id_proceso){
    //LAS TAREAS DE BÚSQUEDA NECESITAN QUE ESTÉ CARGADA CON DATOS LA ESTRUCTURA
    //ARBOL
    case 1: tarea_seleccionada = "insert_arbol_user_id"; break;
    case 2: tarea_seleccionada = "insert_arbol_user_name"; break;
    case 3: tarea_seleccionada = "search_in_arbol_user_id";
            insert_arbol_user_id(5);
            break;
    case 4: tarea_seleccionada = "search_in_arbol_user_name";
            insert_arbol_user_name(5);
            break;
    case 5: tarea_seleccionada = "search_out_arbol_user_id";
            insert_arbol_user_id(5);
            break;
    case 6: tarea_seleccionada = "search_out_arbol_user_name";
            insert_arbol_user_name(5);
            break;

    //HASH ABIERTO
    case 7: tarea_seleccionada = "insert_hash_abierto_user_id"; break;
    case 8: tarea_seleccionada = "insert_hash_abierto_user_name"; break;
    case 9: tarea_seleccionada = "search_in_hash_abierto_user_id";
            insert_hash_abierto_user_id(5);
            break;
    case 10: tarea_seleccionada = "search_in_hash_abierto_user_name";
            insert_hash_abierto_user_name(5);
            break;
    case 11: tarea_seleccionada = "search_out_hash_abierto_user_id";
            insert_hash_abierto_user_id(5);
            break;
    case 12: tarea_seleccionada = "search_out_hash_abierto_user_name"; 
            insert_hash_abierto_user_name(5);
            break;

    //HASH CERRADO
    case 13: tarea_seleccionada = "insert_hash_cerrado_user_id"; break;
    case 14: tarea_seleccionada = "insert_hash_cerrado_user_name"; break;
    case 15: tarea_seleccionada = "search_in_hash_cerrado_user_id";
            insert_hash_cerrado_user_id(5);
            break;
    case 16: tarea_seleccionada = "search_in_hash_cerrado_user_name";
            insert_hash_cerrado_user_name(5);
            break;
    case 17: tarea_seleccionada = "search_out_hash_cerrado_user_id";
            insert_hash_cerrado_user_id(5);
            break;;
    case 18: tarea_seleccionada = "search_out_hash_cerrado_user_name";
            insert_hash_cerrado_user_name(5);
            break;

    default: tarea_seleccionada = ""; break;
  }

  //SI ENTRA CON PARÁMETROS, REALIZA EL TEST
  if((argv > 2) && (strcmp(argc[2],"--test") == 0)){

    int id_dataset = atoi(argc[4]);
    switch(atoi(argc[4]))
    {
      case 1: n = 1000; break;
      case 2: n = 5000; break;
      case 3: n = 10000; break;
      case 4: n = 15000; break;
      case 5: n = 20000; break;

      default: n = 0; break;
    }

    //SI SON PROCESOS DE BUSQUEDA USAN OTROS RANGOS DE DATASET
    if (
        (id_proceso>2 && id_proceso<7) ||
        (id_proceso>8 && id_proceso<13) ||
        (id_proceso>14 && id_proceso<19) 
        )
    {
      switch(atoi(argc[4]))
      {
        case 1: n = 100; break;
        case 2: n = 200; break;
        case 3: n = 300; break;
        case 4: n = 400; break;
        case 5: n = 500; break;

        default: n = 0; break;
      }
    }

    cout<<"Tarea seleccionada: "<< tarea_seleccionada<<endl;

    nombre_archivo_salida = dir_csv + tarea_seleccionada + "_results.csv";
    ofstream outfile(nombre_archivo_salida,std::ios::app);

    double mm_total_time = 0;
    int numero_de_experimentos=10;
    for(int j = 0; j < numero_de_experimentos; j++){ 

        long long single_execution_time = execution_time_ms(centro_tareas, tarea_seleccionada, id_dataset);
        mm_total_time += single_execution_time;
      
    }
    double mm_avg_time = mm_total_time / numero_de_experimentos;
    outfile << n << "," << mm_avg_time <<endl;
    outfile.close(); 
    
    return 0;
  }
  else
  //SINO CREA EL ENCABEZADO PARA GUARDAR EL CSV
  {
    nombre_archivo_salida = dir_csv + tarea_seleccionada + "_results.csv";
    ofstream outfile(nombre_archivo_salida);
    outfile << "Tamaño muestra,Tiempo[ms]\n";

    return 0;
  }


}

