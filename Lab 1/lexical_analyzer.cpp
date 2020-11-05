// Online C++ compiler to run C++ program online
#include <iterator>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <regex>
#include <list>
#include <map>
using namespace std;

void analyse(string str){
        // define list of patterns
    map<string,string> patterns {
        { "[0-9]+" ,   "Number" },
        { "[a-zA-Z]+" ,   "Identifier" },
        { "\\*|\\+|\\-|\\/|\\>|\\<|\\=|\\!",  "Operator" },
        { "\\,|\\(|\\)|\\;|\\{|\\}|\\[|\\]", "Separator"}
    };

    // storage for results
    map< size_t, pair<string,string> > matches;

    for ( auto pattern = patterns.begin(); pattern != patterns.end(); ++pattern )
    {
        regex r(pattern->first);
        auto words_begin = sregex_iterator( str.begin(), str.end(), r );
        auto words_end   = sregex_iterator();

        for ( auto it = words_begin; it != words_end; ++it )
            matches[ it->position() ] = make_pair( it->str(), pattern->second );
    }

    for ( auto match = matches.begin(); match != matches.end(); ++match )
        cout<< match->second.first << " is a " << match->second.second << endl;
}

int main(){
    string str = "hello, world; {welcome to 2020} 2 + 3 = 5";
    analyse(str);
}