#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
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
    int from;
    int to;

    string to_str()
    {
        return to_string(from) + " -> [ " + to_string(id) + " ] -> " + to_string(to);
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

    // 入力文字集合から入力されうる文字をつなげて、部分文字列を作成
    // 部分文字列が登録されていたものなら、頂点を追加
    // 登録されていなかったら、文字列の前から順に探索して、長さが最も大きい部分文字列へのpathを登録

    // 頂点tableの内容をlistする
}
