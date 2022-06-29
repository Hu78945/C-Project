#include <iostream>
#include "Folder.h"

Login::Login(string userName, string password)
{
    this->userName = userName;
    this->password = password;
    CheckIfUserExist();
}

bool Login::CheckIfUserExist()
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
            isLoggedIn = 0;
            return isLoggedIn;
            FileMangement f1;
            string path = "C:\\root\\" + userName + "\\";
            f1.setRootFolderAdress(path.c_str());
        }
    }
    else
    {
        cout << "Please enter the correect information or register the users" << endl;
    }
}