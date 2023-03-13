#ifndef DATA_FILE_H
#define DATA_FILE_H
#include <file_observer.h>
#include <QDebug>
class Data_File:IFile_observer
{
public:
    Data_File();
   virtual void FileChanged();
private:
    int file_size;
    bool exist;
};

#endif // DATA_FILE_H
