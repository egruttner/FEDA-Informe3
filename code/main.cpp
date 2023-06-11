#include <iostream>
#include <algorithm>
#include <chrono>
#include <string.h>
#include "librerias.h"
#include <fstream>
#include "AVLTree.hpp"

using namespace std;

string university, user_id, user_name, number_tweets, friends_count, followers_count, created_at;


int main(int argv, char* argc[]) {
  srand(time(NULL)); 

  int n;
  int numero_de_experimentos;
  string dir_csv;
  string tarea_seleccionada;
  string nombre_archivo_salida;

  cout<<"INICIO"<<endl;

  //TIPOS DE PRUEBAS
  switch(atoi(argc[1])){

    case 1: tarea_seleccionada = "insert-arbol-userid"; break;
    case 2: tarea_seleccionada = "insert-arbol-username"; break;
    case 3: tarea_seleccionada = "delete-arbol-userid"; break;
    case 4: tarea_seleccionada = "delete-arbol-username"; break;
    case 5: tarea_seleccionada = "search-in-arbol-userid"; break;
    case 6: tarea_seleccionada = "search-in-arbol-username"; break;
    case 7: tarea_seleccionada = "search-out-arbol-userid"; break;
    case 8: tarea_seleccionada = "search-put-arbol-username"; break;

    default: tarea_seleccionada = ""; break;
  }

  switch(atoi(argc[3])){
    case 1: dir_csv = "csv/csv1/"; break;
    case 2: dir_csv = "csv/csv2/"; break;
    case 3: dir_csv = "csv/csv3/"; break;
    case 4: dir_csv = "csv/csv4/"; break;
    case 5: dir_csv = "csv/csv5/"; break;
    case 6: dir_csv = "csv/csv6/"; break;
    case 7: dir_csv = "csv/csv7/"; break;
    case 8: dir_csv = "csv/csv8/"; break;


    default: dir_csv = ""; break;
  }

  //SI ENTRA CON PARÁMETROS, REALIZA EL TEST
  if((argv > 2) && (strcmp(argc[2],"--test") == 0)){

    //cout<<"ARG:" << argc[4]<<endl;

    //LEE EL TAMAÑO DEL VECTOR
  


    //Ignorar primera fila
    //29245



    //DEFINE MATRICES DE ENTRADA
    //vector<int> M_A(n);   //MATRIZ A
    //vector<int> result;  //MATRIZ RESULTADO

    //LEE VECTOR
    //read_vector(M_A);
    
    //IMPRIME VECTOR EN OUTPUT
    cout<<"Tarea seleccionada: "<< tarea_seleccionada<<endl;
    //cout<< "Vector inicial:"<<endl;
    //print_vector(M_A);

    //EJECUTA CON EL ALGORITMO SELCCIONADO
    //result = vector_ordena(M_A, tarea_seleccionada);
    //cout<< "Resultado:"<<endl;

    //IMPRIME SALIDA EN OUTPUT
    //print_vector(result);

    nombre_archivo_salida = dir_csv + tarea_seleccionada + "_results.csv";
    ofstream outfile(nombre_archivo_salida,std::ios::app);

    double mm_total_time = 0;
    int numero_de_experimentos=1;
    for(int j = 0; j < numero_de_experimentos; j++){ 

      //long long single_execution_time = execution_time_ms(vector_ordena, M_A, tarea_seleccionada);
      
      long long single_execution_time = execution_time_ms(vector_ordena, tarea_seleccionada);
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
