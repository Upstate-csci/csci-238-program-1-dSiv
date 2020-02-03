/********
 Author: Dennis Sivilay
 Program: Money class - program assignment #1
 Due Date: 2/3/2020
 Purpose:
 ********/
#include "money.h"

// Declaring total

//int totalOfInput;


 // convert current currency values to a string
string Money::toString() {
    // building the string strema
    stringstream ss;

    ss << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters << " quarters " << dimes << " dimes " << nickels << " nickels " << cents << " pennies ";
 //   return ss.str;
    return "";
}

// format amount as a local currency and return
string Money::toCurrency(double amount) {
    stringstream ss;

    ss.imbue(locale(""));

    ss << showbase << put_money(amount * 100);

    return ss.str();
}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
    
    // Taking in the input for all criteria
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents;

    // for calculating total for output
    total = (hundreds * 100) + (tens * 10) + (fives * 5) + (ones * 1) + (quarters * .25) + (dimes * .10) + (nickels * .05) + (cents * .01);

    // returning using toString method for correct format
    return to_string(hundreds) + " hundreds " + to_string(tens) + " tens " + to_string(fives) + " fives " + to_string(ones) + " ones " + to_string(quarters) + " quarters " + to_string(dimes) + " dimes " + to_string(nickels) + " nickles " + to_string(cents) + " pennies = " + toCurrency(total);
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {
    
    float amountOfMoney;
    cin >> amountOfMoney;
    int amountInInt = (int)(amountOfMoney * 100);

    // to convert to float
    std::ostringstream stringStreamObject;

    // for float decimal places (set to 2)
    stringStreamObject << fixed << std::setprecision(2);
    stringStreamObject << amountOfMoney;
    std::string strObj = stringStreamObject.str();

    hundreds = (amountInInt / 1000);
    // tens  = remainder of amountInInt and 10000 then divide by 1000
    tens = (amountInInt % 10000) / 1000;
    fives = ((amountInInt % 10000) % 1000) / 500;
    ones = (((amountInInt % 10000) % 1000) % 500) / 100;
    quarters = ((((amountInInt % 10000) % 1000) % 500) % 100) / 25;
    dimes = (((((amountInInt % 10000) % 1000) % 500) % 100) % 25) / 10;
    nickels = ((((((amountInInt % 10000) % 1000) % 500) % 100) % 25) % 10) / 5;
    cents = (((((((amountInInt % 10000) % 1000) % 500) % 100) % 25) % 10) % 5);
      
    // returning currency in float
    return toCurrency(amountOfMoney) + " = " + to_string(hundreds) + " hundreds " + to_string(tens) + " tens " + to_string(fives) + " fives " + to_string(ones) + " ones " + to_string(quarters) + " quarters " + to_string(dimes) + " dimes " + to_string(nickels) + " nickles " + to_string(cents) + " pennies. "; 
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
    double check, fraction, intVariable;
    // getting user input for the check
    cin >> check;

    fraction = modf(check, &intVariable);

    printf("Check for $%g = %g dollars %g cents ", check, intVariable, fraction);

    return "";
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
    // declaring the variables used in processChangeFloat
    double firstInputNumber, secondInputNumber, totalOfBoth;

    // Getting user input
    cin >> firstInputNumber;
    cin >> secondInputNumber;

    // Adding both after input from user input
    totalOfBoth = firstInputNumber - secondInputNumber;

    int totalToInt = (int)(totalOfBoth * 100);

    std::ostringstream decFloat;

    // for setting decimal places of float
    decFloat << fixed << std::setprecision(2);
    decFloat << totalOfBoth;
    std::string stringStreamObject = decFloat.str();

    hundreds = totalToInt / 10000;
    tens = (totalToInt % 10000) / 1000;
    fives = ((totalToInt % 10000) % 1000) / 500;
    ones = (((totalToInt % 10000) % 1000) % 500) / 100;
    quarters = ((((totalToInt % 10000) % 1000) % 500) % 100) / 25;
    dimes = (((((totalToInt % 10000) % 1000) % 500) % 100) % 25) / 10;
    nickels = ((((((totalToInt % 10000) % 1000) % 500) % 100) % 25) % 10) / 5;
    cents = (((((((totalToInt % 10000) % 1000) % 500) % 100) % 25) % 10) % 5);

    // returning in correct format
    return "Change back on $" + to_string(firstInputNumber) + " for purchase of " + toCurrency(secondInputNumber) + " is " + toCurrency(totalOfBoth) + " which is " +
        " = " + to_string(hundreds) + " hundreds " + to_string(tens) + " tens " + to_string(fives) + " fives " + to_string(ones) + " ones " + to_string(quarters) + " quarters " + to_string(dimes) + " dimes " + to_string(nickels) + " nickels " + to_string(cents) + " cents. ";
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {

    double changedInput, changedAnswer;
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents;
    cin >> changedInput;

    total = (hundreds * 100) + (tens * 10) + (fives * 5) + (ones * 1) + (quarters * 0.25) + (dimes * 0.10) + (nickels * 0.05) + (cents * .01);
    changedAnswer = total - changedInput;

    double totalAnswer = changedAnswer;
    int answerToTheInteger = (int)(changedAnswer * 100);

    int hundredsOverriden, tensOverriden, fivesOverriden, onesOverriden, quartersOverriden, dimesOverriden, nickelsOverriden, centsOverriden;

    hundredsOverriden = answerToTheInteger / 10000;

    tensOverriden = (answerToTheInteger % 10000) / 1000;

    fivesOverriden = ((answerToTheInteger % 10000) % 1000) / 500;

    onesOverriden = (((answerToTheInteger % 10000) % 1000) % 500) / 100;

    quartersOverriden = ((((answerToTheInteger % 10000) % 1000) % 500) % 100) / 25;

    dimesOverriden = (((((answerToTheInteger % 10000) % 1000) % 500) % 100) % 25) / 10;

    nickelsOverriden = ((((((answerToTheInteger % 10000) % 1000) % 500) % 100) % 25) % 10) / 5;

    centsOverriden = (((((((answerToTheInteger % 10000) % 1000) % 500) % 100) % 25) % 10) % 5);


   return "The change back on " + to_string(hundreds) + " hundreds " + to_string(tens) + " tens " + to_string(fives) + " fives " + to_string(ones) + " ones " +
       to_string(quarters) + " quarters " + to_string(dimes) + " dimes " + to_string(nickels) + " nickels " + to_string(cents) + " pennies " +
       " for the purchase of " + toCurrency(changedInput) + " is" + toCurrency(totalAnswer)
       + " which is " + to_string(hundredsOverriden) + " hundreds " + to_string(tensOverriden) + " tens " + to_string(onesOverriden) + " ones " + to_string(quartersOverriden) + " quarters " +
       to_string(dimes) + " dimes " + to_string(nickels) + " nickels " + to_string(cents) + " pennies";
}
