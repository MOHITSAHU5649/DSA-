#include<iostream>
#include<vector>
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

void dfshelper(int a, vector<bool> &visited){
  
    cout<<a<<" ";   visited[a] =true;

    for(int u : l[a]){
        if(!visited[u]){
            dfshelper(u,visited);
        }
    }
}

    void dfs(){
        vector<bool> visited(V,false);
        dfshelper(0, visited);
    }

};



int main(){
    Graph g(5);

    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,4);

    g.dfs();

return 0;
}