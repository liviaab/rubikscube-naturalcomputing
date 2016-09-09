#!/bin/bash

for i in 10 12 14 16 18 20 23 25 27 30
do 
    echo $i
    cd $i
    python avg1.py
    python avg2.py    
    cd ../
done

