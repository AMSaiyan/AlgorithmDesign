#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Graph
{
	struct Vertex
	{
		int number;
		int colour;
		int degree;
		set<int> neighbours;
		Vertex(int number, int colour = -1, int degree = -1);
	};
	int vertexAmount;
	int degreeLimit;
	int chromaticNum;
	vector<Vertex> vertices;
	bool verifyColor(int& verNum, int& colour);
	void createEdge(int firstVer, int secondVer);
	void defineDegree(int verNum);
public:
	Graph(int degreeLimit = 20, int vertexAmount = 100);
	vector<Vertex>& getVertices();
	void generateRandGraph();
	bool changeColour(int verNum, int colour);
	void defineChromaticNum(int usedColors);
	int getVertexAmount();
	void showAdjMatrixAndColors();
};
