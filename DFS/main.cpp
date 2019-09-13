#include <bits/stdc++.h>
using namespace std;


//Implementação de dfs com lista de adjacência e com vértices numerados de forma não sequencial
set<int> visitados;
vector<vector<int> > adjList;

int dfs(int o, int d){
    if (o == d) return 1;
    visitados.insert(o);
    for (int i = 0; i < adjList[o].size(); i++){
        if(visitados.count(adjList[o][i]) == 0){
            if (dfs(adjList[o][i], d) == 1) return 1;
        }
    }
    return 0;
}

//Implementação com árvore
/*
Dois vetores, PE (vetor de entrada) e PS (vetor de saida), ambos do tamanho da quantidade de nós e com valor 0
Um vetor N(G) que representa os vizinhos do vértice G
Um vetor de Pai


int dfs2(int v){
    t++;
    int w;
    PE[v] = t;
    for (int i = 0; i < sizeof(N[v])/sizeof(int); i++){
        w = N[v][i];
        if (PE[w] != 0){
            Pai[w] = v;
            dfs2(w);
        } else {
            if (PS[w] == 0 && w != Pai[v])
        }
    }
    t++;
    PS[v] = t;
}
*/

int main(int argc, char const *argv[]) {
    int n, e, x, y;
    cin >> n >> e;
    adjList.resize(n);
    for (int i = 0; i < e; i++){
        cin >> x >> y;
        adjList[x-1].push_back(y-1);
        adjList[y-1].push_back(x-1);
    }
    cout << dfs(2,5) << endl;
    return 0;
}
