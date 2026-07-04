# ATM System (C++) 🏧

A console-based ATM simulation built in C++, where clients can log in using their account number and PIN code, then perform banking operations like quick withdrawal, normal withdrawal, deposit, and balance check.

This project is built on top of the Bank System's client data, simulating a real ATM experience from the client's perspective.

---

## 🎓 Learning and Programming Foundation

This project was built as part of the practical applications in the **"Algorithms and Problem Solving - Level 3 (Course 8)"** course on [programmingadvices.com](https://programmingadvices.com), under the supervision of engineer **Mohammed Abu Hadhoud** 👑 ([LinkedIn](https://www.linkedin.com/in/abuhadhoud)).

---

## 🏧 How the System Works

- The client logs in using their **Account Number** and **PIN Code**
- After login, the ATM main menu appears with 5 options
- All transactions update the balance in real time and save to the file
- The client can logout and switch accounts

---

## ✨ Key Features

| # | Feature | Description |
|---|---------|-------------|
| 1 | **Login System** | Secure login with account number and PIN |
| 2 | **Quick Withdraw** | Choose from preset amounts (20, 50, 100, 200, 400, 600, 800, 1000) |
| 3 | **Normal Withdraw** | Enter any custom amount (must be multiple of 5) |
| 4 | **Deposit** | Add funds to the account |
| 5 | **Check Balance** | View current account balance |
| 6 | **Logout** | Switch between client accounts |

---

## 🧠 Programming Concepts Applied

- **Structures** (`struct`) — to represent client data
- **Enums** (`enum`) — for menu options
- **Vectors** — to manage client list dynamically
- **File Handling** (`fstream`) — reads and writes client data to `Clients.txt`
- **Functions** — clean separation of every screen and operation
- **Data Validation** — PIN verification, balance checks, amount validation

---

## 📈 My Progress: My Attempt vs. Final Solution

### 1. `ATM_System_MyAttempt.cpp` — My First Try
- My independent approach before watching the solution
- Core logic works with some structural differences

### 2. `ATM_System_FinalSolution.cpp` — The Improved Version
- Cleaner and more structured code
- Better separation between reading input and performing operations

---

## 📂 Project Files

| File | Description |
|------|-------------|
| `ATM_System_FinalSolution.cpp` | The improved and structured version |
| `ATM_System_MyAttempt.cpp` | My first independent attempt |
| `Clients.txt` | Shared with Bank System — stores client records |
| `README.md` | This file, explaining the project |

---

## 🛠 How to Run the Project

### Prerequisites
You need a C++ compiler installed (like **GCC** on Linux/Mac or **MinGW** on Windows).

> **Important:** This project reads from `Clients.txt`. Make sure the file exists with valid client records before running.

### Steps

1. Clone this project:
```bash
git clone https://github.com/karimmesselmi/atm-system.git
```

2. Go to the project folder:
```bash
cd atm-system
```

3. Compile the final version:
```bash
g++ ATM_System_FinalSolution.cpp -o ATMSystem
```

4. Run the program:

On Windows:
```bash
ATMSystem
```
On Linux/Mac:
```bash
./ATMSystem
```

---

## 👤 About Me

**Karim Messelmi** — Computer Science student, building my foundation one project at a time.

🔗 [LinkedIn](https://www.linkedin.com/in/karim-messelmi-34a02a379)

> *"Every project I build teaches me something new. This is just the beginning."* 🚀
