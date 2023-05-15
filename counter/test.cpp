#include <iostream>
#include <string>
#include "Index.h"
#include "DataStore.h"

int main(){

    Index table;
    // std::cout << table.size << " " << table.capacity << std::endl;
    table.insert("tor",5);// 5
    // std::cout << table.size << " " << table.capacity << std::endl;
    // std::cout << table.arr[0]._key << " "<< table.arr[0].node->count << std::endl;
    table.insert("M",10);// 14
    // std::cout << table.size << " " << table.capacity << std::endl;
    // std::cout << table.arr[0]._key << " "<< table.arr[0].node->count << std::endl;
    // std::cout << table.arr[1]._key << " "<< table.arr[1].node->count << std::endl;
    table.insert("a",11); //13
    table.insert("ca",19); //7
    table.insert("to",112); //17
    table.insert("abc",12); //0
    table.insert("T",520);
    table.remove("abc");
    table.increment("a");
    table.increment("0",2);
    table.decrement("0",1);


    // std::cout << table.arr[1]._key << " "<< table.arr[1].node->count << std::endl;
    std::cout << table.arr[6]._key << " "<< table.arr[6].node->count << std::endl;
    std::cout << table.size << " " << table.capacity << std::endl;
    Node * curr = table._data->head;
    // if (curr == nullptr){
    //     std::cout << "wrong" <<std::endl;
    // }
    std::cout << "start list" << std::endl;
    while(curr != nullptr){
        
        std::cout << curr->str << " " << curr->count << std::endl;
        if (curr->last == nullptr && curr->next != nullptr){
            std::cout << "Next: " << curr->next->str << std::endl;
        } 
        else if (curr->last != nullptr && curr->next == nullptr){
            std::cout << "Last: "<<curr->last->str  << std::endl;
        }
        else {
        std::cout << "Last: "<<curr->last->str << " Next: " << curr->next->str << std::endl;
        }
        if (curr->next == nullptr){
            break;
        }
        curr = curr->next;
    }
    std::cout << table.tot <<std::endl;

    

    return 0;
}