#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V =V;
        l = new list<int> [V];}

        void addedge(int a, int b){
            l[a].push_back(b);
            l[b].push_back(a);
        }
        
        bool iscycle(int v, vector<bool> &visited){
            queue<pair<int, int>> Q;
            Q.push({v, -1});
            visited[v] = true;

            while(Q.size() > 0){
                int u = Q.front().first;
                int parent = Q.front().second;
                Q.pop();
                    for(int n : l[u]){
                        if(!visited[n]){
                            visited[n] = true;
                            Q.push({n, u});
                        }else if(parent != n){
                            return true;
                    }
            }
        }
        return false;
    }

    void cycle(){
        vector<bool> visited(V, false);
        for(int i =0;i<V;i++){
            if(!visited[i]){
                if(iscycle(i, visited)){
                    cout<<"Cycle Present"<<endl;
                    return;
                }
            }
        }
    }
};


int main(){
    Graph g(5);
    g.addedge(0,1);
    g.addedge(0,2); 
    g.addedge(0,3);
    g.addedge(1,4);
    g.addedge(3,1);

    g.cycle();
    return 0;
}