#include <stdio.h>
#include <stdlib.h>

// PR GUNAWARDHENA
// AS2022901
// SIMPLE BANKING SYSTEM


//PROTOYPES FUNCTIONS
int isAccExist(int accounts[],int accountNumber, int accountIndex);
int createAcc(int accounts[], float balances[], int accountIndex);
void depositMoney(int accounts[], float balances[], int accountIndex);
void withdrawMoney(int accounts[], float balances[], int accountIndex);
void checkBalance(int accounts[], float balances[], int accountIndex);
int isPositiveValue(float amount);




int main()
{
    int intChoice, intAccountCount = 0;

    //intAccounts Array for store Accounts
    //fltBalances Array for store Balances
    int intAccounts[10];
    float fltBalances[10];


    while(1)
    {
        //display simple menu with navigation.
        printf( "\n\n=== Simple Banking System ===\n\n"
                "1. Create a new bank account\n"
                "2. Deposit money\n"
                "3. Withdraw money\n"
                "4. Check account balance\n"
                "5. Exit\n\n");

        // Get user's choices and assign it to a variable
        printf("Enter your choice: ");
        scanf("%d", &intChoice);

        switch(intChoice)
        {
        case 1:
            intAccountCount = createAcc(intAccounts, fltBalances, intAccountCount);
            break;
        case 2:
            depositMoney(intAccounts, fltBalances, intAccountCount);
            break;
        case 3:
            withdrawMoney(intAccounts, fltBalances, intAccountCount);
            break;
        case 4:
            checkBalance(intAccounts, fltBalances, intAccountCount);
            break;
        case 5:
            printf("\n>>>Happy Banking! Exiting program..");
            exit(0);
        default:
            printf("\n>>>Please Enter a valid choice!");
        }
    }
    return 0;
}

//VALIDATE WITHDRAW OR DEPOSITE AMOUNTS
int isPositiveValue(float amount)
{

    int isValid = 0;

    if (amount > 0)
    {

        isValid = 1;
    }

    return isValid;
}

//VALIDATE ACCOUNTS AVAILABILITY
int isAccExist(int accounts[],int accountNumber, int accountIndex)
{

    //If an account is available for provided account number returning it's index, otherwise returning -1
    int isAvailable = -1;

    for (int index = 0; index < accountIndex; index++)
    {

        if (accounts[index] == accountNumber)
        {

            isAvailable = index;
            break;

        }

    }

    return isAvailable;
}

//CREATE ACCOUNT FUNCTION
int createAcc(int accounts[], float balances[], int accountIndex)
{

    //create a user account if there is not available a account with provided account number
    int newAccountNumber, isAccExists;
    float initialBalance;

    printf("Enter account number: ");
    scanf("%d", &newAccountNumber);


    //check is there already account available
    isAccExists = isAccExist(accounts, newAccountNumber, accountIndex);

    if (isAccExists == -1)
    {
        int isPositive;
        accounts[accountIndex] = newAccountNumber;

        printf("Enter Initial amount: ");
        scanf("%f", &initialBalance);

        isPositive = isPositiveValue(initialBalance);
        if (isPositive)
        {
            balances[accountIndex] = initialBalance;

            printf("\n>>>Bank account created successfully!");
        }
        else
        {
            printf("\n>>> Enter a valid Amount!");
        }


    }
    else
    {
        printf("There is a account already with this account number,");
    }




    return accountIndex + 1;


}

//DEPOSIT MONEY FUNCTION
void depositMoney(int accounts[], float balances[], int accountIndex)
{

    int accountNumber, isAccExists;
    float depositAmount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    //check is account available in array
    isAccExists = isAccExist(accounts, accountNumber, accountIndex);

    if (isAccExists != -1)
    {

        int isPositve;

        printf("Enter amount to deposit: ");
        scanf("%f", &depositAmount);

        isPositve = isPositiveValue(depositAmount);
        if (isPositve)
        {

            balances[isAccExists] += depositAmount;

            printf("\n>>>Deposit successful! New balance: %.2f", balances[isAccExists]);
        }
        else
        {
            printf("\n>>> Enter a valid Amount!");
        }
    }
    else
    {
        printf("Account not available");
    }
}


//WITHDRAW MONEY FUNCTION
void withdrawMoney(int accounts[], float balances[], int accountIndex)
{

    int accountNumber, isAccExists;
    float withdrawAmount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    //check is account available in array
    isAccExists = isAccExist(accounts, accountNumber, accountIndex);

    if(isAccExists != -1)
    {
        int isPositive;
        printf("Enter Withdraw amount: ");
        scanf("%f", &withdrawAmount);

        isPositive = isPositiveValue(withdrawAmount);

        if (isPositive)
        {

            balances[isAccExists] -= withdrawAmount;

            printf("\n>>>Withdrawal successful! New balance: %.2f", balances[isAccExists]);
        }else {
            printf("\n>>> Enter a valid Amount!");
        }

    }
    else
    {
        printf("Account not available");
    }

}


//CHECK BALANCE FUNCTION
void checkBalance(int accounts[], float balances[], int accountIndex)
{

    //>>>check balance function
    int accountNumber, isAccExists;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    //check is account available in array
    isAccExists = isAccExist(accounts, accountNumber, accountIndex);
    printf("%d", isAccExists);

    if(isAccExists != -1)
    {

        printf("----------------------------"
               "Account Number: %d\t"
               "Balance: %.2f"
               "----------------------------", accounts[isAccExists], balances[isAccExists]);
    }
    else
    {
        printf("Account not available");
    }

}
