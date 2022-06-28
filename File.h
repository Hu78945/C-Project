#pragma once
#include <iostream>
#include "Folder.h"
#include <fstream>
using namespace std;
class File : public FileMangement
{
private:
    /* data */
    string fileName;
    string fileContents;
    char *RootPath = FileMangement::getRootFolderAdress();
    string path = static_cast<string>(RootPath);

public:
    void CreateFile(string name);

    void WriteFile(string fileName, string fileContent);

    void ReadFile(string fileName);

    void ClearFile(string fileName);

    void RemoveFile(string fileName);

    // setter functions
    void setPath(string path);

    string getPath();
};
