#include <stdio.h>
#include <time.h>


int isLeapYear(int year){
    if (year % 4 != 0){
        return 0;
    }

    if (year % 100 == 0 && year % 400 != 0){
        return 0;
    }

    return 1;
}

int main(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char *week_days[7]= {
        "Sunday",
        "Monday",
        "Thuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

    char *months[12] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    int months_days[12] = {
        31,
        28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31
    };


    printf("Todas is %s, %d of %s %d\n", week_days[tm.tm_wday], tm.tm_mday, months[tm.tm_mon], tm.tm_year + 1900);
    
    int days_till_monday = (7 + 1) - tm.tm_wday; // 7 + 1 = next week + monday offset

    int monday_day; char* monday_month;

    if ( tm.tm_mon == 1 && isLeapYear(tm.tm_year)){ // account for leap days in february
        months_days[1]++;
    }

    if (tm.tm_mday + days_till_monday > months_days[tm.tm_mday]){
       monday_month = months[(tm.tm_mon + 1) % 12]; // next month
       monday_day = months_days[tm.tm_mon] - days_till_monday;
    } else {
        monday_month = months[tm.tm_mon];
        monday_day = tm.tm_mday + days_till_monday;
    }


    printf("Next Monday will be on %d of %s\n", monday_day, monday_month);

    return 0;
}