#include <istream>
#include <sstream>
#include <vector>

#include "algorithm_function.h"

using namespace std;

void run_algorithm(vector<vector<int>> & m0, vector<vector<int>> & m1, vector<vector<int>> & mm1, int & n)
{
    for (int l = 1; l < (3*(n*n) + 1); l++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n; k++){
                    if ((mm1[i][k] + m1[k][j]) == 0 || (m1[i][k] + mm1[k][j]) == 0) {m0[i][j] = 0;}
                    if ((m1[i][k] + m0[k][j]) == 1 || (m0[i][k] + m1[k][j]) == 1) {m1[i][j] = 1;}
                    if ((mm1[i][k] + m0[k][j]) == -1 || (m0[i][k] + mm1[k][j]) == -1) {mm1[i][j] = -1;}
                }
            }
        }
    }
}
