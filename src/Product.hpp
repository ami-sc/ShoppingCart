#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
    using std::string;

class Product
{
    public:
        Product (string name, double price);

        inline string getName     () { return _name;  }
        inline double getPrice    () { return _price; }

    private:
        string _name  = "";
        double _price = 0;
};

#endif
