#include <iostream>
#include <string>
#include "Index.h"
#include "DataStore.h"
#include "Counter.h"

int main(){


    Counter map;

    // map.set("torry",511);
    // map.set("raissa",228);
    // map.set("torry",512);
    // map.inc("xer",3);
    // map.inc("xer",5);
    // map.del("torry");
    // map.del("raissa");

    // map.del("torry");
    // map.dec("torry",2);
    // map.dec("map");
    // map.dec("xer");
    // map.dec("e", -115);
    // map.inc("dsd", -147);
    // map.dec("raissa",115);
    // map.set("partridge in a pear tree",1);
    // map.set("turtle doves",2);
    // map.set("french hens",3);
    // map.set("calling birds",4);
    // map.set("golden rings",5);
    // map.set("geese a-laying",6);
    // map.set("swans a-swimming",7);
    // map.set("maids a-milking",8);
    // map.set("ladies dancing",9);
    // map.set("lords a-leaping",10);
    // map.set("pipers piping",11);
    // map.set("drummers drumming",12);

    // map.del("partridge in a pear tree");
    // map.del("turtle doves");
    // map.del("french hens");
    // map.del("calling birds");
    // map.del("drummers drumming");
    // map.del("pipers piping");
    // map.del("lords a-leaping");
    // map.inc("for the Elven-kings",1);
    // map.inc("for the Elven-kings");
    // map.inc("for the Elven-kings");
    // map.inc("for the Dwarf-lords",7);
    // map.inc("for mortal men",-2);
    // map.inc("for mortal men",11);
    // map.inc("for the Dark Lord");

    map.set("red",0);
    map.set("orange",0);
    map.dec("yellow",0);
    map.set("green",1);
    map.set("green",0);
    map.set("blue",1);
    map.dec("blue");
    map.dec("purple");
    map.inc("purple");
  

    map.set("red",-1);
    map.inc("orange",2);
    map.dec("yellow",3);
    // std::cout << map.table.arr[68].item_D->head->str<<" "<<map.table.arr[68].item_D->head->count <<std::endl;
    // std::cout << map.table.arr[68].item_D->head->i_next->str<<" "<<map.table.arr[68].item_D->head->count <<std::endl;
    
    map.set("green",4);
    map.inc("blue",-5);
    map.dec("purple",-6);
    map.set("purple",6);

    map.del("orange");
    map.del("yellow");
    map.del("purple");
    // std::cout << map.table.arr[68].item_D->head->i_next->str<<" "<<map.table.arr[68].item_D->head->count <<std::endl;

    map.set("orange",2);
    map.set("yellow",-3);
    map.dec("purple",-6);




    // std::cout << "tail o: " << map.table._data->tail->str << " " <<map.table._data->tail->count <<std::endl;
    
    // std::cout << map.get("torry") <<std::endl;
    // std::cout << map.get("xer") <<std::endl;
    
    std::cout << map.count() <<std::endl;
    std::cout << map.total() <<std::endl;

    // std::cout << map.get("for the Elven-kings") <<std::endl;

    for(Counter::Iterator itr = map.begin();itr != map.end();++itr){
        // std::cout << "tail: " << map.table._data->tail->str << " " <<map.table._data->tail->count <<std::endl;
        // std::cout << "tail: " << map.end().nod->str << " " <<map.end().nod->count<<std::endl;
        std::cout << "List: " << itr.nod->str << " " <<itr.nod->count <<std::endl;
    }


    // Counter::Iterator itr = map.begin();
    // std::cout << "runing: " << itr.nod->str << " " <<itr.nod->count <<std::endl;
    // itr = ++itr;
    // std::cout << "runing: " << itr.nod->str << " " <<itr.nod->count <<std::endl;
    // itr = ++itr;
    // std::cout << "runing: " << itr.nod->str << " " <<itr.nod->count <<std::endl;




    

    return 0;
}