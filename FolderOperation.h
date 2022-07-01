#include <iostream>
#include "Folder.h"
using namespace std;

class FolderOperation
{
private:
    string folderName, path;

public:
    FolderOperation(string folderName, string path);
    void MakeFolderPublic();
    void CopyFolderToPublic();
    void RenameFolder(string newName);
};
