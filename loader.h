#ifndef LOADER_H
#define LOADER_H


class loader { // pure virtual
}; // as for storage_type, text and bin loaders are children of loader

class text_loader : public loader{

};

class bin_loader : public loader{

};

#endif // LOADER_H
