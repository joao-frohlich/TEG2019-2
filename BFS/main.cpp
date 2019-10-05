#include <bits/stdc++.h>
using namespace std;


#define BLUE 0
#define RED 1
#define YELLOW 2
#define GREEN 3
vector<vector<int> > adjList;
vector<pair<pair<int,int>, int> > arestas;
//Implementacao propria
/*
void bfs(int o){
    queue<int> f;
    f.push(o);
    set<int> vis;
    while (!f.empty()){
        int v = f.front();
        f.pop();
        if (vis.count(v) != 0) continue;
        vis.insert(v);
        for (int i = 0; i < adjList[v].size(); i++){
            f.push(adjList[v][i]);
        }
    }
}
*/


//Implementacao aula
//vw significa a cor da aresta; olhar defines pra saber os valores
//representar arestas por meio de um map<pair<int,int>,int>
void bfs(int raiz){
    int t = 1, vw;
    queue<int> f;
    int L[adjList.size()];
    int pai[adjList.size()];
    int nivel[adjList.size()];
    for (int i = 0; i < adjList.size(); i++){
        L[i] = 0;
        pai[i] = -1;
        nivel[i] = 0;
    }
    f.push(raiz);
    L[raiz] = t;
    while (!f.empty()){
        int v = f.front();
        f.pop();
        for (int i = 0; i < adjList[v].size(); i++){
            int w = adjList[v][i];
            if (L[w] == 0){
                pai[w] = v;
                nivel[w] = nivel[v]+1;
                t++;
                L[w] = t;
                f.push(w);
                vw = BLUE;
                arestas.push_back(make_pair(make_pair(v,w),vw));
            } else {
                if (nivel[w] == nivel[v]){
                    if (pai[w] == pai[v]) vw = RED;
                    else vw = YELLOW;
                    arestas.push_back(make_pair(make_pair(v,w),vw));
                } else if (nivel[w] == nivel[v]+1){
                    vw = GREEN;
                    arestas.push_back(make_pair(make_pair(v,w),vw));
                }
            }
        }
    }
    FILE *fp = fopen("graph.dot", "w");
    fprintf(fp, "digraph BFS {\n");
    for (int i = 0; i < arestas.size(); i++){
        fprintf(fp,"\t%c -> %c[", arestas[i].first.first+97, arestas[i].first.second+97);
        if (arestas[i].second == BLUE){
            fprintf(fp, "color=blue,penwidth=3.0];\n");
        } else if (arestas[i].second == YELLOW){
            fprintf(fp, "color=yellow,penwidth=3.0];\n");
        } else if (arestas[i].second == RED){
            fprintf(fp, "color=red,penwidth=3.0];\n");
        } else {
            fprintf(fp, "color=green,penwidth=3.0];\n");
        }
    }
    fprintf(fp, "\n\tnode [fontname=%cArial%c]\n", 34, 34);
    fprintf(fp, "\tnode_A [shape=record label=%c{Vertices|Pai|L|Nivel}", 34);
    for (int i = 0; i < adjList.size(); i++){
        fprintf(fp, "|{%c|%d|%d|%d}", (char)(i+97), pai[i], L[i], nivel[i]);
    }
    fprintf(fp, "%c];\n\n}\n", 34);
    fclose(fp);

}

int main(int argc, char const *argv[]) {
    int n,e,x,y;
    cin >> n >> e;
    adjList.resize(n);
    for (int i = 0; i < e; i++){
        cin >> x >> y;
        x--;
        y--;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    cin >> x;
    bfs(x-1);
    cout << "Programa executado com sucesso" << endl;
    return 0;
}
