#include <iostream>
#include <string>
#include <limits>
#include "matrix.h"
#include "matrix_lv3.h"

using namespace std;

int main(){

    /*
    matrix_lv2 mat1;
    matrix_lv2 mat2 ;
	matrix_lv2 _saving ;

	mat1.get_element();
    cout<< "The matrix determinant is: " << mat1.get_deter() << endl;
    mat1.show();
    cout << "The inverse status of the matrix: " << mat1.get_inverse_status()<< endl;
    mat1.pass_adj_matrix();
    mat1.cal_inverse();
    mat1.show_inverse();

	mat2.get_element();
    cout<< "The matrix determinant is: " << mat2.get_deter() << endl;
    mat2.show();
    cout << "The inverse status of the matrix: " << mat2.get_inverse_status()<< endl;
    mat2.pass_adj_matrix();
    mat2.cal_inverse();
    mat2.show_inverse();

    _saving.init_to_zero();
	_saving = mat1.product( _saving, mat2);
    cout << "The following is the product of the first and the second matrix. " <<endl;
	_saving.show();
    
    */
    

    matrix_lv3 mat3;
    matrix_lv3 mat4;
    matrix_lv3 _saving1;

    mat3.get_element();
    mat3.extract_lv2();
    cout<< "The matrix determinant is: " << mat3.get_deter() << endl;
    mat3.show();
    cout << "The inverse status of the matrix: " << mat3.get_inverse_status()<< endl;
    mat3.pass_adj_matrix();
    mat3.cal_inverse();
    mat3.show_inverse();

    mat4.get_element();
    mat4.extract_lv2();
    cout<< "The matrix determinant is: " << mat4.get_deter() << endl;
    mat4.show();
    cout << "The inverse status of the matrix: " << mat4.get_inverse_status()<< endl;
    mat4.pass_adj_matrix();
    mat4.cal_inverse();
    mat4.show_inverse();


    _saving1.init_to_zero();
    _saving1 = mat3.product(_saving1, mat4);
    cout << "The following is the product of the first and the second matrix. " <<endl;
	_saving1.show();

    return 0;
}