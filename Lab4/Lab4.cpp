#include "Graph.h"
#include "GreedyColorer.h"

int main()
{
    srand(time(NULL));
    Graph graph(20, 100);
    graph.generateRandGraph();
    graph.showAdjMatrixAndColors();
    GreedyColorer colorer;
    colorer.greedyColoring(graph);
    graph.showAdjMatrixAndColors();
    cout << endl;
}
