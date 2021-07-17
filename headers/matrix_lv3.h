#include "matrix.h"
#include <iostream>

using namespace std;

#ifndef MATRIX_LV3_H
#define MATRIX_LV3_H

#define Matrix_row_lv3 3
#define Matrix_col_lv3 3

class matrix_lv3
{
private:
    int _sign;

    double matrix[Matrix_row_lv3][Matrix_col_lv3];
    double deter;
    double deter_swap_lv3[Matrix_row_lv3][Matrix_col_lv3];

    double adj[Matrix_row_lv3][Matrix_col_lv3];
    double adj_swap_lv3[Matrix_row_lv3][Matrix_col_lv3];
    
    double inverse[Matrix_row_lv3][Matrix_col_lv3];
    double inverse_swap_lv3[Matrix_row_lv3][Matrix_col_lv3];

    double swap_lv2[Matrix_row_lv2][Matrix_col_lv2] ;
    // double (*swap_pt)[Matrix_col_lv2] = swap_lv2;
    
    matrix_lv2 coeff[Matrix_row_lv3][Matrix_col_lv3];

    bool inverse_status;
public:
    matrix_lv3(); 
    ~matrix_lv3();
    
    void get_element();
    void extract_lv2();
    double get_deter();

    bool get_inverse_status();
    bool init_sign();
    int swap_sign(int &);
    void pass_adj_matrix();

    void show();
    
    matrix_lv3 product(matrix_lv3, matrix_lv3);

    void cal_inverse();
    void show_inverse();

    void init_to_zero();
    void init_to_zero_swap_lv2();
};


#endif