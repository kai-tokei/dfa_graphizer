#pragma once

#include <iostream>
#include <vector>

using namespace std;

// 頂点
struct Vertex
{
    int id;
    string lambda;
    string sigma;
    vector<int> to;

    Vertex(int i, int t)
    {
        id = i;
        to.resize(t, 0);
    }

    string get_lambda()
    {
        return lambda;
    }

    // dot言語化
    string to_str()
    {
        string out;
        for (int i = 0; i < to.size(); i++)
        {
            out += "    ";
            out += "q_" + to_string(id) + " -> " + "q_" + to_string(to[i]);
            out += " [label=" + to_string(i) + "];";
            // out += " " + lambda;
            out += "\n";
        }
        return out;
    }
};
