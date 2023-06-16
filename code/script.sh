
#LIMPIA
rm main.o
rm csv/*.*
rm output/*.*


#REALIZA EXPERIMENTOS CON DIFERENTES DATASETS

num_datasets=1

for (( i=1; i <= $num_datasets; ++i ))
do
    make num_dataset=$i

    #python3 plot.py csv/insert_arbol_user_id_results.csv insert_arbol_user_id "Gráfico de inserción"
    #python3 plot.py csv/insert_arbol_user_name_results.csv insert_arbol_user_name "Gráfico de inserción"

    #python3 plot.py csv/search_in_arbol_user_id_results.csv search_in_arbol_user_id "Gráfico de inserción"
    #python3 plot.py csv/search_in_arbol_user_name_results.csv search_in_arbol_user_name "Gráfico de inserción"

    #python3 plot.py csv/search_out_arbol_user_id_results.csv search_out_arbol_user_id "Gráfico de inserción"
    #python3 plot.py csv/search_out_arbol_user_name_results.csv search_out_arbol_user_name "Gráfico de inserción"


    #python3 plot.py csv/csv$i/selection_results.csv
    #python3 plot.py csv/csv$i/quicksort_results.csv
    #python3 plot.py csv/csv$i/sortinterno_results.csv
    #python3 plot.py csv/csv$i/mergesort_results.csv
    #python3 plot_todos.py csv/csv$i/selection_results.csv csv/csv$i/quicksort_results.csv csv/csv$i/sortinterno_results.csv csv/csv$i/mergesort_results.csv
    #python3 plot_tres.py csv/csv$i/quicksort_results.csv csv/csv$i/sortinterno_results.csv csv/csv$i/mergesort_results.csv

done



