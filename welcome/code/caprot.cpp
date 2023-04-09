#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    string result;
    if (argc!= 2) {
        exit(-1);
    }
    int shift = stoi(argv[1]);
    int index = 0;
    cin >> result;
    int size = result.size();
    

    string cpyString = result;
    for (int i = 0; i < size; i++) {
        if (isupper(result[i])) {
            if (shift >= 0) {
                cpyString[i] = tolower(result[i]);
                index = i + shift;
                if (index > size-1) {
                    index = (index +1)% size;
                    if (index==0){
                        index = size-1;
                    }
                    else {
                        index = index -1;
                    }
                    cpyString[index] = toupper(result[index]);
                }
                else {
                    cpyString[index] = toupper(result[index]); 
                }
            }
            else{
                cpyString[i] = tolower(result[i]);
                index = i + shift;
                if(index>= 0){
                    cpyString[index] = toupper(result[index]);
                }
                else{
                    index = (index % size )+ size;
                    cpyString[index] = toupper(result[index]);
                }
            }
        }
        
    }
    cout << cpyString << endl;
    return 0;
}