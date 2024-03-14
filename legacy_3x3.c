#include "matrix.h"
//Legacy implementation of the determinant, it works fine to the 3x3 but has no reason to be used;
int determinant_3x3(Matrix *a){
    int determinante = 0;
    if(a->lines == 3 && a->columns == 3){
        int a00 = 0;
        int a01 = 0;
        int a02 = 0;
        for(int linhas = 0; linhas < a->lines; linhas++){
            for(int colunas = 0; colunas < a->columns; colunas++){
                if(linhas == 0 && colunas == 0){
                    a00 =
                        a->e[linhas *a->columns + colunas] *
                        (a->e[1 * a->columns + 1]* a->e[2* a->columns + 2] - a->e[2 * a->columns + 1] * a->e[1 * a->columns + 2]);
                }
                if(linhas == 0 && colunas == 1){
                    a01 =
                        a->e[linhas *a->columns + colunas] *
                        (a->e[1 * a->columns + 0] * a->e[2 * a->columns + 2] - a->e[2* a->columns + 0] * a->e[1 * a->columns + 2]);
                }
                if(linhas == 0 && colunas == 2){
                    a02 =
                        a->e[linhas * a->columns + colunas] * 
                        (a->e[1* a->columns + 0] * a->e[2 * a->columns + 1] - a->e[2 * a->columns + 0] * a->e[1 * a->columns + 1]);
                }
            }
        }
        determinante = a00 - a01 + a02;
    }
    return determinante;
}

float linear_system(const char *first,const char *second){
  int a1,b1,b2,a2,c1,c2;
  size_t equal1 = 0;
  size_t first_size = strlen(first);
  size_t second_size = strlen(second);
  for(int i = 0; i < first_size; i++){
    if(first[i] == 'x' || first[i] == 'X'){
      a1 = (int)first[i-1]-48;
    }
    if(first[i] == 'y' || first[i] == 'Y'){
      b1 = (int)first[i-1]-48;
    }
    if(first[i] == '='){
      equal1 = i;
    }
  }
  c1 = 0;
  for(int i = equal1+2; i < first_size; i++){
    c1 += pow(10, first_size - (i+1)) * ((int)first[i]-48);
  }
    printf("a1=%d\nb1=%d\n",a1,b1);
    printf("%d\n", c1);
  for(int i = 0; i < second_size; i++){
    if(second[i] == 'x' || second[i] == 'X'){
      a2 = (int)second[i-1]-48;
    }
    if(second[i] == 'y' || second[i] == 'Y'){
      b2 = (int)second[i-1]-48;
    }
    if(second[i] == '='){
      equal1 = i;
    }
  }
  c2 = 0;
  for(int i = equal1 + 2; i < second_size; i++){
    c2 += pow(10, second_size - (i+1)) * ((int)second[i] - 48);
  }
  printf("a2=%d\nb2=%d\n",a2,b2);
  printf("%d\n", c2);
return 0;
}
