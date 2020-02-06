/*
     URL : https://www.hackerrank.com/contests/cst370-f19-hw5/challenges/bfs-hops/submissions/code/1316763660
   TITLE : hw5_2.cpp
  AUTHOR : Kyle Dilbeck
ABSTRACT : This program will find 2^n power where n is user input
      ID : 4444
    DATE : 10/4/19
  VERSION: 2.0

*/


#include <iostream>
#include <queue>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector> 
#include <utility>      // std::pair
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

        g[findIndex(from, city)].push_back(findIndex(to, city));

    }
}

void bfs(vector<string> & city, vector<vector<int>> & g, int src, int hops) 
{
    
    queue<pair<int, int> > q;
	int count = 0;
    vector<int> cities; 
	vector<int> mark(g.size(), 0);
    vector<string> print;
	mark[src] = ++count;
    q.push(make_pair(src, hops));
    while (!q.empty()) 
    {
        auto curr = q.front();
        q.pop();
        print.push_back(city[curr.first]);//print city string vector
        if(curr.second != 0)
        {
            for (int i = 0; i < g[curr.first].size(); i++) 
            {
                int neighbor = g[curr.first][i];
                if(mark[neighbor] == 0) 
                {
                    mark[neighbor] = ++count;
                    q.push(make_pair(neighbor , curr.second - 1));
                }
            }
        }
        
    }
    sort(print.begin(), print.end());
    for(int i = 0 ; i < print.size() ; i++)
    {
        cout <<  print[i] << endl; 
    }
    return;
}



int main()
{
    vector<vector<int>> graph;
    vector<string> city;
    int src = 0;
    int hops; 
    string srcCity;
    read_graph(graph, city);//fill graph 
    cin >> srcCity; 
    src = findIndex( srcCity, city); 
    cin >> hops; 
    bfs(city, graph, src, hops);
    return 0;
}
