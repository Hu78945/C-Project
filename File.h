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
    File() : FileMangement(){};
    void CreateFile(string name)
    {
        this->fileName = name;
        ofstream NewFile(path + fileName);
        NewFile.close();
        cout << "File have been created." << endl;
    }
    void WriteFile(string fileName, string fileContent)
    {

        fstream File;
        File.open(path + fileName, ios::app);
        if (File.is_open())
        {
            File << fileContent;
            File.close();
            cout << "Data have been written to the file successfully." << endl;
        }
        else
        {
            cout << "File Do not exist" << endl;
        }
    }
    void ReadFile(string fileName)
    {
        fstream MyFile;
        MyFile.open(path + fileName, ios::in);
        if (MyFile.is_open())
        {
            string line;
            while (getline(MyFile, line))
            {
                cout << line << endl;
            }
            MyFile.close();
        }
        else
        {
            cout << "File Doese Not Exist" << endl;
        }
    }
    void ClearFile(string fileName)
    {
        fstream file;
        file.open(path + fileName, ios::out);
        if (file.is_open())
        {
            file.clear();
            file.close();
            cout << "File data have been cleared." << endl;
        }
        else
        {
            cout << "File dose not exists" << endl;
        }
    }
    void RemoveFile(string fileName)
    {
        string file = path + fileName;
        remove(file.c_str());
        cout << "File have been deleted successfull." << endl;
    }
};
