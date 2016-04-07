cmake_minimum_required(VERSION 3.4)
project(myLeetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp catch.hpp
        001twoSum.cpp 002addTwoNumbers.cpp
        003LongestSubstringWithoutRepeatingCharacters.cpp 004medianOfTwoSortedArrays.cpp
        005longestPalindromicSubstring.cpp 006zigZagConversion.cpp
        007reverseInteger.cpp 008StringToInteger.cpp
        009PalindromeNumber.cpp

        226invertbinarytree.cpp
        )
add_executable(myLeetcode ${SOURCE_FILES})