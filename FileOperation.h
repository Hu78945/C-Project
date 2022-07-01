#include <iostream>
#include "Folder.h"

class FileOperation
{
private:
    string fileName, path;

public:
    FileOperation(string fileName, string path);
    void MakeFilePublic();
    void CopyFileToPublic();
    void RenameFile(string name);
};
