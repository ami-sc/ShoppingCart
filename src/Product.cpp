/**
 * @file    Product.cpp
 * @brief   Implementation of methods defined in the Product.hpp file.
 *
 * @author  Emilio Soriano Chavez
 * @date    Mar 07, 2024
 */

#include "Product.hpp"

/**
 * @brief       Constructs a new Product object.
 *
 * @details     The product will have an initial quantity of "1".
 *
 * @param   name    The name of the product.
 * @param   price   The price of the product.
 */
Product::Product (string name, double price)
{
    _name = name;
    _price = price;
    _quantity = 1;
}

/**
 * @brief   Retrieves the name of the product.
 *
 * @return  The name of the product.
 */
const string Product::getName ()
{
    return _name;
}

/**
 * @brief   Retrieves the price of the product.
 *
 * @return  The price of the product.
 */
const double Product::getPrice ()
{
    return _price;
}

/**
 * @brief   Retrieves the quantity of the product.
 *
 * @return  The quantity of the product.
 */
const int Product::getQuantity ()
{
    return _quantity;
}

/**
 * @brief   Increases the quantity of the product by "1"
 */
void Product::increaseQuantity ()
{
    _quantity++;
}
