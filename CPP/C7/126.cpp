#include "iostream"

int main()
{
    using namespace std;
    int n;
    cin >> n;
    if (n > 12)
    {
        n = 12;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    cout << n << "!=" << ans;
    return 0;
}
