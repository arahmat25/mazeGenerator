#include "maze.h"
#include <iostream>
#include <utility>
#include <ostream>
#include <fstream> 

Maze::Maze(int row, int col,int seeds){
    this->cols = row;
    this-> rows = col;
    this->seed = seeds;
    srand(seed);
    std::cout << "Rows " << rows << " " << "Cols " << cols << "\n";
    //makes base matrix
    for (int i = 0; i < rows; i++) {
        std::vector<int> temp;
        std::vector<int> hold;
        for (int j = 0; j < cols; j++) {
            temp.push_back(15);
            hold.push_back(1);


        }
        this->base_matrix.push_back(temp);
        visited.push_back(hold);

    }


    this->base_matrix[0][0] -=8;
    this->base_matrix[rows-1][cols-1] -=4;
}

void Maze::ShowMatrix(){

    for(int i = 0; i < cols; i++){
        for(int x = 0; x < rows; x++){
            std::cout << base_matrix[i][x] << " ";
        }
        std::cout << std::endl;
    }

}
//construct base maze
Maze::Maze(const Maze &obj) {
    this->rows = obj.rows;
    this->cols = obj.cols;
    for (int i = 0; i < rows; i++) {
        std::vector<int> temp;
        for (int j = 0; j < cols; j++) {
            temp.push_back(0);
        }
        this->base_matrix.push_back(temp);
    }
}

std::vector<std::pair<int,int>> Maze::getNeigh(int x,int y){
    neigh.clear();
    if(x > 0 && visited[x-1][y] == 1){
        neigh.push_back(std::make_pair(x-1,y));

    }
    if(x < (rows - 1) && visited[x+1][y] == 1){
        neigh.push_back(std::make_pair(x+1,y));
    }
    if(y < (cols -1) && visited[x][y+1] == 1){
        neigh.push_back(std::make_pair(x,y+1));
    }
    if(y > 0 && visited[x][y-1] == 1){
        neigh.push_back(std::make_pair(x,y-1));
    }
    
    return neigh;

}
void Maze::removeWall(int x1, int y1, int x2, int y2){
    //N = 8, S = 4, E = 2, W = 1
    if(x1 < x2){
        base_matrix[x1][y1] = (base_matrix[x1][y1] - 4);
        base_matrix[x2][y2] = (base_matrix[x2][y2] - 8);
    }
    else if (x1 > x2){
        base_matrix[x1][y1] = (base_matrix[x1][y1] - 8);
        base_matrix[x2][y2] = (base_matrix[x2][y2] - 4);
    }
    else if(y1 < y2){
        base_matrix[x1][y1] = (base_matrix[x1][y1] - 2);
        base_matrix[x2][y2] = (base_matrix[x2][y2] - 1);
    }
    else if(y1 > y2) {
        base_matrix[x1][y1] = (base_matrix[x1][y1] - 1);
        base_matrix[x2][y2] = (base_matrix[x2][y2] - 2);
    }
}

void Maze::genMaze(std::string outPutFile){
//create empty dynamic array `A`
    std::vector<std::pair<int,int>> A;
    std::vector<std::pair<int,int>> neighbors;

    //first pair
    std::pair<int,int> first_cell = std::make_pair(0,0);
    //std::vector<std::pair<int,int>> neighbors;

//mark cell [0,0] as visited
    visited[first_cell.first][first_cell.second] = 0;
//insert cell [0,0] at the end of `A`
    A.push_back(first_cell);
//while `A` is not empty
    while(!A.empty()){
        //`current` <- remove last element from `A`
        auto current = A.back();
        A.pop_back();
        
        //if `neighbors` is not empty
        
        neighbors = getNeigh(current.first,current.second);
        if(!neighbors.empty()){
            int idx = std::rand() / ((RAND_MAX + 1u) / neigh.size());
            //insert `current` at the end of `A`
            A.push_back(current);
            //`neigh` <- pick a random neighbor from `neighbors`
            // A.push_back(current);
            //remove the wall between `current` and `neigh`
            removeWall(current.first,current.second,neigh[idx].first,neigh[idx].second);
            //N = 8, S = 4, E = 2, W = 1
            //mark `neigh` as visited
            visited[neigh[idx].first][neigh[idx].second] = 0;
            //insert `neigh` at the end of `A`
            A.push_back(neigh[idx]);
            //endif
        }

        

//end while
    }
    std::ofstream output_file(outPutFile);
    for (std::vector<std::vector<int>>::const_iterator i = (base_matrix).begin(); i != (base_matrix).end(); ++i) {
        for (std::vector<int>::const_iterator j = i->begin(); j != i->end(); ++j) {
            output_file << *j << " ";
        }
        output_file << "\n";
    }
    
}