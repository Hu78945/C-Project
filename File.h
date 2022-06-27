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
        ofstream NewFile(this->getPath() + fileName);
        NewFile.close();
        cout << "File have been created." << endl;
    }
    void WriteFile(string fileName, string fileContent)
    {
        std::ifstream test(path + fileName);
        if (!test)
        {
            std::cout << "The file doesn't exist" << std::endl;
        }
        else
        {

            fstream File;
            File.open(path + fileName, ios::app);
            if (File.is_open())
            {
                File << fileContent;
                File.close();
                cout << "Data have been written to the file successfully." << endl;
            }
        }
    }
    void ReadFile(string fileName)
    {
        fstream MyFile;
        std::ifstream test(path + fileName);
        if (!test)
        {
            std::cout << "The file  doesn't exist" << std::endl;
        }
        else
        {
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
        }
    }
    void ClearFile(string fileName)
    {
        std::ifstream test(path + fileName);
        if (!test)
        {
            std::cout << "The file doesn't exist" << std::endl;
        }
        else
        {
            fstream file;
            file.open(path + fileName, ios::out);
            if (file.is_open())
            {
                file.clear();
                file.close();
                cout << "File data have been cleared." << endl;
            }
        }
    }
    void RemoveFile(string fileName)
    {
        std::ifstream test(path + fileName);
        if (!test)
        {
            std::cout << "The file doesn't exist" << std::endl;
        }
        else
        {
            string file = path + fileName;
            int status = remove(file.c_str());
            cout << file << endl;
            if (status == 0)
            {
                cout << "File have been deleted successfull." << endl;
            }
            else
            {
                cout << "Unable to delte the file" << endl;
            }
        }
    }
    // setter functions
    void setPath(string path)
    {
        this->path = path;
    }
    string getPath()
    {
        return this->path;
    }
};
