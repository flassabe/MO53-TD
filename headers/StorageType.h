#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

template <typename T>
class StorageType
{
public:

    //Useful getters to have a clear view of the storage
    virtual StorageType* getNext();
    virtual StorageType* getPrevious();
    virtual int getSize();
    virtual T getElem();

    //Watcher on the element
    virtual bool isNext();
    virtual bool isPrevious();

    virtual void addValue(double value, int position); //Function that add a value at the spécified position
    virtual void removeValue(double value); //Remove the value specified from the storage
    virtual void removeValue_at(int position); //Remove the value at the specified position
};

#endif // STORAGE_TYPE_H
