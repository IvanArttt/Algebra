#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int n;
vector<int> p;
vector<int>::iterator it;
set<int> S;
vector<bool> used;
vector<int> temp;

void Check()
{
    temp.resize(40);
    for (size_t i = 0; i < 40; i++)
    {
        temp[i] = i;
    }
    for (size_t i = 0; i < 40; i++)
    {
        it = find(p.begin(), p.end(), temp[i]);
        if (it == p.end())
        {
            temp[i] = -1;
        }
    }
    for (size_t i = 0; i < 40; i++)
    {
        if (temp[i] < 0)
        {
            cout << "something wrong " << i + 1 << " not found\n";
        }
    }
}


void clear()
{
    for (size_t i = 0; i < 40; i++)
    {
        p[i] = 0;
        used[i] = 0;
    }
}


void input()
{
    n = 40;
    p.resize(n);
    used.resize(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> p[i];
        p[i]--;
    }
}
int dfs(int cur) 
{
    if (used[cur]) return 0;
    used[cur] = true;
    return dfs(p[cur]) + 1;
}
int gcd(int a, int b) 
{
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) 
{
    return a * b / gcd(a, b);
}
void solve()
{
    vector<int> us;
    us.resize(40);
    int Koshi = 1;
    int res = 1;
    int count = 0;
    int countNeMob = 0;
    int tmp = 0;

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            count++;
            int a = dfs(i);
            res = lcm(res, a);
            if (S.find(a) != S.end() )
            {
                S.insert(a);
            }
            else
            {
                ++us[a];
            }
            Koshi *= a;
            if (a == 1)
            {
                ++countNeMob;
            }
        }
    }
    
    if ((- (count % 2 - 1)) == 0)
    {
        tmp = -1;
    }
    else
    {
        tmp = 1;
    }


    for (size_t i = 39; i > 0; i--)
    {
        if (us[i] != 0)
        {
            cout << "{" << i << ',' << us[i] << "}";
        }
        Koshi *= tgamma(us[i] + 1);
    }


    cout << "\t" << Koshi;
    cout << "\t" << res;
    cout << '\t' << 40 - count;
    cout << "\t" << tmp;
    cout << "\t" << 40 - countNeMob << endl;
}
int main()
{
    freopen("data.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << "Цикловая структура\t" << "Число реш. ур. Коши\t" << "Порядок\t" << "Декремент\t" << "Четность\t" << "Число мобильных элементов\n";

    for (size_t i = 0; i < 30; i++)
    {
        input();
        Check();
        solve();
        clear();
    }
    
    return 0;
}