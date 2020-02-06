// A sample program to conduct the breadth first search (BFS). 
// Written by EIR and Dr. Byun for CST370.

// Input graph format:
//   - Number of vertices
//   - Number of edges
//   - Each edge info with a starting and an ending vertices.
// First Example
/* 
3 
2
0 1
1 2
*/

// Second example
/* 
5
4
0 1
0 2
2 3
3 4
*/

// Third example
/* 
5
10
0 1
1 0
0 4
4 0
1 4
4 1
1 2
2 1
2 4
4 2
*/

#include <iostream>
#include <queue>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector> 
using namespace std;




int findIndex(string s, vector<string>  & city)
{
    for(int i = 0 ; i < city.size(); i++ )
    {
        if(s == city[i])
        {
            return i; 
        }
    }
    return -1; 
}


void read_graph(vector<vector<int>> & g, vector<string>  & city)
{
     
    int num_of_vertices;
    cin >> num_of_vertices;
    g.resize(num_of_vertices);
    city.resize(num_of_vertices); // Adjust the size of graph vector to hold all vertices

    for(int i = 0 ; i < num_of_vertices; i++)
    {
        cin >> city[i] ; 
    }
    
   
    
    int num_of_edges;
    cin >> num_of_edges;
    //cout << num_of_edges;

    string from;
    string to;
    
    for (int i = 0; i < num_of_edges; i++) 
    {
        cin >> from;
        cin >> to;
        //cout << "index: " << findIndex(from, city) << "    index2: " << findIndex(to, city)<< endl; 
        g[findIndex(from, city)].push_back(findIndex(to, city));

    }
}



void printGraph(vector<string> & city, vector<vector<int>> & g) 
{
    for (int i = 0; i < g.size(); i++) 
    {

        cout << city[i] ;
        for (int j = 0; j < g[i].size(); j++) 
        {
            cout << " -> " << city[g[i][j]];
        }
        cout << endl;
    }
}


void bfs(vector<string> & city, vector<vector<int>> & g, int src) 
{
    
    queue<int> q;
	int count = 0;
	vector<int> mark(g.size(), 0);
    vector<string> print;
	mark[src] = ++count;
    q.push(src);
    while (!q.empty()) 
    {
        int curr = q.front();
        q.pop();

        print.push_back(city[curr]);
        //cout << city[curr] << endl;
        for (int i = 0; i < g[curr].size(); i++) 
        {
            int neighbor = g[curr][i];
            if(mark[neighbor] == 0) 
            {
				mark[neighbor] = ++count;
                q.push(neighbor);
            }
        }
        
        
    }
    sort(print.begin(), print.end());
    for(int i = 0 ; i < print.size() ; i++)
    {
        cout <<  print[i] << endl; 
    }
    //cout << endl; 

    //cout << "\n==== Mark Array ==== " << endl;
// 	for (int i = 0; i < g.size(); i++)
// 	{
// 		cout << "Mark[" << i << "]: " << mark[i] << endl;
// 	}

    return;
}



int main()
{
    vector<vector<int>> graph;
    vector<string> city;
    int src = 0;
    string srcCity;
    //

    read_graph(graph, city);
    // cout << "==== Printing Input Graph - Vertext By Vertex =====" << endl;
    // printGraph(city, graph);
   
     
    cin >> srcCity; 
    src = findIndex( srcCity, city); 
    // cout <<endl<<findIndex( srcCity, city) << endl;

    // cout << "\n==== BFS - Source Vertext: " << src << " =====" << endl;
    bfs(city, graph, src);

    

    return 0;
}
