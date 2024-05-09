#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<vector>
using namespace std;

void bfs(map<char,vector<char>>& graph,char startNode){
    set<char>visited;
    queue<char>queue;

    visited.insert(startNode);
    queue.push(startNode);

    while(!queue.empty()){
        char currentNode=queue.front();
        queue.pop();

        cout<<currentNode<<" ";

        for(char neighbor : graph[currentNode]){
            if(visited.find(neighbor)==visited.end()){
                visited.insert(neighbor);
                queue.push(neighbor);
            }
        }
    }
}

void dfs(map<char, vector<char>>& graph, set<char>& visited, char node) {
    visited.insert(node);
    cout << node << " ";

    for (char neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, visited, neighbor);
        }
    }
}

int main(){
    
    map<char,vector<char>>graph={
        {'A',{'B','C'}},
        {'B',{'D','E'}},
        {'C',{'F'}},
        {'D',{}},
        {'E',{'F'}},
        {'F',{}}
    };

    cout<<"BFS from node A : ";
    bfs(graph,'A');
    cout << "\n";

    // DFS Traversal
    set<char> visited;  // Visited set for DFS
    cout << "DFS starting from node A: ";
    dfs(graph, visited, 'A');
    cout << "\n";

    return 0;
}