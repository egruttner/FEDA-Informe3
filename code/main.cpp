#include <iostream>
#include <algorithm>
#include <chrono>
#include <string.h>
#include <fstream>
#include "AVLTree.hpp"

using namespace std;

string university, user_id, user_name, number_tweets, friends_count, followers_count, created_at;

AVLTree<string> tree_string;
AVLTree<long> tree_long;

//PARA TOMAR EL TIEMPO
template <typename Func>
long long execution_time_ms(Func function, string tarea, int id_dataset) {
  auto start_time = std::chrono::high_resolution_clock::now();
  
  function(tarea, id_dataset);

  auto end_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
}

// PROCESOS
// 1 - insert_arbol_userid
void insert_arbol_user_id(int id_dataset)
{
    //INPUT
    string filename = "datasets/input/input" + to_string(id_dataset) + ".csv";
    ifstream file;

    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    //LEE ENCABEZADO QUE NO SIRVE
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


// 2 - insert_arbol_user_name
void insert_arbol_user_name(int id_dataset)
{
    //INPUT
    string filename = "datasets/input/input" + to_string(id_dataset) + ".csv";
    ifstream file;

    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    //LEE ENCABEZADO QUE NO SIRVE
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

// 3 - search_in_arbol_user_id
void search_in_arbol_user_id(int id_dataset)
{
    //INPUT
    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    ifstream file;

    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    //LEE ENCABEZADO QUE NO SIRVE
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


// 4 - search_in_arbol_user_name
void search_in_arbol_user_name(int id_dataset)
{
    //INPUT
    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    ifstream file;

    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    //LEE ENCABEZADO QUE NO SIRVE
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



// 5 - search_out_arbol_user_id
void search_out_arbol_user_id(int id_dataset)
{
    //INPUT
    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    ifstream file;

    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    //LEE ENCABEZADO QUE NO SIRVE
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
        cout << user_name << tree_long.find(aux) << endl;

    }

    return;
}



// 6 - search_out_arbol_user_name
void search_out_arbol_user_name(int id_dataset)
{
    //INPUT
    string filename = "datasets/search_in/input" + to_string(id_dataset) + ".csv";
    ifstream file;

    file.open(filename);
    if(!file.is_open()){
        cout << "ERROR!!! el archivo " << filename << " no se pudo abrir\n";
        return;
    }

    //LEE ENCABEZADO QUE NO SIRVE
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



//CENTRO DE LLAMADA DE FUNCIONES
void centro_tareas(string tarea, int id_dataset)
{
    if (tarea=="insert_arbol_user_id") {return insert_arbol_user_id(id_dataset); } 
    if (tarea=="insert_arbol_user_name") {return insert_arbol_user_name(id_dataset); } 

    if (tarea=="search_in_arbol_user_id") {return search_in_arbol_user_id(id_dataset); } 
    if (tarea=="search_in_arbol_user_name") {return search_in_arbol_user_name(id_dataset); } 

    if (tarea=="search_out_arbol_user_id") {return search_out_arbol_user_id(id_dataset); } 
    if (tarea=="search_out_arbol_user_name") {return search_out_arbol_user_name(id_dataset); } 


    //if (tarea=="test-hashing") {return test_hashing();


}







//BLOQUE PRINCIPAL
int main(int argv, char* argc[]) {
  srand(time(NULL)); 

  int n; //tamaño muestras (1000, 5000, 10000, 15000 y total)
  int id_proceso;

  int numero_de_experimentos;
  string dir_csv;
  string tarea_seleccionada;
  string nombre_archivo_salida;

  dir_csv = "csv/";

  cout<<"INICIO"<<endl;

  //TIPOS DE PRUEBAS

  id_proceso=atoi(argc[1]);

  switch(id_proceso){

    case 1: tarea_seleccionada = "insert_arbol_user_id"; break;
    case 2: tarea_seleccionada = "insert_arbol_user_name"; break;

    case 3: tarea_seleccionada = "search_in_arbol_user_id"; break;
    case 4: tarea_seleccionada = "search_in_arbol_user_name"; break;

    case 5: tarea_seleccionada = "search_out_arbol_user_id"; break;
    case 6: tarea_seleccionada = "search_out_arbol_user_name"; break;

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
      case 5: n = 29246; break;

      default: n = 0; break;
    }

    //SI SON PROCESOS DE BUSQUEDA USAN OTROS RANGOS DE DATASET
    if (id_proceso==3 || id_proceso==4 || 
        id_proceso==5 || id_proceso==6)
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

    //Si el proceso es de tipo search o delete, primero debe estar cargada toda la información
    if (id_proceso>2 && id_proceso<7)
    {
      // SE REQUIERE CARGA PREVIA

      //DATASET 5 es lleno
     insert_arbol_user_id(5);
     insert_arbol_user_name(5);

      tree_string.erase("sdfsdf");


    }

    nombre_archivo_salida = dir_csv + tarea_seleccionada + "_results.csv";
    ofstream outfile(nombre_archivo_salida,std::ios::app);

    double mm_total_time = 0;
    int numero_de_experimentos=1;
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
    outfile << "n,tiempo[ms]\n";

    return 0;
  }


}

