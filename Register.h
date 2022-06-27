#include <iostream>
#include <string.h>
#include <dirent.h>
#include <fstream>
#include "Folder.h"
#include <string.h>
using namespace std;

class Register
{
private:
    /* data */
    string userName;
    string password;

public:
    Register(string userName, string password)
    {
        this->userName = userName;
        this->password = password;
        string path = createAuthFolder();
        RegisterUser(path);
        cout << "User have been created with userName: " << userName << endl;
        CreateUserDrive();
    }
    string createAuthFolder()
    {
        string folderPath = "C:\\auth";
        int folder = _mkdir(folderPath.c_str());
        string fullPath = "C:\\auth\\";
        return fullPath;
    }
    void RegisterUser(string authFolderPath)
    {
        std::ifstream test(authFolderPath + userName + ".txt");
        if (!test)
        {

            ofstream AuthFile(authFolderPath + userName + ".txt");
            AuthFile << userName << endl;
            AuthFile << password << endl;
            AuthFile.close();
        }
        else
        {
            cout << "User with that username also exist please try again" << endl;
        }
    }
    void CreateUserDrive()
    {
        FileMangement f1;
        string roothPath = f1.getRootFolderAdress();
        string driveName = userName;
        string DrivePath = roothPath + "//" + userName;
        int folder = _mkdir(DrivePath.c_str());
        string f = "\\";
        DrivePath = DrivePath + "\\";
        cout << "In teh root folder your drive have been created" << endl;
        // f1.setRootFolderAdress(DrivePath.c_str());
        }
};
