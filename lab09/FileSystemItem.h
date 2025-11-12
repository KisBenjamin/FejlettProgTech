//
// Created by beni on 11/12/2025.
//

#ifndef FILESYSTEMITEM_H
#define FILESYSTEMITEM_H

#include <string.h>
#include <iostream>

using namespace std;
class FileSystemItem
{
protected:
    string name;

public:
    FileSystemItem(const string& name): name(name) {}
    virtual ~FileSystemItem() {}

    string getName() const { return name;}

    virtual long getSize() const =0;
    virtual long display(int depth=0) const=0;
    virtual FileSystemItem* clone() const =0;

    bool operator<(const FileSystemItem& other) const
    {
        return this->name < other.name;
    }

    friend ostream& operator<<(ostream& os, const FileSystemItem& item)
    {
        item.display(0);
        return  os;
    }
};

#endif //FILESYSTEMITEM_H
