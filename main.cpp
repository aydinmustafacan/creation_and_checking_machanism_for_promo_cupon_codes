/*
 Name: Mustafa Can AYDIN
 Compile Status: Compiling
 Program Status: Working
 Notes: I have written and tested this code in C++11 using MacOS Big Sur version 11.2.3
 */
#include <iostream>
#include <cstdio>
#include <unordered_set>
#include "md5.h"
using namespace std;
unordered_set<string> hash_set_of_codes;

string GenerateCodes(){
// temproray string with temproray value
std::string tmp="00000000";
const char character_set_for_code[] = "ACDEFGHKLMNPRTXYZ234579";
int length_of_char_set = sizeof(character_set_for_code)-1;
    
for(int i=0;i<8;i++){
    char c= (char) character_set_for_code[rand()%length_of_char_set];
    tmp[i]=c;
}
if(hash_set_of_codes.find(md5(tmp))!=hash_set_of_codes.end()){
    //code has already been generated
    return GenerateCodes();
}
else{
    //code is not generated before thus it is unique
    hash_set_of_codes.insert(md5(tmp));
}
return tmp;
}
bool CheckCode(string code) {
    if(hash_set_of_codes.find(md5(code))!=hash_set_of_codes.end()){
        //we found the hash in our hash set so it is valid
        return true;
    }
    else{
        return false;
    }
}



// Driver Code
int main() {
    FILE* fileptr;
    fileptr = fopen("PromoCodes.txt","a");
    for(int i=0; i<1000 ;i++){
        string myStr= GenerateCodes();
        fprintf(fileptr, "%d- %s\n",(i+1),myStr.c_str());
        if(!CheckCode(myStr)){
            cout<< "error" ;
            break;
        }
    }
    fclose(fileptr);
    cout << hash_set_of_codes.size()<<" unique promo codes has been generated and verified!" <<endl;
    return 0;
}
