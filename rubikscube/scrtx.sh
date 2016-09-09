#!/bin/bash

for i in 'rates/out1.txt' 'rates/out2.txt' 'rates/out3.txt' 'rates/out4.txt' 'rates/out5.txt' 'rates/out6.txt' 'rates/out7.txt' 'rates/out8.txt' 'rates/out9.txt' 'rates/out10.txt'

do
    ./rubcube Testes/testes/in1/in1 $i
done


