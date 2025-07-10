#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#define ll long long
#define pb push_back
#define mod (ll)(1e9 + 7)
#include <bits/stdc++.h>
 
using namespace std;

struct dat
{
    ll x, y;
    dat(ll x, ll y) : x(x), y(y) {}
    dat() = default;
    dat operator+(const dat &b)const { return dat(x + b.x, y + b.y); }
    dat operator-(const dat &b)const { return dat(x - b.x, y - b.y); }
    ll operator^(const dat &b)const { return x * b.y - y * b.x; }
    bool operator<(const dat &b)const { return x == b.x ? y < b.y : x < b.x; }
};
 
dat input[200005];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll tx, ty;
        cin >> tx >> ty;
        input[i] = dat(tx, ty);
    }
    sort(input, input + n);
    vector<dat> ans(2 * n);
    ll place = 0;
    for (ll i = 0; i < n; i++)
    {
        while (place > 1 && ((input[i] - ans[place - 1]) ^ (input[i] - ans[place - 2])) > 0)
            place--;
        ans[place++] = input[i];
    }
    ll np = place;
    for (ll i = n - 2; i >= 0; i--)
    {
        while (place > np && ((input[i] - ans[place - 1]) ^ (input[i] - ans[place - 2])) > 0)
        {
            place--;
        }
        ans[place++] = input[i];
    }
    place--;
    cout << place << "\n";
    for (ll i = 0; i < place; i++)
    {
        cout << ans[i].x << " " << ans[i].y;
        cout << "\n";
    }
    //cout.flush(); system("pause");
    return 0;
}