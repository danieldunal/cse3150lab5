#include <iostream>
#include <istream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

#include "ints_read_matrix.h"
#include "ints_read_vector.h"
#include "ints_write.h"

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

int main() {
    
    using namespace std;

    string files[] = {"graph_0.txt", "graph_1.txt", "graph_m1.txt"};
    string ofiles[] = {"graph_0_out.txt", "graph_1_out.txt", "graph_m1_out.txt"};
    
    ifstream in_file_0, in_file_1, in_file_m1;
    ofstream out_file_0, out_file_1, out_file_m1;

    in_file_0.open(files[0]);
    in_file_1.open(files[1]);
    in_file_m1.open(files[2]);

    vector<vector<int>> m0, m1, mm1;

    m0 = ints_read_matrix(in_file_0);
    m1 = ints_read_matrix(in_file_1);
    mm1 = ints_read_matrix(in_file_m1);

    in_file_0.close();
    in_file_1.close();
    in_file_m1.close();

    int n = m0[0].size();
    run_algorithm(m0, m1, mm1, n);

    out_file_0.open(ofiles[0]);
    out_file_1.open(ofiles[1]);
    out_file_m1.open(ofiles[2]);

    out_file_0<<m0<<endl;
    out_file_1<<m1<<endl;
    out_file_m1<<mm1<<endl;

    out_file_0.close();
    out_file_1.close();
    out_file_m1.close();
    return 0;
}