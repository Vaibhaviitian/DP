// JAI MAHAKALLLLLLLLLLLLLLL
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define dbg(x) cout << #x << " = " << x << "\n"
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
// ASCII values
// A=65, Z=90, a=97, z=122
// Some Tricks
// divide into cases, brute force, pattern finding
// sort, greedy, binary search, two pointer
// transform into graph
// calculating anything in a string = count(in.begin(), in.end(), '0')
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
// function for checking prime
bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
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
            cout << i << " ";
        cout << endl;
    }
}
// Function to print a map
template <typename K, typename V>
void helpmap(const map<K, V> &mp)
{
    cout << "map help is executed:" << endl;
    for (const auto &i : mp)
        cout << i.first << " -> " << i.second << endl;
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
void coderaryan()
{
    // executing code from here
    int t = 1;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        // dp[i][j]->if we are considering ith string of a and jth string of j then what is the value of max LCS
        // base case
        vector<vector<int>> dp(n, vector<int>(m, 0));
        string s;
        for (int i = 0; i < n; i++)
        {
            s += a[i];
            dp[i][0] = count(s.begin(), s.end(), b[0]);
        }
        s.clear();
        for (int i = 0; i < m; i++)
        {
            s += b[i];
            dp[0][i] = count(s.begin(), s.end(), a[0]);
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (a[i] == b[j])
                {
                    if (i - 1 >= 0 && j - 1 >= 0)
                    {
                        dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
                    }
                }
                else
                {
                    if (i - 1 >= 0)
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                    }
                    if (j - 1 >= 0)
                    {
                        dp[i][j] = max(dp[i][j - 1], dp[i][j]);
                    }
                    if (i - 1 >= 0 && j - 1 >= 0)
                    {
                        dp[i][j] = max(dp[i - 1][j - 1], dp[i][j]);
                    }
                }
            }
        }
        // helptwo(dp);
        s.clear();
        int i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0)
        {
            // cout << "Initial" << endl;
            // dbg(i), dbg(j);

            if (a[i] == b[j])
            {
                s += a[i];
                if (i == 0 && j > 0)
                {
                    j--;
                }
                else if (j == 0 && i > 0)
                {
                    i--;
                }
                else
                {
                    i--;
                    j--;
                }
            }
            else if (i > 0 && (j == 0 || dp[i - 1][j] >= dp[i][j - 1]))
            {
                i--;
            }
            else
            {
                j--;
            }

            // cout << "after" << endl;
            // dbg(i), dbg(j);
            // dbg(s);
        }

        reverse(s.begin(), s.end());
        cout << s << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    coderaryan();
    return 0;
}