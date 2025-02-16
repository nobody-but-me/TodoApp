
#!/usr/bin/env bash

# git commit -am "<message>"
# git push -f origin main

# echo "[CONFIG] Do you want to run the project after this compilation? "
# read -rep $"[CONFIG] (y or n): " _run

_CC=g++
_FLAGS=(-lraylib)
_SOURCES=./src/*.cpp

compile() {
    time $_CC -o ./build/Todo $_SOURCES -I./include/ -I./lib/ ${_FLAGS[*]} -lm -Werror -Wall
}

if [ $1 == "--c" ]; then
    echo -e "[INFO] Compiling only... \n"
    compile;
elif [ $1 == "--r" ]; then
    echo -e "[INFO] Running... \n"
    ./build/Todo;
elif [ $1 == "--b" ]; then
    compile;
    echo "[INFO] Compiled Successfully. "
    echo -e "[INFO] Running... \n"
    ./build/Todo;
else
    echo "[INFO] No flag given. "
    exit 1
fi
