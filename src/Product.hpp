/**
 * @file    Product.hpp
 * @brief   Class declaration for a Product with a given name, quantity,
 *          and price.
 *
 * @author  Emilio Soriano Chavez
 * @date    Mar 07, 2024
 */

#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
    using std::string;

class Product
{
    public:
        Product (string name, double price);

        /** Accessors **/

        const string getName     ();
        const double getPrice    ();
        const int    getQuantity ();

        /** Mutators **/

        void increaseQuantity ();

    private:
        string _name     = "";
        double _price    = 0;
        int    _quantity = 0;
};

#endif
