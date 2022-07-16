//
// Created by nimbl on 7/15/2022.
//

#include "MyString.h"

int MyString::str_length(const MyString &str) {
    int i = 0;

    while(str.content[i] != '\0') {
        i++;
    }

    return i;
}

MyString::MyString(const char* _content) {
    content = (char*) _content;
}

int MyString::length() const {
    int i = 0;

    while(content[i] != '\0') {
        i++;
    }

    return i;
}

MyString MyString::operator+(const MyString& toAdd) const {
    char* combined = (char*) calloc(toAdd.length() + length(), 2);

    int i = 0;
    while(content[i] != '\0') {
        memcpy(&combined[i], &content[i],2);
        i++;
    }

    int newI = 0;
    while(toAdd.content[newI] != '\0') {
        memcpy(&combined[i], &toAdd.content[newI],2);
        i++;
        newI++;
    }

    return MyString(combined);
}

char* MyString::toString() const {
    return content;
}

void MyString::append(const MyString& toAppend) {
    const char* appendContent = toAppend.toString();

    char* combined = (char*) calloc(toAppend.length() + length(), 2);
    int i = 0;
    while(content[i] != '\0') {
        memcpy(&combined[i], &content[i],2);
        i++;
    }

    int newI = 0;
    while(toAppend.content[newI] != '\0') {
        memcpy(&combined[i], &toAppend.content[newI],2);
        i++;
        newI++;
    }

    this->content = combined;
}
