#ifndef MONITOR_H
#define MONITOR_H
#include <subject.h>
#include <ifile_observer.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <sys/stat.h>
#include <subject.h>
#include <string>


class Monitor:public Subject<IFile_observer>
{
public:
    Monitor(const char* fileName);                                         //На вход принимает путь файла fileName, состояние которого он должен отслеживать
void checkFile();                                                          //Функция получения состояний источника
private:
static File Check_file( const std::string& fileName );                     //Класс посылает наблюдателям сообщения о произошедших с файлом изменениях
std::string monitor_fileName;
File prevFile;                                                             //Cостояние файла на момент создания объекта класса
};
Monitor::Monitor(const char* fileName):                                    //Установка пути и текущего состояния файла
monitor_fileName( fileName ),prevFile( Check_file( monitor_fileName ) ){}

void Monitor::checkFile()
{

  File tmp_file = Check_file( monitor_fileName );                          //берем обьект файла с путем  monitor_fileName  и проверяем
  if(tmp_file.exists!=0)                                                   //Проверяем файл что он существует
  {
    if( tmp_file != prevFile )                                             //Проверяем на произошедшие изменения
    {
        notifyObservers( &IFile_observer::onFileChanged,tmp_file);         //Уведомляем всех наблюдателей об изменении,передаем функцию обработки изменеиния файла с аргументом обьекта файла
        prevFile =  tmp_file;
    }
    else
    {
    notifyObservers( &IFile_observer::File_Info, tmp_file );               //Уведомляем всех наблюдателей об изменении,передаем функцию обработки состяния файла с аргументом обьекта файла
    }
  }
else
{
    notifyObservers( &IFile_observer::File_not_exist);                     //Уведомляем всех наблюдателей об изменении, функция о том что файл не существует
}
}

File Monitor::Check_file( const std::string& fileName )                    //Фунцкия возвращающая объект типа File, на вход путь файла
{
    File fileState;
    struct stat statBuf;
    fileState.exists = stat( fileName.c_str(), &statBuf ) == 0;            //Проверка на то что файл существует
    fileState.size = fileState.exists ? statBuf.st_size : 0;               //Если файл существует то устанавливаем иначе 0
    return fileState;
}

#endif // MONITOR_H
