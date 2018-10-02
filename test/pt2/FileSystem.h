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
