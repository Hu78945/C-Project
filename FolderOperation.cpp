#include "iostream"
#include "Folder.h"
using namespace std;

FolderOperation::FolderOperation(string folderName, string path)
{
    this->folderName = folderName;
    this->path = path;
}

void FolderOperation::MakeFolderPublic()
{
    string RootPath = path + folderName;
    if (Folder::IsPathExist(RootPath) == 0)
    {
        FileMangement f1;
        string command = "Xcopy /E /I   " + RootPath + " " + f1.getRootFolderAdress();
        system(command.c_str());
    }
    else
    {
        cout << "Folder Does not exist" << endl;
    }
}

void FolderOperation::RenameFolder(string newName)
{
    string RootPath = path + folderName;
    string NewPath = path + newName;
    if (Folder::IsPathExist(RootPath) == 0)
    {
        if (rename(RootPath.c_str(), NewPath.c_str()) != 0)
        {
            cout << "There was a error in rnaimg the folder" << endl;
        }
        else
        {
            cout << "Folder is remaned successfully" << endl;
        }
    }
}
