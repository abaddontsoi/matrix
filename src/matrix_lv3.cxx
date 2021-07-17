#include "matrix_lv3.h"
#include "matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

void matrix_lv3::get_element(){
	cout << "enter matrix elements from x11 to x33: " <<endl;
        
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

void matrix_lv3::extract_lv2()
{
    // init_to_zero_swap_lv2();
    int sub_row = 0;
    int sub_col = 0; 

    // allocating the position for storing coeff
    for (int i = 0; i < Matrix_row_lv3; i++)
    {
        for (int j = 0; j < Matrix_col_lv3; j++)
        {
            // allocating elements for the coeff
            for (int k = 0; k < Matrix_row_lv3; k++)
            {
                for (int m = 0; m < Matrix_col_lv3; m++)
                {
                    if (k!=i && m!=j)
                    {
                        swap_lv2[sub_row][sub_col] = matrix[k][m];
                        sub_col++;
                    }
                    
                }
                if (sub_col == 1)
                {
                    sub_row++;
                }
            }
            coeff[i][j].get_element(swap_lv2);
            sub_row = 0;
            sub_col = 0;

        }
        
    }
    
}

double matrix_lv3::get_deter(){
    deter = 0;
    deter = matrix[0][0] * coeff[0][0].get_deter() - matrix[0][1] * coeff[0][1].get_deter() + matrix[0][2] * coeff[0][2].get_deter();
    return deter;
}

bool matrix_lv3::get_inverse_status(){
    if (deter != 0)
    {
        return true;
    }
	else{
        return false;
    }
}

bool matrix_lv3::init_sign(){
    return _sign = -1 ;
}

int matrix_lv3::swap_sign(int &sign){
    return sign * -1;
}

void matrix_lv3::show(){
    cout << "The matrix is: " << endl;
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
    init_sign();
    for (int i = 0; i < Matrix_row_lv3; i++)
    {
        for (int j = 0; j < Matrix_col_lv3; j++)
        {
            adj[i][j] = coeff[j][i].get_deter() * swap_sign(_sign);
        }
        
    }
    
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
    inverse_status = get_inverse_status();
    if (deter == 0)
    {
        cout<< "The inverse status is: " << inverse_status << endl ;
        cout<<"The matrix is invertible."<< endl;
    }
    else{
        double scaler = 1/deter;
        for (int i = 0; i < Matrix_row_lv3; i++)
        {
            for (int j = 0; j < Matrix_col_lv3; j++)
            {
                inverse[i][j] = scaler * adj[i][j];
            }
            
        }
        
    }

}

void matrix_lv3::show_inverse(){
    cout << setprecision(3) ;
    if (inverse_status == true)
    {
        cout << "The inverse matrix is: "<<endl;
        for (int i = 0; i < Matrix_row_lv3; i++)
        {
            for (int j = 0; j < Matrix_col_lv3; j++)
            {
                cout << inverse[i][j] << " ";
            }
            cout<<endl;
        }
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

void matrix_lv3::init_to_zero_swap_lv2(){
    for (int i = 0; i < Matrix_row_lv3; i++)
    {
        for (int j = 0; j < Matrix_col_lv3; j++)
        {
            swap_lv2[i][j] = 0;
        }
        
    }
    
   
}

matrix_lv3::matrix_lv3(){
    init_to_zero();
}

matrix_lv3::~matrix_lv3(){

}