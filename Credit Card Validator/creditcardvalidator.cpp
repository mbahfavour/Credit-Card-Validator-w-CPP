#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>

using namespace std;


bool isNumberString(const string& s) {
    int len = s.length();

    for (int i = 0; i<len; i++) {
        if (s[i] < '0'|| s[i] > '9') {
            return false;
        }
        return true;
    }
}


int main()
{
    string creditCardNum;

    cout << "This program uses an algorithm called Luhn's Algorithm to validate a credit card number."<< endl;
    cout << "You may enter 'QUIT' anytime to leave the program"<< endl;

    while (true) 
    {
        cout << "Please enter a credit card number to validate: "<< endl;
        cin >> creditCardNum;

        if (creditCardNum == "QUIT")
        {
            cout << "Now quitting program" <<endl;
            Sleep(3000);
            break;
        }

        else if(!isNumberString(creditCardNum))
        {
            cout << "Invalid Input! ";
            continue;
        }

        int len = creditCardNum.length();
        int doubleEvenSum = 0;

        for(int i=len-2; i>=0; i=i-2)
        {
            int dbl = ((creditCardNum[i] - 48) * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }

        for(int i = len - 1; i >= 0; i = i-2) {
            doubleEvenSum += (creditCardNum[i] - 48);
        }

        cout << (doubleEvenSum % 10 == 0 ? "This is a a valid credit card number!" : "Not a valid Credit Card Number!") <<endl;
        continue;
    }

    return 0;
}