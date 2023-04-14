#ifndef main_hpp
#define main_hpp

#include <stdio.h>
#include <iostream>

class BankData{

    public:
        int BankMoney = 20000;
        int BankCustomers = 3000;// how much people put their money in the bank
        int BankIncome = 6000;
        int BankTax = 4000;

};

class FederalReserve{

    public:
        int FederalReserveTax = 210000; // 210000
        int FederalReserveMoney = NULL; //how much money did the Federal Reserve take from the bank
};

// class Inflation{
    
//     public:
//         int InflationTax = 100000; //how much the inflation will increase the Federaltax
        
// };

#endif
