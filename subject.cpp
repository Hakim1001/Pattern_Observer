#include "subject.h"
template <class Observer>
template< typename F, typename... Args >
void   Subject<Observer>::notifyObservers( F f, Args... args )
{
    ++m_count;
    for( Observer* o : m_observers ) {
        ( o->*f )( args... );
    };
    --m_count;
    if( m_count == 0 ) {
        for( const ObserverRequest& r : m_requests ) {
            ( this->*r.operation )( r.observer );
        };
        m_requests.clear();
    }
}
template <class Observer>
void Subject<Observer>::registerObserver( Observer* observer ) {
    if( m_count != 0 ) {
        m_requests.push_back( ObserverRequest { &Subject< Observer >::registerObserver, observer } ); // Запоминаем запрос на добавление Наблюдателя
    } else if( observer ) {
        m_observers.insert( observer );                                                              //Добавляем наблюдателя
    }
}
template <class Observer>
void Subject<Observer>::unregisterObserver( Observer* observer ) {
    if( m_count != 0 ) {
        m_requests.push_back( ObserverRequest { &Subject< Observer >::unregisterObserver, observer } );// Запоминаем запрос на удаление Наблюдателя
    } else if( observer ) {
        m_observers.erase( observer );                                                                 //Удаляем наблюдателя
    }
}
