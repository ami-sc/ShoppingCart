/**
 * @file    Catalog.cpp
 * @brief   Implementation of methods defined in the Catalog.hpp file.
 *
 * @author  Emilio Soriano Chavez
 * @date    Mar 07, 2024
 */

#include "Catalog.hpp"

/**
 * @brief       Constructs a new Catalog object from a .csv file.
 *
 * @details     It is assumed that the .csv file follows a structure of
 *              "name,code,price" for every line.
 *
 * @param   file_name   The file path for the .csv containing the catalog.
 */
Catalog::Catalog (string file_name)
{
    ifstream fin;
    fin.open(file_name);

    /* Check if the file exists and can be opened. */
    if (!fin)
    {
        cout << "Unable to open catalog file: " << file_name << endl;
        cout << "Exiting..." << endl;

        /* Terminate the program if the catalog cannot be opened. */
        exit(1);
    }

    string name;
    string code;
    double price = 0;

    /* Add every product in the file to the catalog. */
    while(fin)
    {
        getline(fin, name, ',');
        getline(fin, code, ',');
        fin >> price;

        /* Skip the trailing newline left by the stream extraction operator. */
        fin.ignore();

        addProduct(name, code, price);
    }
}

/**
 * @brief       Adds a new Product to the Catalog given its name, code, and
 *              price.
 *
 * @details     A new Product item is constructed and added to the Catalog,
 *              mapped to its product code.
 *
 * @param   name    The name of the product.
 * @param   code    The unique code identifying the product.
 * @param   price   The price of the product.
 */
void Catalog::addProduct (string name, string code, double price)
{
    _catalog.insert({code, {name, price}});
}

/**
 * @brief       Searches and retrieves a product from the Catalog.
 *
 * @throws  std::out_of_range   If the target product code is not in the
 *                              Catalog.
 *
 * @param   code    The unique code of the product to search for.
 *
 * @return  A Product object corresponding to the target product.
 */
Product Catalog::getProduct (string code)
{
    /* Search for the product. */
    map<string, Product>::iterator search_it = _catalog.find(code);

    if (search_it == _catalog.end())
    {
        throw std::out_of_range{"Product not in catalog."};
    }

    return search_it -> second;
}

/**
 * @brief       Retrieves the current number of Products in the Catalog.
 *
 * @return  The number of Products in the Catalog.
 */
const int Catalog::getProductCount ()
{
    return _catalog.size();
}
