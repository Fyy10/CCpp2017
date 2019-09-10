#include "iostream"

using namespace std;

class Location
{
    private:
        int X, Y;
    public:
        void init(int initX, int initY)
        {
            X = initX;
            Y = initY;
        }
        int GetX()
        {
            return X;
        }
        int GetY()
        {
            return Y;
        }
};

int main()
{
    Location AI;
    AI.init(20, 90);
    Location &rAI = AI;
    cout << rAI.GetX()  << rAI.GetY();
    return 0;
}
