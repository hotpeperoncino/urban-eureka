#!/bin/bash
for n in and  biimp  diff  imp  invimp  ite  less  nand  nor  or  xor
do
    echo $n
    bin/$n
    awk -f script/fmt.awk $n.dot > dot/$n.dot
    echo dot/$n.dot
done
