#pragma once
#include "FileMangement.h"
#include <iostream>
#include <string.h>
#include <direct.h>
#include <dirent.h>
using namespace std;
class Folder : public FileMangement
{
private:
    char *folderName;

public:
    Folder(char *folderName) : FileMangement()
    {
        this->folderName = folderName;
        char *RootPath = FileMangement::getRootFolderAdress();
        char *NewFolderPath = static_cast<char *>(malloc(strlen(this->folderName) + strlen(RootPath) + 1));
        strcpy(NewFolderPath, RootPath);
        strcat(NewFolderPath, this->folderName);
        int folder = _mkdir(NewFolderPath);
        string f = "\\";
        strcat(NewFolderPath, f.c_str());
        this->folderName = NewFolderPath;
        cout << "Folder have been created" << endl;
    };
    void static Remove(char *folderName)
    {
        FileMangement f1;
        char *NewFolderPath = static_cast<char *>(malloc(strlen(folderName) + strlen(f1.getRootFolderAdress()) + 1));
        strcpy(NewFolderPath, f1.getRootFolderAdress());
        strcat(NewFolderPath, folderName);
        string c = (string)NewFolderPath;
        string a = "rmdir /s /q " + c;
        system(a.c_str());
    }
    friend class File;
};
