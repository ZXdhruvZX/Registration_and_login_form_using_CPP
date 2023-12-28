#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <sstream>


using namespace std;

class Login {
private:
    string LoginID, Password;

public:
    Login() : LoginID(""), Password("") {}

    void setID(const string& id) {
        LoginID = id;
    }

    void setPW(const string& pw) {
        Password = pw;
    }

    string getID() const {
        return LoginID;
    }

    string getPW() const {
        return Password;
    }
};


void registration(Login &log) {
    system("cls");
    string id, pw;
    cout << "\tEnter LoginID: ";
    cin >> id;
    log.setID(id);

    while (true) {
        cout << "\tEnter a strong Password: ";
        cin >> pw;
        if (pw.length() >= 8) {
            log.setPW(pw);
            break;
        } else {
            cout << "\tEnter minimum 8 characters!" << endl;
        }
    }

    ofstream outfile("C:/Users/dhruv/Codes/Coding/Projects/Registration-and-Login-form-using-file-handling-in-CPP/Login.txt", ios::app);
    if (!outfile) {
        cout << "\tError" << endl;
    } else {
        outfile << "\t" << log.getID() << " : " << log.getPW() << endl << endl;
        cout << "\tUser Registered Successfully" << endl;
    }
    outfile.close();

    Sleep(3000);
}

void login() {
    system("cls");
    string id, pw;
    cout << "\tEnter Login ID: ";
    cin >> id;
    cout << "\tEnter Password: ";
    cin >> pw;

    ifstream infile("C:/Users/dhruv/Codes/Coding/Projects/Registration-and-Login-form-using-file-handling-in-CPP/Login.txt");

    if (!infile) {
        cout << "\tError" << endl;
    } else {
        string line;
        bool found = false;

        while (getline(infile, line)) {
            stringstream ss;
            ss<<line;
            string userID, userPW;
            char delimiter;

            ss >> userID >> delimiter >> userPW;

            if (id == userID && pw == userPW) {
                found = true;
                cout << "\tPlease Wait";
                for (int i = 0; i < 3; i++) {
                    cout << ".";
                    Sleep(800);
                }
                system("cls");
                cout << "\tWelcome to This Page" << endl;
            }
        }

        if (!found) {
            cout << "\tError: Incorrect ID or Password" << endl;
        }
    }

    infile.close();
    Sleep(5000);
}
int main() {
    Login log;
    bool exit = false;
    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome to Registration & Login Form" << endl;
        cout << "\t***********************************" << endl;
        cout << "\t1. Register." << endl;
        cout << "\t2. Login." << endl;
        cout << "\t3. Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            // Pass the Login object by reference
            registration(log);
        } else if (val == 2) {
            login();
        }
        else if(val==3)
        {
        	system("cls");
        	
        	exit=true;
        	Sleep(3000);
        	cout<<"\tGood Luck";
        	
		}
        

        Sleep(3000);
    }

    // ...

    // Add a return statement
    return 0;
}

