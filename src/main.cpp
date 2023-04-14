#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <unistd.h>
#include <algorithm>
#include <cstdio>
#include "main.hpp"



int main()
{

    // g++ -std=c++14 main.cpp

    BankData BankData;
    BankData.BankMoney;
    BankData.BankCustomers;
    BankData.BankTax;
    BankData.BankIncome;

    FederalReserve FederalReserve;
    FederalReserve.FederalReserveTax;
    FederalReserve.FederalReserveMoney;

    int countTaxTimesArray;
    int addTaxToFile;
    int InflationTax = 10000; // how much the inflation will increase the Federaltax

    long elaspedSeconds = time(0);
    srand(elaspedSeconds);
    int inflation = rand() % 3; // any number under 3

    while (BankData.BankMoney >= 100)
    {

        BankData.BankMoney = BankData.BankMoney - BankData.BankTax;
        BankData.BankMoney = BankData.BankMoney + BankData.BankIncome;
        sleep(1);
        std::cout << BankData.BankMoney << '\n';

        if (BankData.BankMoney >= 300000)
        {
            std::cout << "You have reached $" << BankData.BankMoney << ", you will be taxed the %61 percent \n";
            std::cout << "The %61 percent of the tax will be sent to the Federal Reserve \n";
            sleep(2);
            BankData.BankMoney = BankData.BankMoney - FederalReserve.FederalReserveTax;
            FederalReserve.FederalReserveMoney = FederalReserve.FederalReserveMoney + FederalReserve.FederalReserveTax;

            std::cout << "You have been taxed $" << FederalReserve.FederalReserveTax << '\n';

            // this code checks if the TaxTimes(array) is full, or if i wanted to checked how many 1's are in the array

            // std::vector<int> taxTimes = {}; //amount of time the bank has been taxed
            // taxTimes.push_back(1);
            // countTaxTimesArray = count(taxTimes.begin(), taxTimes.end(), 1);
            countTaxTimesArray = countTaxTimesArray += 1;
            std::cout << "You have been taxed " << countTaxTimesArray << " times \n";

            // Inflation code
            if (countTaxTimesArray >= 20)
            { // if the taxcount exceeds 20, it will reset

                countTaxTimesArray = 0;
                try
                {
                    if (inflation == 2)
                    {                                                                                       // If inflation is 2, then inflation will be put in the simulation
                        FederalReserve.FederalReserveTax = FederalReserve.FederalReserveTax + InflationTax; // 10 percent increase in the Federal Tax
                        std::cout << "Inflation has spiked in, the Federal Tax has increased by %10 percent \n";
                    }
                    else if (inflation == 1)
                    { // if Inflation is 1 then inflation will not be put in the simulation
                        std::cout << "Inflation is not in the simulation \n";
                    }
                    else
                    { // it will make the inflation(int) run again to pick a number
                        perror("Inflation will rerun so it can infect this simulation \n");
                        throw(inflation);
                    }
                }
                catch (int Retry)
                {
                    perror("Inflation can not infect this simulation");
                }
            }

            // Inflation code

            // if (inflation == 2){ //If inflation is 2, then inflation will be put in the simulation

            //     FederalReserve.FederalReserveTax = FederalReserve.FederalReserveTax + InflationTax; // 10 percent increase in the Federal Tax
            //     std::cout << "Inflation has spiked in, the Federal Tax has increased by %10 percent \n";
            
            // }else if (inflation == 1){ // if Inflation is 1 then inflation will not be put in the game

            //     std::cout << "Inflation is not in the simulation yet \n";
            // }else{ // it will make the inflation(int) run again to pick a number
            //     std::cout << "";
            // }
        }

        // all code here will run everytime the code runs, so when the code is ran, the file will update so i need to put code here if i want it updated everytime the file is ran

        std::ofstream Bank;
        Bank.open("Bank Data.txt");
        Bank << "The bank has been taxed " << countTaxTimesArray << " times\n";
        Bank << "The The current amount of money the bank holds is $" << BankData.BankMoney << '\n';
        Bank << '\n';
        Bank << "Federal Reserve Data:\n";
        Bank << "Federal Reserve currently holds " << FederalReserve.FederalReserveMoney << '\n';
        Bank << "The current tax is : $" << FederalReserve.FederalReserveTax << '\n';
        Bank << "The Federal Reserve has %61 tax on any bank/company that has over 300k in their holding \n";
        Bank.close();
    }
}