#include "Graph.h"
#include "GreedyColorer.h"

int main()
{
    srand(time(NULL));
    Graph graph(20, 100);
    graph.generateRandGraph();
    GreedyColorer colorer;
    colorer.greedyColoring(graph);
    cout << endl;
}
