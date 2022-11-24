#include "GreedyColorer.h"

void GreedyColorer::colorVer(Graph& graph, int verNum)
{
	int colorNum = 0;
	while (!graph.changeColour(verNum, colorNum))
	{
		colorNum++;
	}
	if (usedColors.count(colorNum) == 0)
		usedColors.insert(colorNum);
}

void GreedyColorer::traversalGraph(Graph& graph)
{
	for (int i = 0; i < graph.getVertexAmount(); i++)
		colorVer(graph, i);
}

GreedyColorer::GreedyColorer() : usedColors(set<int>()){}

int GreedyColorer::greedyColoring(Graph& graph)
{
	usedColors.clear();
	if (graph.getVertexAmount() > 0)
		traversalGraph(graph);
	graph.defineChromaticNum(usedColors.size());
	return usedColors.size();
}
