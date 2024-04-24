#include <stdio.h>


double goldenRatio(int depth){
    if (depth == 0){
        return 1;
    }

    return 1 + 1 / goldenRatio(--depth);
}



int main(){


    printf("Golden Ratio: %f\n", goldenRatio(100));

    return 0;
}