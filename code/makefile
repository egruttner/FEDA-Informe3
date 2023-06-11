CC = g++
CFLAGS = -std=c++14 -O2

SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)

LDLIBS="arbolBinarioBusqueda.cpp" "AVLTree.cpp" "AVLTreeNode.cpp"


# g++ kod.cpp AVLTree.cpp AVLTreeNode.cpp -o kod -std=c++11


TEST_CASES_NUMBER := $(shell seq 1 1) #rango de archivos de input y output

RANGE = 1 #distintos algoritmos a probar

# 1 INSERT - Árbol binario de búsqueda sin balanceo - User ID
# 2 INSERT - Árbol binario de búsqueda sin balanceo - User Name
# 3 DELETE - Árbol binario de búsqueda sin balanceo - User ID
# 4 DELETE - Árbol binario de búsqueda sin balanceo - User Name
# 5 SEARCH - IN - Árbol binario de búsqueda sin balanceo - User ID
# 6 SEARCH - IN - Árbol binario de búsqueda sin balanceo - User Name
# 7 SEARCH - OUT - Árbol binario de búsqueda sin balanceo - User ID
# 8 SEARCH - OUT - Árbol binario de búsqueda sin balanceo - User Name

# 9 INSERT - Tabla hash con hashing abierto - User ID
# 10 INSERT - Tabla hash con hashing abierto - User Name
# 11 DELETE - Tabla hash con hashing abierto - User ID
# 12 DELETE - Tabla hash con hashing abierto - User Name
# 13 SEARCH - IN - Tabla hash con hashing abierto - User ID
# 14 SEARCH - IN - Tabla hash con hashing abierto - User Name
# 15 SEARCH - OUT - Tabla hash con hashing abierto - User ID
# 16 SEARCH - OUT - Tabla hash con hashing abierto - User Name

# 17 INSERT - Tabla hash con hashing cerrado - User ID
# 18 INSERT - Tabla hash con hashing cerrado - User Name
# 19 DELETE - Tabla hash con hashing cerrado - User ID
# 20 DELETE - Tabla hash con hashing cerrado - User Name
# 21 SEARCH - IN - Tabla hash con hashing cerrado - User ID
# 22 SEARCH - IN - Tabla hash con hashing cerrado - User Name
# 23 SEARCH - OUT - Tabla hash con hashing cerrado - User ID
# 24 SEARCH - OUT - Tabla hash con hashing cerrado - User Name


INPUT_PREFIX := datasets/input$(num_dataset)/input

OUTPUT_PREFIX := output/output$(num_dataset)/output

all: program

	for j in $(RANGE); do \
		echo "Executing program with $$j --head $$num_dataset"; \
		./program $$j --head $$num_dataset; \
		for i in $(TEST_CASES_NUMBER); do \
			echo "./program --test $$j $$num_dataset > $(OUTPUT_PREFIX)$$j$$i.txt"; \
			./program $$j --test $$num_dataset > $(OUTPUT_PREFIX)$$j$$i.txt; \
		done; \
	done

program: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o program

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) program output*

