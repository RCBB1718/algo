//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
 vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0;i<=n;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUpar(int node){
        if(node==parent[node])
            return node;
        else{
            int result=findUpar(parent[node]);
            parent[node]=result;
            return result;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v){
            size[ulp_u]++;
            return ;}
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>>edges;

       for(int i=0;i<V;i++){
           for(auto it:adj[i]){
               int a=it[0];
               int b=it[1];
             int node=i;
             edges.push_back({b,{node,a}});
           }
       }
       DisjointSet ds(V);
       sort(edges.begin(),edges.end());
      int mstWt=0;
     for(auto it:edges){
         int wt=it.first;
         int a=it.second.first;
         int b=it.second.second;
        if(ds.findUpar(a)!=ds.findUpar(b)){
            mstWt+=wt;
            ds.unionBySize(a,b);
        }
     }
     return mstWt;

    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
