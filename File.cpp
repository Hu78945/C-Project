#include <iostream>
#include "Folder.h"
using namespace std;

void File::CreateFile(string name)
{
    this->fileName = name;
    ofstream NewFile(this->getPath() + fileName);
    NewFile.close();
    cout << "File have been created." << endl;
}

void File::WriteFile(string fileName, string fileContent)
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

void File::ReadFile(string fileName)
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

void File::ClearFile(string fileName)
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

void File::RemoveFile(string fileName)
{
    std::ifstream test(path + fileName);
    if (!test)
    {
        std::cout << "The file doesn't exist" << std::endl;
    }
    else
    {
        test.close();
        string file = path + fileName;
        int status = remove(file.c_str());
        if (status == 0)
        {
            cout << "File have been deleted successfull." << endl;
        }
        else
        {
            cout << "Unable to delte the file 2" << endl;
        }
    }
}

void File::setPath(string path)
{
    this->path = path;
}

string File::getPath()
{
    return this->path;
}
