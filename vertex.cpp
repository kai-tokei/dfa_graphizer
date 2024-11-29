#pragma once
#include <vector>
#include <iostream>

using namespace std;

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

    string to_str()
    {
        string out;
        for (int i = 0; i < to.size(); i++)
        {
            out += "    ";
            out += "q_" + to_string(id) + " -> " + "q_" + to_string(to[i]);
            out += " [label=" + to_string(i) + "];";
            out += "\n";
        }
        return out;
    }
};

ostream &operator<<(ostream &os, const Vertex vtx)
{
    for (int i = 0; i < vtx.to.size(); i++)
    {
        os << "\tq_" << to_string(vtx.id) << " -> " << "q_" << to_string(vtx.to[i]);
        os << "[label=" << to_string(i) << "]";
        os << endl;
    }
    return os;
}
