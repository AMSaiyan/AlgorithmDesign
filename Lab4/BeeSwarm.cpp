#include "BeeSwarm.h"

//void BeeSwarm::foragerCycle(int districtNum, int foragerAmount)
//{
//	auto trySwitchColors = [this, districtNum, foragerAmount](int vertexNum) 
//	{
//		int chosenVertexColor = districts[districtNum].getVertices()[vertexNum].colour;
//		int neighbourColor;
//		bool successChosen = false;
//		bool successNeighbour = false;
//		int neighbourSuccessIndex = -1;
//		for (auto neighbour : districts[districtNum].getVertices()[vertexNum].neighbours)
//		{
//			neighbourColor = districts[districtNum].getVertices()[neighbour].colour;
//			districts[districtNum].changeColour(neighbour, -1);
//			successChosen = districts[districtNum].changeColour(vertexNum, neighbourColor);
//			successNeighbour = districts[districtNum].changeColour(neighbour, chosenVertexColor);
//			if (successChosen && successNeighbour)
//			{
//				neighbourSuccessIndex = neighbour;
//			}
//		}
//	};
//}

queue<Graph> BeeSwarm::scoutCycle()
{
	queue<Graph> scoutedDistricts;
	auto comparator = [](Graph left, Graph right)
	{
		return left.getChromaticNum() < right.getChromaticNum();
	};
	int randomScouts = (scouts / 3 > 0) ? (scouts / 3) : 1;
	int eliteScouts = scouts - randomScouts;
	sort(districts.begin(), districts.end(), comparator);
	for (int i = 0; i < eliteScouts && i < districts.size(); i++)
	{
		scoutedDistricts.push(districts[i]);
	}
	if (eliteScouts >= districts.size())
		return scoutedDistricts;
	else
	{
		for (int i = 0; i < randomScouts && i < districts.size() - eliteScouts; i++)
		{
			int randDistrictNum = rand() % (districts.size() - eliteScouts - 1) + eliteScouts - 1;
			scoutedDistricts.push(districts[randDistrictNum]);
		}
	}
	return scoutedDistricts;
}

BeeSwarm::BeeSwarm(int iterationsLimit, int scouts, int foragers) :
	iterationsLimit(iterationsLimit),
	scouts(scouts),
	foragers(foragers) {}

Graph BeeSwarm::colourGraph(Graph inputGraph)
{
	GreedyColorer greedy;
	greedy.greedyColoring(inputGraph);
	foragersForDistrict = inputGraph.getMaxDegree();
	districts.push_back(inputGraph);
	Graph bestResult = districts[0];
	queue<Graph> scoutedDistricts;
	while (iterationsLimit-- != 0)
	{
		scoutedDistricts = scoutCycle();
		int freeForagers = foragers;
		for (int i = 0; i < scouts && i < districts.size(); i++)
		{
			freeForagers -= foragersForDistrict;
			if (foragers >= 0)
				foragerCycle(i, foragersForDistrict);
			else
				foragerCycle(i, foragersForDistrict + freeForagers);
		}
		for (auto district : districts)
		{
			if (district.getChromaticNum() < bestResult.getChromaticNum())
				bestResult = district;
		}
	}
	return bestResult;
}
