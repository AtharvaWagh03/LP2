#include<iostream>
using namespace std;
#include<vector>
#include<climits>

int minKey(const vector<int>& key,const vector<bool>& mstSet){
        int min=INT_MAX, minIndex=-1;
        for(int i=0;i<key.size();i++){
            if(mstSet[i]==false && key[i]<min){
                min=key[i];
                minIndex=i;
            }
        }
        return minIndex;

}

void printMST(const vector<int>& parent, const vector<vector<int>>& graph,int sum){
        cout<<"Edge \t Weight\n";
        for(int i=1;i<parent.size();i++){
            cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
        }
        cout << "Minimum weight of MST: " << sum << "\n";
}

void prim(const vector<vector<int>>& graph,int numVertices){
        vector<int>key(numVertices);
        vector<int>parent(numVertices);
        vector<bool>mstSet(numVertices);

        for(int i=0;i<numVertices;i++){
            key[i]=INT_MAX;
            mstSet[i]=false;
        }

        key[0]=0;
        parent[0]=-1;

        for(int count=0;count<numVertices-1;count++){
            int u=minKey(key,mstSet);
            mstSet[u]=true;

            for(int v=0;v<numVertices;v++){
                if(graph[u][v]!=0 && mstSet[v]==false && graph[u][v]<key[v]){
                    parent[v]=u;
                    key[v]=graph[u][v];
                }
            }

        }

        int sum=0;
        for(int i=0;i<numVertices;i++){
            sum+=key[i];
        }
    printMST(parent,graph,sum);
}

int main(){

    int n;
    cout<<"Enter n";
    cin>>n;

    vector<vector<int>> graph(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter wt from "<<i<<" to "<<j;
            cin>>graph[i][j];
        }
    }

    prim(graph,n);

    return 0;
}