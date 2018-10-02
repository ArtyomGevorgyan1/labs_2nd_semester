#include <bits/stdc++.h>
using namespace std;

class Time {
    int day;
    int month;
    int year;
    pair <int, int> time = make_pair(0, 0);
    static Time defaultTime;
    bool validateSring(string test) {
        if (test.find(":") != std::string::npos) {
            size_t pos = test.find(":");
            string s1 = test.substr(0, pos);
            string s2 = test.substr(pos + 1, std::string::npos - pos - 1);
            bool good = true;
            for (int i = 0; i < (int)s1.size(); i++) {
                if (i > 1 || s1[i] < '0' || s1[i] > '9') good = false;
            }
            if (!good) return false;
            for (int i = 0; i < (int)s2.size(); i++) {
                if (i > 1 || s2[i] > '9' || s2[i] < '0') good = false;
            }
            if (!good) return false;
            return true;
        }
    }
public:
    Time() {}
    Time(pair<int, int> time = defaultTime.time, int day = defaultTime.day, int month = defaultTime.month,
            int year = defaultTime.year) {
        this->time.first = time.first;
        this->time.second = time.second;
        this->day = day;
        this->month = month;
        this->year = year;
    }
    Time(string time, int day = defaultTime.day, int month = defaultTime.month, int year = defaultTime.year) {
        if (!validateSring(time)) {
            cerr << "Bad data\n";
        }
        int pos = time.find(":");
        int first = stoi(time.substr(0, pos));
        int second = stoi(time.substr(pos + 1, std::string::npos));
        this->time.first = first;
        this->time.second = second;
        this->day = day;
        this->month = month;
        this->year = year;
    }
    ~Time() {}
};

// default time static object
Time Time::defaultTime{make_pair(0, 0), 0, 0, 0};

class File {
    size_t sz;
    string name;
    string type;
    Time created;
    Time modified;
public:
    File() {

    }
};

int main() {
    return 0;
}
