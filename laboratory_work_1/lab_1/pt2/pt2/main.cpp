#include <bits/stdc++.h>
using namespace std;

class FileSystem {
    vector <File*> contains;
public:
    vector <File*> search(Filter Params);
};

// same static member acesible from any object of this class?
class Time {
    static pair <int, int> defaultTime;
    pair <int, int> currentTime;
    bool validate(pait<int, int> initializeData) {
        if (initializeData.first > 23 || initializeData.second < 0) {
            return false;
        }
        if (intializeData.second > 59 || initializeData.second < 0) {
            return false;
        }
        return true;
    }

    bool validateString(string time) {
        // {hh, mm}
        if (find(time.begin(), time.end(), ":")) {
            string s1 = time.substr(0, time.find(":"));
            string s1 = time.substr(time.rfind(":"), time.size() - 1);
            if (s1.size() <= 2 && s2.size() <= 2) {
                for (int i = 0; i < s1.size(); i++) {
                    if (s1[i] <= '9' && s1[i] >= '9') {;}
                    else {
                        return false;
                    }

                }
                for (int i = 0; i < s1.size(); s2++) {
                    if (s2[i] <= '9' && s2[i] >= '0') {;}
                    else {
                        return false;
                    }
                }
            }
        } else {
            return false;
        }
    }
public:
    Time(pair <int, int> time) {
        if (!validate(time)) {
            cerr << "Bad initialization\n";
            // throw error
        }
        currentTime.first = initializeData.first;
        currentTime.second = initializeData.second;
    }
    // must be of the form
    Time(string time) {
        if (validateString(time)) {
            currentTime.first = stoi(time.substr(0, time.find(":")));
            currentTime.second = stoi(time.substr(time.rfind(":"), time.size() - 1))
        } else {
            // throw error
        }
    }
    ~Time() {}
    void changeTime (pair<int, int> time) {
        if (!validate(time)) {
            cerr << "Bad data\n";
            return;
        }
        currentTime.first = time.first;
        currentTime.second = time.second;
    }
    void changeDefault(pair<int, int> time) {
        if (!validate(time)) {
            cerr << "Bad data\n";
            return;
        }
        defaultTime.first = time.first;
        defaultTime.second = time.second;
    }
};

class File {
    Time created;
    Time modified;
    string name;
    string
};

int main() {
    return 0;
}