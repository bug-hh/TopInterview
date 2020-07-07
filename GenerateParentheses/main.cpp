//
//  main.cpp
//  GenerateParentheses
//
//  Created by bughh on 2020/7/7.
//  Copyright © 2020 bughh. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
void dfs(vector<string> &ret, int left, int right, string &s);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

vector<string> generateParenthesis(int n) {
    vector<string> ret;
    string s = "";
    dfs(ret, n, n, s);
    return ret;
}

/*
对于这种列出所有结果的题首先还是考虑用递归 Recursion 来解，由于字符串只有左括号和右括号两种字符，而且最终结果必定是左括号3个，右括号3个，
 所以这里定义两个变量 left 和 right 分别表示剩余左右括号的个数，如果在某次递归时，左括号的个数大于右括号的个数，
 说明此时生成的字符串中右括号的个数大于左括号的个数，即会出现 ')(' 这样的非法串，所以这种情况直接返回，不继续处理。
 如果 left 和 right 都为0，则说明此时生成的字符串已有3个左括号和3个右括号，且字符串合法，则存入结果中后返回。如果以上两种情况都不满足，
 若此时 left 大于0，则调用递归函数，注意参数的更新，若 right 大于0，则调用递归函数，同样要更新参数。
 */
void dfs(vector<string> &ret, int left, int right, string &s) {
    if (left > right) {
        return;
    }
    if (left == 0 && right == 0) {
        ret.push_back(s);
        return;
    } else {
        if (left > 0) {
            s.push_back('(');
            dfs(ret, left - 1, right, s);
            s.pop_back();
        }
        if (right > 0) {
            s.push_back(')');
            dfs(ret, left, right - 1, s);
            s.pop_back();
        }
    }
}
