//
// Created by santhosh chaitanya singaraju on 11/27/20.
//

#ifndef FINALPROJECT_SET_H
#define FINALPROJECT_SET_H

#include<forward_list>

template <class T>
class SetT{
public:
    SetT();
    SetT(int number_buckets);
    ~SetT();

    void Add(T elem);
    void Remove(T elem);
    bool contains(T elem) const;
    int size(){ return numElems;};

    void operator+(T elem);				// Add
    void operator-(T elem);				// Remove
    SetT operator+(const SetT& other);  // Union
    SetT operator*(const SetT& other);  // Intersection
    SetT operator-(const SetT& other);  // Difference
    SetT operator=(const SetT& other);


private:
    std::forward_list<T>** buckets;
    int numBuckets;
    int getHashIndex(const T& elem) const;
    int numElems = 0;
    int curBucket;
    mutable typename std::forward_list<T>::iterator bucketIter;
};


#endif //FINALPROJECT_SET_H
