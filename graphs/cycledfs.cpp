#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V= V;
        l = new list<int> [V];
    }

    void addedge(int a, int b){
        l[a].push_back(b);
        l[b].push_back(a);
    }

    bool cyclehelper(int V, int paretn, vector<bool> & visited){
        visited[V]= true;

        for( int u : l[V]){
            if(!visited[u]){
                if(cyclehelper(u, V, visited)){
                    return true;
                }else if(u != paretn){
                    return true;
                }
            }
        }
        return false;
    }


void iccycle(){
    vector<bool> visited(V, false);
    for(int i =0;i<V;i++){
        if(!visited[i]){
            if(cyclehelper(i, -1, visited)){
                cout<<"Cycle Present"<<endl;
                return;
        }
    }
}
    cout<<"No Cycle Present"<<endl;
}

};

int main(){
    Graph g(5);
    g.addedge(0,1);
    g.addedge(0,2); 
    g.addedge(0,3);
    g.addedge(1,4);
    g.addedge(3,1);
    g.iccycle();

    return 0;

    // backedge is the imporatn thing in this 
}