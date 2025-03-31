 #include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Currency {
    string code;
    double rate;
};

Currency exchangeRates[] = {
    {"USD", 1.0},  {"EUR", 0.91}, {"GBP", 0.78}, {"INR", 83.21}, 
    {"JPY", 151.12}, {"CAD", 1.35}, {"AUD", 1.51}, {"CNY", 7.24}
};

string getCurrencyInput(string prompt) {
    string currency;
    bool valid = false;

    while (!valid) {
        cout << prompt;
        cin >> currency;

        for (int i = 0; i < 8; i++) {
            if (exchangeRates[i].code == currency) {
                valid = true;
                break;
            }
        }

        if (!valid) {
            cout << "Invalid currency! Please enter a valid code.\n";
        }
    }
    return currency;
}

double getAmount() {
    double amount;
    while (true) {
        cout << "Enter amount: ";
        cin >> amount;
        
        if (cin.fail() || amount <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a valid number.\n";
        } else {
            return amount;
        }
    }
}

double getExchangeRate(string currency) {
    for (int i = 0; i < 8; i++) {
        if (exchangeRates[i].code == currency) {
            return exchangeRates[i].rate;
        }
    }
    return 1.0;
}

double convertCurrency(double amount, string from, string to) {
    double amountInUSD = amount / getExchangeRate(from);
    return amountInUSD * getExchangeRate(to);
}

void displayCurrencies() {
    cout << "\nAvailable Currencies: ";
    for (int i = 0; i < 8; i++) {
        cout << exchangeRates[i].code << " ";
    }
    cout << endl;
}

int main() {
    cout << fixed << setprecision(2);

    while (true) {
        cout << "\n===== ?? Currency Converter =====\n";
        displayCurrencies();

        string fromCurrency = getCurrencyInput("Enter source currency: ");
        string toCurrency = getCurrencyInput("Enter target currency: ");
        double amount = getAmount();

        double convertedAmount = convertCurrency(amount, fromCurrency, toCurrency);

        cout << "\n?? Converted Amount: " << amount << " " << fromCurrency
             << " = " << convertedAmount << " " << toCurrency << "\n";

        char choice;
        cout << "\nDo you want to convert another amount? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            cout << "Thank you for using the Currency Converter! ??\n";
            break;
        }
    }
    return 0;
}

