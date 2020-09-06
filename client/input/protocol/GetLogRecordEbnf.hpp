//
// Created by piotr@janczura.pl on 2020.09.01
//

#ifndef CLIENT_INPUT_GETLOGRECORDEBNF
#define CLIENT_INPUT_GETLOGRECORDEBNF

#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include <QDateTime>

#include "common/def.h"
#include "common/data/entity/Log.hpp"
#include "common/data/record/Log.hpp"


namespace cl::in {

using namespace std::literals::string_literals;
namespace ent = data::entity;
namespace rec = data::record;


class GetLogRecordEbnf {
public:
    explicit GetLogRecordEbnf(cm::NetInput &&input);
    virtual ~GetLogRecordEbnf() = default;

    bool parse();
    rec::Log::ptr record();

private: //attributes
    cm::NetInput input_;
    rec::Log::ptr logRec_;

public: // lock
    GetLogRecordEbnf(const GetLogRecordEbnf &) = delete;
    GetLogRecordEbnf(GetLogRecordEbnf &&) = delete;
    GetLogRecordEbnf &operator=(const GetLogRecordEbnf &) = delete;
    GetLogRecordEbnf &operator=(GetLogRecordEbnf &&) = delete;

};

// parser

struct Request {
    struct Command {
        std::string name;
        std::string id;
    };
    Command command;
    struct Record {
        std::string id;
        std::string message;
        std::string priority;
        std::string date;
    };
    Record record;
};
}

BOOST_FUSION_ADAPT_STRUCT(cl::in::Request::Command, name, id)
BOOST_FUSION_ADAPT_STRUCT(cl::in::Request::Record, id, message, priority, date)
BOOST_FUSION_ADAPT_STRUCT(cl::in::Request, command, record)

namespace cl::in {

template <typename Iterator>
struct request_parser : boost::spirit::qi::grammar<Iterator, Request()>
{
    request_parser() : request_parser::base_type(start)
    {
        using namespace boost::spirit::qi;

        delim_  = &lit('}') | ',';
        string_ = '"' >> *~char_('"') >> '"';
        //key_    = '"' >> string(_r1) >> '"';
        prop_   = string_ >> delim_;
        //prop_   = key_(_r1) >> ':' >> string_ >> delim_;

        command_ = '{' >> (prop_("command_name"s) ^ prop_("command_id"s));
        record_ = (prop_("record_id"s) ^ prop_("record_message"s) ^ prop_("record_priority"s) ^ prop_("record_date"s)) >> '}';


        request_ = (command_ ^ record_);
        start    = skip(space) [ request_ ];
    }

private:
    using Skipper = boost::spirit::qi::space_type;
    boost::spirit::qi::rule<Iterator, Request()> start;
    boost::spirit::qi::rule<Iterator, Request(), Skipper> request_;
    boost::spirit::qi::rule<Iterator, Request::Command(), Skipper> command_;
    boost::spirit::qi::rule<Iterator, Request::Record(), Skipper> record_;
    boost::spirit::qi::rule<Iterator, std::string(std::string), Skipper> prop_;

    // lexemes
    boost::spirit::qi::rule<Iterator, std::string()> string_;
    // literals
    //boost::spirit::qi::rule<Iterator, void(std::string)> key_;
    boost::spirit::qi::rule<Iterator> delim_;
};

}

#endif
