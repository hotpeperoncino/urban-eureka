#!/bin/bash
cc -g -I include -I /usr/local/include -o appex appex.c -lbdd -lm
cc -g -I include -I /usr/local/include -o compose compose.c -lbdd -lm
cc -g -I include -I /usr/local/include -o test01 test01.c -lbdd -lm

