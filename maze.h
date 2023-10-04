#include <vector>
#include <iostream> 
#include <string> 
class Maze{
public:
    int rows;
    int cols;
    int seed;
    std::vector<std::vector<int>> base_matrix;
    std::vector<std::vector<int>> visited;
    std::vector<std::pair<int,int>> neigh;
    // std::vector<std::vector<std::pair<int,int>>> pair;

    Maze(int row, int col,int seeds);
    Maze(const Maze &obj);
    void ShowMatrix();
    std::vector<std::pair<int,int>> getNeigh(int x,int y);
    void removeWall(int x1, int y1, int x2, int y2);
    void genMaze(std::string outPutFile);
    

};
