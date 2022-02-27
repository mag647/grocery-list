
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    //Author: Michele Gay
    //Creation Date: 6/29/20
    //Purpose: To ouput total cost of grocery items

    //Variable Declaration
    char printResponse;
    double couponTotal = 0.0;
    double stateTax;
    double taxTotal = 0.0;
    double subtotalPrice = 0.0;
    double preTaxPrice;
    int numItems;
    int numCoupons;
    string stateAbb;
    string userName;
    unsigned int i;
    vector<string> itemNameList;
    vector<double> itemPriceList;
    vector<double> couponList;

    //Welcome user and start shopping
    cout << "Welcome to the Grocery Store App!" << endl;
    cout << "What is your first name?:" << endl;
    cin >> userName;
    cout << "Hello, " << userName << ". Let's start shopping!" << endl;
    cout << "Enter your state (2-letter postal abbreviation): " << endl;
    cin >> stateAbb;

    //If lowercase abbreviation entered, change to uppercase. 
    stateAbb[0] = toupper(stateAbb[0]);
    stateAbb[1] = toupper(stateAbb[1]);

    //Determine state tax on groceries. This app does not distinguish between candy/soda and other groceries.
    //Source: https://taxfoundation.org/sales-taxes-on-soda-candy-and-other-groceries-2018/

    if (stateAbb == "AR") {
        stateTax = 0.015;
    }
    else if (stateAbb == "IL") {
        stateTax = 0.01;
    }
    else if (stateAbb == "MO") {
        stateTax = 0.01225;
    }
    else if (stateAbb == "TN") {
        stateTax = 0.05;
    }
    else if (stateAbb == "UT") {
        stateTax = 0.03;
    }
    else if (stateAbb == "VA") {
        stateTax = 0.025;
    }
    else {
        stateTax = 0.00;
    }

    //Get number of items from user and resize vectors 
    cout << "Enter the number of items you will be buying today (whole number only): " << endl;
    cin >> numItems;
    itemNameList.resize(numItems);
    itemPriceList.resize(numItems);

    //Populate item name and price vectors
    cout << "Let's add your items and prices." << endl;
    cout << "Enter item name as a single word and price as a decimal number, separated by a space." << endl;
    cout << "Ex: Bananas 2.99" << endl;

    for (i = 0; i < itemNameList.size(); ++i) {
        if (i == 0) {
            cout << "Enter the first item name and price:" << endl;
            cin >> itemNameList.at(i) >> itemPriceList.at(i);
            subtotalPrice += itemPriceList.at(i);
        }
        else {
            cout << "Enter the next item name and price:" << endl;
            cin >> itemNameList.at(i) >> itemPriceList.at(i);
            subtotalPrice += itemPriceList.at(i);
        }
    }

    cout << fixed << setprecision(2);
    cout << "Your subtotal (without tax or coupons) comes to: $" << subtotalPrice << "." << endl;

    //Resize and populate coupon vector
    cout << "Enter the number of coupons you will be using today (whole number only): " << endl;
    cin >> numCoupons;
    couponList.resize(numCoupons);

    if (numCoupons > 0) {
        for (i = 0; i < couponList.size(); ++i) {
            cout << "Enter coupon amount:" << endl;
            cin >> couponList.at(i);
            couponTotal += couponList.at(i);
        }
        preTaxPrice = subtotalPrice - couponTotal;
        cout << "You saved: $" << couponTotal << ". Your subtotal is now: $" << preTaxPrice << "." << endl;
    }
    else {
        preTaxPrice = subtotalPrice;
        cout << "No valid coupons entered. Your subtotal remains: $" << preTaxPrice << "." << endl;
    }
   
    //Output grand total to user
    cout << "With " << stateAbb << " state tax on groceries of " << stateTax * 100 << 
        "%, your grand total is: $" << preTaxPrice + (preTaxPrice * stateTax) << "." << endl;

    //Give option for user to print shopping list
    cout << "Print shopping list? Enter Y or y for yes and N or n for no." << endl;
    cin >> printResponse;
    if (printResponse == 'Y' || printResponse == 'y') {
        for (i = 0; i < itemNameList.size(); ++i) {
            cout << itemNameList.at(i) << ": $" << itemPriceList.at(i) << endl;
        }
    }
    else if (printResponse == 'N' || printResponse == 'n') {
        cout << "List not printed." << endl;
    }
    else {
        cout << "Invalid response." << endl;
    }

    cout << "Thank you for shopping with us, " << userName << "! Have a nice day!" << endl;

    return 0;
}
