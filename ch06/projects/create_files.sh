#!/bin/bash

for i in $(seq -f "%02g" 1 12)
do
  touch $i.c
  echo "#include <stdio.h>" >> $i.c
  echo "" >> $i.c
  echo "int main()" >> $i.c
  echo "{" >> $i.c
  echo "}" >> $i.c
done