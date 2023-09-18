#!/bin/bash
gcc -wall -Wextra -Werror -pedantic -c -fPIC *.c
gcc -shared -o liball.co *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH