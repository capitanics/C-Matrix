#include "matrix.h"
#include "time.h"

float rand_float(){
    return (float)rand()/RAND_MAX;
}

void allocate_matrix(int lines, int rows, Matrix *a){
    (*a).lines = lines;
    (*a).columns = rows;
    (*a).e = malloc(sizeof(int)*(*a).lines*(*a).columns);
    for(int i = 0; i < lines*rows; i++){
        (*a).e[i] = 0.0f;
    }

}

void reallocate_matrix(int lines, int rows, Matrix *a){
    free(a->e);
    (*a).lines = lines;
    (*a).columns = rows;
    (*a).e = malloc(sizeof(int)*(*a).lines*(*a).columns);
    for(int i = 0; i < lines*rows; i++){
        (*a).e[i] = 0.0f;
    }

}

void set_matrix_value(Matrix *a){
    for(int linha = 0; linha < a->lines; linha++){
        for(int coluna = 0; coluna < a->columns; coluna++){
            scanf("%d", &a->e[linha * a->columns + coluna]);
        }
    }
}


void print_matrix(Matrix a){
    for (int linha = 0; linha < a.lines; linha++) {
        for (int coluna = 0; coluna < a.columns; coluna++) {
            printf("%2d ", a.e[linha*a.columns + coluna]);
        }
        printf("\n");
    }
}

void sum_matrix(Matrix *a, Matrix *b){
    if(a->lines == b->lines && a->columns == b->columns){
        for(int linha = 0; linha < a->lines; linha++){
            for(int coluna = 0; coluna < a->columns; coluna++){
                a->e[linha*a->columns + coluna] += b->e[linha * a->columns + coluna];
            }
        }

    }
    else{
        printf("Informe Matrizes do mesmo tamanho");
    }
}

void multiply_matrix(Matrix *a, Matrix *b, Matrix *c) {
    if (c->lines == a->lines && c->columns == b->columns && a->columns == b->lines) {
        for (int linha_a = 0; linha_a < a->lines; linha_a++) {
            for (int j = 0; j < b->columns; j++) {
                float temp = 0;
                for (int k = 0; k < a->columns; k++) {
                    temp += a->e[linha_a * a->columns + k] * b->e[k * b->columns + j];
                }
                c->e[linha_a * c->columns + j] = temp;
            }
        }
    }
}

//This algorithim makes use of the cofactor of a matrix and calculates the determinant recusively, it basically reduces the matrix to a 2*2 when it can be easily calculated
int determinant(Matrix *a){
    if (a->lines != a->columns) {
        printf("Matrix is not square!\n");
        return 0; // Return 0 for non-square matrices
    }
    
    if (a->lines == 2 && a->columns == 2) {
        return a->e[0] * a->e[3] - a->e[1] * a->e[2];
    }
    
    int det = 0;
    for (int col = 0; col < a->columns; col++) {
        Matrix submatrix;
        submatrix.lines = a->lines - 1;
        submatrix.columns = a->columns - 1;
        submatrix.e = (int *)malloc(submatrix.lines * submatrix.columns * sizeof(int));

        reduce_matrix(col, a, &submatrix);//calculates the cofactor

        int sign = (col % 2 == 0) ? 1 : -1;//Alternates the sign
        det += sign * a->e[col] * determinant(&submatrix);//Recursive part

        free(submatrix.e);
    }
    return det;

}

void reduce_matrix(int column, Matrix *a, Matrix *b){
    int b_lin = 0; // Index for rows in matrix 'b'
    
    for(int linhas = 0; linhas < a->lines; linhas++){
        if (linhas != 0) { // Skip the specified row
            int b_col = 0; // Index for columns in matrix 'b'
            
            for(int colunas = 0; colunas < a->columns; colunas++){
                if(colunas != column){
                    b->e[b_lin * (a->columns - 1) + b_col] = a->e[linhas * a->columns + colunas];
                    b_col++; // Move to the next column in matrix 'b'
                }
            }
            
            b_lin++; // Move to the next row in matrix 'b'
        }
    }
}

void random_matrix(Matrix *a){
    for(int i = 0; i < a->lines * a->columns; i++){
        a->e[i] = rand_float()*10;
    }
}

int string_to_int(const char *string, char stop){
  int a = 0;
  int start = 0;
  size_t size = strlen(string);
  size_t equal;
  for(int i = 0; i < size; i++){
    if(string[i] == stop && stop == '='){
      equal = size;
      start = i+2;
      break;
    }
    if(string[i] == stop){
      equal = i;
      break;
    }
    if(string[i] == '+' || string[i] == '-'){
      start = i+2;
    }
  }
  for(int i = start; i < equal; i++){
    a += pow(10, equal - (i+1)) * ((int)string[i] - 48);
  }
  return a;
}

double* linear_system(const char *first,const char *second){
  int a1 = string_to_int(first, 'x');
  int b1 = string_to_int(first, 'y');
  int c1 = string_to_int(first, '=');
  int a2 = string_to_int(second, 'x');
  int b2 = string_to_int(second, 'y');
  int c2 = string_to_int(second, '=');
  double det_main = a1 * b2 - a2 * b1;
  double det_x = c1 * b2 - c2 * b1;
  double det_y = a1 * c2 - a2 * c1;
  double x = det_x / det_main;
  double y = det_y / det_main;
  double *result = malloc(sizeof(double)*2);
  result[0] = x;
  result[1] = y;
return result;
}








