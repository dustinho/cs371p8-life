#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#ifndef Life_h
#define Life_h

using namespace std;

// forward declaration of TestLife to add as a friend
namespace cs {
	struct TestLife;
}

template <typename T>
class Life {

	// add TestLife as a friend so it access the grid
	friend struct cs::TestLife;

    private:
        vector<vector<T> > _grid;
        int generation;
        int population;
        int rows;
        int cols;


    public:
        Life() {
            generation = 0;
            population = 0;
            rows = 0;
            cols = 0;
        }

        friend istream& operator>> (istream& in, Life<T>& l) {
            string line;
            int linenumber = 0;
            while (getline(in, line)){
                if (linenumber == 0){
                    l.rows = atoi(line.c_str());
                } else if (linenumber == 1){
                    l.cols = atoi(line.c_str());
                } else {
                    vector<T> row;
                    for (int i = 0; i < (int) line.length(); ++i){
                        //cout << "seg now?" << endl;
                        //l._grid[linenumber][i] = new T(line[i]);
                        row.push_back(T(line[i]));
                        //cout << "seg NOW!" << endl;
                    }
                    l._grid.push_back(row);
                }
                ++linenumber;

            }
            assert((int) l._grid.size() == l.rows && (int) l._grid[0].size() == l.cols);

            return in;
        }

        friend ostream& operator<< (ostream& out, const Life<T>& l) {
            out << "Generation = " << l.generation << ", Population = " << l.population << "." << endl;
            for (int i = 0; i < l.rows; ++i){
                for (int j = 0; j < l.cols; ++j){
                    out << l._grid[i][j].get();
                }
                out << std::endl;
            }
            out << endl;
            return out;
        }

        void move() {
            // Increment neighbor count of center cells
            for (int r = 1; r < rows-1; ++r) {
                for (int c = 1; c < cols-1; ++c) {
                    if (_grid[r][c].isAlive()) {
                        _grid[r-1][c].incNeighbors();
                        _grid[r][c-1].incNeighbors();
                        _grid[r][c+1].incNeighbors();
                        _grid[r+1][c].incNeighbors();

                        _grid[r-1][c-1].conwayInc();
                        _grid[r-1][c+1].conwayInc();
                        _grid[r+1][c-1].conwayInc();
                        _grid[r+1][c+1].conwayInc();
                    }
                }
            }

            // Increment neighbor count of sides
            for (int r = 1; r < rows-1; ++r) {
                int c = 0;
                if (_grid[r][c].isAlive()) {
                    _grid[r-1][c].incNeighbors();
                    _grid[r][c+1].incNeighbors();
                    _grid[r+1][c].incNeighbors();

                    _grid[r-1][c+1].conwayInc();
                    _grid[r+1][c+1].conwayInc();
                }

                c = cols - 1;
                if (_grid[r][c].isAlive()) {
                    _grid[r-1][c].incNeighbors();
                    _grid[r][c-1].incNeighbors();
                    _grid[r+1][c].incNeighbors();

                    _grid[r-1][c-1].conwayInc();
                    _grid[r+1][c-1].conwayInc();
                }
            }

            // Increment neighbor count of top sides
            for (int c = 1; c < cols-1; ++c) {
                int r = 0;
                if (_grid[r][c].isAlive()) {
                    _grid[r][c-1].incNeighbors();
                    _grid[r][c+1].incNeighbors();
                    _grid[r+1][c].incNeighbors();

                    _grid[r+1][c-1].conwayInc();
                    _grid[r+1][c+1].conwayInc();
                }

                r = rows - 1;
                if (_grid[r][c].isAlive()) {
                    _grid[r-1][c].incNeighbors();
                    _grid[r][c-1].incNeighbors();
                    _grid[r][c+1].incNeighbors();

                    _grid[r-1][c-1].conwayInc();
                    _grid[r-1][c+1].conwayInc();
                }
            }

            // Increment neighbor count of corners
            int r;
            int c;

            r = 0;
            c = 0;
            if (_grid[r][c].isAlive()) {
                _grid[r][c+1].incNeighbors();
                _grid[r+1][c].incNeighbors();

                _grid[r+1][c+1].conwayInc();
            }

            r = 0;
            c = cols-1;
            if (_grid[r][c].isAlive()) {
                _grid[r][c-1].incNeighbors();
                _grid[r+1][c].incNeighbors();

                _grid[r+1][c-1].conwayInc();
            }

            r = rows-1;
            c = 0;
            if (_grid[r][c].isAlive()) {
                _grid[r-1][c].incNeighbors();
                _grid[r][c+1].incNeighbors();

                _grid[r-1][c+1].conwayInc();
            }

            r = rows-1;
            c = cols-1;
            if (_grid[r][c].isAlive()) {
                _grid[r-1][c].incNeighbors();
                _grid[r][c-1].incNeighbors();

                _grid[r-1][c-1].conwayInc();
            }

            // Eval each cell
			population = 0;
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    _grid[r][c].eval();
                    _grid[r][c].setNeighbors(0);

					if (_grid[r][c].isAlive()) {
						++population;
					}
                }
            }
			++generation;
        }


};

#endif // Life_h

