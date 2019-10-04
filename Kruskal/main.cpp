#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
#define fi first
#define se second

vector<vector<ii> > kruskal(vector<pair<int, ii> > &edgeList, int tam){
    sort(edgeList.begin(), edgeList.end());
    bool vis[tam];
    memset(&vis, false, tam);
    vector<vector<ii> > adjList (tam);
    for (int i = 0; i < edgeList.size(); i++){
        int u,v,w;
        u = edgeList[i].se.fi;
        v = edgeList[i].se.se;
        w = edgeList[i].fi;
        if (!(vis[u] && vis[v])){
            vis[u] = true;
            vis[v] = true;
            adjList[u].push_back(make_pair(v,w));
            // adjList[v].push_back(make_pair(u,w));
        }
    }
    return adjList;
}

int main(int argc, char const *argv[]) {
    int n,e,x,y,z;
    cin >> n >> e;
    vector<vector<ii> > adjList;
    vector<pair<int,ii> > edgeList;
    for (int i = 0; i < e; i++){
        cin >> x >> y >> z;
        edgeList.push_back(make_pair(z, make_pair(x,y)));
    }
    adjList = kruskal(edgeList, n);
    printf("Origem\tDestino\tCusto\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < adjList[i].size(); j++){
            x = i;
            y = adjList[i][j].fi;
            z = adjList[i][j].se;
            printf("%d\t%d\t%d\n", x,y,z);
        }
    }
    return 0;
}
