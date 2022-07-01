#include <iostream>
#include "Folder.h"
#include <cstdio>

using namespace std;

FileOperation::FileOperation(string fileName, string path)
{
    this->fileName = fileName;
    this->path = path;
}

void FileOperation::MakeFilePublic()
{
    string RootPath = path + fileName;
    ifstream test(path + fileName);
    if (!test)
    {
        std::cout << "The file doesn't exist" << std::endl;
    }
    else
    {
        test.close();
        FileMangement f1;
        string command = "move " + RootPath + " " + f1.getRootFolderAdress();
        system(command.c_str());
        cout << "Root Path is : " << RootPath << endl;
    }
}

void FileOperation::CopyFileToPublic()
{
    string RootPath = path + fileName;
    ifstream test(path + fileName);
    if (!test)
    {
        std::cout << "The file doesn't exist" << std::endl;
    }
    else
    {
        test.close();
        FileMangement f1;
        string command = "copy " + RootPath + " " + f1.getRootFolderAdress();
        system(command.c_str());
    }
}

void FileOperation::RenameFile(string name)
{
    string RootPath = path + fileName;
    ifstream test(path + fileName);
    if (!test)
    {
        std::cout << "The file doesn't exist" << std::endl;
    }
    else
    {
        test.close();
        FileMangement f1;
        string NewName = path + name;
        if (rename(RootPath.c_str(), NewName.c_str()) != 0)
        {
            cout << "There was a error in renaming file" << endl;
        }
        else
        {
            cout << "File have been renamed successfully" << endl;
        }
    }
}