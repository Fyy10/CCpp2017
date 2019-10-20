#include "iostream"

using namespace std;

class Date
{
    private:
        int year;
        int month;
        int day;
        bool ry(int y)
        {
            return (y % 4) == 0 && (y % 400);
        }
    public:
        Date(int y = 1996, int m = 1, int d = 1)
        {
            day = d;
            month = m;
            year = y;
            if (m >= 12 || m < 1)
            {
                month = 1;
            }
            if (d > days(y, m) || d < 1)
            {
                cout << "Invalid day!\n";
                day = 1;
            }
        }
        int days(int, int);
        void display()
        {
            cout << year << "-" << month << "-" << day << endl;
        }
        friend ostream & operator << (ostream& out, Date& din);
};

int Date::days(int y, int m)
{
    int rys[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int nys[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (ry(y))
    {
        return rys[m];
    }
    else
    {
        return nys[m];
    }
}

ostream & operator << (ostream& out, Date& din)
{
    std::cout << din.year << "-" << din.month << "-" << din.day << std::endl;
    return out;
}

int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    Date dt(y, m, d);
    //dt.display();
    cout << dt;
    return 0;
}
