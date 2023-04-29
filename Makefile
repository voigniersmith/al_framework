CC = g++
FLAGS = -W -Wall

SRC_DIR := ./src
OBJ_DIR := ./obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
DEP_FILES := $(wildcard $(SRC_DIR)/*.hpp)

OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

p := pkg-config --cflags --libs
l := raylib

LIBS := $p $l

# Set the number of changes to commit after
NUM_CHANGES := 10
# Check the number of changes since the last commit
NEW_CHANGES := $(shell git diff --name-only | wc -l)

.PHONY: clean all gitcommands gen_ctags
.SILENT: gen_ctags

all: main gitcommands gen_ctags

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP_FILES)
	$(CC) $(FLAGS) -I. `$(LIBS)` -c -o $@ $<

main: $(OBJ_FILES)
	$(CC) $(FLAGS) -I. `$(LIBS)` -o $@ $^

gitcommands: main
	if [ $(NEW_CHANGES) -ge $(NUM_CHANGES) ]; then \
		git add . && git commit -a -m "Makefile Incremental Commit" && git push origin main; \
	fi;

gen_ctags: main
	ctags --c++-kinds=+p --fields=+iaS --extras=+q -f tags_temp $(DEP_FILES); \
	if [ `diff tags_temp tags | wc -l` ]; then \
		mv tags_temp tags; \
	else \
		echo "no update to ctags" && rm tags_temp; \
	fi;

clean:
	rm obj/*.o main

