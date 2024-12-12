#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

/* ================================================================================ */

class Edge {
    int vertex;
    int weight;
};

class Graph {
    int numVertices;
    vector<vector<Edge>> adjList;
};

Graph createGraph(int numVertices) {
    Graph graph;
    graph.numVertices = numVertices;
    graph.adjList.resize(numVertices);

    return graph;
}

void addEdge(Graph& graph, int src, int dest, int weight) {
    Edge edge;
    edge.vertex = dest;
    edge.weight = weight;

    graph.adjList[src].push_back(edge);
    edge.vertex = src;
    // adding the reverse edge, since the graph is undirected
    graph.adjList[dest].push_back(edge);
}

/* ================================================================================ */

void primMST(Graph& graph) {
    vector<bool> visited(graph.numVertices, false);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>> pq;

    visited[0] = true;

    for (const auto& edge : graph.adjList[0]) {
        pq.push({edge.weight, {0, edge.vertex}});
    }

    cout << "Edges of the Minimum Spanning Tree:\n";
    while (!pq.empty()) {
        auto edge = pq.top();
        pq.pop();

        // if the destination vertex has not been visited yet, add the edge to the MST
        if (!visited[edge.second.second]) {
            cout << "Vertex " << edge.second.first << " - Vertex " << edge.second.second << " : Weight = " << edge.first << "\n";

            // mark the destination vertex as visited
            visited[edge.second.second] = true;

            // add all the edges adjacent to the destination vertex to the priority queue
            for (const auto& adjacentEdge : graph.adjList[edge.second.second]) {
                if (!visited[adjacentEdge.vertex]) {
                    pq.push({adjacentEdge.weight, {edge.second.second, adjacentEdge.vertex}});
                }
            }
        }
    }
}

int main() {

    // create a basic undirected graph

    Graph graph = createGraph(5);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    primMST(graph);

    return 0;
}