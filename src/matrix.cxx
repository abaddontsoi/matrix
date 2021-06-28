#include <iostream>
#include <string>
#include <limits>
#include "matrix.h"

using namespace std;

int main(){
    matrix_lv2 mat1;
    matrix_lv2 mat2;
	matrix_lv2 _saving;

	mat1.get_element();
    cout<< "The matrix determinant is: " << mat1.get_deter() << endl;
    mat1.show();
    cout << "The reverse status of the matrix: " << mat1.get_inverse_status()<< endl;
    mat1.pass_adj_matrix();
    mat1.cal_inverse();
    mat1.show_inverse();

	mat2.get_element();
    cout<< "The matrix determinant is: " << mat2.get_deter() << endl;
    mat2.show();
    cout << "The reverse status of the matrix: " << mat2.get_inverse_status()<< endl;
    mat2.pass_adj_matrix();
    mat2.cal_inverse();
    mat2.show_inverse();

	_saving = mat1.product(_saving, mat2);
    cout << "The following is the product of the first and the second matrix. " <<endl;
	_saving.show();

    return 0;
}


