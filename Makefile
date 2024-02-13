CC=g++
CFLAGS=-c -Wall -I/usr/include/SDL2
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf
SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin

# List of source files
SOURCES=$(SRC_DIR)/Image.cpp $(SRC_DIR)/Pixel.cpp $(SRC_DIR)/mainTest.cpp $(SRC_DIR)/mainExemple.cpp $(SRC_DIR)/mainAffichage.cpp

# List of object files
OBJECTS=$(addprefix $(OBJ_DIR)/,$(notdir $(SOURCES:.cpp=.o)))

# List of executable files
EXECUTABLES=test exemple affichage

# Rules to build executables
all: $(EXECUTABLES) docu

test: $(OBJ_DIR)/mainTest.o $(OBJ_DIR)/Image.o $(OBJ_DIR)/Pixel.o
	$(CC) $(LDFLAGS) $^ -o $(BIN_DIR)/$@

exemple: $(OBJ_DIR)/mainExemple.o $(OBJ_DIR)/Image.o $(OBJ_DIR)/Pixel.o
	$(CC) $(LDFLAGS) $^ -o $(BIN_DIR)/$@

affichage: $(OBJ_DIR)/mainAffichage.o $(OBJ_DIR)/Image.o $(OBJ_DIR)/Pixel.o
	$(CC) $(LDFLAGS) $^ -o $(BIN_DIR)/$@

docu: doc/image.doxy
	cd doc ; doxygen image.doxy

# Rules to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(EXECUTABLES:%=$(BIN_DIR)/%) doc/html
