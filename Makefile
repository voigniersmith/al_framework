CC = g++
FLAGS = -W -Wall

SRC_DIR := ./src
OBJ_DIR := ./obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
DEP_FILES := $(wildcard $(SRC_DIR)/*.hh)

OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

COMMIT := $(shell)

p := pkg-config --cflags --libs
l := allegro-5 allegro_main-5 allegro_font-5 allegro_image-5 allegro_primitives-5

LIBS := $p $l

.PHONY: all clean

all: main

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP_FILES)
	$(CC) $(FLAGS) -I. `$(LIBS)` -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.class $(DEP_FILES)
	$(CC) $(FLAGS) -I. `$(LIBS)` -c -o $@ $<

main: $(OBJ_FILES)
	$(CC) $(FLAGS) -I. `$(LIBS)` -o $@ $^

gitcommands: all
	git add .
	git commit -a -m "Makefile Commit"
	git push origin main

clean:
	rm obj/*.o main

