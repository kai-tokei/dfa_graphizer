#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

template <typename T>
void debug_vector(vector<T> vec)
{
    cout << "debug: ";
    for (const auto v : vec)
        cout << v << " ";
    cout << endl;
}

// 頂点
struct Vertex
{
    int id;
    vector<int> to;

    Vertex(int i, int t)
    {
        id = i;
        to.resize(t);
    }
};

int main(int argc, char *argv[])
{
    string target = "101101100"; // 入力期待文字列
    string sigma = "01";         // 入力文字集合

    // 頂点のtable (id, from, to)
    vector<Vertex> vtxs;

    // targetから部分文字列を作成し、tableに保存
    // mapに、部分文字列をiとともに保存
    vector<string> substrs;
    map<string, int> strmap;
    for (int i = 0; i < target.size(); i++)
    {
        substrs.push_back(target.substr(0, i));
        strmap[substrs.back()] = i;
    }
    debug_vector(substrs);

    // 頂点を設定
    vtxs.resize(substrs.size() - 1);
    for (int i = 0; i < vtxs.size(); i++)
        vtxs[i] = Vertex(i, sigma.size());

    // 入力文字集合から入力されうる文字をつなげて、部分文字列を作成
    // 部分文字列が登録されていたものなら、頂点を追加
    // 登録されていなかったら、文字列の前から順に探索して、長さが最も大きい部分文字列へのpathを登録
    for (int i = 0; i < target.size(); i++)
    {
        string crt_str = target.substr(0, i);

        // sigma の文字を連結
        for (int j = 0; j < sigma.size(); j++)
        {
            string attempt = crt_str + sigma[i];

            // 部分文字列が合致したら、頂点を登録
            if (strmap.count(attempt))
            {
                // 期待文字列と完全に一致していたら、受容ノードへのpathを繋ぐ
                if (attempt == substrs.back())
                {
                    vtxs[i].to[j] = 0;
                }
                else
                {
                    vtxs[i].to[j] = strmap[attempt];
                }
            }
            else
            {
                // そうでないなら、直前の一致する部分文字列へpathを返す
                reverse(attempt.begin(), attempt.end());
                for (int k = 0; k < attempt.size(); k++)
                {
                    string return_str = attempt.substr(0, k);
                    if (strmap.count(return_str))
                    {
                        vtxs[i].to[j] = strmap[return_str];
                    }
                }
            }
        }
    }

    // 頂点tableの内容をlistする
}
