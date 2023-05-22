#include "Heap.h"
#include <vector>
#include <iostream>

Heap::Heap(size_t capacity){
    mData = new Entry[capacity];
    this->mCapacity = capacity;
    this->mCount = 0;
    for (size_t i=0; i< mCapacity; i++){
        mData[i].value = "";
        mData[i].score = 99;

    }

}

Heap::Heap(const Heap& other){
    mData = new Entry[other.mCapacity];
    this->mCapacity = other.mCapacity;
    this->mCount = other.mCount;
    for (size_t i = 0; i < mCapacity; i++){
        mData[i] = other.mData[i];
    }
}

Heap::Heap(Heap&& other){
    // mData = other.mData;
    // this->mCapacity = other.mCapacity;
    // this->mCount = other.mCount;
}

Heap::~Heap(){
    // std::cout << "desctructer" <<std::endl;
    delete [] mData;
}

size_t  Heap::capacity() const{
    return mCapacity;
}

size_t  Heap::count() const{
    return mCount;
}

const Heap::Entry& Heap::lookup(size_t index) const{
    if (index >= mCapacity){
        throw std::out_of_range("out of range");
    }
    return mData[index];
}

Heap::Entry  Heap::pop(){
    if (mCount == 0){
        throw std::underflow_error("underflow error");
    }
    Heap::Entry result = mData[0];
    // std::cout << "running1" <<std::endl;
    if (mCount ==1){
        delete [] mData;
        mData = new Heap::Entry[mCapacity];
        mCount = 0;
        return result;
    }

    // std::cout << "running2" <<std::endl;
    size_t i = mCapacity-1;

    while (i!=0){
        if (mData[i].value != ""){
            mData[0].value = mData[i].value;
            mData[0].score = mData[i].score;
            mData[i].value = "";
            mData[i].score = 99;
            mCount = mCount -1;
            break;
        }
        i = i-1;
    }
    // std::cout << "running3" <<std::endl;
    i = 0;
    while(i*2+1 < mCapacity|| i*2+2 < mCapacity){
        // std::cout << "running3" <<std::endl;
        if (mData[i*2+1].value == "" && mData[i*2+2].value==""){
            break;
        }

        if (mData[i].score > mData[i*2+1].score || mData[i].score > mData[i*2+2].score){
            
            if(mData[i*2+1].score <= mData[i*2+2].score){
                std::string str = mData[i].value;
                float score = mData[i].score;
                
                mData[i].value = mData[i*2+1].value;
                mData[i].score = mData[i*2+1].score;
                i = i*2+1;
                mData[i].value = str;
                mData[i].score = score;
            }
            else {
                std::string str = mData[i].value;
                float score = mData[i].score;
                
                mData[i].value = mData[i*2+2].value;
                mData[i].score = mData[i*2+2].score;
                i = i*2+2;
                mData[i].value = str;
                mData[i].score = score;
            }
        }
        else{
            break;
        }
    }

    return result;
}


Heap::Entry  Heap::pushpop(const std::string& value, float score){
    if(mCount == 0){
        throw std::underflow_error("underflow error");
    }
    Heap::Entry result = mData[0];


    mData[0].value = value;
    mData[0].score = score;
    if(mCount == 1){
        return result;
    }

    size_t i =0;

    while(i*2+1 < mCapacity|| i*2+2 < mCapacity){
        // std::cout << "running3" <<std::endl;
        if (mData[i*2+1].value == "" && mData[i*2+2].value==""){
            break;
        }

        if (mData[i].score > mData[i*2+1].score || mData[i].score > mData[i*2+2].score){
            if(mData[i*2+1].score <= mData[i*2+2].score){
                // std::cout << "running2" <<std::endl;
                std::string str = mData[i].value;
                float s = mData[i].score;
                
                mData[i].value = mData[i*2+1].value;
                mData[i].score = mData[i*2+1].score;
                i = i*2+1;
                mData[i].value = str;
                mData[i].score = s;
            }
            else {
                // std::cout << "running1" <<std::endl;
                std::string str = mData[i].value;
                float s = mData[i].score;
                
                mData[i].value = mData[i*2+2].value;
                mData[i].score = mData[i*2+2].score;
                i = i*2+2;
                mData[i].value = str;
                mData[i].score = s;
            }
        }
        else{
            break;
        }
    }
    return result;
}

void    Heap::push(const std::string& value, float score){
    size_t index = 0;
    if(mCount == mCapacity){
        throw std::overflow_error("overflow error");
    }

    if(mCount == 0){
        mData[0].value = value;
        mData[0].score = score;
        mCount = mCount + 1;
        return;
    }

    for (size_t i = 0; i< mCapacity; i++){
        if (mData[i].value == ""){
            mData[i].value = value;
            mData[i].score = score;
            index = i;
            mCount = mCount +1;
            break;
        }
    }

    while(index != 0){
        if (mData[index].score < mData[(index-1)/2].score){
                std::string str = mData[index].value;
                float s = mData[index].score;
                
                mData[index].value = mData[(index-1)/2].value;
                mData[index].score = mData[(index-1)/2].score;
                index = (index-1)/2;
                mData[index].value = str;
                mData[index].score = s;
        }
        else{
            break;
        }
    }

}

const Heap::Entry& Heap::top() const{
    if (mCount == 0){
        throw std::underflow_error("underflow error");
    }
    if (mCount == 1){
        return mData[0];
    }
    size_t i = mCapacity-1;
    while(i!=0){
        if(mData[i].value !=""){
            return mData[i];
        }
        i = i-1;
    }
    std::cout << "wrong" <<std::endl;
    return mData[mCapacity-1]; 

}