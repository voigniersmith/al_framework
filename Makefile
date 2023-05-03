CC = g++
FLAGS = -std=c++11 -W -Wall

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
# Check the number of changes since the last commit (and remove whitespace)
NEW_CHANGES := $(shell git diff --name-only | wc -l | sed -e 's/^[ \t]*//')

# Get Username from Git & Set Branch
BRANCH := $(shell git config --get user.name)-stage

.PHONY: clean all git ctags
.SILENT: run git ctags

all: main git ctags

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP_FILES)
	$(CC) $(FLAGS) -I. `$(LIBS)` -c -o $@ $<

main: $(OBJ_FILES)
	$(CC) $(FLAGS) -I. `$(LIBS)` -o $@ $^

run: main
	./main

clean:
	rm obj/*.o main

git: main
	./scripts/git_configure.sh; \
	if [ $(NEW_CHANGES) -ge $(NUM_CHANGES) ]; then \
		git add . && git commit -a -m "Makefile Incremental Commit" && git push -u origin $(BRANCH); \
	fi; \
	echo; \
	echo "Changed $(NEW_CHANGES) files, will push at $(NUM_CHANGES) files."; \
	echo

ctags: main
	ctags --c++-kinds=+p --fields=+iaS --extras=+q -f tags_temp $(DEP_FILES); \
	if [ `diff tags_temp tags | wc -l` ]; then \
		mv tags_temp tags; \
	else \
		echo "no update to ctags" && rm tags_temp; \
	fi;

