#include "FindKpSubgraphs.hpp"

int main() {
    auto [vertices, edges] = inputGraph();
    if (vertices.empty() || edges.empty()) {
        return 1;  
    }

    Graph g = createGraphFromInput(vertices, edges);
    findAndPrintKpSubgraphs(g, vertices);
    
    return 0;
}
