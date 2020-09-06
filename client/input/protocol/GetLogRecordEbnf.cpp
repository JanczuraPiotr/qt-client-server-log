//
// Created by piotr@janczura.pl on 2020.09.01
//

#include "GetLogRecordEbnf.hpp"
#include <QDebug>

namespace cl::in {

GetLogRecordEbnf::GetLogRecordEbnf(cm::NetInput &&input)
    : input_(input)
{

}


bool GetLogRecordEbnf::parse()
{
    Request parsed;
    request_parser<std::string::iterator> parser;
    std::string str = input_.toStdString();
    auto begin = str.begin();
    auto end = str.end();

    if(!boost::spirit::qi::parse(begin, end, parser, parsed)){
        return false;
    } else {
        logRec_ = rec::Log::create(
                std::stoul(parsed.record.id)
                , QDateTime::fromString(parsed.record.date.c_str(), cm::DATE_TIME_TEMPLATE.c_str())
                , static_cast<cm::LogPriority>(std::stoi(parsed.record.priority))
                , parsed.record.message.c_str()
                );
        return true;
    }
}

rec::Log::ptr GetLogRecordEbnf::record()
{
    return logRec_;
}


}