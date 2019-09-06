#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[]) {
    int n, m, x, y, cont = 0;
    cin >> n >> m;
    vector<vector<int> > adjList(n);
    int *L = (int *)calloc(n,sizeof(int));
    vector<int> S;
    vector<int> resp;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        adjList[x-1].push_back(y-1);
        L[y-1]++;
    }
    for (int i = 0; i < n; i++) if (L[i] == 0) S.push_back(i);
    while (S.size() > 0){
        x = S.back();
        S.pop_back();
        resp.push_back(x);
        for (int i = 0; i < adjList[x].size(); i++){
            y = adjList[x][i];
            L[y]--;
            if (L[y] == 0){
                S.push_back(adjList[x][i]);
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (L[i] != 0){
            cout << "Nao foi possivel encontrar a ordenacao topologica" << endl;
            return 0;
        }
    }
    cout << "Ordenacao encontrada:" << endl;
    for (int i = 0; i < n-1; i++){
        cout << resp[i]+1 << " ";
    }
    cout << resp[n-1]+1 << endl;
    return 0;
}
