/*
     URL : https://www.hackerrank.com/contests/cst370-f19-hw5/challenges/dfs-4
   TITLE : hw5_3.cpp
  AUTHOR : Kyle Dilbeck
ABSTRACT : This program will preform DFS on given int input 
      ID : 4444
    DATE : 10/4/19
  VERSION: 4.0

*/

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

void read_graph(vector<vector<int>> & g)
{
    int num_of_vertices;
    cin >> num_of_vertices;
    
    // Adjust the size of graph vector to hold all vertices.
    g.resize(num_of_vertices);
    
    int num_of_edges;
    cin >> num_of_edges;

    int from;
    int to;
    for (int i = 0; i < num_of_edges; i++) 
    {
        cin >> from;
        cin >> to;
        g[from].push_back(to);
    }
    

    for(int i = 0; i < num_of_vertices; i++)
    {
        for(int j = 0; j < g[i].size(); j++)
        {
            sort(g[i].begin(), g[i].end());
        }
    }
}

void printGraph(vector<vector<int>> & g) 
{
    for (int i = 0; i < g.size(); i++) 
    {
        cout << i;
        for (int j = 0; j < g[i].size(); j++) 
        {
            cout << " -> " << g[i][j];
        }
        cout << endl;
    }
}

void dfs(vector<vector<int>> & g, int src) 
{
    stack<int> s;
	int count = 0;
	vector<int> mark(g.size(), 0);
    
	mark[src] = ++count;
    s.push(src);
    while (!s.empty()) 
    {
        int curr = s.top();
        for (int i = 0; i < g[curr].size(); i++) 
        {
            
            int neighbor = g[curr][i];

            // cout << "DEBUG: CURRENT " << curr << endl ;
            // cout << "DEBUG: neighbor " << neighbor << endl ;
            
            if(mark[neighbor] == 0) 
            {
                mark[neighbor] = ++count; 
                s.push(neighbor);
                curr = s.top();
                i = -1;
            }
            
        }
        s.pop();
    }


	for (int i = 0; i < g.size(); i++)
	{
		cout << "Mark[" << i << "]:" << mark[i] << endl;
	}

    return;
}

int main()
{
    vector<vector<int>> graph;
    read_graph(graph);
    int src = 0;
    dfs(graph, src);

    return 0;
}
