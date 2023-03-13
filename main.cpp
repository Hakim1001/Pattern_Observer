#include <QCoreApplication>
#include <monitor.h>
#include <file_observer.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Monitor monitor( "test.txt" );                //создаем объект для отслеживания состояния конкретного файла
    File_observer obs;                            //определяется объект наблюдатель
    monitor.registerObserver( &obs);              //связываем Наблюдателя с Источником

    while( true )
    {
        monitor.checkFile();
        std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
    }

    return 0;
    return a.exec();
}
