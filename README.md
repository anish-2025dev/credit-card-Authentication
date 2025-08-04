# 💳 Credit Card Validator in C++

This is a simple C++ program that validates a credit card number using the **Luhn algorithm** and detects the **card type** (Visa, MasterCard, American Express, or RuPay) based on the number pattern.

---

## 🚀 Features

- Input validation for negative numbers
- Implements **Luhn's algorithm** for checksum validation
- Detects card types based on 2025 standards:
  - ✅ Visa
  - ✅ MasterCard
  - ✅ American Express
  - ✅ RuPay (updated BIN ranges)
  - ❓ Others

---

## 🧠 How It Works

1. Prompts the user to enter a credit card number.
2. Validates the number using the **Luhn checksum algorithm**.
3. Determines the card type using the starting digits and length:
   - **Visa**: Starts with 4, length 13, 16, or 19
   - **MasterCard**: Starts with 51–55, length 16
   - **Amex**: Starts with 34 or 37, length 15
   - **RuPay**: BIN ranges like 5085, 6069, 6521, etc., length 16

---

## 🧪 Sample Run

```bash
Enter Your Credit Card Number: 5085123412341234
Valid
Card Type: RUPAY
