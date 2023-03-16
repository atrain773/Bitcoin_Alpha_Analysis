#include <iostream>
#include <fstream>
#include "Graph.h"
#include "cs225/PNG.h"
#include <fstream>

/*int main (int argc, const char * argv[]) {
    std::cout << "Hello World" << std::endl;
}*/

int main(){
    std::ifstream file;
    file.open("tests/realtest.txt");
    Graph graph(file, 7604);
    
    
    cs225::PNG* g = graph.drawGraph();
    g->writeToFile("out.png");
    

}