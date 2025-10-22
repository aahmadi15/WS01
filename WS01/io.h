#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_H
#define SENECA_H
namespace seneca {
    struct PhoneRec
    {
        /* data */
        char first_name[15];
        char last_name[15];
        long long phone_number;

    };
    void read(char* name);
    void print(long long phone_number);
    void print(const PhoneRec& rec, size_t& row_num, const char* name = nullptr);
    bool read(PhoneRec& rec, FILE* readfile);
    void print(PhoneRec* rec[], int arrSize, const char* filter = nullptr);
    void setPointers(PhoneRec* arr[], PhoneRec recs[], int arrSize);
    void sort(PhoneRec* arr[], size_t arrSize, bool sortCriteria);
}

#endif