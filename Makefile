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

.PHONY: all clean gitcommands

all: main gitcommands

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP_FILES)
	$(CC) $(FLAGS) -I. `$(LIBS)` -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.class $(DEP_FILES)
	$(CC) $(FLAGS) -I. `$(LIBS)` -c -o $@ $<

main: $(OBJ_FILES)
	$(CC) $(FLAGS) -I. `$(LIBS)` -o $@ $^

gitcommands:
	# Check the number of changes since the last commit
	NUM_CHANGES_SINCE_COMMIT=$$(git diff --name-only | wc -l); \
	# Increment the number of changes so far
	NUM_CHANGES_SO_FAR=$$((NUM_CHANGES_SO_FAR + NUM_CHANGES_SINCE_COMMIT)); \
	# If we have reached the target number of changes, commit and reset the count
	if [ $$NUM_CHANGES_SO_FAR -ge $(NUM_CHANGES) ]; then \
        git add . && git commit -a -m "Makefile commit" && git push origin main; \
        NUM_CHANGES_SO_FAR=0; \
    fi; \
	# Update the count in the Makefile
	echo "NUM_CHANGES_SO_FAR := $$NUM_CHANGES_SO_FAR" > makefile.tmp; \
    mv makefile.tmp Makefile

gitcommands_original: all
	git add .
	git commit -a -m "Makefile Commit"
	git push origin main

clean:
	rm obj/*.o main

