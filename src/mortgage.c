#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mortgage.h"

int init_mortgage_data(
    struct mortgageData **p_mortData,
    char *p_housePrice,
    char *p_downPayment,
    char *p_loanTerm,
    char *p_interestRate
) {
    struct mortgageData *temp_mortData = malloc(sizeof(struct mortgageData));    
    if (temp_mortData == NULL) {
        printf("Failed to allocate memory for mortgage data\n");
        return -1;
    }

    temp_mortData->housePrice = atof(p_housePrice);
    temp_mortData->downPayment = atof(p_downPayment);
    temp_mortData->loanTerm = atof(p_loanTerm);
    temp_mortData->interestRate = atof(p_interestRate);
    temp_mortData->downPaymentPercentage = temp_mortData->downPayment / temp_mortData->housePrice;

    *p_mortData = temp_mortData;
    return 0;
}


int calculate_mortgage(struct mortgageData **p_mortData) {

    double interestRate = (*p_mortData)->interestRate / 100.0;
    double loanTermMonths = (*p_mortData)->loanTerm * 12.0;
    double expValue = pow((1 + interestRate), loanTermMonths);

    (*p_mortData)->monthlyPayment = (*p_mortData)->housePrice * (
        ((*p_mortData)->interestRate / 100) / (
            1 - pow((1 + ((*p_mortData)->interestRate / 100)), -((*p_mortData)->loanTerm * 12))
        )    
    );
    printf("Interest rate: %f\n", interestRate);
    printf("Loan term: %f\n", loanTermMonths);
    printf("Exponential value: %f\n", expValue);
    double inverseExpo = 1.0 / expValue;
    printf("Inverse exponential: %e\n", inverseExpo);
    return 0;
}