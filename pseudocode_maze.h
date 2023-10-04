class Maze{
public:
    int rows;
    int cols;
    int seed;
    //created the base of maze
    std::vector<std::vector<int>> base_matrix;
    //check which spaces have been visited 
    std::vector<std::vector<int>> visited;
    //check a spaces neighbor 
    std::vector<std::pair<int,int>> neigh;

    //constructors 
    Maze(int row, int col,int seeds);
    Maze(const Maze &obj);
    //print the matrix 
    void ShowMatrix();
    std::vector<std::pair<int,int>> getNeigh(int x,int y);
    //take out certain walls 
    void removeWall(int x1, int y1, int x2, int y2);
    //print the matrix to a file 
    void genMaze(std::string outPutFile);
    

};
