#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    long long creditnum;

    // Input Validation
    do {
        cout << "Enter Your Credit Card Number: ";
        cin >> creditnum;
    } while (creditnum < 0);

    long long pcc = creditnum;
    int sum = 0;
    int count1 = 0;
    long long divisor = 10;
    char types[30];

    // Step 1: Add digits that are not multiplied by 2 (Luhn's algorithm)
    while (pcc > 0) {
        int lastdigit = pcc % 10;
        sum += lastdigit;
        pcc /= 100;
    }

    // Step 2: Add digits that are multiplied by 2 (Luhn's algorithm)
    pcc = creditnum / 10;
    while (pcc > 0) {
        int lastsecdigit = pcc % 10;
        int db = lastsecdigit * 2;
        sum += (db % 10) + (db / 10);
        pcc = pcc / 100;
    }

    // Step 3: Count number of digits
    pcc = creditnum;
    while (pcc != 0) {
        pcc /= 10;
        count1++;
    }

    // Step 4: Extract leading digits
    for (int i = 0; i < count1 - 2; i++) {
        divisor *= 10;
    }

    int firstdigit = creditnum / divisor;
    int first_two = creditnum / (divisor / 10);
    int first_three = creditnum / (divisor / 100);
    int first_four = creditnum / (divisor / 1000);
    int first_six = creditnum / (divisor / 100000);

    // Step 5: Determine Card Type
    if (sum % 10 == 0) {
        if ((firstdigit == 4) && (count1 == 13 || count1 == 16 || count1 == 19)) {
            cout << "Valid\nCard Type: ";
            strcpy(types, "VISA");
        } else if ((first_two == 34 || first_two == 37) && count1 == 15) {
            cout << "Valid\nCard Type: ";
            strcpy(types, "AMERICAN EXPRESS");
        } else if ((first_two >= 51 && first_two <= 55) && count1 == 16) {
            cout << "Valid\nCard Type: ";
            strcpy(types, "MASTERCARD");
        } 
        // RuPay logic as per updated 2025 ranges
        else if (
            (first_four == 5085 || first_four == 5086 || first_four == 5089 ||
             first_four == 6069 || first_four == 6070 || first_four == 6071 ||
             first_four == 6080 || first_four == 6521 || first_four == 6522 ||
             first_two == 60 || first_two == 65 || first_two == 81 || first_two == 82) 
            && count1 == 16
        ) {
            cout << "Valid\nCard Type: ";
            strcpy(types, "RUPAY");
        } else {
            cout << "Valid\nCard Type: ";
            strcpy(types, "OTHER CARD TYPE");
        }
    } else {
        strcpy(types, "INVALID");
    }

    cout << types << endl;
    return 0;
}
