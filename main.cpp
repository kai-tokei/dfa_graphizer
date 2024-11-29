#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    string target = argv[0]; // 入力期待文字列
    string sigma = "01";     // 入力文字集合

    // 頂点のtable (id, from, to)

    // targetから部分文字列を作成し、tableに保存
    // ハッシュテーブルに、部分文字列をiとともに保存

    // 入力文字集合から入力されうる文字をつなげて、部分文字列を作成
    // 部分文字列が登録されていたものなら、頂点を追加
    // 登録されていなかったら、文字列の前から順に探索して、長さが最も大きい部分文字列へのpathを登録

    // 頂点tableの内容をlistする
}
