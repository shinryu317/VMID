#pragma once
#include <plog/Record.h>
#include <plog/Util.h>
#include <iomanip>

namespace plog
{
    class TxtFormatter
    {
    public:
        static util::nstring header()
        {
            return util::nstring();
        }

        static util::nstring format(const Record& record)
        {
            tm t;
            util::localtime_s(&t, &record.getTime().time);

            util::nstringstream ss;
            ss << "[" << t.tm_year + 1900 << "-"
               << std::setfill(PLOG_NSTR('0')) << std::setw(2) << t.tm_mon + 1             << PLOG_NSTR("-")
               << std::setfill(PLOG_NSTR('0')) << std::setw(2) << t.tm_mday                << PLOG_NSTR(" ")
               << std::setfill(PLOG_NSTR('0')) << std::setw(2) << t.tm_hour                << PLOG_NSTR(":")
               << std::setfill(PLOG_NSTR('0')) << std::setw(2) << t.tm_min                 << PLOG_NSTR(":")
               << std::setfill(PLOG_NSTR('0')) << std::setw(2) << t.tm_sec                 << PLOG_NSTR(".")
               << std::setfill(PLOG_NSTR('0')) << std::setw(3) << record.getTime().millitm << PLOG_NSTR(" ")
               << std::setfill(PLOG_NSTR(' ')) << severityToString(record.getSeverity()) << "] ";
            ss << record.getMessage() << PLOG_NSTR("\n");

            return ss.str();
        }
    };
}