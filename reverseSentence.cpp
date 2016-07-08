//
// Created by Pasco on 16/6/17.
//

#include "catch.hpp"
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseSentence(char *str)
    {
        int size = 0;
        int wbegin =  0;
        while(str[size] != '\0')
        {
            if (str[size] == ' ')
            {
                reverseWord(str, wbegin, size-1);
                wbegin = size+1;
            }
            size++;
        }
        reverseWord(str,wbegin,size-1);

        for (int i = 0; i <= size; i++,size--) {
            swap(str[i], str[size-1]);
        }

//        cout<<str<<endl;

    }
    void reverseWord(char *str, int begin, int end)
    {
        if(begin >= end)
            return;
        while (begin < end)
        {
            swap(str[begin], str[end]);
            begin++;
            end--;
        }
    }
};

TEST_CASE("111reverseSentence"){
    Solution solution;
    char str[] = "i love study, study make me happy";
    char str1[] = "happy me make study study, love i";
    solution.reverseSentence(str);
    REQUIRE(strcmp(str,str1)==0);

}




