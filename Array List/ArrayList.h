//
//  ArrayList.h
//  assigment1-question4
//
//  Created by Carlos  Burbano on 2/12/22.
//

#ifndef ArrayList_h
#define ArrayList_h


template <typename T>
class ArrayList {
private:
    T* list;
    int numValues;
    int size;
    bool _resize();
    bool binarySearchHelper( const T&, int, int, int&);

public:
    ArrayList(int = 10);
    ~ArrayList();
    ArrayList(const ArrayList<T>&);
    void insert(const T&);
    void print()const;
    bool isEmpty()const;
    bool isFull()const;
    int listSize()const;
    int binarySearch( const T&);
};

template <typename  T>
ArrayList<T>::ArrayList( int size)
{
    this->size = size;
    numValues = 0;
    list = new T [size];
}

template <typename  T>
ArrayList<T>::~ArrayList()
{
    delete [] list;
    list = nullptr;
    size = 0;
    numValues = 0 ;

}

template <typename  T>
ArrayList<T>::ArrayList(const ArrayList<T>& object2)
{
    this->size = object2.size;
    this->numValues = object2.numValues;
    list = new T [size];

}

template <typename  T>
void ArrayList<T>:: insert(const T & item){

    int i= 0 ;

    if (size == numValues){
        _resize();
    }
        for ( i = numValues -1 ; i >= 0 && list[i] > item; i--){
            list[i+1] = list[i];
        }
        list[i+1] = item;
        numValues++;


}

template <typename  T>
void ArrayList<T>:: print()const
{
    if ( numValues > 0){
        for ( int i = 0; i < numValues ; i++)
            std::cout<<list[i]<< " "<<std::endl;
    }



}

template <typename T>
bool ArrayList<T>::_resize()
{
    bool success = false;
    T* temp = new T[size*2];
    if ( temp!= nullptr){
        size = size *2;
        for ( int i = 0 ; i < numValues; i++){
            temp[i] = list[i];

        }
        delete [] list;
        list =nullptr;
        list = temp;
        success = true;
    }
    return success;
}

template <typename T>
bool ArrayList<T>::isEmpty()const{
    bool success = false;

    if (numValues == 0){
        success = true;
    }

    return success;
}

template <typename  T>
int ArrayList<T>::listSize()const
{
    return numValues;
}

template <typename  T>
bool ArrayList<T>:: isFull()const
{
    bool success = false;
    if ( numValues == size)
        success = true;

    return success;
}

template <typename T>
int ArrayList<T>::binarySearch( const T &item)
{

    int loc= 0;
    if (!binarySearchHelper(item, 0, numValues-1 , loc)){
        loc = -1;
    }

    return loc+1;

}

template <typename T>
bool ArrayList<T>::binarySearchHelper( const T &item, int first, int last,int &loc)
{
    bool found = true;
    if ( first > last){
        found = false;
    }else {
        loc = (first + last)/2;
        if ( item > list[loc]){
            binarySearchHelper(item, first, loc-1, loc);
        }else if (item < list[loc]) {
            binarySearchHelper(item, loc+1, last, loc);
        }else{
            found = true;
        }

    }
    return found;
}
#endif /* ArrayList_h */
