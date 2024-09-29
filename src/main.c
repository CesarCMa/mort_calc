#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "mortgage.h"

int main(int argc, char *argv[]) {

    int c;
    char *p_housePrice, *p_downPayment, *p_loanTerm, *p_interestRate;
    struct mortgageData *p_mortData = NULL;


    while ((c = getopt(argc, argv, "p:d:t:i:")) != -1) { 
        switch (c) {
            case 'p':
                p_housePrice = optarg;
                break;
            case 'd':
                p_downPayment = optarg;
                break;
            case 't':
                p_loanTerm = optarg;
                break;
            case 'i':
                p_interestRate = optarg;
                
            case '?':
                printf("Unknown option -%c\n", c);
                break;
            default:
                return -1;
        }
    }

    if (p_housePrice == NULL || p_downPayment == NULL || p_loanTerm == NULL || p_interestRate == NULL) {
        printf("Missing argument\n");
        return -1;
    }
    
    if (init_mortgage_data(&p_mortData, p_housePrice, p_downPayment, p_loanTerm, p_interestRate) != 0) {
        printf("Failed to initialize mortgage data\n");
        return -1;
    }

    if (calculate_mortgage(&p_mortData) != 0) {
        printf("Failed to calculate mortgage\n");
        return -1;
    }
    
    printf("Mortgage data:\n");
    printf("House price: %.2f\n", p_mortData->housePrice);
    printf("Down payment: %.2f\n", p_mortData->downPayment);
    printf("Loan term: %.0f\n", p_mortData->loanTerm);
    printf("Interest rate: %.2f %% \n", p_mortData->interestRate);

    printf("Down payment percentage: %.2f %%\n", p_mortData->downPaymentPercentage * 100);
    printf("Monthly payment: %.2f\n", p_mortData->monthlyPayment);
    printf("Total payment: %.2f\n", p_mortData->totalPayment);
    printf("Total interest: %.2f\n", p_mortData->totalInterest);




    return 0;
}