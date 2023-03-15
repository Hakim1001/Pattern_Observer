#ifndef SUBJECT_H
#define SUBJECT_H
//#include "iostream"
#include <set>
#include <vector>
#include <QDebug>
template< class Observer >
class Subject
{
public:
    virtual ~Subject(){};
    void registerObserver( Observer* observer )
    {
        if( m_count != 0 ) {
            m_requests.push_back( ObserverRequest { &Subject< Observer >::registerObserver, observer } );   // Запоминаем запрос на добавление Наблюдателя
        } else if( observer ) {
            m_observers.insert( observer );                                                                 //Добавляем наблюдателя
        }
    }
    void unregisterObserver( Observer* observer )
    {
        if( m_count != 0 ) {
            m_requests.push_back( ObserverRequest { &Subject< Observer >::unregisterObserver, observer } );  // Запоминаем запрос на удаление Наблюдателя
        } else if( observer ) {
            m_observers.erase( observer );                                                                   //Удаляем наблюдателя
        }
    }
protected:
    Subject(): m_count( 0 ){};
    template< typename F, typename... Args >
    void   notifyObservers( F f, Args... args )                                                            //Шаблонная функция оповещения наблюдателей
    {
        ++m_count;
        for( Observer* o : m_observers )                                                                   //Обход по наблюдателям
        {
            ( o->*f )( args... );
        };
        --m_count;
        if( m_count == 0 )                                                          //Проверка на то что обход по наблюдателям закончен
        {
            for( const ObserverRequest& r : m_requests )                            //Обход по  запросам наблюдателей тех что могли поступить
            {
                ( this->*r.operation )( r.observer );
            };
            m_requests.clear();
        }
    }
private:
    struct ObserverRequest
    {
        void ( Subject< Observer >::*operation )( Observer* );  //Функция запоминает запрос наблюдателя
        Observer* observer;                                     //Указатель на запросы наблюдателя
    };
        std::set< Observer* > m_observers;                      //Источник хранит указатели на объекты-Наблюдатели в std::set, чтобы предотвратить создание дублирующих связей.
        int m_count;                                            //Счетчик входа в цикл обхода по запросам наблдателся observer
        std::vector< ObserverRequest > m_requests;              //Вектор хранит запросы наблюдателя
};

#endif // OBSERVABLE_H
