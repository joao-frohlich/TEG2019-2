#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
#define fi first
#define se second
#define INF 1000000007

vector<vector<ii> > prim(vector<vector<ii> > &adjList){
    int tam = adjList.size();
    bool vis[tam];
    memset(&vis, false, tam);
    vis[0] = true;
    priority_queue<pair<int,ii>, vector<pair<int,ii> >, greater<pair<int,ii> > > pq;
    vector<vector<ii> > aux(tam);
    ii v;
    pair<int,ii> front;
    int x,y,w;
    for (int i = 0; i < adjList[0].size(); i++){
        v = adjList[0][i];
        pq.push(pair<int,ii> (v.se, ii(0,v.fi)));
    }
    while (!pq.empty()){
        front = pq.top();
        pq.pop();
        x = front.se.fi;
        y = front.se.se;
        w = front.fi;
        if (!vis[y]){
            aux[x].push_back(make_pair(y,w));
            vis[y] = true;
            for (int i = 0; i < adjList[y].size(); i++){
                v = adjList[y][i];
                if (!vis[v.fi]){
                    pq.push(pair<int,ii> (v.se, ii(y,v.fi)));
                }
            }
        }
    }
    return aux;
}

int main(int argc, char const *argv[]) {
    int n,e,x,y,z,min = INF;
    ii edge;
    cin >> n >> e;
    vector<vector<ii> > adjList(n);
    vector<vector<ii> > mst;
    for (int i = 0; i < e; i++){
        cin >> x >> y >> z;
        adjList[x].push_back(make_pair(y,z));
        adjList[y].push_back(make_pair(x,z));
    }
    mst = prim(adjList);
    printf("Origem\tDestino\tCusto\n");
    int custo=0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < mst[i].size(); j++){
            printf("%c\t%c\t%d\n", i+97,mst[i][j].fi+97,mst[i][j].se);
            custo+=mst[i][j].se;
        }
    }
    printf("Custo total: %d\n", custo);
    return 0;
}
