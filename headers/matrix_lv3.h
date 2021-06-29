#ifndef MATRIX_LV3_H
#define MATRIX_LV3_H

#define Matrix_row_lv3 3
#define Matrix_col_lv3 3

class matrix_lv3
{
private:
    double matrix[Matrix_row_lv3][Matrix_col_lv3];
    double deter;
    double adj[Matrix_row_lv3][Matrix_col_lv3];
    double inverse[Matrix_row_lv3][Matrix_col_lv3];
    double swap[Matrix_row_lv3][Matrix_col_lv3];

    matrix_lv2 sub_matrix;    

    bool inverse_status;
public:
    matrix_lv3(/* args */); 
    ~matrix_lv3();
    void get_element();
    double get_deter();
    bool get_inverse_status();
    void show();
    void pass_adj_matrix();
    matrix_lv3 product(matrix_lv3, matrix_lv3);

    void cal_inverse();
    void show_inverse();

    void init_to_zero();
};


#endif