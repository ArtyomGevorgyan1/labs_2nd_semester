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
    void fillRandom() {
        sz = rand()%1000 * 8;
        created.fillRandom();
        modified.fillRandom();
        string name1 = "", type1 = "", from1 = "";
        for (int i = 0; i < rand() % 10; i++) {
            name1 += (char) (rand() % 26 + 97);
        }
        for (int i = 0; i < rand() % 10; i++) {
            type1 += (char) (rand() % 26 + 97);
        }
        for (int i = 0; i < rand() % 10; i++) {
            from1 += (char) (rand() % 26 + 97);
        }
        name = name1;
        type = type1;
        from = from1;
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
