#ifndef FILE_OBSERVER_H
#define FILE_OBSERVER_H
#include <data_file.h>
#include <monitor.h>
class IFile_observer
{
public:
 virtual ~IFile_observer(){}
 virtual void onFileChanged( const File& state ) = 0;     //функция-обработчик изменений
};


class File_observer:public IFile_observer
{
public:
   ~File_observer()override{};
    void onFileChanged( const File& state ) override;
};
#endif // FILE_OBSERVER_H
