# ATM System V1 (C++) 🏧

A console-based Automated Teller Machine (ATM) application built in C++, featuring a secure client login system and full banking operations. This project simulates a real-world ATM experience where clients can securely log in using their account numbers and PIN codes to manage their balances and perform quick or custom financial transactions.

This is my fifth practical programming project in C++, designed to deepen my understanding of file-based data persistence, vector data structures, structural design patterns, and robust input validation.

---

## 🎓 Learning and Programming Foundation

This project was built as part of the practical applications in the **"Data Structures & Algorithms - Level 5 (Course 8)"** course on [programmingadvices.com](https://programmingadvices.com), under the supervision of engineer **Mohammed Abu Hadhoud** 👑 ([LinkedIn](https://www.linkedin.com/in/abuhadhoud)).

---

## 🆚 ATM System vs Bank System V2

Unlike the **Bank System V2** which focuses on *Admin/Employee management tools* (managing clients, users, and global permissions), this **ATM System** is *Client-Facing*, providing a dedicated, secure, and streamlined portal for the bank's actual customers.

| Feature | Bank System V2 | ATM System |
| :--- | :---: | :---: |
| **Primary User** | Admins / Staff | Bank Clients |
| **Authentication** | Username + Password | Account Number + PIN |
| **Quick Withdraw Menu** | ❌ | ✅ (Pre-set amounts: 20 to 1000) |
| **Normal Withdraw Menu** | ✅ (Custom amount) | ✅ (Enforced multiples of 5) |
| **Deposit Operations** | ✅ | ✅ (Instant balance updating) |
| **User & Permission Management** | ✅ | ❌ (Client-isolated context) |

---

## 🏧 How the System Works

- **Secure Login Screen:** The system prompts for an Account Number and PIN code, matching it against the live records.
- **Client Session Isolation:** Once logged in, the application binds the active session to that specific client (`CurrentClient`), making data tampering impossible.
- **Real-Time Text File Persistence:** Every withdrawal or deposit dynamically updates the `Clients.txt` file using record-to-line serialization.
- **Robust Input Boundaries:** Prevents overdrafts during quick or custom withdrawals and gives instant feedback.

---

## ✨ Key Features

| # | Feature | Description |
| :-: | :--- | :--- |
| **1** | **Secure Client Login** | Validates account credentials against database files with error flags. |
| **2** | **Quick Withdraw Menu** | Fast withdrawal options for common amounts: 20, 50, 100, 200, 400, 600, 800, 1000. |
| **3** | **Normal Withdraw Menu** | Allows withdrawing any custom amount, strictly enforced to be a **multiple of 5**. |
| **4** | **Instant Cash Deposit** | Adds positive amounts instantly to the customer's balance. |
| **5** | **Check Balance Screen** | Displays up-to-the-second precise account balances. |
| **6** | **Session Logout** | Securely terminates the active client session and returns safely to the login screen. |

---

## 🧠 Programming Concepts Applied

- **Structures (`struct`) & State:** Encapsulating client properties and tracking active session state globally.
- **Advanced String Tokenization (`SplitString`):** Splitting data lines using customizable delimiters (`#//#`) to reconstruct runtime objects.
- **Dynamic Array Structures (`std::vector`):** Managing datasets in memory efficiently for search and amendment loops.
- **File Handling Stream (`fstream`):** Running structural dual-mode reads (`ios::in`) and overwrite writes (`ios::out`) to guarantee data integrity.
- **Mathematical Validation:** Applying mathematical modulus operators (`Amount % 5 != 0`) to guarantee proper physical currency distributions.

---

## 📈 My Progress: My Attempt vs. Final Solution

### 1. `ATM_System_MyAttempt.cpp` — My First Try
- Built entirely independently before analyzing the optimized solution template.
- Functional routing works flawlessly, though contains hardcoded local diagnostic paths (e.g., specific absolute Windows file system strings).

### 2. `ATM_System_FinalSolution.cpp` — The Improved Version
- Cleaner structure with streamlined logic routing.
- Parameterized generic lookups, making file structures relative and ready for cross-platform deployment.

---

## 📂 Project Files

| File | Description |
| :--- | :--- |
| `ATM_System_FinalSolution.cpp` | Optimized, structured, and deployment-ready source code. |
| `ATM_System_MyAttempt.cpp` | My standalone initial implementation showcasing the core logic setup. |
| `Clients.txt` | Auto-generated database text file storing structured client records. |
| `README.md` | Comprehensive architectural and project overview documentation (This file). |

---

## 🛠 How to Run the Project

### Prerequisites
A cross-platform C++ compiler installed (e.g., **GCC** for Linux/Mac or **MinGW** for Windows operating systems).

### Steps
1. Clone this repository:
   ```bash
   git clone https://github.com/karimmesselmi/atm-system-cplusplus.git
   ```
2. Navigate to the project directory:
   ```bash
   cd atm-system-cplusplus
   ```
3. Compile the production version:
   ```bash
   g++ ATM_System_FinalSolution.cpp -o ATMSystem
   ```
4. Run the program executable:
   - **Windows:**
     ```bash
     ATMSystem
     ```
   - **Linux/Mac:**
     ```bash
     ./ATMSystem
     ```

> 💡 **Pro Tip:** Ensure that a `Clients.txt` file exists in the directory before running, containing records separated by `#//#` (e.g., `A101#//#1234#//#Karim Messelmi#//#0666666666#//#5000.00`).

---

## 👤 About Me

**Karim Messelmi** — Computer Science student, passionate about clean software architecture and software engineering principles.

🔗 [LinkedIn](https://www.linkedin.com/in/karim-messelmi-34a02a379)

> *"Every project I build teaches me something new. This is just the beginning."* 🚀
