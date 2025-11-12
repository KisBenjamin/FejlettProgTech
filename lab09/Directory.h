//
// Created by beni on 11/12/2025.
//

#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <string.h>
#include <iostream>

#include "FileSystemItem.h"
using namespace std;

class Directory : public FileSystemItem
{
private:
    vector<FileSystemItem*> children;

    void clearChildren()
    {
        for (FileSystemItem* item : children)
        {
            delete item;
        }
        children.clear();
    }

    void copyChildren(const vector<FileSystemItem*>& otherChildren)
    {
        for (const FileSystemItem* item : otherChildren)
        {
            children.push_back(item->clone());
        }
    }

public:
    Directory(const string& name) : FileSystemItem(name){}

    virtual ~Directory()
    {
        clearChildren();
    }

    void add(FileSystemItem* item)
    {
        children.push_back(item);
    }

    
};

#endif //DIRECTORY_H
