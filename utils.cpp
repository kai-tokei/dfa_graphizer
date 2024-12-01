#pragma once

#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <map>

#include "./vertex.cpp"

using namespace std;

// 配列をデバッグする
template <typename T>
void debug_vector(vector<T> &vec)
{
    cout << "debug: ";
    for (const auto &v : vec)
        cout << v << " ";
    cout << endl;
}

// ファイル読み込み
string read_file(string path)
{
    ifstream file(path);
    string line, out = "";

    // ファイルが開けるか
    if (!file.is_open())
    {
        cerr << "Error: Cannot open file " << path << endl;
        return "";
    }

    while (getline(file, line))
    {
        out += line + '\n';
    }
    return out;
}

// ファイル書き込み
void write_file(string path, string content)
{
    ofstream file(path);

    // ファイルが開けるか
    if (!file.is_open())
    {
        cerr << "Error: Cannot open file " << path << endl;
        return;
    }

    file << content << endl;
}

// Dotのノードを生成する
string gen_node_dot(int id, string name, string shape = "circle")
{
    return "q_" + to_string(id) + "[label=<q<sub>" + name + "</sub>>,shape=" + shape + "];";
}

