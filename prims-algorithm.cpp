#include <iostream>
#include <cstring>

using namespace std;

#define INF 99999
#define V 5

int graph[V][V] = {
    {0, 4, 0, 5, 2},
    {4, 0, 1, 3, 0},
    {0, 1, 0, 8, 0},
    {5, 3, 8, 0, 2},
    {2, 0, 0, 2, 0}
};

int main()
{
    int no_edge;

    // create an array to track selected vertex
    // for adjacency matrix to represent graph
    int selected[V];

    // set selected false initially
    memset(selected, false, sizeof(selected));

    // set number of edges to 0
    no_edge = 0;

    selected[0] = true;

    int x;
    int y;

    cout << "Edge" << " : " << "Weight" << endl;

    while (no_edge < V - 1)
    {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && graph[i][j])
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << graph[x][y] << endl;
        selected[y] = true;
        no_edge++;
    }


    return 0;
}