#ifndef CALCULATION_H
#define CALCULATION_H


class calculation { // pure virtual
}; // average, rolling_average, etc. inherit from calculation

class average : public calculation{

};

class rolling_average{

};

#endif // CALCULATION_H
