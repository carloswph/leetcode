#include <iostream>
#include <string>
#include <locale>

class Solution {
public:
    string toLowerCase(string s) {
    	
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ 
        	return std::tolower(c); 
        });

        return s;
    }
};