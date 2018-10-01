#include <iostream>

using namespace std;

class FileSystem {
public:

};

class File {
public:
    void showInfo() const;
private:
    string name;
    size_t sz;
    Date appeared;
    Date modified;
};

class Date {
public:
    void showInfo() const ();
private:
    int month;
    int year;
    int day;
    Time time;
};

class Time {
public:
    static pair <int, int> currentTime;
    Time() {
        hours = currentTime.first;
        minutes = currentTime.second;
    }
    ~Time();
    pair<int, int> showInfo() const {
        return make_pair(hours, minutes);
    }
    void setInfo(pair<int, int> info) {
        hours = info.first;
        minutes = info.second;
    }
private:
    int hours;
    int minutes;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
