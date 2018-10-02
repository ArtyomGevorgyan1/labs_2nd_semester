#include <bits/stdc++.h>
using namespace std;
// same static member acesible from any object of this class?
class Time {
    static pair <int, int> defaultTime;
    pair <int, int> currentTime;
    bool validate(pair<int, int> initializeData){
        if (initializeData.first > 23 || initializeData.second < 0) {
            return false;
        }
        if (initializeData.second > 59 || initializeData.second < 0) {
            return false;
        }
        return true;
    }

    bool validateString(string time) {
        // {hh, mm}
        if (find(time.begin(), time.end(), ":") != time.end()) {
            string s1 = time.substr(0, time.find(":"));
            string s2 = time.substr(time.rfind(":"), time.size() - 1);
            if (s1.size() <= 2 && s2.size() <= 2) {
                for (int i = 0; i < (int) s1.size(); i++) {
                    if (s1[i] <= '9' && s1[i] >= '9') {;}
                    else {
                        return false;
                    }

                }
                for (int i = 0; i < (int)s1.size(); i++) {
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
        currentTime.first = time.first;
        currentTime.second = time.second;
    }
    // must be of the form
    Time(string time) {
        if (validateString(time)) {
            currentTime.first = stoi(time.substr(0, time.find(":")));
            currentTime.second = stoi(time.substr(time.rfind(":"), time.size() - 1));
        } else {
            // throw error
        }
    }
    Time() {}
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
        bool Time::operator==(Time a) {
        return a.currentTime.first == this.currentTime.first && a.currentTime.second == this.currentTime.second;
    }
};

class File {
public:
    Time* created;
    Time* modified;
    string name;
    string type;
    size_t sz;
public:
    File() {
        sz = 0;
        name = "";
        created = new Time("00:00");
        modified = new Time("00:00");
        type = ".dat";
    }
    File (Time created, Time modified, size_t sz, string name, string type) {
        this->created = created;
        this->modified = modified;
        this->name = name;
        this->sz = sz;
        this->type = type;
    }
    File (Time created, Time modified, size_t sz, string name) {
        if (name.find(".") == -1) {
            // throw wxceptionss
        }
        this->created = created;
        this->modified = modified;
        this->name = name.substr(0, name.find("."));
        this->sz = sz;
        this->type = name.substr(name.rfind("."), name.size() - 1);
    }
    ~File () {}
};

// todo: 16 possibilities for search but it is too much code by using class Filter


class FileSystem {
    vector <File*> contains;
public:
    //vector <File*> search(Filter Params);
    void addPointer(File* item) {
        contains.push_back(item);
    }
    void removePointer(File* item) {
        for (int i = 0; i < contains.size(); i++) {
            if (contains[i] == item) {
               contains.erase(contains.begin(), contains.begin() + i);
               break;
            }
        }
    }
    vector <File*> searchByName(string match) const {
        vector <File*> result;
        for(int i = 0; i < contains.size(); i++) {
            if (contains[i] -> name == match) {
                result.push_back(contains[i]);
            }
        }
        return result;
    };
    vector <File*> searchByType(string match) const {
        vector <File*> result;
        for (int i = 0; i < contains.size(); i++) {
            if (contains[i] -> type == match) {
                result.push_back(contains[i]);
            }
        }
        return result;
    };
    vector <File*> searchBySize(size_t match) const {
        vector <File*> result;
        for (int i = 0; i < contains.size(); i++) {
            if (contains[i] -> sz == match) {
                result.push_back(contains[i]);
            }
        }
        return result;
    };
    vector <File*> searchByCreationDate(Time match) const {
        vector <File*> result;
        for (int i = 0; i < contains.size(); i++) {
                //??
            if (contains[i] -> created == match) {
                result.push_back(contains[i]);
            }
        }
        return result;
    };
    vector <File*> searchByModificationDate(Time match) const {
        vector <File*> result;
        for (int i = 0; i < contains.size(); i++) {
            if (contains[i] -> modified == match) {
                result.push_back(contains[i]);
            }
        }
        return result;
    };
};

