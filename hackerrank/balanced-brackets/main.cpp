#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    stack<char> st;
    
    for (int i = 0; i < s.length(); ++i)
    {
        if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[')  // opening bracket, just add to stack
            st.push(s.at(i));  // add bracket to stack
        else // it is closing bracket
            if (!stack.empty() && (abs(s.at(i) - stack.top()) <= 2))  // distance between opening/closing brackets are 1,2,2
                --top, ++s;
            else
                break;
    }

    free(stack);

    // return yes, if stack is empty, i.e. all opening brackets are closed
    // and iterated through whole string without interruption
    return (*s == 0 && top == -1) ? "YES" : "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
