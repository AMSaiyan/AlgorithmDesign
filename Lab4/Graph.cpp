#include "Graph.h"

Graph::Vertex::Vertex(int number, int colour, int degree) : number(number), colour(colour), degree(degree)
{
	neighbours = set<int>();
}

bool Graph::verifyColor(int& verNum, int& colour)
{
	for (auto neighbour : vertices[verNum].neighbours)
	{
		if (vertices[neighbour].colour == colour)
			return false;
	}
	return true;
}

void Graph::createEdge(int firstVer, int secondVer)
{
	if (firstVer == secondVer || 
		vertices[secondVer].neighbours.size() == degreeLimit ||
		vertices[firstVer].neighbours.count(secondVer) > 0 || 
		vertices[secondVer].neighbours.count(firstVer) > 0)
		return;
	vertices[firstVer].neighbours.insert(secondVer);
	vertices[secondVer].neighbours.insert(firstVer);
}

void Graph::defineDegree(int verNum)
{
	vertices[verNum].degree = vertices[verNum].neighbours.size();
}

Graph::Graph(int degreeLimit, int vertexAmount) : vertexAmount(vertexAmount), chromaticNum(-1)
{
	if (degreeLimit >= vertexAmount)
		degreeLimit = vertexAmount - 1;
	this->degreeLimit = degreeLimit;
	for (int i = 0; i < vertexAmount; i++)
		vertices.emplace_back(Vertex(i));
}

vector<Graph::Vertex> Graph::getVertices()
{
	return vertices;
}

void Graph::generateRandGraph()
{
	for (int i = 0; i < vertexAmount; i++)
	{
		int randAmount = rand() % degreeLimit + 1;
		while (vertices[i].neighbours.size() < randAmount)
		{
			int randSecond = rand() % vertexAmount;
			createEdge(i, randSecond);
		}
	}
	for (int i = 0; i < vertexAmount; i++)
		defineDegree(i);
}

bool Graph::changeColour(int verNum, int colour)
{
	if (verifyColor(verNum, colour))
	{
		vertices[verNum].colour = colour;
		return true;
	}
	else
		return false;
}
