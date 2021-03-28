#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

const int N=100001;

vector<int> graph[N];
bool visited[N];
int level[N];

//depth first search recursive
void dfs(int source){
    cout<<source<<" ";
    visited[source]=true;
    for(int i=0;i<graph[source].size();i++){
        int to=graph[source][i];
        if(visited[to]==true) continue;
        dfs(to);
    }
}

//depth first search iterative using stack
void dfs_stack(int source){
    stack<int> S;
    S.push(source);
    visited[source]=true;
    while(!S.empty()){
        int cur=S.top();
        S.pop();
        cout<<cur<<" ";
        for(int i=0;i<graph[cur].size();i++){
            int to=graph[cur][i];
            if (visited[to]) continue;
            S.push(to);
            visited[to]=true;
        }
    }
}

//how to find connected components using DFS ??
int connected_components(int nodes){
    int count=0;
    for(int i=0;i<nodes;i++){
        if (visited[i]==true) continue;
        dfs(i);
        count++;
    }
    return count;
}

//breadth first search using queue
void bfs(int source){
    queue<int> Q;
    Q.push(source);
    visited[source]=true;
    while(!Q.empty()){
        int cur=Q.front();
        Q.pop();
        cout<<cur<<" ";
        for(int i=0;i<graph[cur].size();i++){
            int to=graph[cur][i];
            if(visited[to]==true) continue;
            Q.push(to);
            visited[to]=true;
        }
    }
}

//how to determine the level of each node in the given tree using BFS ??
void node_level(int source){
    queue<int> Q;
    Q.push(source);
    visited[source]=true;
    level[source]=0;
    while(!Q.empty()){
        int cur=Q.front();
        Q.pop();
        cout<<cur<<" "<<"is at level "<<level[cur]<<" "<<endl;
        for(int i=0;i<graph[cur].size();i++){
            int to=graph[cur][i];
            level[to]=level[cur]+1;
            if(visited[to]==true) continue;
            Q.push(to);
            visited[to]=true;
        }
    }
}
bool is_cyclic(int cur,int par){
    visited[cur]=1;
    for(int i=0;i<graph[cur].size();i++){
        int to=graph[cur][i];
        if(visited[to]==1 && to!=par ){
            return true;
        }
        else if(!visited[to]){
            return is_cyclic(to,cur);
        }
    }
    return false;
}


int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //  code starts
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> start;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
        start.pb({x,y});
    }
    //dfs(0);
    //dfs_stack(0);
    ///cout<<connected_components(n);
    //bfs(0);
    node_level(0);
    // if (is_cyclic(start[0].F,-1)) cout<<"NO"<<endl;
    // else cout<<"YES"<<endl;
}