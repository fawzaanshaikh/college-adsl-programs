#include <iostream>

#define infinite 9999

using namespace std;

class Graph
{
    public:
        int no_of_nodes;
        int graph_adj_matrix[20][20];
        void acceptGraph();
        void displayGraph();
        void calculateDistance();
};

void Graph :: acceptGraph()
{
    cout << "Enter the number of nodes : ";
    cin >> no_of_nodes;

    int start_node, end_node;
    // Setting initial values to 9999
    for (start_node = 1; start_node <= no_of_nodes; start_node++)
    {
        for (end_node = 1; end_node <= no_of_nodes; end_node++)
        {
            graph_adj_matrix[start_node][end_node] = infinite;
        }
    }

    // Accepting input edge-wise
    for (start_node = 1; start_node <= no_of_nodes; start_node++)
    {
        for (end_node = start_node + 1; end_node <= no_of_nodes; end_node++)
        {
            cout << "Is there an edge between " << start_node << " and " << end_node << "? (weight) : ";
            cin >> graph_adj_matrix[start_node][end_node];
        }
    }
}

void Graph :: displayGraph()
{
    int start_node, end_node;
    // Display the graph matrix
    for (start_node = 1; start_node <= no_of_nodes; start_node++)
    {
        for (end_node = 1; end_node <= no_of_nodes; end_node++)
        {
            cout << graph_adj_matrix[start_node][end_node] << "\t";
        }
        cout << "\n";
    }
}

void Graph :: calculateDistance()
{
    int vertex, visited[20], min_distance[20];

    for (vertex = 1; vertex <= no_of_nodes; vertex++)
    {
        visited[vertex] = 0;
        min_distance[vertex] = infinite;
    }

    int source, destination;
    cout << "Enter source and destination vertex : ";
    cin >> source >> destination;

    visited[source] = 1;
    min_distance[source] = 0;

    
}

int main()
{
    Graph graphObj;
    graphObj.acceptGraph();
    graphObj.displayGraph();

    return 0;
}