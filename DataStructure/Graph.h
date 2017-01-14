
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>

struct Edge {

	Edge(const std::string& start, const std::string& end, int cost)
		: startEdge(start)
		, endEdge(end)
		, weight(cost)
	{
	}

	std::string startEdge;
	std::string endEdge;
	int weight;
};

class Graph
{
public:
	void addVertex(const std::string& vertex)
	{
		vertexList.push_back(vertex);
	}

	void addEdges(const std::string& start, const std::string& end, int cost)
	{
		edgeList.push_back( Edge(start, end, cost) );
	}


private:
	std::vector<std::string> vertexList;
	std::vector<Edge>		 edgeList;
};

#endif
