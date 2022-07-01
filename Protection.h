#include <iostream>
#include "Folder.h"
using namespace std;
class Protection
{
private:
    /* data */
    string folderName;
    bool lock;

public:
    Protection(string folderName)
    {
        this->folderName = folderName;
    }
    void HideFolder()
    {
        string command = "attrib +h +s " + folderName;
        system(command.c_str());
    }
    void UnHideFolder(string folderName)
    {
        string command = "attrib +h +s " + folderName;
        system(command.c_str());
    }
    void MakeFilePublic(string fileName, string path)
    {
        string RootPath = path + fileName;
        std::ifstream test(path + fileName);
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
};
