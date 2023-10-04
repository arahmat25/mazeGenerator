#include <iostream>
#include <vector>
#include "maze.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream> 


int main(int argc, char* argv[]) {
    int seed = std::stoi(argv[1]);
    int cols = std::stoi(argv[2]);
    int rows = std::stoi(argv[3]);
    std::string outfile = std::string(argv[4]);
    Maze maze(rows, cols,seed);
    maze.genMaze(outfile);

} 
