#define _CRT_SECURE_NO_WARNINGS 1

//Ï´ÅÆ
#include <iostream>
#include <vector>
using namespace std;

void Shuffle(vector<unsigned int>& brand)
{
    int size = brand.size();
    vector<unsigned int> tmp(size, 0);
    int mid = size / 2;
    int j = 0;
    for (int i = 0; i < size / 2; ++i)
    {
        tmp[j++] = brand[i];
        tmp[j++] = brand[mid++];
    }
    brand = tmp;
}

int main()
{
    int T = 0;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<unsigned int> init(2 * n);
        for (int i = 0; i < 2 * n; ++i)
            cin >> init[i];
        while (k--)
            Shuffle(init);
        for (int i = 0; i < init.size(); ++i)
            cout << init[i] << ' ';
        cout << endl;
    }
    return 0;
}

//MP3¹â±êÎ»ÖÃ
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    string oprt;
    cin >> oprt;

    vector<int> music(n);
    for (int i = 0; i < n; ++i)
        music[i] = i + 1;

    int m = (n >= 4 ? 4 : n);
    vector<int> curTable(music.begin(), music.begin() + m);

    int curMusic = 0;
    if (n > 4)
    {
        for (int i = 0; i < oprt.size(); ++i)
        {
            if (curTable[curMusic] == 1 && oprt[i] == 'U')
            {
                vector<int> tmp(music.begin() + n - 4, music.begin() + n);
                curTable = tmp;
                curMusic = curTable.size() - 1;
            }
            else if (curTable[curMusic] == n && oprt[i] == 'D')
            {
                vector<int> tmp(music.begin(), music.begin() + 4);
                curTable = tmp;
                curMusic = 0;
            }
            else if (curMusic == 0 && oprt[i] == 'U')
            {
                vector<int> tmp(music.begin() + curTable[curMusic] - 2, music.begin() + curTable[curMusic] + 2);
                curTable = tmp;
            }
            else if (curMusic == 3 && oprt[i] == 'D')
            {
                vector<int> tmp(music.begin() + curTable[0], music.begin() + curTable[0] + 4);
                curTable = tmp;
            }
            else if (oprt[i] == 'U')
                --curMusic;
            else
                ++curMusic;
        }
    }
    else
    {
        for (int i = 0; i < oprt.size(); ++i)
        {
            if (curMusic == 0 && oprt[i] == 'U')
                curMusic = n - 1;
            else if (curMusic == n - 1 && oprt[i] == 'D')
                curMusic = 0;
            else if (oprt[i] == 'U')
                --curMusic;
            else
                ++curMusic;
        }
    }
    for (int i = 0; i < curTable.size(); ++i)
        cout << curTable[i] << ' ';
    cout << endl;
    cout << curTable[curMusic] << endl;
    return 0;
}