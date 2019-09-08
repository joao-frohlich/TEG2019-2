#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > leituraLista(string caminhoArquivo){
    ifstream f (caminhoArquivo);
    string l;
    int num, aux, i,j,k=0;
    vector<vector<int> > adjList;
    while(getline(f,l)){
        adjList.push_back(vector<int> {});
        j=0;
        i = 0;
        while (l[i]>=48 && l[i] <= 57){
            num += (l[i]-48)*pow(10,j);
            j++;
            i++;
        }
        j=0;
        aux = num;
        num=0;
        for (i; l[i] != '\0'; i++){
            if (l[i]>=48 && l[i] <= 57){
                num += (l[i]-48)*pow(10,j);
                j++;
            } else if (num != 0){
                j = 0;
                adjList[k].push_back(num-1);
                num = 0;
            }
        }
        if (num != 0){
            adjList[k].push_back(num-1);
        }
        k++;
    }
    return adjList;
}

bool ehConexo(vector<vector<int> > grafo){
    int numeroVertices = grafo.size();
    int numeroConexos = 0;
    set<int> visitados;
    queue<int> fila;
    int verticeAtual = 0;
    visitados.insert(verticeAtual);
    fila.push(verticeAtual);
    while (!fila.empty()){
        int i;
        numeroConexos++;
        verticeAtual = fila.front();
        for (i = 0; i < grafo[verticeAtual].size(); i++){
            int verticeAux = grafo[verticeAtual][i];
            if (visitados.count(verticeAux) == 0){
                fila.push(verticeAux);
                visitados.insert(verticeAux);
            }
        }
        fila.pop();
    }
    if (numeroConexos == numeroVertices) return true;
    return false;
}

bool ehEuleriano(vector<vector<int> > grafo){
    int i,j, numeroVertices = grafo.size(), numeroArestas;
    for (i = 0; i < numeroVertices; i++){
        numeroArestas = grafo[i].size();
        if (numeroArestas%2 != 0) return false;
    }
    return true;
}

vector<int> fleury(vector<vector<int> > grafo){
    int numeroVertices = grafo.size(), i, j;

}

int main(int argc, char const *argv[]) {
    vector<vector<int> > listaAdjacencia = leituraLista("graph.txt");
    int i,j;
    if (ehConexo(listaAdjacencia)){
        if (ehEuleriano(listaAdjacencia)){
            cout << "ce" << endl;
        } else cout << "c" << endl;
    } else cout << "n" << endl;
    // for (i = 0; i < listaAdjacencia.size(); i++){
    //     cout << i+1 << ":";
    //     for (j = 0; j < listaAdjacencia[i].size(); j++){
    //         cout << " " << listaAdjacencia[i][j]+1;
    //     }
    //     cout << endl;
    // }
    return 0;
}
