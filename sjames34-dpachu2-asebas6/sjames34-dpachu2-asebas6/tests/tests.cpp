#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "../catch/catch.hpp"
#include "../Graph.h"

Graph createBasicGraph() {
    Graph G(6);
    G.insertVertex(1);
    G.insertVertex(2);
    G.insertVertex(3);
    G.insertVertex(4);
    G.insertVertex(5);
    G.insertVertex(6);
    G.insertEdge(1, 2, 2);
    G.insertEdge(1, 3, 4);
    G.insertEdge(2, 3, 1);
    G.insertEdge(2, 4, 7);
    G.insertEdge(3, 5, 3);
    G.insertEdge(5, 4, 2);
    G.insertEdge(4, 6, 1);
    G.insertEdge(5, 6, 5);
    return G;
}

TEST_CASE("Basic dijkstra test", "[dijkstra]") {   
    Graph G = createBasicGraph();
    //G.dijkstrasAlgo(0);
    std::vector<int> solution{0, 2, 3, 8, 6, 9};
    REQUIRE(G.dijkstrasAlgo(0) == solution);
}		

TEST_CASE("Basic BFS test", "[BFS1]"){
    Graph G = createBasicGraph();
    std::vector<int> solution{1, 2, 3, 4, 5, 6};
    REQUIRE(G.BFS(1) == solution);
}

TEST_CASE("Basic file reader", "[FileRead1]"){
    std::ifstream file;
    file.open("tests/test1.txt");
    Graph graph(file,30);
    std::vector<int> solution{1, 25}; 
    std::vector<int> result = graph.BFS(1);
    REQUIRE(result == solution);
}

TEST_CASE("Basic file reader2", "[FileRead1]"){
    std::ifstream file;
    file.open("tests/test2.txt");
    Graph graph(file, 7604);
    std::vector<int> solution{1, 7188, 430, 3134, 3026, 3010, 804, 160, 95, 377, 888};
    std::vector<int> result = graph.BFS(1);
    REQUIRE(result == solution);
    
}

TEST_CASE("Extreme file reader", "[FileRead1]"){
    std::ifstream file;
    file.open("tests/realtest.txt");
    Graph graph(file, 7604);
    std::vector<int> result = graph.BFS(1);
    std::ofstream output;
    output.open("tests/realtestout.txt");
    for(size_t i=0; i<result.size(); i++){
        output << result[i] << std::endl;
    }
    file.close();
}

TEST_CASE("Graph Constructor Size", "[constructor]") {
    Graph graph(10);
    REQUIRE(graph.getMatrix().size() == 10); 
}

TEST_CASE("Graph Constructor File Parsing Size", "[constructor]") {
    std::ifstream file;
    file.open("tests/realtest.txt");
    Graph graph(file, 7604);
    REQUIRE(graph.getMatrix().size() == 7604); 
}


/*
TEST_CASE("Test empty File", "[File Parsing]") {
    std::ifstream file;
    file.open("tests/realtest.txt");
    Graph graph(file, 0);
    REQUIRE(graph.getMatrix().size() == 0);
}
*/

TEST_CASE("Adjacent edges", "[Matrix]") {
    Graph g = createBasicGraph();
    REQUIRE(g.areAdjacent(g.getVertex(1), g.getVertex(2)) == true);
}

TEST_CASE("Non adjacent edges", "[Matrix]") {
    Graph g = createBasicGraph();
    g.insertVertex(8);
    REQUIRE(g.areAdjacent(g.getVertex(2), g.getVertex(8)) != false); 
}

TEST_CASE("Get valid edges") {

     Graph g = createBasicGraph();
     std::vector<int> ans;
     ans.push_back(2);
     ans.push_back(4);
     REQUIRE(g.incidentEdges(g.getVertex(1)) == ans); 
}





