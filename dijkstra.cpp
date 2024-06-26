#include<iostream>
using namespace std;
#include<limits.h>

#define V 9

void printSol(int dist[]){
    cout<<"Vertx\tDistance from src"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }
}

int minDist(int dist[],bool set[]){
    int min=INT_MAX;
    int minIndex;

    for(int v=0;v<V;v++){
        if(set[v]==false && dist[v]<=min){
            min=dist[v];
            minIndex=v;
        }
    }
    return minIndex;
}

void dijkstra(int graph[V][V],int src){

    int dist[V];

    bool set[V];

    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        set[i]=false;
    }

    dist[src]=0;

    for(int count=0;count<V-1;count++){
        int u=minDist(dist,set);

        set[u]=true;

        for(int v=0;v<V;v++){
            if(!set[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printSol(dist);
}

int main(){

    int graph[V][V]={{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
					 { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
					 { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
					 { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
					 { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
					 { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
					 { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
					 { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
					 { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};

    dijkstra(graph,0);

    return 0;
}