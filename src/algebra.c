#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    if(a.rows!=b.rows||a.cols!=b.cols)
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
    Matrix result;
    result.rows=a.rows;
    result.cols=a.cols;
    int i,j;
    for(i=0;i<a.rows;i++)
    {
        for(j=0;j<a.cols;j++)
        {
            result.data[i][j]=a.data[i][j]+b.data[i][j];
        }
    }
    return result;
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    if(a.rows!=b.rows||a.cols!=b.cols)
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
    Matrix result;
    result.rows=a.rows;
    result.cols=a.cols;
    int i,j;
    for(i=0;i<a.rows;i++)
    {
        for(j=0;j<a.cols;j++)
        {
            result.data[i][j]=a.data[i][j]-b.data[i][j];
        }
    }
    return result;
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    if(a.cols!=b.rows)
    {
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
        return create_matrix(0, 0);
    }
    Matrix result;
    result.rows=a.rows;
    result.cols=b.cols;
    int i,j;
    for(i=0;i<a.rows;i++)
    {
        for(j=0;j<b.cols;j++)
        {
            result.data[i][j]=0;
            int k;
            for(k=0;k<a.cols;k++)
            {
                result.data[i][j]+=a.data[i][k]*b.data[k][j];
            }
        }
    }
    return result;
}

Matrix scale_matrix(Matrix a, double k)
{
    Matrix result=create_matrix(a.rows,a.cols);
    int i,j;
    for(i=0;i<a.rows;i++)
    {
        for(j=0;j<a.cols;j++)
        {
            result.data[i][j]=k*a.data[i][j];
        }
    }
    return result;
}

Matrix transpose_matrix(Matrix a)
{
    Matrix result=create_matrix(a.cols,a.rows);
    int i,j;
    for(i=0;i<result.rows;i++)
    {
        for(j=0;j<result.cols;j++)
        {
            result.data[i][j]=a.data[j][i];
        }
    }
    return result;
}

double det_matrix(Matrix a)
{
    if(a.rows!=a.cols)
    {
        printf("Error: The matrix must be a square matrix.\n");
        return 0;
    }
    double det;
    if (a.rows == 1) {
        return a.data[0][0];
    }
    if (a.rows == 2) {
        return a.data[0][0] * a.data[1][1] - a.data[0][1] * a.data[1][0];
    }
    double temp[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];  
    int i,j;
    for (i = 0; i < a.rows; i++) {
        for (j = 0; j < a.cols; j++) {
            temp[i][j] = a.data[i][j];  
        }
    }
    
    int sign = 1; 
    
    for (i = 0; i < a.rows; i++) {
        int pivot = i;
        for (j = i; j < a.rows; j++) {
            if (fabs(temp[j][i]) > fabs(temp[pivot][i])) {
                pivot = j;  
            }
        }
        if (pivot != i) {
            for (j = i; j < a.rows; j++) {
                double temp_val = temp[i][j];
                temp[i][j] = temp[pivot][j];
                temp[pivot][j] = temp_val;
            }
            sign *= -1; 
        }
        if (temp[i][i] == 0) {
            return 0;
        }
        for (j = i + 1; j < a.rows; j++) {
            double factor = temp[j][i] / temp[i][i];
            int k;
            for (k = i; k < a.rows; k++) {
                temp[j][k] -= factor * temp[i][k];
            }
        }
    }
    det = sign;
    for (i = 0; i < a.rows; i++) {
        det *= temp[i][i];
    }
    
    return det;

}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    double temp[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    int i,j;
    for (i = 0; i < a.rows; i++) {
        for (j = 0; j < a.cols; j++) {
            temp[i][j] = a.data[i][j];
        }
    }
    int rank = 0;  
    int row,col;
    for (col = 0; col < a.cols; col++) {
        int pivot_row = -1;
        for (row = rank; row < a.rows; row++) {
            if (temp[row][col] != 0) {
                if (pivot_row == -1 || fabs(temp[row][col]) > fabs(temp[pivot_row][col])) {
                    pivot_row = row;
                }
            }
        }
        if (pivot_row != -1) {
            for (j = col; j < a.cols; j++) {
                double temp_val = temp[rank][j];
                temp[rank][j] = temp[pivot_row][j];
                temp[pivot_row][j] = temp_val;
            }
            for (row = rank + 1; row < a.rows; row++) {
                double factor = temp[row][col] / temp[rank][col];
                for (j = col; j < a.cols; j++) {
                    temp[row][j] -= factor * temp[rank][j];
                }
            }
            rank++; 
        }
    }
    return rank;
}

double trace_matrix(Matrix a)
{
    if(a.rows!=a.cols)
    {
        printf("Error: The matrix must be a square matrix.\n");
        return 0;
    }
    double trace=0;
    int i;
    for(i=0;i<a.rows;i++)
    {
        trace+=a.data[i][i];

    }
    return trace;

}

void print_matrix(Matrix a)
{
    int i,j;
    for (i = 0; i < a.rows; i++)
    {
        for (j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}