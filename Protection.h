#include <iostream>
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
};
