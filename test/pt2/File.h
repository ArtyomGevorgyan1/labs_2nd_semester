#pragma once
#include "Time.h"

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
