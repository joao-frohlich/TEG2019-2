#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1000000007
typedef pair<int,int> ii;
vector<vector<ii > > adjList;
priority_queue<ii, vector<ii>, greater<ii> > f;
vector<vector<int> > precedencia;

vector<int> dijkstra(int o){
    int n = adjList.size(), m,z;
    ii x,y;
    f.push(mp(0,o));
    vector<int> caminho;
    for (int i = 0; i < n; i++){
        caminho.pb(INF);
        precedencia.pb(vector<int> {-1});
    }
    caminho[o] = 0;
    while (!f.empty()){
        x = f.top();
        f.pop();
        m = adjList[x.se].size();
        for (int i = 0; i < m; i++){
            y = adjList[x.se][i];
            z = x.fi+y.se;
            if (z < caminho[y.fi]){
                f.push(mp(z,y.fi));
                caminho[y.fi] = z;
                precedencia[y.fi].clear();
                precedencia[y.fi].pb(x.se);
            } else if (z == caminho[y.fi]){
                precedencia[y.fi].pb(x.se);
            }
        }
    }
    return caminho;
}

int main(int argc, char const *argv[]) {
    int n,e,x,y,z;
    cin >> n >> e;
    adjList.resize(n);
    vector<int> c;
    for (int i = 0; i < e; i++){
        cin >> x >> y >> z;
        adjList[x].pb(mp(y,z));
    }
    c = dijkstra(0);

    printf("Nó\tDist\tPai\n");
    for (int i = 0; i < precedencia.size(); i++){
        cout << (char)(i+65) <<"\t"<< c[i];
        cout << "\t";
        if (precedencia[i][0] == -1){
            cout << "Raiz";
        } else {
            cout << (char)(precedencia[i][0]+65);
        }
        for (int j = 1; j < precedencia[i].size(); j++){
            cout << ", " << (char)(precedencia[i][j]+65);
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
