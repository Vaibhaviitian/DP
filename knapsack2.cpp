// JAI MAHAKALLLLLLLLLLLLLLL
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define dbg(x) cout << #x << " = " << x << "\n"
#define vi vector<int>
#define vl vector<int>
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
int min(int a, int b) { return std::min(a, b); }
int max(int a, int b) { return std::max(a, b); }
// initialising memoization
vector<vector<int>> dp(101, vector<int>(1e5 + 1, -1));
int rec(int inx, int value_tobuild, vl &wt, vl &values)
{
    // base case
    if (value_tobuild <= 0)
        return 0;
    if (inx < 0)
        return 1e15;
    if (dp[inx][value_tobuild] != -1) return dp[inx][value_tobuild];
    int new_wt = 1e9;
    // concept is same what you have to think just how achieving the same value with minimum cost
    // Don't
    new_wt = rec(inx - 1, value_tobuild, wt, values);
    // lena hai khol ke
    new_wt = min(new_wt, rec(inx - 1, value_tobuild - values[inx], wt, values) + wt[inx]);
    return dp[inx][value_tobuild] = new_wt;
}
void coderaryan()
{
    // executing code from here
    int n, k;
    cin >> n >> k;
    vl wt(n), values(n);
    // now just see how we can use our recursion function to throw the output
    // it will be like we can iterate in the max values of value and then we call the recusrive function and in case if there is a chance of getting any wt<given wt that is answer because our values will be maximum as we are iterating from 1e5 to 1
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> values[i];
    }
    // state of dp gives us for ith
    int ans = -1;
    for (int i = 1e5; i >= 0; i--)
    {
        if (rec(n - 1, i, wt, values) <= k)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    coderaryan();
    return 0;
}