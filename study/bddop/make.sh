#!/bin/bash
cc -g -I include -I /usr/local/include -o bin/and src/testbddand.c -lbdd -lm
cc -g -I include -I /usr/local/include -o bin/biimp src/testbddbiimp.c -lbdd -lm
cc -g -I include -I /usr/local/include -o bin/diff src/testbdddiff.c -lbdd -lm
cc -g -I include -I /usr/local/include -o bin/imp src/testbddimp.c -lbdd -lm
cc -g -I include -I /usr/local/include -o bin/invimp src/testbddinvimp.c -lbdd -lm
cc -g -I include -I /usr/local/include -o bin/ite src/testbddite.c -lbdd -lm
cc -g -I include -I /usr/local/include -o bin/less src/testbddless.c -lbdd -lm
cc -g -I include -I /usr/local/include -o bin/nand src/testbddnand.c -lbdd -lm
cc -g -I include -I /usr/local/include -o bin/nor src/testbddnor.c -lbdd -lm
cc -g -I include -I /usr/local/include -o bin/or src/testbddor.c -lbdd -lm
cc -g -I include -I /usr/local/include -o bin/xor src/testbddxor.c -lbdd -lm


