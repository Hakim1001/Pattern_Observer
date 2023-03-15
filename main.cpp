#include <iostream>
#include <monitor.h>
#include <file_observer.h>
#include <subject.h>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QDebug>
using namespace std;
int main()
{



    const char* str="Observe_example.txt";        //#2 пример файл существует
    QFile file(str);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << "something" ;
    }
    Monitor monitor( str );                       //создаем объект для отслеживания состояния конкретного файла
    File_observer obs;                            //определяется объект наблюдатель
    monitor.registerObserver( &obs);              //связываем Наблюдателя с Источником
    while( true )
    {
        monitor.checkFile();                                               //Проверяем на измение файла наблюдателя
        std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );  //Обновлять состояние объекта Источника каждые 2000 миллисекунд
    }

    return 0;
    //return a.exec();
}
