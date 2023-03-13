#ifndef MONITOR_H
#define MONITOR_H
#include <subject.h>
#include <data_file.h>
#include <file_observer.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <sys/stat.h>
struct File {
    bool operator!=( const File& other )
    {
        if( this == &other )
        {
            return false;
        }
        return exists != other.exists || size != other.size;
    }
    bool exists;
    size_t size;
};
class Monitor:public Subject< File_observer>
{
public:
    Monitor(const char* fileName);                    //На вход принимает имя файла fileName, состояние которого он должен отслеживать
    void checkFile();                                 //
private:
    File Check_file( const std::string& fileName );   //Класс посылает наблюдателям сообщения о произошедших с файлом изменениях
    std::string monitor_fileName;
    File prevFile;                                    //Cостояние файла на момент создания объекта класса
};

#endif // MONITOR_H
