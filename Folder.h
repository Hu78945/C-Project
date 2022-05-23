#include <iostream>
#include <string.h>
#include <direct.h>
#include <dirent.h>
#include "FileMangement.h"
using namespace std;
class Folder : public FileMangement
{
private:
    /* data */
    char *folderName;

public:
    Folder(char *folderName) : FileMangement()
    {
        this->folderName = folderName;
        char *RootPath = FileMangement::getRootFolderAdress();
        char *NewFolderPath = static_cast<char *>(malloc(strlen(this->folderName) + strlen(RootPath) + 1));
        int folder = _mkdir(NewFolderPath);
        cout << "Folder have been created" << endl;
    };
    friend class File;
};
