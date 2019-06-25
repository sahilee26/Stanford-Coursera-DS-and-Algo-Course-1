#include<bits/stdc++.h>
using namespace std;

//implementing a undirected and unweighted graph using adjacency list with STL

void addedge(vector<long long> adj[],long long u,long v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printgraph(vector <long long> adj[],long long V)
{
    for(long long v=0; v<V; v++)
    {
        cout <<"Adjacency list of vertex "<<v<<endl;
        cout<<"head";

        for(auto x : adj[v])
        {
            cout <<"->"<<x;
        }
        printf("\n");
    }
}

int main()
{
    #ifndef ONLINE JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    long long V=5;
    vector <long long> adj[V];
    addedge(adj,0,1);
    addedge(adj,0,4);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,1,4);
    addedge(adj,2,3);
    addedge(adj,3,4);
    printgraph(adj, V);
    return 0;
}
