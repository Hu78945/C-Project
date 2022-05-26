#pragma once
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
        strcpy(NewFolderPath, RootPath);
        strcat(NewFolderPath, this->folderName);
        int folder = _mkdir(NewFolderPath);
        string f = "\\";
        strcat(NewFolderPath, f.c_str());
        this->folderName = NewFolderPath;
        cout << "Folder have been created" << endl;
    };
    void Remove()
    {
        try
        {
            _rmdir(this->folderName);
            string err = "Error";
            throw err;
        }
        catch (string err)
        {
            cerr << err;
        }
    }
    friend class File;
};
