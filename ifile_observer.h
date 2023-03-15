#ifndef IFILE_OBSERVER_H
#define IFILE_OBSERVER_H
#include <file.h>



class IFile_observer
{
public:
 virtual ~IFile_observer(){}
 virtual void onFileChanged(const File& state ) = 0;     //Функция извещающая об изменеии файла на вход получает объект файла
 virtual  void File_Info(const File& state) = 0;         //Функция показывающая информацию файла
 virtual void File_not_exist() = 0;                      //Функция извещающая об отсутствии файла
};


#endif // IFILE_OBSERVER_H
