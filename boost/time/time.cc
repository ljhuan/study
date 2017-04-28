#include <boost/date_time.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace std;
int main(int argc, char const *argv[]) {
    ptime pt = second_clock::local_time();
    
    string t = to_iso_extended_string(pt);
    int pos = t.find("T");
    t.replace(pos, 1, " ");
    cout << "time:" << pt << endl;
    cout << "extended time:" << t << endl;

    stringstream ss;
    string date, day, hour;

    ptime p = second_clock::local_time();
    ss << p;
    ss >> day;
    ss >> hour;

    day += " ";
    day += hour;
    ptime tmp = time_from_string(day);
    cout << "tmp:" << tmp << endl;
    day = to_iso_extended_string(tmp);
    int pos1 = day.find("T");
	day.replace(pos1, 1, " ");
    std::cout << "day:" << day << endl;

    // ----------------test lexcical_cast-----------
    ptime time = second_clock::local_time();
    cout << "befor lexical_cast time:" << time << endl;
    string aftTime = boost::lexical_cast<string>(time);
    cout << "after lexical_cast time:" << aftTime << endl;

    // ----------------time classify---------------
    hours h(3);
    minutes m(10);
    ptime etime = time + h + m;
    ptime btime(time);
    cout << "----------------time classify---------------" << endl;
    std::cout << "end time:" << etime << std::endl;
    std::cout << "begin time:" << btime << std::endl;

    std::vector<std::string> v;
    for (auto pt = btime; pt < etime; pt += hours(1))
    {
        std::string d1, h1, tmp;
        ss.clear();
        ss.str("");
        ss << pt;
        ss >> d1;
        ss >> h1;

        if (pt == btime)
        {
            std::string tm;
            tm = boost::lexical_cast<std::string>(btime);
            v.push_back(tm);
            continue;
        }
        int pos = h1.find(":");
        std::string h2 = h1.substr(0, pos);
        h2 += ":00:00";
        tmp = d1 + " " + h2;
        v.push_back(tmp);
    }

    for (auto mem : v)
    {
        cout << "mem:" << mem << endl;
    }


    // --------------time format----------
    ptime now = boost::posix_time::second_clock::local_time();
    std::string strTime = boost::lexical_cast<std::string>(now);
    int pos2 = strTime.find(":");
    std::string tmp1 = strTime.substr(0, pos2);
    tmp1 += ":00:00";
    cout << "--------------time format----------" << endl;
    cout << tmp1 << endl;

    // ------------------------------------
    cout << "===================================" << endl;
    std::string normal_time = "2016-08-31 12:35:00";
    ptime p1 = time_from_string(normal_time);
    cout << "p1: " << p1 << endl;

    ptime nn = boost::posix_time::second_clock::local_time();
    for (int i = 0; i < 12; ++i){
        boost::gregorian::months mm(i);
        std::cout << (nn - mm) << std::endl;
    }

    // ---------------- ptime -> time_t
    tm tm1 = boost::posix_time::to_tm(now);
    time_t tt = mktime(&tm1);
    std::cout << tt << std::endl;
    return 0;
}
