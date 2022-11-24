#include "Graph.h"

Graph::Vertex::Vertex(int number, int colour, int degree) : number(number), colour(colour), degree(degree)
{
	neighbours = set<int>();
}

bool Graph::verifyColor(int& verNum, int& colour)
{
	if (colour == -1)
		return true;
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
	if (this->degreeLimit == 0)
	{
		this->degreeLimit = 1;
		this->vertexAmount = 2;
	}
	for (int i = 0; i < this->vertexAmount; i++)
		vertices.emplace_back(Vertex(i));
}

vector<Graph::Vertex>& Graph::getVertices()
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

void Graph::defineChromaticNum(int usedColors)
{
	chromaticNum = usedColors;
}

int Graph::getVertexAmount()
{
	return vertexAmount;
}

void Graph::showAdjMatrixAndColors()
{
	string tableHeader = "        ";
	for (int i = 0; i < vertexAmount; i++)
	{
		tableHeader += to_string(i) + "   ";
	}
	cout << tableHeader << endl;
	for (int i = 0; i < vertexAmount; i++)
	{
		cout << "\n" << "   " << i << "|   ";
		for (int j = 0; j < vertexAmount; j++)
		{
			if (vertices[i].neighbours.count(j) > 0)
				cout << "1" << "   ";
			else
				cout << "0" << "   ";
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "Colors:" << endl << tableHeader << "\n\n        ";
	for (int i = 0; i < vertexAmount; i++)
		cout << vertices[i].colour << "   ";
	cout << endl << endl << endl;
}
