#include <iostream>
#include <vector>
#include <string>

//time complexity = 0(n) - one pass through the vector, a for loop.
void removeCopies(std::vector<int>& data) {

if (data.empty()) return; //if there's nothing to begin with, just clean up and exit

int marker = 0; //unique value, starting point (index 0)
    //check everything after starter point (index 1)
    for (int scout = 1; scout < (int)data.size(); scout++){
        if (data[scout] != data[marker]){
            marker++;                  // move marker forward
            data[marker] = data[scout]; // copies the new value to scout
        }
        // everything else is a duplicate, and skip it (marker stays put)
    }
    data.resize(marker + 1); // cuts the vector down to the right size
}
// time complexity 0(n) -> goes for n times(officer) + n times (spy) + 26 times (tally) fixed time
// it is not a nested loop (nxn)
void isAnagram(std::string officer_name, std::string spy_name){

   if (officer_name.length() != spy_name.length()){
        std::cout << "IMPOSTER! IMPOSTER!" << std::endl; // different lengths can't be anagrams
        return;
    }
 
    int tally[26] = {0}; // a-z
    //ASCII - values a= 97, b=98
    for (char c : officer_name) {
        tally[c - 'a']++; //add 1 to tally every letter inside officer
    }
    for (char c : spy_name) {
        tally[c - 'a']--; //subtracts 1  to tally for every letter inside spy
    }
    for (int i = 0; i < 26; i++){
        if (tally[i] != 0){ // if letters count dont match
            std::cout << "IMPOSTER! IMPOSTER!" << std::endl;
            return;
        }
    }

    std::cout << "No imposter detected!" << std::endl; // all counts cancelled to 0 (same lenght)

}

int main(){

    /*Use other test cases to make sure you program works*/
    std::vector<int> server = {1,1,2,2,2,3,3,4,5,6,6,6};

    /*Print out the original server vector before function called*/
     for (auto data : server){
        std::cout << data << " "; // 1,1,2,2,2,3,3,4,5,6,6,6
    }

    removeCopies(server);
    
    /*Print out the modification of the server vector after function called*/
    for (auto data : server){
        std::cout << data << " ";
    }

    std::cout << std::endl;

    /****************************TEST ANAGRAM*************************************/

    isAnagram("carlos", "solrac"); // No imposter detected!
    isAnagram("Syeda", "johnny"); // IMPOSTER! IMPOSTER!

    return 0;

}
