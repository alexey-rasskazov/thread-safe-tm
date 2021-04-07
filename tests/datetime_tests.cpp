#include "gtest/gtest.h"
#include <datetime.h>
#include <mutex>

static std::mutex time_mutex;

std::tm localtime_mt(std::time_t t)
{
    std::lock_guard<std::mutex> lock(time_mutex);
    std::tm dt = *localtime(&t);
    return dt;
}

std::tm gmtime_mt(std::time_t t)
{
    std::lock_guard<std::mutex> lock(time_mutex);
    std::tm dt = *gmtime(&t);
    return dt;
}

bool operator == (const std::tm& a, const std::tm& b)
{
    return a.tm_sec == b.tm_sec
        && a.tm_min == b.tm_min
        && a.tm_hour == b.tm_hour
        && a.tm_mday == b.tm_mday
        && a.tm_mon == b.tm_mon
        && a.tm_year == b.tm_year
        && a.tm_wday == b.tm_wday
        && a.tm_yday == b.tm_yday
        && a.tm_isdst == b.tm_isdst
    ;
}

TEST(DateTime, local_datetime)
{
    std::tm dt;
    std::time_t t;
    time(&t);

    local_datetime(&dt, t);

    std::tm dt1 = localtime_mt(t);
    
    EXPECT_EQ(dt, dt1);
}

TEST(DateTime, utc_datetime)
{
    std::tm dt;
    std::time_t t;
    time(&t);

    utc_datetime(&dt, t);

    std::tm dt1 = gmtime_mt(t);

    EXPECT_EQ(dt, dt1);
}