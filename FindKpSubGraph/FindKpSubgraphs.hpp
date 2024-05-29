#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <utility>

class Graph {
public:
    Graph(int vertices) : adjList(vertices), V(vertices) {}

    void addEdge(int u, int v);

    std::vector<std::vector<int>> findCompleteSubgraphs(int p);
private:
    std::vector<std::vector<int>> adjList;
    int V;

    bool isCompleteSubgraph(const std::vector<int>& subset);
    void findKp(int p, int start, std::vector<int>& subset, std::vector<std::vector<int>>& completeSubgraphs);
};

std::pair<std::vector<int>, std::vector<std::pair<int, int>>> inputGraph ();
Graph createGraphFromInput(const std::vector<int>& vertices, const std::vector<std::pair<int, int>>& edges);
void findAndPrintKpSubgraphs(Graph& graph, const std::vector<int>& vertices);