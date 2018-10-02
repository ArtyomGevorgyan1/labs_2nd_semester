#include <bits/stdc++.h>
using namespace std;

class Time {
    int day;
    int month;
    int year;
    static int defaultDay;
    static int defaultMonth;
    static int defaultYear;
    pair <int, int> time;
    static pair <int, int> defaultTime;
    bool validateSring(string test) {
        if (test.find(":") != std::string::npos) {
            size_t pos = test.find(":");
            string s1 = test.substr(0, pos);
            string s2 = test.substr(pos + 1, std::string::npos - pos - 1);
            bool good = true;
            for (int i = 0; i < s1.size(); i++) {
                if (i > 1 || s1[i] < '0' || s1[i] > '9') good = false;
            }
            if (!good) return false;
            for (int i = 0; i < s2.size(); i++) {
                if (i > 1 || s2[i] > '9' || s2[i] < '0') good = false;
            }
            if (!good) return false;
            return true;
        }
    }
public:
    Time() {}
    Time(pair<int, int> time, int day, int month, int year) {
        this->time.first = time.first;
        this->time.second = time.second;
        this->day = day;
        this->month = month;
        this->year = year;
    }
    ~Time() {}
    void setDefaultTime(pair <int, int> time, int day, int month, int year) {
        defaultTime.first = time.first;
        defaultTime.second = time.second;
        defaultDay = day;
        defaultMonth = month;
        defaultYear = year;
    }
};

int main() {
    Time t;
    t.test("22:22");
    return 0;
}
