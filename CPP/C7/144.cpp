#include "iostream"

int main()
{
    using namespace std;
    int n;
    cin >> n;
    if ((n & 1) && n <= 80 && n > 0)
    {
        int i = 0;
        while (n > 0)
        {
            for (int j = 0; j < i; j++) cout << " ";
            for (int j = 0; j < n; j++) cout << "*";
            cout << endl;
            i++;
            n -= 2;
        }
    }
    else
    {
        cout << "error";
    }
    return 0;
}
