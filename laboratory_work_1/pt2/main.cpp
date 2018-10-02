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
    bool operator == (Time compareTo) {
        return (compareTo.day == this->day &&
                compareTo.month == this->month &&
                compareTo.year == this->year &&
                compareTo.time.first == this->time.first&&
                compareTo.time.second == this->time.second);
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
    static File defaultFile;
public:
    File() {}
    File(int sz, string name, string type, Time created, Time modified) {
        // define < for Time and throw exceptions when Time created > Time modified, later
        this->sz = sz;
        this->name = name;
        this->type = type;
        this->created = created;
        this->modified = modified;
    }
    size_t getSize() {
        return sz;
    }
    string getName() {
        return name;
    }
    string getType() {
        return type;
    }
    Time getCreatedDate() {
        return created;
    }
    Time getModifiedDate() {
        return modified;
    }
    ~File() {}
};

class FileSystem {
    vector <File*> files;
public:
    void addItem(File* file) {
        files.push_back(file);
    }
    void removeItem(File* file) {
        files.erase(std::remove(files.begin(), files.end(), file), files.end());
    }
    vector <File*> searchFiles(bool (*parameters)(File*)) {
        vector <File*> answer;
        for (size_t i = 0; i < files.size(); i++) {
            if (parameters(files[i])) {
                answer.push_back(files[i]);
            }
        }
        return answer;
    }
};

bool parameters(File* file) {
    if (file-> getSize() > 10) {
        return 1;
    }
}

int main() {
    File f;
    return 0;
}
