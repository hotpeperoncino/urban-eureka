#!/bin/bash
gcc -g -I include -I ../../include test01diff.c -L../../lib -lbdd -lm -o test01diff
gcc -g -I include -I ../../include test02compose.c -L../../lib -lbdd -lm -o test02compose
gcc -g -I include -I ../../include test03makeset.c -L../../lib -lbdd -lm -o test03makeset


