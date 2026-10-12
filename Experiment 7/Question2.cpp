#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <algorithm>
using namespace std;

unordered_map<string, int> memo;
const int INF = 1e9;

int idx(char c)
{
    if (c == 'R') return 0;
    if (c == 'Y') return 1;
    if (c == 'B') return 2;
    if (c == 'G') return 3;
    if (c == 'W') return 4;

    return -1;
}

string shrink(string s)
{
    bool changed = true;

    while (changed)
    {
        changed = false;

        for (int i = 0; i < (int)s.size();)
        {
            int j = i;

            while (j < (int)s.size() && s[j] == s[i])
                j++;

            if (j - i >= 3)
            {
                s.erase(i, j - i);
                changed = true;
                break;
            }

            i = j;
        }
    }

    return s;
}

int dfs(string board, array<int, 5> &hand)
{
    if (board.empty())
        return 0;

    string key = board + "#";

    for (int i = 0; i < 5; i++)
    {
        key += to_string(hand[i]) + ",";
    }

    if (memo.count(key))
        return memo[key];

    int ans = INF;
    int n = (int)board.size();

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && board[i] == board[i - 1])
            continue;

        int id = idx(board[i]);

        if (id == -1 || hand[id] == 0)
            continue;

        hand[id]--;

        string next = board.substr(0, i)
                    + board[i]
                    + board.substr(i);

        next = shrink(next);

        int res = dfs(next, hand);

        if (res != INF)
            ans = min(ans, res + 1);

        hand[id]++;
    }

    return memo[key] = ans;
}

int findMinStep(string board, string hand)
{
    memo.clear();

    array<int, 5> cnt = {0, 0, 0, 0, 0};

    for (char c : hand)
    {
        int id = idx(c);

        if (id != -1)
            cnt[id]++;
    }

    board = shrink(board);

    int ans = dfs(board, cnt);

    return ans == INF ? -1 : ans;
}

int main()
{
    cout << "Minimum Steps: "
         << findMinStep("WWRRBBWW", "WRBRW")
         << endl;

    return 0;
}
