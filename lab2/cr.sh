#!/bin/sh
echo "Compiling $1"
gcc -Wall $1

echo "Running $1 with test1"
./a.out < test1
