/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw8/challenges/kahns-topological-sort/submissions/code/1317351803
 * Title: hw8_2.cpp
 * Abstract: This program will preform topological sorts.
 * Author: Kyle Dilbeck
 * ID: 4444
 * Date: 10/31/19
 * Version: 4.6 
 */


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


void read_graph(vector<vector<int>> & g,  vector<int>  &inDegree)
{
    
    int num_of_vertices;
    cin >> num_of_vertices;
    //vector<int> inDegree(num_of_vertices,0); 
    // Adjust the size of graph vector to hold all vertices.
    g.resize(num_of_vertices);
    inDegree.resize(num_of_vertices); 
    int num_of_edges;
    cin >> num_of_edges;

    int from;
    int to;
    
    for (int i = 0; i < num_of_edges; i++) 
    {
        cin >> from;
        cin >> to;
        g[from].push_back(to);
        inDegree[to]++; 
    }

    for(int i = 0 ; i < num_of_vertices ; i++)
    {
        cout << "In-degree["<<i << "]: " << inDegree[i]<< endl; 
    }

    //cout << "Order:" ; 
    

}
//end read graph

void printGraph(vector<vector<int>> & g) 
{
    cout << endl; 
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


vector<int> bfs(vector<vector<int>> & g, vector<int> &inDegree) 
{
    queue<int> q;
    int count = 0;
    vector<int> mark(g.size(), 0);
    vector<int> v;
    vector<bool> visited(inDegree.size(), false); 
    bool bool1 = false;
    int count2 = 1;  
     
    for(int i = 0 ; i < g.size(); i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i); 
        }
    }
    cout << "Order:";
    int i = 0; 
    while (!q.empty() && i < g.size()) 
    {
        int curr = q.front();
        if(i < g.size() -1)
        {
            cout << curr << "->" ;
        } 
        else
        {
            cout << curr;
        }
        
        q.pop();
        i++;
        for(int n : g[curr])
        { 
            if(visited[n] == true)//test for cycle
            {
                cout << "Cycle, exiting" << endl; return g[n]; 
            }
             inDegree[n]--; 
             if(inDegree[n] == 0)
             { 
                 q.push(n); 
                 visited[n]=true; 
             }
             
        }
        
    }//end while 
    
    return g[q.front()];
}
//end bfs


int main()
{
    vector<vector<int>> graph;
    vector<int> inDegree; 

    read_graph(graph, inDegree);

    bfs(graph, inDegree); 
    

    return 0;
}

/*TEST CASES 

5 
4
0 1
1 2
0 2
3 4


OUTPUT(CORRECT)
In-degree[0]:0
In-degree[1]:1
In-degree[2]:2
In-degree[3]:0
In-degree[4]:1
Order:0->3->1->4->2


*/