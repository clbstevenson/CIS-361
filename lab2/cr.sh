#!/bin/sh
echo "Compiling $1"
gcc -Wall $1

echo "Running $1 with test2"
./a.out < test2
