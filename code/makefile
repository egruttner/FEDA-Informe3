CC = g++
CFLAGS = -std=c++14 -O2

SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)

LDLIBS="AVLTree.cpp" "AVLTreeNode.cpp"

# g++ kod.cpp AVLTree.cpp AVLTreeNode.cpp -o kod -std=c++11

TEST_CASES_NUMBER := $(shell seq 1 5) #rango de archivos de input y output

RANGE = 7 8 9 10 11 12#distintos algoritmos a probar

# 1 INSERT - Árbol binario de búsqueda sin balanceo - User ID
# 2 INSERT - Árbol binario de búsqueda sin balanceo - User Name
# 3 SEARCH - IN - Árbol binario de búsqueda sin balanceo - User ID
# 4 SEARCH - IN - Árbol binario de búsqueda sin balanceo - User Name
# 5 SEARCH - OUT - Árbol binario de búsqueda sin balanceo - User ID
# 6 SEARCH - OUT - Árbol binario de búsqueda sin balanceo - User Name

# 7 INSERT - Tabla hash con hashing abierto - User ID
# 8 INSERT - Tabla hash con hashing abierto - User Name
# 9 SEARCH - IN - Tabla hash con hashing abierto - User ID
# 10 SEARCH - IN - Tabla hash con hashing abierto - User Name
# 11 SEARCH - OUT - Tabla hash con hashing abierto - User ID
# 12 SEARCH - OUT - Tabla hash con hashing abierto - User Name

# 13 INSERT - Tabla hash con hashing cerrado - User ID
# 14 INSERT - Tabla hash con hashing cerrado - User Name
# 15 SEARCH - IN - Tabla hash con hashing cerrado - User ID
# 16 SEARCH - IN - Tabla hash con hashing cerrado - User Name
# 17 SEARCH - OUT - Tabla hash con hashing cerrado - User ID
# 18 SEARCH - OUT - Tabla hash con hashing cerrado - User Name


INPUT_PREFIX := datasets/input$(num_dataset)/input

OUTPUT_PREFIX := output/output

all: program

	for j in $(RANGE); do \
		echo "Executing program with $$j --head $$num_dataset"; \
		./program $$j --head $$num_dataset; \
		for i in $(TEST_CASES_NUMBER); do \
			echo "./program --test $$j $$num_dataset $$i > $(OUTPUT_PREFIX)$$j$$i.txt"; \
			./program $$j --test $$num_dataset $$i > $(OUTPUT_PREFIX)$$j$$i.txt; \
		done; \
	done

program: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o program

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) program output*

