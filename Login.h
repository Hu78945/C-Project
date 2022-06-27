#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Login
{
private:
    /* data */
    string userName;
    string password;
    string authFolder = "C:\\auth\\";

public:
    Login(string userName, string password)
    {
        this->userName = userName;
        this->password = password;
        CheckIfUserExist();
    }
    void CheckIfUserExist()
    {
        fstream AuthFile;

        AuthFile.open(authFolder + userName + ".txt", ios::in);
        int i = 1;
        if (AuthFile.is_open())
        {
            string line, dbUsername, dbPassword;
            while (getline(AuthFile, line))
            {
                if (i == 1)
                {
                    dbUsername = line;
                }
                else if (i == 2)
                {
                    dbPassword = line;
                }
                i++;
            }
            AuthFile.close();
            if (userName == dbUsername && password == dbPassword)
            {
                cout << "You have logged in" << endl;
            }
        }
        else
        {
            cout << "Please enter the correect information or register the users" << endl;
        }
    }
};
