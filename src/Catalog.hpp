/**
 * @file    Catalog.hpp
 * @brief   Class declaration for a Catalog of products define din a .csv file,
 *          implemented as an std::map of product codes and a Product objects.
 *
 * @author  Emilio Soriano Chavez
 * @date    Mar 07, 2024
 */

#ifndef CATALOG_HPP
#define CATALOG_HPP

#include <map>
    using std::map;
#include <string>
    using std::string;
#include <fstream>
    using std::ifstream;
#include <iostream>
    using std::cout;
    using std::endl;

#include "Product.hpp"

class Catalog
{
    public:
        Catalog (string file_name);

        /** Accessors **/

        Product getProduct      (string code);
        int     getProductCount () const;

        /** Mutators **/

        void addProduct (string name, string code, double price);

    private:
        map<string, Product> _catalog = {};
};

#endif
