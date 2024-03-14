#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    int lines;
    int columns;
    int *e;
}Matrix;

float rand_float();

void allocate_matrix(int lines, int columns, Matrix *a);

void reduce_matrix(int column, Matrix *a, Matrix *b);

void print_matrix(Matrix a);

void set_matrix_value(Matrix *a);

void random_matrix(Matrix *a);

void sum_matrix(Matrix *a, Matrix *b);

void multiply_matrix(Matrix *a, Matrix *b, Matrix *c);

int any_determinant(Matrix *a, Matrix *b);

int matrix_determinant(Matrix *a);

int determinant_3x3(Matrix *a);

int determinant(Matrix *a);

double* linear_system(const char *first, const char *second);

#endif
