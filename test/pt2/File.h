#pragma once
#include "Time.h"

class File {
    size_t sz;
    string name;
    string type;
    string from;
    Time created;
    Time modified;
    static File defaultFile;
public:
    File() {}
    File(int sz, string name, string type, Time created, Time modified, string from) {
        // define < for Time and throw exceptions when Time created > Time modified, later
        this->sz = sz;
        this->name = name;
        this->type = type;
        this->created = created;
        this->modified = modified;
        this->from = name;
    }
    size_t getSize() const {
        return sz;
    }
    string getName() const {
        return name;
    }
    string getType() const {
        return type;
    }
    string getParentFolder() const {
        return from;
    }
    Time getCreatedDate() const {
        return created;
    }
    Time getModifiedDate() const {
        return modified;
    }
    ~File() {}
};

ostream& operator<<(ostream& os, const File* v)
{
    os << v->getName() << ' ';
    os << v->getType() << ' ';
    os << v->getSize() << ' ';
    os << v->getParentFolder() << ' ';
    os << v->getCreatedDate() << ' ';
    os << v->getModifiedDate() << ' ';
    return os;
}
