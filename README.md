# ATM Interface

## 1\. Introduction

ATM Interface is a C++ mini project developed using Object-Oriented Programming (OOP) concepts.

The project simulates the basic working of an Automated Teller Machine (ATM). It allows multiple users to access their individual accounts and perform banking operations such as checking balance, depositing money, withdrawing cash, and viewing transaction history.

An Automated Teller Machine (ATM) is an electronic banking system that allows customers to perform basic banking operations without visiting a bank branch. It provides a convenient, secure, and time-saving way to access banking services.
This project demonstrates how OOP concepts can be used to develop a simple banking application.

## 2\. Project Objectives

The main objectives of this project are:

- To understand the practical implementation of Object-Oriented Programming.
- To simulate basic ATM operations.
- To manage multiple bank accounts.
- To implement PIN-based authentication.
- To maintain transaction records.
- To understand account management using C++ classes.
- To implement balance enquiry efficiently.
- 

## 3\. Features

The ATM Interface project includes the following features:

- **Multiple User Accounts:** Supports separate accounts for three users.
- **PIN Authentication:** Provides PIN-based account access.
- **Balance Enquiry:** Displays the current account balance.
- **Cash Deposit:** Allows users to deposit money.
- **Cash Withdrawal:** Allows users to withdraw money.
- **Mini Statement:** Displays recent transaction details.
- **Transaction History:** Maintains records of account transactions.
- **Savings Tracker:** Helps users monitor their savings.
- **Spending Analyzer:** Helps users analyze their spending.
- **PIN Change:** Allows users to change their existing ATM PIN.
- **Secure Logout:** Allows users to safely exit their accounts.


## 4\. Technologies Used

- Programming Language: C++
- IDE: Visual Studio Code
- Compiler: MSYS2 GCC
- Version Control: Git and GitHub

## 5\. Object-Oriented Programming Concepts

The project uses the following OOP concepts:

### Classes and Objects

Classes are used to organize the program, while objects represent individual accounts and transactions.

### Encapsulation

Data and related functions are grouped inside classes.

### Inheritance

The SavingsAccount class inherits properties and functions from the BankAccount class.

### Polymorphism

Virtual functions are used to support runtime polymorphism.

### Abstraction

The abstract BankAccount class provides a common structure for account operations.

### Constructors

Constructors initialize account and transaction details when objects are created.

## 6\. Project Structure

The project is divided into multiple header and source files.

| File Name | Description |
| --- | --- |
| main.cpp | Main entry point of the program |
| ATM.h | ATM class declaration |
| ATM.cpp | ATM operations and menu |
| BankAccount.h | BankAccount class declaration |
| BankAccount.cpp | Banking operations |
| SavingsAccount.h | SavingsAccount class declaration |
| SavingsAccount.cpp | Savings account implementation |
| Transaction.h | Transaction class declaration |
| Transaction.cpp | Transaction implementation |

## 7\. How to Compile and Run

### Step 1: Open the project folder

Open the ATM Interface folder in Visual Studio Code.

### Step 2: Compile the program

Open the VS Code terminal and enter:

``` bash
g++ -std=c++17 main.cpp ATM.cpp BankAccount.cpp SavingsAccount.cpp Transaction.cpp -o atm.exe
```

### Step 3: Run the program

Enter:

``` bash
.\atm.exe
```

The ATM Interface menu will appear in the terminal.

## 8\. Team Members

This project was developed by:

1. Simar
2. Suman
3. Sukhman

## 9\. Conclusion

The ATM Interface project helped us understand the practical application of Object-Oriented Programming in C++.

Through this project, we learned how to use classes, objects, inheritance, encapsulation, abstraction, and polymorphism to develop a simple banking simulation.

It also improved our understanding of C++ programming, modular coding, debugging, and collaborative project development.
