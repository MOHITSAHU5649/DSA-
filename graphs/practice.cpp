#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addedge(int a, int b){
        l[a].push_back(b);
        l[b].push_back(a);
    }

    void bfs(){
        vector<bool> visited (V, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(q.size() >0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";

            for(int v : l[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void dfshelper(int b, vector<bool> &visited){
        visited[b] = true;
        cout<<b<<" ";

        for(int a : l[b]){
            if(!visited[a]){
                dfshelper(a, visited);
            }
        }

    }

    void dfs(){
        vector<bool> visited(V, false);
        dfshelper(0, visited);
    }
};



int main(){
Graph g(5);
g.addedge(0,1);
g.addedge(1,2);
g.addedge(1,3);
g.addedge(2,4);

g.bfs();
g.dfs();

    return 0;
}