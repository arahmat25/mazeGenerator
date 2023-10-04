Maze Constructor (int row, int col, int seeds):
    Initialize cols, rows, and seed with row, col, and seeds respectively
    Seed random number generator with seed
    Create base_matrix and visited matrices with dimensions rows x cols
    Initialize base_matrix with 15 and visited with 1
    Reduce base_matrix[0][0] by 8
    Reduce base_matrix[rows-1][cols-1] by 4

ShowMatrix():
    For i from 0 to cols:
        For x from 0 to rows:
            Display base_matrix[i][x]
        Display newline

Copy Constructor (const Maze &obj):
    Initialize rows and cols with obj.rows and obj.cols respectively
    Create a new base_matrix with dimensions rows x cols, initializing with zeros

getNeigh(int x, int y):
    Initialize neigh as an empty list
    If x > 0 and visited[x-1][y] is 1:
        Add (x-1, y) to neigh
    If x < rows - 1 and visited[x+1][y] is 1:
        Add (x+1, y) to neigh
    If y < cols - 1 and visited[x][y+1] is 1:
        Add (x, y+1) to neigh
    If y > 0 and visited[x][y-1] is 1:
        Add (x, y-1) to neigh
    Return neigh

removeWall(int x1, int y1, int x2, int y2):
    If x1 < x2:
        Reduce base_matrix[x1][y1] by 4, base_matrix[x2][y2] by 8
    Else If x1 > x2:
        Reduce base_matrix[x1][y1] by 8, base_matrix[x2][y2] by 4
    Else If y1 < y2:
        Reduce base_matrix[x1][y1] by 2, base_matrix[x2][y2] by 1
    Else If y1 > y2:
        Reduce base_matrix[x1][y1] by 1, base_matrix[x2][y2] by 2

genMaze(String outPutFile):
    Create empty lists A and neighbors
    Mark visited[0][0] as 0
    Add (0, 0) to A

    While A is not empty:
        Set current as the last element of A
        Remove the last element from A
        Get neighbors using getNeigh(current.first, current.second)

        If neighbors is not empty:
            Generate a random index idx between 0 and the size of neighbors
            Add current to A
            Pick a random neighbor from neighbors at index idx
            Remove the wall between current and neighbor using removeWall
            Mark neighbor as visited
            Add neighbor to A

    Open an output file at outPutFile
    For each row in base_matrix:
        For each element j in the row:
            Write j followed by a space to the output file
        Write a newline to the output file
