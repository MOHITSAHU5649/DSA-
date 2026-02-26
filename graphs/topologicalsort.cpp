#include <iostream>
#include<vector>
#include<stack>
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

    void dfs(int curr, vector<int> &visited, stack<int> &s){
        visited[curr] = true;

        for(int  u : l[curr]){
            if(!visited[u]){
                dfs(u, visited,s);
            }
        }
        s.push(curr);
    }

    void toposort(){
        vector<int> visited(V,false);
        stack<int> s;

        for(int i =0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,s);
            }
        }

        while(s.size() > 0){
            cout<<s.top() <<" ";
            s.pop();
        }
        cout<<endl;
    }

};


int main(){
    Graph g(6);
    g.addedge(3,1);
    g.addedge(2,3);
    g.addedge(4,0);
    g.addedge(4,1);
    g.addedge(5,0);
    g.addedge(5,3);

    g.toposort();
// topologial sort uses hwwne we want dependency 
    return 0;
}