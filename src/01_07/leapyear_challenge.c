#include <stdio.h>



int isLeapYear(int year){

    if (year % 400 == 0){
        return 1;
    }

    if (year % 100 == 0){
        return 0;
    }

    if (year % 4 == 0){
        return 1;
    }

    return 0;


    // or


    if (year % 4 != 0){
        return 0;
    }

    if (year % 100 == 0 && year % 400 != 0){
        return 0;
    }

    return 1;



    // or 


    if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0){
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}




int main(){

    for (int year = 1582; year < 2102; year++){
        if (isLeapYear(year)){
            printf("%d\n", year);
        }
    }

    return 0;
}