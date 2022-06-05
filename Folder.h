#pragma once
#include "FileMangement.h"
#include <iostream>
#include <string.h>
#include <direct.h>
#include <dirent.h>
#include <errno.h>
using namespace std;
class Folder : public FileMangement
{
private:
    char *folderName;

public:
    Folder(std::string folderName) : FileMangement()
    {
        char *RootPath = FileMangement::getRootFolderAdress();
        char *NewFolderPath = static_cast<char *>(malloc(strlen(RootPath) + strlen(folderName.c_str()) + 1));
        strcpy(NewFolderPath, RootPath);
        strcat(NewFolderPath, folderName.c_str());
        int folder = _mkdir(NewFolderPath);
        if (folder == -1)
        {
            perror("Error");
        }
        else
        {
            string f = "\\";
            strcat(NewFolderPath, f.c_str());
            this->folderName = NewFolderPath;
            cout << "Folder have been created" << endl;
        }
    };
    void static Remove(std::string folderName)
    {
        FileMangement f1;
        char *NewFolderPath = static_cast<char *>(malloc(strlen(folderName.c_str()) + strlen(f1.getRootFolderAdress()) + 1));
        strcpy(NewFolderPath, f1.getRootFolderAdress());
        strcat(NewFolderPath, folderName.c_str());
        cout << NewFolderPath << endl;
        string c = (string)NewFolderPath;
        string a = "rmdir /s /q " + c;
        system(a.c_str());
        }
    friend class File;
};
