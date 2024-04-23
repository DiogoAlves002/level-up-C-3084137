#include <stdio.h>
#include <time.h>
#include <stdlib.h>


struct matrix {
    char **m_ptr;
    int height;
    int length;

};



void initializeMatrix(struct matrix *m){
    m->m_ptr = (char **)malloc(m->height * sizeof(char *));

    char random_c;
    for (int h = 0; h < m->height; h++){
        m->m_ptr[h] = (char *)malloc(m->length * sizeof(char));

        for (int l = 0; l < m->length; l++){
            random_c = 'a' + (random() % 26);

            m->m_ptr[h][l] = random_c;
        }
    }
}



void freeMatrix(struct matrix *m) {
    for (int i = 0; i < m->height; ++i) {
        free(m->m_ptr[i]);
    }
    free(m->m_ptr);
}



void rotateMatrix(struct matrix *m){
    struct matrix rotated_m = {NULL, m->length, m->height};

    rotated_m.m_ptr = (char **)malloc(rotated_m.height * sizeof(char *));
    for (int h = 0; h < rotated_m.height; h++){
        rotated_m.m_ptr[h] = (char *)malloc(rotated_m.length * sizeof(char));

        for (int l = 0; l < rotated_m.length; l++){

            rotated_m.m_ptr[h][l] = m->m_ptr[m->height - 1 - l][h];
        }
    }

    freeMatrix(m);
    m->m_ptr = rotated_m.m_ptr;
    m->height = rotated_m.height;
    m->length = rotated_m.length;
}



void printMatrix(struct matrix *m){
    printf("\n");
    for (int h = 0; h < m->height; h++){
        for (int l = 0; l < m->length; l++){
            printf("%c ", m->m_ptr[h][l]);
        }
        printf("\n");
    }
    printf("\n");
}



int main(){
    srand(time(NULL));   // Initialization of RNG


    struct matrix matrix_1 = {NULL, 3, 8};
    struct matrix matrix_2 = {NULL, 5, 5};
    struct matrix matrix_3 = {NULL, 6, 4};

    struct matrix *test_cases[3] = {&matrix_1, &matrix_2, &matrix_3};

    for (int test_case = 0; test_case < 3; test_case++ ){
        struct matrix *m = test_cases[test_case];

        printf("----------\n");
        printf("Original %d\n", test_case + 1);
        
        
        initializeMatrix(m);
        printMatrix(m);

        printf("Rotated %d\n", test_case + 1);
        rotateMatrix(m);
        printMatrix(m);

        freeMatrix(m);

    }
    
    return 0;
}