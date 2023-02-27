//*****************************************************************************************************
//
//              File:                   PriorityQueue.h
//
//              Student:                Carlos Burbano
//
//              Assignment:             Assignment # 7
//
//              Course Name:            Data Structures II
//
//              Course Number:          COSC 3100 01
//
//              Due:                    March 28, 2022
//
//
//              Other files required:
//
//                  Stock.cpp
//                  Stock.h
//                  main.cpp
//                  Stock.txt
//
//***********************************************************************************************

#ifndef UNTITLED_PRIORITYQUEUE_H
#define UNTITLED_PRIORITYQUEUE_H

#include <iostream>
#include <string>

//*****************************************************************************************************

//using namespace std;


template <typename T>
class PriorityQueue {
private:
    int size;
    int arraySize;
    T* elements;
    void heapify(int);
    bool _resize();

public:
    PriorityQueue(int = 12);
    ~PriorityQueue();
    bool enqueue(const T&);
    bool dequeue(T&);
    void display()const;
};

//*****************************************************************************************************

template <typename T>
PriorityQueue<T>::PriorityQueue(int arraySize)
{
    this->size = size;
    this->arraySize = arraySize;
    elements = new T [arraySize];
}

//*****************************************************************************************************

template <typename T>
PriorityQueue<T>::~PriorityQueue<T>()
{
    delete [] elements;
    elements = nullptr;
    size = 0;
    arraySize = 0 ;

}

//*****************************************************************************************************

template <typename T>
bool PriorityQueue<T>::enqueue(const T & value) {
    bool check = false;
    int child = size;
    int parent = ( child - 1)/2;

    if ( size == arraySize){
        _resize();
    }
    while((child > 0 ) && (value > elements[parent])){
        elements[child] = elements[parent];
        child = parent;
        parent = (parent-1)/2;
    }
    elements[child] = value;
    ++size;
    check = true;
    return check;
}

//*****************************************************************************************************

template <typename T>
bool PriorityQueue<T>::dequeue(T & value) {
    bool check = false;
    if (size > 0 ){
        value = elements[0];
        check = true;
        elements[0] = elements[size-1];
        --size;
        heapify(0);
    }
    return check;
}

//*****************************************************************************************************

template <typename T>
void PriorityQueue<T>::heapify(int i) {
    int leftChild;
    int rightChild;
    int largest;
    bool stop = false;
    T temp = elements[i];
    leftChild = i * 2 + 1;
    while ( (leftChild < size) && !stop){
        rightChild = leftChild +1;
        if ( rightChild >= size){
            largest =leftChild;
        }else {
            if ( elements[leftChild] > elements[rightChild]){
                largest = leftChild;
            } else {
                largest = rightChild;
            }
        }
        if ( elements[largest] > temp){
            elements[i] = elements[largest];
            i = largest;
            leftChild = i * 2 + 1;
        }else {
            stop = true;
        }
    }
    elements[i] = temp;
}

//*****************************************************************************************************

template <typename T>
void PriorityQueue<T>::display() const {
    for ( int i = 0 ; i < size ; i++)
        std::cout<<elements[i]<<" "<< std::endl;
}

//*****************************************************************************************************

template <typename T>
bool PriorityQueue<T>::_resize()
{
    bool success = false;
    T* temp = new T[arraySize*2];
    if ( temp!= nullptr){
        arraySize = arraySize *2;
        for ( int i = 0 ; i < size; i++){
            temp[i] = elements[i];
        }
        delete [] elements;
        elements =nullptr;
        elements = temp;
        success = true;
    }
    return success;
}

//*****************************************************************************************************

#endif //UNTITLED_PRIORITYQUEUE_H
