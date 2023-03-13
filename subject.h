#ifndef SUBJECT_H
#define SUBJECT_H
#include "iostream"
#include <set>
#include <vector>
template< class Observer >
class Subject
{
public:
    virtual ~Subject(){};
    void registerObserver( Observer* observer );
    void unregisterObserver( Observer* observer );
protected:
    Subject(): m_count( 0 ){};
    template< typename F, typename... Args >
    void notifyObservers( F f, Args... args );
private:
    struct ObserverRequest
    {
        void ( Subject< Observer >::*operation )( Observer* );
        Observer* observer;                                     //Указатель на запросы наблюдателя
    };
        std::set< Observer* > m_observers;                      //Источник хранит указатели на объекты-Наблюдатели в std::set, чтобы предотвратить создание дублирующих связей.
        int m_count;                                            //Счетчик входа в цикл обхода по запросам наблдателся observer
        std::vector< ObserverRequest > m_requests;
};

#endif SUBJECT_H
