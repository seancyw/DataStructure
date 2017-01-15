
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <map>

namespace graphStructure {

	struct Edge {
		Edge(size_t start, size_t end, size_t cost)
			: startIndex(start)
			, endIndex(end)
			, weight(cost)
		{
		}

		size_t startIndex;
		size_t endIndex;
		size_t weight;
	};

	class Graph
	{
	public:
		Graph()
		{
		}

		~Graph()
		{
		}

		bool addVertex(const std::string& vertex)
		{
			if (contains(vertex)) {
				std::cout << "vertex " << vertex << " existed in the graph. Can't be added.\n";
				return false;
			}
			
			vertexList.push_back(vertex);
			std::cout << "vertex " << vertex << " is added to the graph.\n";

			return true;
		}

		bool addEdges(const std::string& start, const std::string& end, size_t cost)
		{
			size_t startIndex = getVertexIndex(start);
			size_t endIndex = getVertexIndex(end);

			//return if both start and end index is the same
			//Assume no self-loop on the vertex
			if (startIndex == endIndex || startIndex == -1 || endIndex == -1) {
				std::cout << "Cannot adding the vertex\n";
				return false;
			}

			//Assume this is an undirected graph
			edgeList.push_back(Edge(startIndex, endIndex, cost));

			std::cout << "Edges between " << start << " and " << end << " is added\n";

			return true;
		}

		bool isLinkBetweenVertex(const std::string& start, const std::string& end)
		{
			size_t startIndex = getVertexIndex(start);
			size_t endIndex = getVertexIndex(end);

			//return if both start and end index is the same
			//Assume no self-loop on the vertex
			if (startIndex == endIndex) {
				std::cout << "No link between vertex\n";
				return false;
			}

			return std::any_of(edgeList.begin(), edgeList.end(), [&](Edge & edge) { 
			return (edge.startIndex == startIndex && edge.endIndex == endIndex) || (edge.startIndex == endIndex && edge.endIndex == startIndex); });
		}

		std::vector<std::string> getAdjacentVertex(const std::string& vertex)
		{
			std::vector<std::string> adjacentList;

			//get the vertex index;
			size_t index = getVertexIndex(vertex);

			//retrieve the edge list adjacent vertex
			for (size_t i = 0; i < edgeList.size(); ++i) {

				if(edgeList[i].startIndex == index)
					adjacentList.push_back(getVertexName(edgeList[i].endIndex));
				else if(edgeList[i].endIndex == index)
					adjacentList.push_back(getVertexName(edgeList[i].startIndex));
			}

			return adjacentList;
		}

		void printAdjacentVertexList(const std::string& vertex)
		{
			//get the vertex index;
			size_t index = getVertexIndex(vertex);

			std::cout << "vertex " << vertex << " contains adjacent vertex : ";

			//retrieve the edge list adjacent vertex
			for (size_t i = 0; i < edgeList.size(); ++i) {
				
				if (edgeList[i].startIndex == index)
					std::cout << getVertexName(edgeList[i].endIndex) << " ";
				else if (edgeList[i].endIndex == index)
					std::cout << getVertexName(edgeList[i].startIndex) << " ";
			}

			std::cout << std::endl;
		}

	private:
		std::vector< std::string > vertexList;
		std::vector< Edge > edgeList;

		size_t getVertexIndex(const std::string& vertex)
		{
			for (size_t i = 0; i < vertexList.size(); ++i) {

				if (vertexList[i] == vertex) {
					return i;
				}
			}
			return -1;
		}

		std::string getVertexName(const size_t& index)
		{
			return vertexList[index];
		}

		bool contains(const std::string vertex)
		{
			for (size_t i = 0; i < vertexList.size(); ++i) {

				if (vertexList[i] == vertex)
					return true;
			}

			return false;
		}
	};

	void testGraph()
	{
		Graph graph;

		graph.addVertex("a");
		graph.addVertex("b");
		graph.addVertex("c");
		graph.addVertex("d");
		graph.addVertex("e");
		graph.addVertex("f");
		graph.addVertex("g");
		graph.addVertex("h");

		graph.addEdges("a", "h", 19);
		graph.addEdges("a", "e", 2);
		graph.addEdges("a", "f", 3);
		graph.addEdges("a", "g", 5);
		graph.addEdges("b", "c", 19);
		graph.addEdges("d", "g", 2);

		std::cout << std::endl;
		std::cout << "Link between a and f is : " << graph.isLinkBetweenVertex("a", "f") << std::endl;
		std::cout << "Link between d and e is : " << graph.isLinkBetweenVertex("d", "e") << std::endl;

		std::cout << "Adjacent list for a is:\n";
		graph.printAdjacentVertexList("a");
	}
}
#endif
