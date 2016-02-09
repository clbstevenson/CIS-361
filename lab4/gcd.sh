#!/bin/sh
echo "Compiling lab4.c with debug options"
rm lab4
gcc -Wall -g lab4.c -o lab4

echo "Starting gdb debugger"
gdb lab4
