#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;
    v.insert(v.begin(),2);
    v.insert(v.begin(),21);
    std::cout << v.at(0) <<std::endl;

}