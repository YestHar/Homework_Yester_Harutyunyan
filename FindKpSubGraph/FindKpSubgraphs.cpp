#include "FindKpSubgraphs.hpp"

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

std::vector<std::vector<int>> Graph::findCompleteSubgraphs(int p) {
    std::vector<int> subset;
    std::vector<std::vector<int>> completeSubgraphs;
    findKp(p, 0, subset, completeSubgraphs);
    return completeSubgraphs;
}

bool Graph::isCompleteSubgraph(const std::vector<int>& subset) {
    for (int i = 0; i < subset.size(); ++i) {
        for (int j = i + 1; j < subset.size(); ++j) {
            if (std::find(adjList[subset[i]].begin(), adjList[subset[i]].end(), subset[j]) == adjList[subset[i]].end()) {
                return false;
            }
        }
    }
    return true;
}

void Graph::findKp(int p, int start, std::vector<int>& subset, std::vector<std::vector<int>>& completeSubgraphs) {
    if (subset.size() == p) {
        if (isCompleteSubgraph(subset)) {
            completeSubgraphs.push_back(subset);
        }
        return;
    }
    for (int i = start; i < V; ++i) {
        subset.push_back(i);
        findKp(p, i + 1, subset, completeSubgraphs);
        subset.pop_back();
    }
}

std::pair<std::vector<int>, std::vector<std::pair<int, int>>> inputGraph () {
    std::ifstream inFile("graph_input.txt");
    if (!inFile) {
        std::cerr << "Unable to open input file!" << std::endl;
        return {};
    }

    int numVertices, numEdges;
    inFile >> numVertices >> numEdges;

    std::vector<int> vertices(numVertices);
    std::vector<std::pair<int, int>> edges(numEdges);

    for (int i = 0; i < numVertices; ++i) {
        inFile >> vertices[i];
    }

    for (int i = 0; i < numEdges; ++i) {
        inFile >> edges[i].first >> edges[i].second;
    }

    inFile.close();

    return {vertices, edges};
}

Graph createGraphFromInput(const std::vector<int>& vertices, const std::vector<std::pair<int, int>>& edges) {
    Graph graph(vertices.size());
    for (const auto& edge : edges) {
        graph.addEdge(edge.first - 1, edge.second - 1);  // assuming 1-based index input
    }
    return graph;
}

void findAndPrintKpSubgraphs(Graph& graph, const std::vector<int>& vertices) {
    for (int p = 3; p <= vertices.size(); ++p) {
        std::vector<std::vector<int>> subgraphs = graph.findCompleteSubgraphs(p);
        if (!subgraphs.empty()) {
            std::cout << "K_" << p << " subgraphs:" << std::endl;
            for (const auto& subgraph : subgraphs) {
                std::cout << "Subgraph:";
                for (int v : subgraph) {
                    std::cout << " -> " << v + 1;  // converting back to 1-based index for display
                }
                std::cout << std::endl;
            }
        } else {
            break;
        }
    }
}