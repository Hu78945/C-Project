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
    Register(string userName, string password);
    string createAuthFolder();
    void RegisterUser(string authFolderPath);
    void CreateUserDrive();
};
