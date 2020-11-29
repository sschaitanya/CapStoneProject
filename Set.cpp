//
// Created by santhosh chaitanya singaraju on 11/27/20.
//

#include "Set.h"
#include <iostream>
#include<string>
#include <unordered_map>

using namespace std;
const int DEFAULT_BUCKET = 5;
template<class T>

int SetT<T>::getHashIndex(const T& key) const
{
    unordered_map<int,T> mapper;
    typename unordered_map<int,T>::hasher hashFunction = mapper.hash_function();
    return static_cast<int>(hashFunction(key) % numBuckets);
}

template<class T>
SetT<T>::SetT()
{
    // Create an array of forward_lists and initially set to an empty forward_list
    buckets = new forward_list<T>*[DEFAULT_BUCKET];
    for (int i = 0; i < DEFAULT_BUCKET; i++) {
        buckets[i] = new forward_list<T>;
    }
    numBuckets = DEFAULT_BUCKET;
}
template<class T>
SetT<T>::SetT(int numBucks)
{
    buckets = new forward_list<T>*[numBucks];
    for (int i = 0; i < numBucks; i++) {
        buckets[i] = new forward_list<T>;
    }
    numBuckets = numBucks;
}

template<class T>
SetT<T>::~SetT()
{
    for (int i = 0; i < numBuckets; i++) {
        delete buckets[i];
    }
}

template<class T>
void SetT<T>::Add(T elem)
{
    if (contains(elem) == true) {
        return;
    }
    else {
        int index = getHashIndex(elem);
        buckets[index]->push_front(elem);
        numElems++;
    }
}

template<class T>
void SetT<T>::Remove(T elem)
{
    if (contains(elem) == false) {
        return;
    }
    else {
        int index = getHashIndex(elem);
        buckets[index]->remove(elem);
        numElems--;
    }
}

template<class T>
bool SetT<T>::contains(T elem) const
{
    int index = getHashIndex(elem);
    for (auto iter = buckets[index]->begin(); iter != buckets[index]->end(); ++iter) {
        if (*iter == elem) {
            return true;
        }
    }
    return false;
}
template<class T>
void SetT<T>::operator+(T elem)
{
    this->Add(elem);
}
template<class T>
SetT<T> SetT<T>::operator+(const SetT & other)
{
    SetT<T> result;
    for(int i = 0; i < numBuckets; i++) {
        for (auto itr = buckets[i]->begin(); itr != buckets[i]->end(); ++itr) {
            result.Add(*itr);
        }
    }
    for (int j = 0; j < other.numBuckets; j++) {
        for (auto itr1 = other.buckets[j]->begin(); itr1 != other.buckets[j]->end(); ++itr1) {
            result.Add(*itr1);
        }
    }
    return result;
}

template<class T> SetT<T> SetT<T>::operator*(const SetT & other)
{
    SetT<T> result;
    for (int i = 0; i < numBuckets; i++) {
        for (auto itr3 = buckets[i]->begin(); itr3 != buckets[i]->end(); ++itr3) {
            if (other.contains(*itr3)) {
                result.Add(*itr3);
            }
        }
    }
    return result;
}

template<class T>
void SetT<T>::operator-(T elem)
{
    this->Remove(elem);
}

template<class T>
SetT<T> SetT<T>::operator-(const SetT & other)
{
    SetT<T> result;
    for(int i = 0; i < numBuckets; i++) {
        for (auto itr = buckets[i]->begin(); itr != buckets[i]->end(); ++itr) {
            result.Add(*itr);
        }
    }
    for (int j = 0; j < other.numBuckets; j++) {
        for (auto itr1 = other.buckets[j]->begin(); itr1 != other.buckets[j]->end(); ++itr1) {
            result.Add(*itr1);
        }
    }

    for (int i = 0; i < numBuckets; i++) {
        for (auto itr5 = buckets[i]->begin(); itr5 != buckets[i]->end(); ++itr5) {
            if (other.contains(*itr5)) {
                result.Remove(*itr5);
            }
        }
    }
    return result;
}

template<class T>
SetT<T> SetT<T>::operator=(const SetT& other)
{
    delete [] buckets;
    this->numBuckets = other.numBuckets;
    this->numElems = 0;
    buckets = new forward_list<T>*[numBuckets];
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = new forward_list<T>;
    }
    for (int i = 0; i < other.numBuckets; i++) {
        for (auto itr4 = other.buckets[i]->begin(); itr4 != other.buckets[i]->end(); ++itr4) {
            this->Add(*itr4);
        }
    }
    return other;
}

template class SetT<int>;
