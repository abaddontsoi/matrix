#ifndef MATRIX_H
#define MATRIX_H
#define Matrix_row_lv2 2
#define Matrix_col_lv2 2

class matrix_lv2
{
private:
    double matrix[Matrix_row_lv2][Matrix_col_lv2];
    double deter;
    double adj[Matrix_row_lv2][Matrix_col_lv2];
    double inverse[Matrix_row_lv2][Matrix_col_lv2];

    bool inverse_status;

public:
    matrix_lv2();
    matrix_lv2(double [Matrix_row_lv2][Matrix_col_lv2]);
    ~matrix_lv2();
	void get_element();
    void get_element(double passing[][2]);
    
    double get_deter();

    bool get_inverse_status();
    void pass_adj_matrix();
    
    void show();
    matrix_lv2 product(matrix_lv2, matrix_lv2);

    void cal_inverse();
    void show_inverse();

    void init_to_zero();
};

#endif