
#LIMPIA
rm main.o
rm csv/*.*

#REALIZA EXPERIMENTOS CON DIFERENTES DATASETS

num_datasets=1

for (( i=1; i <= $num_datasets; ++i ))
do
    make num_dataset=$i

    #python3 plot.py csv/insert-arbol-user_id_results.csv insert-arbol-user-id "Gráfico de inserción"
    #python3 plot.py csv/insert-arbol-user_name_results.csv insert-arbol-user-name "Gráfico de inserción"

    #python3 plot.py csv/csv$i/selection_results.csv
    #python3 plot.py csv/csv$i/quicksort_results.csv
    #python3 plot.py csv/csv$i/sortinterno_results.csv
    #python3 plot.py csv/csv$i/mergesort_results.csv
    #python3 plot_todos.py csv/csv$i/selection_results.csv csv/csv$i/quicksort_results.csv csv/csv$i/sortinterno_results.csv csv/csv$i/mergesort_results.csv
    #python3 plot_tres.py csv/csv$i/quicksort_results.csv csv/csv$i/sortinterno_results.csv csv/csv$i/mergesort_results.csv

done



