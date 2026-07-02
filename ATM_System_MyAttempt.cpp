#include <iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

const string ClientsFileName = "C:\\Users\\hp\\source\\repos\\Bank Requirements Course 8\\Bank Requirements Course 8\\Cleints.txt";

void ShowATMmainMenue();
void Login();
void ShowQuickWithdrawMenue();
void ShowNormalWithdrawMenue();

enum enQuickWithdrawOptions {
    e20 = 1, e50 = 2, e100 = 3,
    e200 = 4, e400 = 5, e600 = 6,
    e800 = 7, e1000 = 8, eExit = 9,
};

enum enATMmainMenueOptions {
    eQuickWithdraw = 1, eNormalWithdraw = 2, eDeposit = 3,
    eChekBalance = 4, eLogout = 5
};
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

sClient CurrentClient;

vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double


    return Client;

}
string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;

}
vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;

            }

        }

        MyFile.close();

    }

    return vClients;

}
vector <sClient> LoadCleintsDataFromFile(string FileName)
{

    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return vClients;

}
bool FindClientByAccountNumberAndPincode(string AccountNumber, string Pincode, sClient& Client)
{

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    for (sClient C : vClients)
    {

        if (C.AccountNumber == AccountNumber && C.PinCode == Pincode)
        {
            Client = C;
            return true;
        }

    }
    return false;

}
bool DepositBalanceToClientByAccountNumber(double Amount, vector <sClient>& vClients)
{
    char Answer = 'n';
    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == CurrentClient.AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                return true;
            }

        }


        return false;
    }

}

bool ChekBalance()
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    for (sClient& C : vClients)
    {
        if (C.AccountNumber == CurrentClient.AccountNumber)
        {
            cout << "Your Balance is " << C.AccountBalance;

            return true;
        }

    }
}
void GoBackToContinueNormalWithdraw()
{
    cout << "\n\nPress any key to continue...";
    system("pause>0");
    ShowNormalWithdrawMenue();
}
void GoBackToContinue()
{
    cout << "\n\nPress any key to continue...";
    system("pause>0");
    ShowQuickWithdrawMenue();
}
void ShowWithDrawScreen(int Amount = 0)
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    if (Amount == 0)
    {
        do
        {
            cout << "\nEnter an amount multiple of 5's? ";
            cin >> Amount;
        } while (Amount % 5 != 0);

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == CurrentClient.AccountNumber)
            {
                if (Amount > C.AccountBalance)
                {
                    cout << "\nAmount Exceeds the balance, make another choice";
                    GoBackToContinueNormalWithdraw();
                    return;
                }
            }
        }

        DepositBalanceToClientByAccountNumber(Amount * -1, vClients);
    }
    else
    {
        for (sClient& C : vClients)
        {
            if (C.AccountNumber == CurrentClient.AccountNumber)
            {
                if (Amount > C.AccountBalance)
                {
                    cout << "\nAmount Exceeds the balance, make another choice";
                    GoBackToContinue();
                    return;
                }
            }
        }
        DepositBalanceToClientByAccountNumber(Amount * -1, vClients);
    }



}

void ShowBalancesScreen()
{
    cout << "===========================================\n";
    cout << "\t\tChek Balance Screen\n";
    cout << "===========================================\n";

    ChekBalance();

}

void GoBackToATMmainMenue()
{
    cout << "\n\nPress any key to go back to ATM Main Menue...";
    system("pause>0");
    ShowATMmainMenue();
}
void PerfromQuickWithdrawMenueOption(enQuickWithdrawOptions QuickWithdrawMenueOption)
{
    switch (QuickWithdrawMenueOption)
    {
    case enQuickWithdrawOptions::e20:
    {

        ShowWithDrawScreen(20);
        GoBackToATMmainMenue();
        break;
    }

    case enQuickWithdrawOptions::e50:
    {

        ShowWithDrawScreen(50);
        GoBackToATMmainMenue();
        break;
    }

    case enQuickWithdrawOptions::e100:
    {

        ShowWithDrawScreen(100);
        GoBackToATMmainMenue();
        break;
    }

    case enQuickWithdrawOptions::e200:
    {

        ShowWithDrawScreen(200);
        GoBackToATMmainMenue();
        break;
    }

    case enQuickWithdrawOptions::e400:
    {

        ShowWithDrawScreen(400);
        GoBackToATMmainMenue();
        break;
    }
    case enQuickWithdrawOptions::e600:
    {

        ShowWithDrawScreen(600);
        GoBackToATMmainMenue();
        break;
    }
    case enQuickWithdrawOptions::e800:
    {

        ShowWithDrawScreen(800);
        GoBackToATMmainMenue();
        break;
    }
    case enQuickWithdrawOptions::e1000:
    {

        ShowWithDrawScreen(1000);
        GoBackToATMmainMenue();
        break;
    }

    case enQuickWithdrawOptions::eExit:
    {
        ShowATMmainMenue();
    }
    }

}

short ReadQuickWithdrawMenueOption()
{
    cout << "\nChoose what do you want to do? [1 to 9]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}
void ShowQuickWithdrawMenue()
{

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tQuick Withdraw Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] 20\t";
    cout << "\t[2] 50\n";
    cout << "\t[3] 100\t";
    cout << "\t[4] 200\n";
    cout << "\t[5] 400\t";
    cout << "\t[6] 600\n";
    cout << "\t[7] 800\t";
    cout << "\t[8] 1000\n";
    cout << "\t[9] Exit\n";

    cout << "===========================================\n";

    ChekBalance();
    PerfromQuickWithdrawMenueOption((enQuickWithdrawOptions)ReadQuickWithdrawMenueOption());
}
void ShowNormalWithdrawMenue()
{

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tNormal Withdraw Screen\n";
    cout << "===========================================\n";

    ShowWithDrawScreen();

}
void ShowDepositMenue()
{

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tDeposit Screen\n";
    cout << "===========================================\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    double Amount;

    do
    {
        cout << "\nEnter a positive Deposit amount? ";
        cin >> Amount;
    } while (Amount < 0);



    DepositBalanceToClientByAccountNumber(Amount, vClients);



}
short ReadATMmainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 5]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}
void PerfromMainMenueOption(enATMmainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enATMmainMenueOptions::eQuickWithdraw:
    {
        system("cls");
        ShowQuickWithdrawMenue();
        GoBackToATMmainMenue();
        break;
    }
    case enATMmainMenueOptions::eNormalWithdraw:
    {
        system("cls");
        ShowNormalWithdrawMenue();
        GoBackToATMmainMenue();
        break;
    }

    case enATMmainMenueOptions::eDeposit:
    {
        system("cls");
        ShowDepositMenue();
        GoBackToATMmainMenue();
        break;
    }
    case enATMmainMenueOptions::eChekBalance:
    {
        system("cls");
        ShowBalancesScreen();
        GoBackToATMmainMenue();
        break;
    }

    case enATMmainMenueOptions::eLogout:
    {
        system("cls");
        Login();
        break;
    }
    }

}

void ShowATMmainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";


    PerfromMainMenueOption((enATMmainMenueOptions)ReadATMmainMenueOption());
}
bool  LoadClientInfo(string AccountNumber, string Pincode)
{

    if (FindClientByAccountNumberAndPincode(AccountNumber, Pincode, CurrentClient))
        return true;
    else
        return false;

}
void Login()
{
    bool LoginFaild = false;

    string Accountnumber, Pincode;
    do
    {
        system("cls");

        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (LoginFaild)
        {
            cout << "Invlaid Account Number/Pincode!\n";
        }

        cout << "Enter Account Number? ";
        cin >> Accountnumber;

        cout << "Enter Pincode? ";
        cin >> Pincode;

        LoginFaild = !LoadClientInfo(Accountnumber, Pincode);

    } while (LoginFaild);

    ShowATMmainMenue();

}

int main()
{
    Login();

    system("pause>0");
    return 0;
}