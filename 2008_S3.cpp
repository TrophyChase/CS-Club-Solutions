//Jordan Snyder
//Jan 23, 2014

#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

//find the shortest path through the city
int shortest_path (vector< vector<char> > &grid, int row, int column, int max_row, int max_column)
{
    int directions;
    //assume all possible directions are dead ends until proven otherwise
    int path_length [4] = {-1,-1,-1,-1};
    int min_length=50000;

    //if our position is outside the city, or on an impassible area it cannot lead to a valid solution
    if (row>max_row or column > max_column or row < 0 or column < 0 or grid[row][column]=='*')
        return -1;
    //if we reached the bottom right most square, we are at the end
    else if (row==max_row and column==max_column)
        return 1;
    else
    {
        //any solution which doubles back on itself is sub-optimal, so make the tile we are standing on impassible from now on
        directions=grid[row][column];
        grid[row][column]='*';

        //get the shortest path lengths for all possible directions we can move
        if (directions=='+' or directions == '|')

            path_length[0]=shortest_path(grid, row+1, column, max_row, max_column);
            path_length[1]=shortest_path(grid, row-1, column, max_row, max_column);
        }

        if (directions=='+' or directions == '-')
        {
            path_length[2]=shortest_path(grid, row, column+1, max_row, max_column);
            path_length[3]=shortest_path(grid, row, column-1, max_row, max_column);
        }

        //find the shortest path length available ( -1 indicates an invalid path, so ignore them)
        for (int i=0; i<4; i++)
        {
            if (path_length[i]< min_length and path_length[i]!=-1)
                min_length=path_length[i];
        }

        //if the minimum length is still the default, then all directions must be impassible
        if (min_length==50000)
        {
            return -1;
        }


        return min_length+1;
}


int main()
{
    int rows, columns, num_cases;
    //this forms our 2 dimensional grid of tiles
    vector < vector <char> > grid;
    //this just holds the output until we need it
    stringstream output("");

    cin >> num_cases;

    for (int solutions=1;solutions<=num_cases; solutions++)
    {
        cin >> rows >> columns;
        //resize the vectors to contain the appropriate number of elements
        grid.resize(rows);
        for (int i=0;i<rows;i++)
            grid[i].resize(columns);

        //fill the grid
        for (int x=0; x<rows; x++)
         {
            for (int y=0; y<columns; y++)
                {
                    cin >>  grid[x][y];
                }
         }

        //store the shortest path in output for later
        output << shortest_path(grid,0,0,rows-1,columns-1) << endl;
    }

    cout << output.str();

}
