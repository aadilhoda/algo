    #include<bits/stdc++.h>  //naive dfs implementation of maximum bipartite matching
    using namespace std;
    vector<int> adj[2009];
    bool mark[2009];
    int match[2009];
    void init()
    {
        for(int i=0;i<2009;++i)
        {match[i]=-1;adj[i].clear();}
    }
    bool dfs(int v){// v is in X, it reaturns true if and only if there is an augmenting path starting from v
    	if(mark[v])
    		return false;
    	mark[v] = true;
    	for(auto &u : adj[v])
    		if(match[u] == -1 or dfs(match[u])) // match[i] = the vertex i is matched with in the current matching, initially -1
    			return match[v] = u, match[u] = v, true;
    	return false;
    }
     
    int main()
    {
       
        init();
       int n;cin>>n;
        int m;cin>>m;
      
       int p=1;
        for(int i=0;i<m;++i)
        {
            int a,b;cin>>a>>b;
          adj[a].push_back(b);
        }
        int ct=0;             
 for(int i = 0;i < n;i ++)  //considering 0-based index (can loop be started from 1 if vertex are 1-indexed)
       if(match[i] == -1){   
	memset(mark, false, sizeof mark);
    if(	dfs(i)) ct++;
    }
     
     cout<<ct<<endl;   //ct=maximum bipartite matching
    
    return 0;
    } 
