//
// Created by piotr@janczura.pl on 2020.07.07
//

#ifndef ENTITY_INTERVAL
#define ENTITY_INTERVAL

#include <boost/shared_ptr.hpp>
#include <QtCore/QDateTime>

namespace data::entity {

/// \brief Typ przechowujący przedziały czasowe.
class Interval {
public:
    typedef std::shared_ptr<Interval> ptr;
    static ptr create();

    /// \brief Sprawdza czy podane daty stanowią poprawny przedział czasowy.
    /// @task \todo określić i przetestować warunki poprawności przedziału
    bool isOk();
    /// \brief Nowa wartość pierwszego momentu wchodzącego w przedział czasowy.
    void timeFrom(const QDateTime &timeFrom);
    /// \brief Pierwszy moment przedziału czasu.
    QDateTime timeFrom() const;
    /// \brief Nowa wartość ostatniego momenty wchodzącego w przedział czasowy.
    void timeTo(const QDateTime &timeTo);
    /// \brief Ostatni moment przedziału czasu.
    QDateTime timeTo() const;

private: // attributes
    QDateTime timeFrom_;
    QDateTime timeTo_;

private: // locks
    Interval();
    Interval(Interval&) = delete;
    Interval(Interval&&) = delete;
    Interval &operator = (Interval&) = delete ;
    Interval &&operator = (Interval&&) = delete;
};

}

#endif //QT_CLIENT_SERVER_LOG_INTERVAL_HPP
