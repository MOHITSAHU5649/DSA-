#include<iostream> 
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int v;
    list<int> *l;

public:
    Graph(int v){
        this->v = v;
        l = new list<int> [v];
    }

    void addedge(int a, int b){
        l[a].push_back(b);
        l[b].push_back(a);

    }

    void bfs(){
        vector<bool> vis(v,false);
        queue<int> q;

        q.push(0);
        vis[0] = true;

        while(q.size() > 0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";

            for(int V: l[u]){
                if(!vis[V]){
                    vis[V] = true;
                    q.push(V);
                }
            }
        }
        cout<<endl;
    }
};


int main(){

    Graph g(5);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,3);
    g.addedge(2,4);

    g.bfs();
        return 0;
}