#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
# include <assert.h>
#include "io.h"
#include "cstr.h"



using namespace seneca;
using namespace std;

namespace seneca {
    PhoneRec phone;

    void read(char* name)
    {
        cout << "name>\n ";
        cin >> name;
        return;
    }

    void print(long long ph_num) {
        int area, middle, end;
        end = ph_num % 10000;
        ph_num /= 10000;
        middle = ph_num % 1000;
        area = ph_num / 1000;
        std::cout << " (" << std::setw(3) << std::setfill('0') << area
            << ") " << std::setw(3) << std::setfill('0') << middle << "-" << std::setw(3) << std::setfill('0') << end << std::endl;
    }

    void print(const PhoneRec& rec, size_t& row_num, const char* name)
    {
        if (name == nullptr || (strstr(name, rec.first_name) && strstr(name, rec.last_name)))
        {
            std::cout << "RowNumber: " << rec.first_name << " " << rec.last_name << " "; 
            print(rec.phone_number);
            row_num++;
        }
    }


    bool read(PhoneRec& rec, FILE* readfile)
    {
        while (readfile)
        {
           
            int items = fscanf(readfile, "%14s %14s %17lld",
                &rec.first_name,
                &rec.last_name,
                &rec.phone_number);
                assert(items == 2);
                if (items == 3)
                {
                    return true;
                }
                else {
                    return false;
                }
            
        }
    }

    void print(PhoneRec* rec[], int arrSize, const char* filter)
    {
        size_t row_num = 1;

        for (size_t i = 0; i < arrSize; i++)
        {
            if (rec[i] == nullptr) {
                return;
            }
            else {
                print(*rec[i], row_num, filter);
            }
        }
    }

    void setPointers(PhoneRec* arr[], PhoneRec recs[], int arrSize)
    {
        size_t i = 1;
        for (size_t i = 0; i < arrSize; i++)
        {
            arr[i] = &recs[i];
        }
    }

    void sort(PhoneRec* arr[], size_t arrSize, bool sortCriteria)
    {
        bool swap = false;
        for (size_t i = 0; i < arrSize; i++)
        {
            for (size_t j = 0; j < arrSize; j++)
            {
                if (sortCriteria)
                {
                    if (strcmp(arr[i]->last_name, arr[j]->last_name) > 0)
                    {
                        swap = true;
                    }
                }

                else {
                    if (strcmp(arr[i]->first_name, arr[j]->last_name) > 0)
                    {
                        swap = true;
                    }
                }
            }
        }


    }
}