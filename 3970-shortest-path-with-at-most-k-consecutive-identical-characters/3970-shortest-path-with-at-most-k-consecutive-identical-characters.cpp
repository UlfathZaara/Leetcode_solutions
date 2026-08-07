#include<vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
        }
        const int INF = 1e9  +7;
        vector<vector<int>> dist(n, vector<int>(k+1, INF));
        priority_queue<tuple<int,int,int>,vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
         dist[0][1]=0;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto[d,u,count]= pq.top();
            pq.pop();
            if(d> dist[u][count])continue;
            if( u== n-1) return d;
            for(const auto& neighbour : adj[u]){
                int v = neighbour.first;
                int w = neighbour.second;
                int next_count =(labels[v] == labels[u]) ? (count +1) : 1;
                if(next_count <= k){
                    if(d+w < dist[v][next_count]){
                        dist[v][next_count]= d+w;
                        pq.push({dist[v][next_count],v, next_count});
                    }
                }
            }
        }
        return -1;
        
    }
};