// // JAI MAHAKALLLLLLLLLLLLLLL
// #include <bits/stdc++.h>
// using namespace std;
// #define MOD 1000000007
// #define int long long
// #define dbg(x) cout << #x << " = " << x << "\n"
// #define vi vector<int>
// #define vl vector<int>
// #define pii pair<int, int>
// #define pb push_back
// #define mp make_pair
// #define cy cout << "YES" << endl
// #define cn cout << "NO" << endl
// // ASCII values
// // A=65, Z=90, a=97, z=122
// // Some Tricks
// // divide into cases, brute force, pattern finding
// // sort, greedy, binary search, two pointer
// // transform into graph
// // calculating anything in a string = count(in.begin(), in.end(), '0')
// // is a substring present on main string or not and X is repetition
// // bool checking_substring = in.find(string(X, '1')) != string::npos;
// // {for knowing MSB 32 -  __builtin_clz(n)}
// // {for knowing set bits  -  __builtin_popcount(n) and __builtin_popcountll(n)}

// // Function for modular exponentiation
// long long mod_exp(long long base, long long exp, long long mod)
// {
//     long long result = 1;
//     base = base % mod; // Handle base larger than mod
//     while (exp > 0)
//     {
//         if (exp % 2 == 1)
//         {
//             result = (result * base) % mod;
//         }
//         base = (base * base) % mod;
//         exp /= 2;
//     }
//     return result;
// }
// template <typename T>
// void help(const vector<T> &vec)
// {
//     cout << "help is executed" << endl;
//     for (const auto &i : vec)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
// }
// int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
// int lcm(int a, int b) { return a / gcd(a, b) * b; }
// int mod(int a) { return a < 0 ? -a : a; }

// int prefix_sum(int a, int n)
// {
//     return (n * (2 * a + (n - 1))) / 2;
// }
// int coordinate_distance(int x1, int x2, int y1, int y2)
// {
//     int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
//     return dist;
// }
// int min(int a, int b) { return std::min(a, b); }
// int max(int a, int b) { return std::max(a, b); }
// // initialising memoization
// vector<vector<int>> dp(101, vector<int>(1e5 + 1, -1));
// int rec(int inx, int left_wt, vl &wt, vl &values)
// {

//     // base case are so simple
//     if (inx < 0 || left_wt == 0)
//         return 0;
//     if (dp[inx][left_wt] != -1)
//         return dp[inx][left_wt];
//     // brute force recursion
//     // 1-> not including the inx quantity
//     int ans = rec(inx - 1, left_wt, wt, values);
//     // including the i choice
//     // now we have to add here something because if we are considering the i-1 chice then we have to add something
//     if (left_wt - wt[inx] >= 0)
//         ans = max(ans, rec(inx - 1, left_wt - wt[inx], wt, values) + values[inx]);
//     // dbg(ans);
//     return dp[inx][left_wt] = ans;
// }
// void coderaryan()
// {
//     // executing code from here
//     int n, k;
//     cin >> n >> k;
//     vl wt(n), values(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> wt[i] >> values[i];
//     }
//     cout << rec(n - 1, k, wt, values) << endl;
// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     coderaryan();
//     return 0;
// }

// iterative dp

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
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> vec(n, {0, 0});
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i].first >> vec[i].second;
        }
        // dp[i][j]-> upto the ith index and bag having j capacity what is the max value
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
            // bag capacity is zero
        }

        for (int j = 0; j <= k; j++)
        {
            if (j >= vec[0].first)
            {
                dp[0][j] = vec[0].second;
            }
            else
            {
                dp[0][j] = 0;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= vec[i].first)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - vec[i].first] + vec[i].second);
                }
            }
        }
        helptwo(dp);
        // cout<<dp[n-1][k]<<endl;
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