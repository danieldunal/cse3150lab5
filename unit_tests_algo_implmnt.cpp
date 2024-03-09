#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "ints_read_matrix.h"
#include "ints_read_vector.h"
#include "ints_write.h"
#include "algorithm_function.h"

TEST_CASE("ints_read_matrix") {
  
  SUBCASE("ints_read_matrix : edge cases - istringstream") {
    istringstream istr_0("");
    vector<vector<int>> matrix_0 = ints_read_matrix(istr_0);
    CHECK(1 == matrix_0.size());
  
    istringstream istr_99("-99");
    vector<vector<int>> matrix_99 = ints_read_matrix(istr_99);
    CHECK(-99 == matrix_99[0][0]);
    CHECK(1 == matrix_99.size());
    CHECK(1 == matrix_99[0].size());
  };
  
  SUBCASE("ints_read_matrix : small cases") {

    istringstream istr("0 1 2\n4 5 6\n7 8 9");
    vector<vector<int>> matrix = ints_read_matrix(istr);
    CHECK(0 == matrix[0][0]);
    CHECK(1 == matrix[0][1]);
    CHECK(2 == matrix[0][2]);
    CHECK(3 == matrix.size());
    CHECK(3 == matrix[0].size());
    CHECK(3 == matrix[2].size());

  };

  SUBCASE("test algorithm") {
    istringstream m0istr("0 2 2 2 2 2\n2 0 2 2 2 2\n2 2 0 2 2 2\n2 2 2 0 2 2\n2 2 2 2 0 2\n2 2 2 2 2 0");
    istringstream m1istr("2 1 2 2 2 2\n2 2 1 2 2 2\n2 2 2 1 2 2\n2 2 2 2 1 2\n2 2 2 2 2 1\n1 2 2 2 2 2");
    istringstream mm1istr("-1 2 2 2 2 2\n2 2 2 2 2 2\n2 2 2 2 2 2\n2 2 2 2 2 2\n2 2 2 2 2 2\n2 2 2 2 2 2");

    vector<vector<int>> m0 = ints_read_matrix(m0istr);
    vector<vector<int>> m1 = ints_read_matrix(m1istr);
    vector<vector<int>> m2 = ints_read_matrix(mm1istr);

    int n = m0[0].size();

    run_algorithm(m0, m1, m2, n);

    bool all0 = true;
    bool all1 = true;
    bool allm1 = true;

    for (int i = 0; i < n; i++){
      for (int j = 0; j < 0; j++){
        if (m0[i][j] != 0) {all0 = false;}
      }
    }

    for (int i = 0; i < n; i++){
      for (int j = 0; j < 0; j++){
        if (m1[i][j] != 1) {all1 = false;}
      }
    }

    for (int i = 0; i < n; i++){
      for (int j = 0; j < 0; j++){
        if (m2[i][j] != -1) {allm1 = false;}
      }
    }

    CHECK_EQ(all0, true);
    CHECK_EQ(all1, true);
    CHECK_EQ(allm1, true);
  }
}


