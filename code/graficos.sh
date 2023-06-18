#Individuales
#Arbol
: 
python3 plot.py csv/insert_arbol_user_id_results.csv insert_arbol_user_id "Inserción Árbol User_Id"
python3 plot.py csv/insert_arbol_user_name_results.csv insert_arbol_user_name "Inserción Árbol User_Name"
python3 plot.py csv/search_in_arbol_user_id_results.csv search_in_arbol_user_id "Búsqueda FOUND Árbol User_Id"
python3 plot.py csv/search_in_arbol_user_name_results.csv search_in_arbol_user_name "Búsqueda FOUND Árbol User_Name"
python3 plot.py csv/search_out_arbol_user_id_results.csv search_out_arbol_user_id "Búsqueda FAIL Árbol User_Id"
python3 plot.py csv/search_out_arbol_user_name_results.csv search_out_arbol_user_name "Búsqueda FAIL Árbol User_Name"

#Hash Abierto
python3 plot.py csv/insert_hash_abierto_user_id_results.csv insert_hash_abierto_user_id "Inserción Hash Abierto User_Id"
python3 plot.py csv/insert_hash_abierto_user_name_results.csv insert_hash_abierto_user_name "Inserción Hash Abierto User_Name"
python3 plot.py csv/search_in_hash_abierto_user_id_results.csv search_in_hash_abierto_user_id "Búsqueda FOUND Hash Abierto User_Id"
python3 plot.py csv/search_in_hash_abierto_user_name_results.csv search_in_hash_abierto_user_name "Búsqueda FOUND Hash Abierto User_Name"
python3 plot.py csv/search_out_hash_abierto_user_id_results.csv search_out_hash_abierto_user_id "Búsqueda FAIL Hash Abierto User_Id"
python3 plot.py csv/search_out_hash_abierto_user_name_results.csv search_out_hash_abierto_user_name "Búsqueda FAIL Hash Abierto User_Name"

#Hash Cerrado
python3 plot.py csv/insert_hash_cerrado_user_id_results.csv insert_hash_cerrado_user_id "Inserción Hash Cerrado User_Id"
python3 plot.py csv/insert_hash_cerrado_user_name_results.csv insert_hash_cerrado_user_name "Inserción Hash Cerrado User_Name"
python3 plot.py csv/search_in_hash_cerrado_user_id_results.csv search_in_hash_cerrado_user_id "Búsqueda FOUND Hash Cerrado User_Id"
python3 plot.py csv/search_in_hash_cerrado_user_name_results.csv search_in_hash_cerrado_user_name "Búsqueda FOUND Hash Cerrado User_Name"
python3 plot.py csv/search_out_hash_cerrado_user_id_results.csv search_out_hash_cerrado_user_id "Búsqueda FAIL Hash Cerrado User_Id"
python3 plot.py csv/search_out_hash_cerrado_user_name_results.csv search_out_hash_cerrado_user_name "Búsqueda FAIL Hash Cerrado User_Name"


#Comparaciones de a 2

#Inserción User_id - 2 métodos
python3 plot_dos.py csv/insert_arbol_user_id_results.csv csv/insert_hash_abierto_user_id_results.csv Árbol  Hash-Abierto "Comparación Inserción User_Id - 1"
python3 plot_dos.py csv/insert_arbol_user_id_results.csv csv/insert_hash_cerrado_user_id_results.csv Árbol  Hash-Cerrado "Comparación Inserción User_Id - 2"
python3 plot_dos.py csv/insert_hash_abierto_user_id_results.csv csv/insert_hash_cerrado_user_id_results.csv Hash-Abierto Hash-Cerrado "Comparación Inserción User_Id - 3"

#Inserción User_name - 2 métodos
python3 plot_dos.py csv/insert_arbol_user_name_results.csv csv/insert_hash_abierto_user_name_results.csv Árbol  Hash-Abierto "Comparación Inserción User_Name - 4"
python3 plot_dos.py csv/insert_arbol_user_name_results.csv csv/insert_hash_cerrado_user_name_results.csv Árbol  Hash-Cerrado "Comparación Inserción User_Name - 5"
python3 plot_dos.py csv/insert_hash_abierto_user_name_results.csv csv/insert_hash_cerrado_user_name_results.csv Hash-Abierto Hash-Cerrado "Comparación Inserción User_Name - 6"


#Búsqueda IN User_id - 2 métodos
python3 plot_dos.py csv/search_in_arbol_user_id_results.csv csv/search_in_hash_abierto_user_id_results.csv Árbol  Hash-Abierto "Comparación Búsqueda User_Id - 1"
python3 plot_dos.py csv/search_in_arbol_user_id_results.csv csv/search_in_hash_cerrado_user_id_results.csv Árbol  Hash-Cerrado "Comparación Inserción User_Id - 2"
python3 plot_dos.py csv/search_in_hash_abierto_user_id_results.csv csv/search_in_hash_cerrado_user_id_results.csv Hash-Abierto Hash-Cerrado "Comparación Inserción User_Id - 3"

#Búsqueda IN User_name - 2 métodos
python3 plot_dos.py csv/search_in_arbol_user_name_results.csv csv/search_in_hash_abierto_user_name_results.csv Árbol  Hash-Abierto "Comparación Búsqueda User_Name - 4"
python3 plot_dos.py csv/search_in_arbol_user_name_results.csv csv/search_in_hash_cerrado_user_name_results.csv Árbol  Hash-Cerrado "Comparación Búsqueda User_Name - 5"
python3 plot_dos.py csv/search_in_hash_abierto_user_name_results.csv csv/search_in_hash_cerrado_user_name_results.csv Hash-Abierto Hash-Cerrado "Comparación Búsqueda User_Name - 6"

#Comparaciones de a 3
#Insert User_Id - User_Name
python3 plot_tres.py csv/insert_arbol_user_id_results.csv csv/insert_hash_abierto_user_id_results.csv csv/insert_hash_cerrado_user_id_results.csv Árbol  Hash-Abierto Hash-Cerrado "Comparación Inserción User_Id"
python3 plot_tres.py csv/insert_arbol_user_name_results.csv csv/insert_hash_abierto_user_name_results.csv csv/insert_hash_cerrado_user_name_results.csv Árbol  Hash-Abierto Hash-Cerrado "Comparación Inserción User_Name"

#Búsqueda IN User_Id - User_Name
python3 plot_tres.py csv/search_in_arbol_user_id_results.csv csv/search_in_hash_abierto_user_id_results.csv csv/search_in_hash_cerrado_user_id_results.csv Árbol  Hash-Abierto Hash-Cerrado "Comparación Búsqueda FOUND User_Id"
python3 plot_tres.py csv/search_in_arbol_user_id_results.csv csv/search_in_hash_abierto_user_id_results.csv csv/search_in_hash_cerrado_user_id_results.csv Árbol  Hash-Abierto Hash-Cerrado "Comparación Búsqueda FOUND User_Id"
python3 plot_tres.py csv/search_in_arbol_user_name_results.csv csv/search_in_hash_abierto_user_name_results.csv csv/search_in_hash_cerrado_user_name_results.csv Árbol  Hash-Abierto Hash-Cerrado "Comparación Búsqueda FOUND User_Name"
python3 plot_tres.py csv/search_out_arbol_user_name_results.csv csv/search_out_hash_abierto_user_name_results.csv csv/search_out_hash_cerrado_user_name_results.csv Árbol  Hash-Abierto Hash-Cerrado "Comparación Búsqueda FAIL User_Name"


