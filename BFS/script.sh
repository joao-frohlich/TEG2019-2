#!/bin/bash
g++ main.cpp -o main
echo "Informe caminho do arquivo de entrada"
read ARQUIVO
./main < $ARQUIVO
dot -Tps graph.dot -o graph.ps
