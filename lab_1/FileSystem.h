#pragma once
#include "Folder.h"

ostream& operator<<(ostream& os, const vector<Folder*>& v)
    {
        os <<"[" << endl;
        for (size_t i = 0; i < v.size(); ++i) {
            os << '\t' << v[i];
            if (i != v.size() - 1)
                os << ", ";
        }
        os << "]\n";
        return os;
}

class FileSystem {
    vector <Folder*> folders;
public:
    void addItem(Folder* folder) {
        folders.push_back(folder);
    }
    void removeItem(Folder* folder) {
        folders.erase(std::remove(folders.begin(), folders.end(), folder), folders.end());
    }
    vector <Folder*> searchFiles(bool (*parameters)(Folder*)) {
        vector <Folder*> answer;
        for (size_t i = 0; i < folders.size(); i++) {
            if (parameters(folders[i])) {
                answer.push_back(folders[i]);
            }
        }
        return answer;
    }
    void fillRandom() {
        for (int i = 0; i < rand() % 100; i++) {
            Folder* folder = new Folder();
            folder->fillRandom();
            folders.push_back(folder);
        }
    }
    friend ostream& operator<<(ostream& os, FileSystem FS) //const vector<File*>& v)
    {
        os << "FileSystem object: \n";
        os << FS.folders;
        return os;
    }
};

