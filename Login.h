#include <iostream>
#include <fstream>
#include <string.h>
#include "Folder.h"
using namespace std;

class Login
{
private:
    /* data */
    string userName;
    string password;
    string authFolder = "C:\\auth\\";

public:
    bool isLoggedIn = 1;

    Login(string userName, string password);
    bool CheckIfUserExist();
};
