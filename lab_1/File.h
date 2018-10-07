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

ostream& operator<<(ostream& os, File v)
{
    os << '\t'<< "File name: ";
    os << '\t'<< v.getName() << '\n';
    os << '\t'<< "File type: ";
    os << '\t' << v.getType() << '\n';
    os << '\t'<<"File size: ";
    os << '\t'<< v.getSize() << '\n';
    os << '\t'<<"Folder: ";
    os <<'\t'<< v.getParentFolder() << '\n';
    os <<'\t'<< "Created: ";
    os <<'\t'<< v.getCreatedDate() << '\n';
    os <<'\t'<< "Modified: ";
    os <<'\t'<<v.getModifiedDate() << '\n';
    return os;
}

ostream& operator<<(ostream& os, const File* v)
{
    os <<'\t'<< "File name: ";
    os <<'\t'<< v->getName() << '\n';
    os <<'\t'<< "File type: ";
    os <<'\t'<< v->getType() << '\n';
    os <<'\t'<< "File size: ";
    os <<'\t'<< v->getSize() << '\n';
    os << '\t'<<"Folder: ";
    os <<'\t'<< v->getParentFolder() << '\n';
    os <<'\t'<< "Created: ";
    os <<'\t'<< v->getCreatedDate() << '\n';
    os <<'\t'<< "Modified: ";
    os <<'\t'<< v->getModifiedDate() << '\n';
    return os;
}
