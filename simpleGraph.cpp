#include <unordered_map>

template<typename T> 
class Graph {
    public:
        int numberOfNodes = 0;
        std::unordered_map<T, std::vector<T>> adjacentList;

        void addVertex(T node) {
            // adds a node to the graph
            numberOfNodes++;
            adjacentList[node];
        }

        void addEdge(T node1, T node2) {
            // undirected graph
            auto it = adjacentList.find(node1);
            auto it2 = adjacentList.find(node2);
            if (it != adjacentList.end() && it2 != adjacentList.end()) {
                adjacentList[node1].push_back(node2);
                adjacentList[node2].push_back(node1);
            }
        }

        auto showConnections() {

            return nodeMatrix;
        }
}