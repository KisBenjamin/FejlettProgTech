//
// Created by beni on 11/12/2025.
//

#ifndef FILE_H
#define FILE_H
#include <string.h>
#include <iostream>

#include "FileSystemItem.h"

using namespace std;

class File : public FileSystemItem
{
private:
    long size;
public:
    File(const string& name,long size)
        : FileSystemItem(name),size(size){}

    virtual long getSize() const override
    {
        return size;
    }

    virtual void display(int depth =0) const override
    {
        cout << string(depth * 2, ' ') << name << " (" << size << ")" << endl;
    }

    virtual FileSystemItem* clone() const override
    {
        return new File(*this);
    }
};
#endif //FILE_H
