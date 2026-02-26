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
    }

    bool dfshel(vector<bool> &visited, vector<bool> & recpath, int curr){
        visited[curr] = true;
        recpath[curr] = true;

    for(int u : l[curr]){
        if(!visited[u]){
            if(dfshel (visited, recpath, u)){
                return true;
            }
           
    }
     else if(recpath[u]){
                return true;
        }
    }
    recpath[curr] = false;
    return false;
}

    bool iscycle(){
        vector<bool> visited(V, false);
        vector<bool> recpath(V, false);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(dfshel(visited, recpath, i)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){

    Graph g(5);
    g.addedge(0, 1);
    g.addedge(1, 2);        
    g.addedge(2, 3);
    g.addedge(3, 0);  // cycle
    g.addedge(3, 4);
    if(g.iscycle()){
        cout<<"Cycle Present"<<endl;
    }
    else{
        cout<<"No Cycle Present"<<endl;
    }
    return 0;
}