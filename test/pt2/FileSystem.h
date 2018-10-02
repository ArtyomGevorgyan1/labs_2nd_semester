#pragma once

#include "File.h"


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

ostream& operator<<(ostream& os, const vector<File*>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

