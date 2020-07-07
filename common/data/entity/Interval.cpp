//
// Created by piotr@janczura.pl on 2020.07.07
//

#include "Interval.hpp"

namespace data::entity {

Interval::ptr Interval::create()
{
    return std::shared_ptr<Interval>(new Interval());
}

Interval::Interval()
    : timeFrom_()
    , timeTo_()
{

}

bool Interval::isOk()
{
    // @task określić i przetestować warunki poprawności przedziału
    return timeFrom_.isValid() && timeTo_.isValid();
}

void Interval::timeFrom(const QDateTime &timeFrom)
{
    timeFrom_ = timeFrom;
}

QDateTime Interval::timeFrom() const
{
    return timeFrom_;
}

void Interval::timeTo(const QDateTime &timeTo)
{
    timeTo_ = timeTo;
}

QDateTime Interval::timeTo() const
{
    return timeTo_;
}

}