#ifndef MORTGAGE_H
#define MORTGAGE_H

struct mortgageData {
    double housePrice;
    double downPayment;
    double loanTerm;
    double interestRate;

    double downPaymentPercentage;
    double monthlyPayment;
    double totalPayment;
    double totalInterest;
};


int init_mortgage_data(
    struct mortgageData **p_mortData,
    char *p_housePrice,
    char *p_downPayment,
    char *p_loanTerm,
    char *p_interestRate
);

int calculate_mortgage(struct mortgageData **p_mortData);


#endif