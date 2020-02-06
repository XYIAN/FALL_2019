/*
 * HackerRank link:https://www.hackerrank.com/contests/cst370-f19-hw6/challenges/connect-components/submissions/code/1317011431
 * Title: hw6_2.cpp
 * Abstract: this program will connect unconnected graphs from user input 
 * Author: Kyle Dilbeck
 * ID: 4444
 * Date: 10/16/19
 * Version: 5.6 
 */


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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


void bfs(vector<vector<int>> & g, int src) 
{
    queue<int> q;
    int count = 0;
    vector<int> mark(g.size(), 0);
    vector<int> v;
    mark[src] = ++count;
    q.push(src);
    v.push_back(src);


    while (!q.empty()) 
    {
        int curr = q.front();
        q.pop();
         
        //cout << "visiting: " << curr << endl;

        for (int i = 0; i < g[curr].size(); i++) 
        {
            int neighbor = g[curr][i];
            if(mark[neighbor] == 0) 
            {
                mark[neighbor] = ++count;
                q.push(neighbor);
            }
        }
        //cout << "debug q.size() " << q.size() << endl; 
        if(q.size() == 0)
        {
            
            for(int i = 0 ; i < mark.size() ; i++)
            {

                if(mark[i] == 0)
                {
                    mark[i] = ++count;
                    q.push(i);
                    v.push_back(i);
                }
            }

        }

    }//end while 
    
    for(int j = 0 ; j < (v.size() - 1) ; j++)
    {
        for(int k = 0; k < g[v[j]].size(); k++)
        {
            if(g[v[j]][k] == v[j+1])
            {
                v.erase(v.begin()+j+1);
            }
        }
        
    }

    if(v.size() == 1){
        cout << "No new edge:" << endl;
    }
    for(int j = 0 ; j < (v.size() - 1) ; j++)
    {
        cout << "Edge: " << v.at(j) << "-" << v.at(j+1) << endl;
    }

    cout << "\n==== Mark Array ==== " << endl;
    for (int i = 0; i < g.size(); i++)
    {
        cout << "Mark[" << i << "]: " << mark[i] << endl;
    }

    

    return;
}
//end bfs


int main()
{
    vector<vector<int>> graph;
    
    read_graph(graph);

    //cout << "==== Printing Input Graph - Vertext By Vertex =====" << endl;
    //printGraph(graph);
    
    int src = 0;
    //cout << "\n==== BFS - Source Vertext: " << src << " =====" << endl;
    bfs(graph, src);

    return 0;
}
