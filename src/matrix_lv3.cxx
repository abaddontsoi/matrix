#include "matrix_lv3.h"
#include "matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

void matrix_lv3::get_element(){
	cout << "enter matrix elements from x11 to x22: " <<endl;
        
    for (int i = 0; i < Matrix_row_lv3; i++)
    {
        for (int j = 0; j < Matrix_col_lv3; j++)
        {
			cin >> matrix[i][j];
			while (cin.fail())
    		{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invaild value! Enter again: \n";
				cin >> matrix[i][j];
			}
    	}          
   	}
}

double matrix_lv3::get_deter(){
    return 0;
}

bool matrix_lv3::get_inverse_status(){
    if (deter == 0)
    {
        return false;
    }
    else 
    return true;
}

void matrix_lv3::show(){
    cout << "Your matrix is: " << endl;
    cout << setprecision(6);
    for(int i = 0; i < Matrix_row_lv3; i++){
        for (int j = 0; j < Matrix_col_lv3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix_lv3::pass_adj_matrix(){

}

matrix_lv3 matrix_lv3::product(matrix_lv3 result_matrix, matrix_lv3 second_matrix){
    for (int i = 0; i < Matrix_row_lv3; i++)
    {
        for (int j = 0; j < Matrix_col_lv3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                result_matrix.matrix[i][j] += matrix[i][k] * second_matrix.matrix[k][j];
            }            
        }
        
    }
    return result_matrix;
}

void matrix_lv3::cal_inverse(){

}

void matrix_lv3::show_inverse(){
    cout << "The inverse matrix is: "<<endl;
    cout << setprecision(6);
    for (int i = 0; i < Matrix_row_lv3; i++)
    {
        for (int j = 0; j < Matrix_col_lv3; j++)
        {
            cout << inverse[i][j] << " ";
        }
        cout<<endl;
    }
    
}

void matrix_lv3::init_to_zero(){
    for (int i = 0; i < Matrix_row_lv3; i++)
    {
        for (int j = 0; j < Matrix_col_lv3; j++)
        {
            matrix[i][j] = 0;
        }
        
    }
    
}

matrix_lv3::~matrix_lv3(){

}