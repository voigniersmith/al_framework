CC = g++
FLAGS = -W -Wall

SRC_DIR := ./src
OBJ_DIR := ./obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
DEP_FILES := $(wildcard $(SRC_DIR)/*.hh)

OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

p := pkg-config --cflags --libs
l := allegro-5 allegro_main-5 allegro_font-5 allegro_image-5 allegro_primitives-5

LIBS := $p $l

# Set the number of changes to commit after
NUM_CHANGES := 5
# Check the number of changes since the last commit
NEW_CHANGES := $(shell git diff --name-only | wc -l)

.PHONY: clean all gitcommands

all: main gitcommands

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP_FILES)
	$(CC) $(FLAGS) -I. `$(LIBS)` -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.class $(DEP_FILES)
	$(CC) $(FLAGS) -I. `$(LIBS)` -c -o $@ $<

main: $(OBJ_FILES)
	$(CC) $(FLAGS) -I. `$(LIBS)` -o $@ $^

gitcommands: main
	if [ $(NEW_CHANGES) -ge $(NUM_CHANGES) ]; then \
		git add . && git commit -a -m "Makefile commit" && git push origin main; \
	fi; \

clean:
	rm obj/*.o main

