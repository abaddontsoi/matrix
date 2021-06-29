#include "matrix.h"
#include "matrix_lv3.h"
#include <iostream>
#include <iomanip>

using namespace std;

matrix_lv2::matrix_lv2(/* args */)
{
}

matrix_lv2::~matrix_lv2()
{
}

void matrix_lv2::get_element(){
	cout << "enter matrix elements from x11 to x22: " <<endl;
        
    for (int i = 0; i < Matrix_row_lv2; i++)
    {
        for (int j = 0; j < Matrix_col_lv2; j++)
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

void matrix_lv2::get_element(double x00, double x01, double x10, double x11){

}


double matrix_lv2::get_deter(){
    //deter = x11 * x22 - x12 * x21;

    deter = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    double Deter = deter;
    return Deter;
}

bool matrix_lv2::get_inverse_status(){
    if (deter != 0)
    {
        return true;
    }
	else{
        return false;
    }
    
}

void matrix_lv2::show(){
    cout << "Your matrix is: " << endl;
    cout << setprecision(6);
    for(int i = 0; i < Matrix_row_lv2; i++){
        for (int j = 0; j < Matrix_col_lv2; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix_lv2::pass_adj_matrix(){
	adj[0][0] = matrix[1][1];
	adj[0][1] = matrix[0][1] * -1;
	adj[1][0] = matrix[1][0] * -1;
	adj[1][1] = matrix[0][0];
}

matrix_lv2 matrix_lv2::product(matrix_lv2 result_matrix,matrix_lv2 second_matrix){

    /*
    result_matrix.matrix[0][0] = matrix[0][0] * second_matrix.matrix[0][0] + matrix[0][1] * second_matrix.matrix[1][0];
	result_matrix.matrix[0][1] = matrix[0][0] * second_matrix.matrix[0][1] + matrix[0][1] * second_matrix.matrix[1][1];
	result_matrix.matrix[1][0] = matrix[1][0] * second_matrix.matrix[0][0] + matrix[1][1] * second_matrix.matrix[1][0];
	result_matrix.matrix[1][1] = matrix[1][0] * second_matrix.matrix[0][1] + matrix[1][1] * second_matrix.matrix[1][1];
    */
	
   for (int i = 0; i < Matrix_row_lv2; i++)
   {
       for (int j = 0; j < Matrix_col_lv2; j++)
       {
           
           for (int k = 0; k < 2; k++)
           {
                result_matrix.matrix[i][j] += matrix[i][k] * second_matrix.matrix[k][j];
           }
           
           // result_matrix.matrix[i][j] = matrix[i][0] * second_matrix.matrix[0][j] + matrix[i][1]*second_matrix.matrix[1][j];
       }
       
   }
	return result_matrix;
}

void matrix_lv2::cal_inverse(){
    if (deter == 0)
    {
        cout<< "The inverse status is:" <<inverse_status<< endl ;
    }
    else{
        double scaler = 1/deter;
        for (int i = 0; i < Matrix_row_lv2; i++)
        {
            for (int j = 0; j < Matrix_col_lv2; j++)
            {
                inverse[i][j] = scaler * adj[i][j];
            }
            
        }
        
    }
}

void matrix_lv2::show_inverse(){
    cout << "The inverse matrix is: "<<endl;
    cout << setprecision(6);
    for (int i = 0; i < Matrix_row_lv2; i++)
    {
        for (int j = 0; j < Matrix_col_lv2; j++)
        {
            cout << inverse[i][j] << " ";
        }
        cout<<endl;
    }
    
}

void matrix_lv2::init_to_zero(){
    /*
    */
    for (int i = 0; i < Matrix_row_lv2; i++)
    {
        for (int j = 0; j < Matrix_col_lv2; j++)
        {
            matrix[i][j] = 0;
        }
        
    }
}