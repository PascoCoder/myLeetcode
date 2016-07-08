//
// Created by Pasco on 16/7/8.
//

#import "catch.hpp"
#import <iostream>
#import <map>

using namespace std;

class Solution {
public:
    set<char> charactersInTwoStrings(string str1, string str2){
        map<char,char> map1;
        set<char> set1;
        for (int i = 0; i < str1.size(); ++i) {
            map1[str1[i]] = str1[i];
        }
        for (int j = 0; j < str2.size(); ++j) {
            if(map1[str2[j]]){
                set1.insert(str2[j]);
            }
        }
        return set1;
    }
};


TEST_CASE("charactersInTwoStrings"){
    Solution solution;
    string str1 = "abcdefghijklmnopqrstuvwxyz";
    string str2 = "abcdefghijklmn";
    set<char> set1 = solution.charactersInTwoStrings(str1,str2);
    set<char> set2 = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n'};
    REQUIRE(set1 == set2);
}