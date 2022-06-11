#ifndef WRITER_H
#define WRITER_H


class writer { // pure virtual
}; // any output (file - text or bin, screen) inherit from this one

class text_writer : public writer {

};

class bin_writer : public writer{

};

#endif // WRITER_H
