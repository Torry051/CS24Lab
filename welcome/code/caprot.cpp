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
    getline(cin, result);
    int size = result.size();
    int newShift = 0;
    

    string cpyString = result;
    for (int i = 0; i < size; i++) {
        if (isupper(result[i])) {
            if (shift >= 0) {
                cpyString[i] = tolower(result[i]);
                // cout << "before: " << result[i]<< endl;
                if (shift > size-i-1) {
                    newShift = shift - (size - 1 -i);
                    // cout << "1: "<< shift << endl; 
                    if (newShift > size) {
                        newShift = newShift - size;
                        index = newShift % size;
                        if (index == 0) {
                            index = size -1;
                        }
                        else {
                            index = index -1;
                        }
                        // cout << "2: " << index << endl;
                    }
                    else{
                    index = newShift -1;
                    // cout << "3: " << index << endl;
                    }
                }
                else {
                    index = i + shift;
                }
                cout << index << endl;
                cpyString[index] = toupper(result[index]); 
                cout << "after: " << cpyString[index] << endl;
            }
            else{
                cpyString[i] = tolower(result[i]);
                index = i + shift;
                if(index>= 0){
                    cpyString[index] = toupper(result[index]);
                }
                else{
                    index = (index % size);
                    if (index != 0) {
                        index = index + size;
                    }
                    cpyString[index] = toupper(result[index]);
                }
            }
        }
        
    }
    cout << cpyString << endl;
    return 0;
}