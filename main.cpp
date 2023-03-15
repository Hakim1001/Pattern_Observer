#include <iostream>
#include <monitor.h>
#include <file_observer.h>
#include <subject.h>
#include <string>
#include <QDebug>
using namespace std;
int main()
{
    const char* str="t.pdf";
    Monitor monitor( str );                       //создаем объект для отслеживания состояния конкретного файла
    File_observer obs;                            //определяется объект наблюдатель
    monitor.registerObserver( &obs);              //связываем Наблюдателя с Источником
    while( true )
    {
        monitor.checkFile();
        std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );
    }

    return 0;
    //return a.exec();
}
