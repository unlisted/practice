#include <iostream>
#include <string>
#include <cstring>
#include <unordered_set>
#include <algorithm>

using namespace std;



bool IsPalindrome(const char *word) {

    char *head = const_cast<char*>(word);
    auto sz = strlen(word);
    char *tail = head + sz - 1;


    while (head < tail) {
        if (*(head++) != *(tail--))
            return false;
    }
    return true;
}

unordered_set<string> FindSequences(const char *word) {
    // first print all sequences
    //
    unordered_set<string> sequences;
    auto len = strlen(word);
    char buff[len + 1];
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            auto seqLen = j - i + 1;
            memset(buff, 0, seqLen + 1);
            memcpy(buff, &word[i], seqLen);
            buff[seqLen] = '\0';

            string seq(buff);
            if (sequences.find(seq) == sequences.end()) {
                // check for palindrome
                sequences.insert(seq);
            }
        }
    }

    /*
    for (auto &s : sequences) {
        cout << s << endl;
    }*/
    return sequences;

}

int main(int argc, char *argv[]) {

    string line;
    getline(cin, line);

    auto seqs = FindSequences(line.c_str());
    
    int count = 0;
    for_each(begin(seqs), end(seqs), [&count](const string &s) {count += IsPalindrome(s.c_str()); });

    cout << count << endl;

    //for (auto &s : seqs) {
    //    cout << s<< ": " << IsPalindrome(s.c_str()) << endl;;
    //}
    return 0;
}
