// Copyright 2024 Marina Usova

#define MATRIX
#ifdef MATRIX

#include <iostream>
#include <iomanip>
#include "../lib_easy_example/easy_example.h"
#include "matrix_calc.h"
#include "../lib_matrix/matrix.h"
#include "../lib_point/point.h"
#include "../lib_list/list.h"

int main() {
    //print_main_menu();


    List<int> list;

    for (int i = 0; i < 10; i++)
        list.push_back(i * 3 + 1);

    for (List<int>::Iterator it = list.begin();
        it != list.end(); it++) {
        std::cout << *it << " ";
    }
  return 0;
}

#endif  // MATRIX
