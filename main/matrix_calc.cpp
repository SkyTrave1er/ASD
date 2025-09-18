#include "matrix_calc.h"
#include <iostream>
#include <stdexcept>
#include <Windows.h>
#include "../lib_matrix/matrix.h"

void print_main_menu() {
    int choice;
    std::cout << "Choose:" << std::endl;
    std::cout << "1. Matrix" << std::endl;
    std::cout << "2. Triangle Matrix" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        print_matrix_menu();
        break;
    case 2:
        system("cls");
        print_tmatrix_menu();
        break;
    case 0:
        break;
    default:
        std::cout << "Wrong input";
        break;
    }
}

void print_matrix_menu() {
    int choice;
    std::cout << "Choose the operation:" << std::endl;
    std::cout << "1. Matrix + Matrix" << std::endl;
    std::cout << "2. Matrix - Matrix" << std::endl;
    std::cout << "3. Matrix * Matrix" << std::endl;
    std::cout << "4. Matrix * Vector" << std::endl;
    std::cout << "5. Matrix * Scalar" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    switch (choice) {
    case 1:
        system("cls");
        matr_plus();
        break;
    case 2:
        system("cls");
        matr_minus();
        break;
    case 3:
        system("cls");
        matr_umn_matr();
        break;
    case 4:
        system("cls");
        matr_umn_vec();
        break;
    case 5:
        system("cls");
        matr_umn_int();
        break;
    default:
        std::cout << "Wrong input";
        break;
    }
}

void print_tmatrix_menu() {
    int choice;
    std::cout << "Choose the operation:" << std::endl;
    std::cout << "1. Triangle Matrix + Triangle Matrix" << std::endl;
    std::cout << "2. Triangle Matrix - Triangle Matrix" << std::endl;
    std::cout << "3. Triangle Matrix * Triangle Matrix" << std::endl;
    std::cout << "4. Triangle Matrix * Vector" << std::endl;
    std::cout << "5. Triangle Matrix * Scalar" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    switch (choice) {
    case 1:
        system("cls");
        tmatr_plus();
        break;
    case 2:
        system("cls");
        tmatr_minus();
        break;
    case 3:
        system("cls");
        tmatr_umn_tmatr();
        break;
    case 4:
        system("cls");
        tmatr_umn_vec();
        break;
    case 5:
        system("cls");
        tmatr_umn_int();
        break;
    default:
        std::cout << "Wrong input";
        break;
    }
}

void matr_plus() {
    int r1, r2, c1, c2;
    while (1) {
        std::cout << "Enter the first matrix size: " << std::endl;
        std::cin >> r1;
        std::cin >> c1;
        std::cout << "Enter the second matrix size: " << std::endl;
        std::cin >> r2;
        std::cin >> c2;
        if (c1 != r2) {
            std::cout << "Wrong input" << std::endl;
            Sleep(2000);
            system("cls");
        }
        else {
            break;
        }
    }
    Matrix<int> a(r1, c1);
    Matrix<int> b(r2, c2);
    std::cout << "Enter the first matrix data: " << std::endl;
    std::cin >> a;
    std::cout << "Enter the second matrix data: " << std::endl;
    std::cin >> b;
    Matrix<int> result = a + b;
    std::cout << "Result:" << std::endl << result;
}

void matr_minus() {
    int r1, r2, c1, c2;
    while (1) {
        std::cout << "Enter the first matrix size: " << std::endl;
        std::cin >> r1;
        std::cin >> c1;
        std::cout << "Enter the second matrix size: " << std::endl;
        std::cin >> r2;
        std::cin >> c2;
        if (c1 != r2) {
            std::cout << "Wrong input" << std::endl;
            Sleep(2000);
            system("cls");
        }
        else {
            break;
        }
    }
    Matrix<float> a(r1, c1);
    Matrix<float> b(r2, c2);
    std::cout << "Enter the first matrix data: " << std::endl;
    std::cin >> a;
    std::cout << "Enter the second matrix data: " << std::endl;
    std::cin >> b;
    Matrix<float> result = a - b;
    std::cout << "Result:" << std::endl << result;
}
void matr_umn_matr() {
    int r1, r2, c1, c2;
    while (1) {
        std::cout << "Enter the first matrix size: " << std::endl;
        std::cin >> r1;
        std::cin >> c1;
        std::cout << "Enter the second matrix size: " << std::endl;
        std::cin >> r2;
        std::cin >> c2;
        if (c1 != r2) {
            std::cout << "Wrong input" << std::endl;
            Sleep(2000);
            system("cls");
        }
        else {
            break;
        }
    }
    Matrix<float> a(r1, c1);
    Matrix<float> b(r2, c2);
    std::cout << "Enter the first matrix data: " << std::endl;
    std::cin >> a;
    std::cout << "Enter the second matrix data: " << std::endl;
    std::cin >> b;
    Matrix<float> result = a * b;
    std::cout << "Result:" << std::endl << result;
}
void matr_umn_vec() {
    int r, c;
    std::cout << "Enter the matrix size: " << std::endl;
    std::cin >> r;
    std::cin >> c;
    Matrix<float> a(r, c);
    Math_vector<float> b(c);
    std::cout << "Enter the matrix data: " << std::endl;
    std::cin >> a;
    std::cout << "Enter the vector data: " << std::endl;
    std::cin >> b;
    Math_vector<float> result = a * b;
    std::cout << "Result:" << std::endl << result;
}
void matr_umn_int() {
    int r, c;
    std::cout << "Enter the matrix size: " << std::endl;
    std::cin >> r;
    std::cin >> c;
    Matrix<float> a(r, c);
    float b;
    std::cout << "Enter the matrix data: " << std::endl;
    std::cin >> a;
    std::cout << "Enter the number: " << std::endl;
    std::cin >> b;
    Matrix<float> result = a * b;
    std::cout << "Result:" << std::endl << result;
}
void tmatr_plus() {
    int n;
    std::cout << "Enter the matrix size: " << std::endl;
    std::cin >> n;
    Triangle_matrix<float> a(n);
    Triangle_matrix<float> b(n);
    std::cout << "Enter the first matrix data: " << std::endl;
    std::cin >> a;
    std::cout << "Enter the second matrix data: " << std::endl;
    std::cin >> b;
    Triangle_matrix<float> result = a + b;
    std::cout << "Result:" << std::endl << result;
}
void tmatr_minus() {
    int n;
    std::cout << "Enter the matrix size: " << std::endl;
    std::cin >> n;
    Triangle_matrix<float> a(n);
    Triangle_matrix<float> b(n);
    std::cout << "Enter the first matrix data: " << std::endl;
    std::cin >> a;
    std::cout << "Enter the second matrix data: " << std::endl;
    std::cin >> b;
    Triangle_matrix<float> result = a + b;
    std::cout << "Result:" << std::endl << result;
}
void tmatr_umn_tmatr() {
    int n;
    std::cout << "Enter the matrix size: " << std::endl;
    std::cin >> n;
    Triangle_matrix<float> a(n);
    Triangle_matrix<float> b(n);
    std::cout << "Enter the first matrix data: " << std::endl;
    std::cin >> a;
    std::cout << "Enter the second matrix data: " << std::endl;
    std::cin >> b;
    Triangle_matrix<float> result = a * b;
    std::cout << "Result:" << std::endl << result;
}
void tmatr_umn_vec() {
    int n, s;
    std::cout << "Enter the matrix size: " << std::endl;
    std::cin >> n;
    Triangle_matrix<float> a(n);
    Math_vector<float> b(n);
    std::cout << "Enter the matrix data: " << std::endl;
    std::cin >> a;
    std::cout << "Enter the vector data: " << std::endl;
    std::cin >> b;
    Math_vector<float> result = a * b;
    std::cout << "Result:" << std::endl << result;
}
void tmatr_umn_int() {
    int n;
    std::cout << "Enter the matrix size: " << std::endl;
    std::cin >> n;
    Triangle_matrix<float> a(n);
    float b;
    std::cout << "Enter the matrix data: " << std::endl;
    std::cin >> a;
    std::cout << "Enter the number: " << std::endl;
    std::cin >> b;
    Triangle_matrix<float> result = a * b;
    std::cout << "Result:" << std::endl << result;
}