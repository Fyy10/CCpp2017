#ifndef SAFE_ARRAY_H

#define SAFE_ARRAY_H

const int NORMAL_SIZE = 100;

enum Status
{
    SUCCESS,
    FAIL
};

class SafeArray
{
    public:
        SafeArray(int n = NORMAL_SIZE);
        SafeArray(SafeArray&);
        ~SafeArray();

        int get(int);
        Status insert(int, int);
        Status opp();
    private:
        int *arr;
        int size;
};

#endif
