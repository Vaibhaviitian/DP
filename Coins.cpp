// JAI MAHAKALLLLLLLLLLLLLLL
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define dbg(x) cout << #x << " = " << x << "\n"
#define vi vector<int>
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
// ASCII values
// A=65, Z=90, a=97, z=122
// is a substring present on main string or not and X is repetition
// bool checking_substring = in.find(string(X, '1')) != string::npos;
// {for knowing MSB 32 -  __builtin_clz(n)}
// {for knowing set bits  -  __builtin_popcount(n) and __builtin_popcountll(n)}

// Function for modular exponentiation
long long mod_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod; // Handle base larger than mod
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
template <typename T>
void help(const vector<T> &vec)
{
    cout << "help is executed" << endl;
    for (const auto &i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
}
// Function to print 2D vector
template <typename T>
void helptwo(const vector<vector<T>> &vec)
{
    cout << "2D help is executed:" << endl;
    for (const auto &row : vec)
    {
        for (const auto &i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
// Function to print a map
template <typename K, typename V>
void helpmap(const map<K, V> &mp)
{
    cout << "map help is executed:" << endl;
    for (const auto &i : mp)
    {
        cout << i.first << " -> " << i.second << endl;
    }
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int mod(int a) { return a < 0 ? -a : a; }

int prefix_sum(int a, int n)
{
    return (n * (2 * a + (n - 1))) / 2;
}
int coordinate_distance(int x1, int x2, int y1, int y2)
{
    int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return dist;
}
const int N = 10000005;
vector<bool> sievearray(N, true);
vector<int> primes;
void sieve()
{
    sievearray[0] = sievearray[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (sievearray[i])
        {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i)
            {
                sievearray[j] = false;
            }
        }
    }
}
vector<int> factorial(N);
void fact()
{
    factorial[0] = 1;
    for (int i = 1; i < N; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}
int nCr(int n, int r)
{
    if (r > n)
    {
        return 0;
    }
    int ans = factorial[n];
    ans = (ans * mod_exp(factorial[r], MOD - 2, MOD)) % MOD;
    ans = (ans * mod_exp(factorial[n - r], MOD - 2, MOD)) % MOD;
    return ans;
}
void coderaryan()
{
    // executing code from here
    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long double> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        vector<vector<long double>> dp(n + 1, vector<long double>(n + 1));
        dp[0][0] = 1;
        // base coase for first coloumn
        for (int i = 1; i < n + 1; i++)
        {
            dp[i][0] = dp[i - 1][0] * (1 - vec[i - 1]);
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] * vec[i - 1] + dp[i - 1][j] * (1 - vec[i - 1]);
            }
        }
        // helptwo(dp);
        long double ans = 0;
        for (int i = n / 2 + 1; i <= n; i++)
        {
            ans += dp[n][i];
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // sieve();
    // fact();
    coderaryan();
    return 0;
}