#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <map>

#include "./utils.cpp"
#include "./vertex.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    string target = "101101100"; // 入力期待文字列
    string sigma = "01";         // 入力文字集合

    string dot_header = read_file("dot_header.txt"); // dotファイルのheader
    string dot_footer = read_file("dot_footer.txt"); // dotファイルのfooter

    string dot_code = dot_header; // dot言語のコード

    // 頂点のtable (id, from, to)
    vector<Vertex> vtxs(target.size(), Vertex(0, sigma.size()));
    for (int i = 0; i < vtxs.size(); i++)
        vtxs[i].id = i;

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

    // ノードをDotコードに登録
    dot_code += "    " + gen_node_dot(0, "0", "doublecircle") + "\n";
    dot_code += "\n";
    for (int i = 1; i < vtxs.size(); i++)
    {
        dot_code += "    " + gen_node_dot(i, to_string(i)) + "\n";
    }

    // input
    dot_code += "\n    input -> q_0 [periphries=2];\n";

    // 入力文字集合から入力されうる文字をつなげて、部分文字列を作成
    // 部分文字列が登録されていたものなら、頂点を追加
    // 登録されていなかったら、文字列の前から順に探索して、長さが最も大きい部分文字列へのpathを登録
    for (int i = 0; i < vtxs.size(); i++)
    {
        string crt_str = target.substr(0, i);

        // sigma の文字を連結
        for (int j = 0; j < sigma.size(); j++)
        {
            string attempt = crt_str + sigma[j];

            // 部分文字列が合致したら、頂点を登録
            if (strmap.count(attempt))
            {
                vtxs[i].to[j] = strmap[attempt];
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
    for (int i = 0; i < vtxs.size(); i++)
    {
        dot_code += vtxs[i].to_str();
    }
    dot_code += dot_footer;
    write_file("sample.dot", dot_code);

    return 0;
}
