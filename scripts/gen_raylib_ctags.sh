#!/bin/zsh
# This script assumes MacOS

cd /opt/homebrew/Cellar/raylib
ctags --c++-kinds=+p --fields=+iaS --extras=+q -R .

# If you run this script, please add
#  set tags+=/opt/homebrew/Cellar/raylib/tags
# to your .vimrc file
